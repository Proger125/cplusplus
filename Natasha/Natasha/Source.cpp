#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
struct Node {
  int val;
  struct Node *left;
  struct Node *right;
};
class Tree {
 public:
  Tree() { root = nullptr; };
  ~Tree() { delete root; };
  void Add(int element) {
    if (root == nullptr) {
      root = new Node();
      root->left = nullptr;
      root->right = nullptr;
      root->val = element;
    } else {
      if (element > root->val) {
        Node *current = root;
        while (element > current->val) {
          if (current->right == nullptr) {
            Node *nNode = new Node();
            current->right = nNode;
            nNode->val = element;
            nNode->left = nullptr;
            nNode->right = nullptr;
            return;
          }
          current = current->right;
        }
        if (element == current->val) {
          return;
        }
        Node *nNode = new Node();
        current->left = nNode;
        nNode->val = element;
        nNode->left = nullptr;
        nNode->right = nullptr;
      } else if (element < root->val) {
        Node *current = root;
        while (element < current->val) {
          if (current->left == nullptr) {
            Node *nNode = new Node();
            current->left = nNode;
            nNode->val = element;
            nNode->left = nullptr;
            nNode->right = nullptr;
            return;
          }
          current = current->left;
        }
        if (element == current->val) {
          return;
        }
        Node *nNode = new Node();
        current->right = nNode;
        nNode->val = element;
        nNode->left = nullptr;
        nNode->right = nullptr;
      }
    }
  };
  friend void Go(Tree t) {
    ofstream fout("output.txt");
    Node *nroot = t.root;
    t.preOrderTravers(t.root, fout);
    fout.close();
  };
  void preOrderTravers(Node *root, ofstream &fout) {
    if (root != nullptr) {
      fout << root->val << endl;
      preOrderTravers(root->left, fout);
      preOrderTravers(root->right, fout);
    }
  }

 private:
  Node *root;
};
void ReadData(Tree &t) {
  ifstream fin("input.txt");
  if (fin.peek() == EOF) {
    return;
  }
  while (!fin.eof()) {
    int tmp = 0;
    fin >> tmp;
    t.Add(tmp);
  }
  fin.close();
}
int c = 0;
void Function(int a, int b) {
  if (a == 0) {
    c++;
  } else {
    while (b < a) {
      b++;
      Function(a - b, b);
    }
  }
}

  int main() {
    // Tree t;
    // ReadData(t);
    // Go(t);
    Function(50, 0);
    cout << c << endl;
    system("pause");
    return 0;
  }