#include <time.h>
#include "Input.h"
#include "Sort.h"

int main() {
  vector<int> a;
  int n;
  InputFile();
  InputVector(a);
  ChooseSort(n);
  clock_t start = clock();
  switch (n) {
    case 1: {
      InsertSort(a);
      break;
	}
    case 2: {
      ShellSort(a);
      break;
    }
    case 3: {
      Bubble_sort(a);
      break;
    }
    case 4: {
      OddEvenSort(a);
      break;
    }
    case 5: {
      ShakerSort(a);
      break;
    }
    case 6: {
      CombSort(a);
      break;
    }
    case 7: {
      ChooseSort(a);
      break;
    }
    case 8: {
      DoubleChooseSort(a);
      break;
    }
  }
  ofstream fout("result.txt");
  for (auto &element : a) {
    fout << element << " ";
  }
  fout << endl;
  fout.close();
  cout << "Algorithm works = " << (clock() - start) / 1000.0 << " seconds"
       << endl;
  cout << "Count of compasions = " << count_of_compasions << endl;
  cout << "Count of swaps = " << count_of_swaps << endl;
  cout << "Do you want to run program once again? Press 1 if you want or press "
          "0 if you don't want. ";
  bool again;
  cin >> again;
  if (again) {
    system("cls");
    cin.clear();
    while (cin.get() != '\n');
    count_of_compasions = 0;
    count_of_swaps = 0;
    return main();
  } else {
    system("pause");
    return 0;
  }
}