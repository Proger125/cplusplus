#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include "Containers.h"
#include "Point.h"
#include "Shape.h"

using namespace std;

map<string, int> names{{"Circle", 0}, {"Sector", 1}};

Shape* Do(int name, ifstream& in) {
  switch (name) {
    case 0: {
      point3d a, b;
      in >> a >> b;
      return new Circle(a, b, "3D");
      break;
    }
    case 1: {
      point3d a, b;
      double d;
      in >> a >> b;
      in >> d;
      return new Sector(a, b, d, "3D");
      break;
    }
  }
}
class Programm {
 public:
  static bool Main() {
    int n;
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n;
    string name;
    BiDirectionalList<Shape*> List;
    out << "Number of figures:"
        << " " << n << endl;
    for (int i = 0; i < n; ++i) {
      in >> name;
      List.PushBack(Do(names[name], in));

      Shape3d* figure = dynamic_cast<Shape3d*>(List.PopFront());
      out << "  "
          << "ID"
          << " " << figure->GetId() << " " << name << " " << figure->GetType()
          << " ";
      out << "Square: " << figure->Square() << endl;
    }
    in.close();
    out.close();
    return 0;
  };
};