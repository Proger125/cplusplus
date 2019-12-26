#pragma once
#include <istream>

using namespace std;

class point {
 public:
  point(){};
  virtual ~point(){};
  point(point& second){};
  point operator=(point& second) { return (*this); }
  point(point&& second) {}
  point operator=(point&& second) { return (*this); }
};
class point1d : public point {
 public:
  double x;
  point1d() : x(0){};

  point1d(double a) : x(a){};

  point1d(point1d& second) { x = second.x; }
  point1d operator=(point1d& second) {
    x = second.x;
    return (*this);
  }

  point1d(point1d&& second) { x = second.x; }
  point1d operator=(point1d&& second) {
    x = second.x;
    return (*this);
  }
  bool operator==(const point1d& second) { return (x == second.x); }
  bool operator!=(const point1d& second) { return !(*(this) == second); }

  virtual ~point1d(){};
  friend istream& operator>>(istream& in, point1d p);
};
istream& operator>>(istream& in, point1d p) {
  in >> p.x;
  return in;
};

class point2d : public point1d {
 public:
  double y;

  point2d() : point1d(), y(0){};
  point2d(double a, double b) : point1d(a), y(b){};
  point2d(point2d& second) {
    x = second.x;
    y = second.y;
  }
  point2d operator=(point2d& second) {
    x = second.x;
    y = second.y;
    return (*this);
  }

  point2d(point2d&& second) {
    x = second.x;
    y = second.y;
  }
  point2d operator=(point2d&& second) {
    x = second.x;
    y = second.y;
    return (*this);
  }
  bool operator==(const point2d& second) {
    return (x == second.x && y == second.y);
  }
  bool operator!=(const point2d& second) { return !(*(this) == second); }

  virtual ~point2d(){};
  friend istream& operator>>(istream& in, point2d& p);
};
istream& operator>>(istream& in, point2d p) {
  in >> p.x >> p.y;
  return in;
};

class point3d : public point2d {
 public:
  double z;
  point3d() : point2d(), z(0){};
  point3d(double a, double b, double c) : point2d(a, b), z(c){};

  point3d(point3d& second) {
    x = second.x;
    y = second.y;
    z = second.z;
  }
  point3d operator=(point3d& second) {
    x = second.x;
    y = second.y;
    z = second.z;
    return (*this);
  }

  point3d(point3d&& second) {
    x = second.x;
    y = second.y;
    z = second.z;
  }
  point3d operator=(point3d&& second) {
    x = second.x;
    y = second.y;
    z = second.z;
    return (*this);
  }
  bool operator==(const point3d& second) {
    return (x == second.x && y == second.y && z == second.z);
  }
  bool operator!=(const point3d& second) { return !(*(this) == second); }
  virtual ~point3d(){};
  friend istream& operator>>(istream& in, point3d& p);
};
istream& operator>>(istream& in, point3d& p) {
  in >> p.x >> p.y >> p.z;
  return in;
};