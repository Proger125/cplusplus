#pragma once
#include <algorithm>
#include <cmath>
#include <fstream>
#include <memory>
#define PI 3.1415926
#include "Point.h"

using namespace std;
class Shape {
 protected:
  static size_t ShapeCount_;
  size_t ShapeId_;
  string type_;

 public:
  virtual double Length(point*, point*) = 0;
  size_t GetId() { return ShapeId_; }
  size_t GetCount() { return ShapeCount_; }
  string GetType() { return type_; }
  void NewId() { ShapeId_ = ShapeCount_; }
  static void IncreaseShareCount() { ShapeCount_++; }
  Shape() {
    IncreaseShareCount();
    NewId();
  }
  Shape(string new_type) {
    IncreaseShareCount();
    NewId();
    type_ = new_type;
  }
  virtual ~Shape() {}
  virtual double Square() = 0;
  virtual double Perimeter() = 0;
  virtual double Volume() = 0;
};
size_t Shape::ShapeCount_ = 0;
class Shape2d : public Shape {
 public:
  Shape2d() : Shape(){};
  Shape2d(string new_type) : Shape(new_type){};
  virtual ~Shape2d(){};
  double Length(point* first, point* second) {
    point2d first_ = *(static_cast<point2d*>(first));
    point2d second_ = *(static_cast<point2d*>(second));
    return hypot(first_.x - second_.x, first_.y - second_.y);
  }
  virtual double Square() = 0;
  virtual double Perimeter() = 0;
  virtual double Volume() = 0;
};

class Shape3d : public Shape {
 public:
  Shape3d() : Shape(){};
  Shape3d(string new_type) : Shape(new_type){};
  double Length(point* first, point* second) {
    point3d first_ = *(static_cast<point3d*>(first));
    point3d second_ = *(static_cast<point3d*>(second));
    return hypot(first_.x - second_.x,
                 hypot(first_.y - second_.y, first_.z - second_.z));
  }

  virtual double Square() = 0;
  virtual double Perimeter() = 0;
  virtual double Volume() = 0;
  virtual ~Shape3d(){};
};
class Circle : public Shape3d {
 protected:
  point3d center;
  point3d top;

 public:
  Circle() : Shape3d(), center(), top(){};
  Circle(point3d first, point3d second, string new_type) : Shape3d(new_type) {
    center = first;
    top = second;
  };
  Circle operator=(Circle& second) {
    this->ShapeId_ = second.ShapeId_;
    this->type_ = second.type_;
    this->center = second.center;
    this->top = second.top;
    return (*this);
  };
  Circle(Circle& second) {
    this->ShapeId_ = second.ShapeId_;
    this->type_ = second.type_;
    this->center = second.center;
    this->top = second.top;
  };
  virtual double Square() {
    return Length(&center, &top) * Length(&center, &top) * PI;
  }
  virtual double Perimeter() { return 0; }

  double Volume() { return 0; }
  virtual ~Circle() {}
};
class Sector : public Circle {
 public:
  double degree;

  Sector() : degree(), Circle(){};
  Sector(point3d first, point3d second, double deg, string new_type) {
    type_ = new_type;
    center = first;
    top = second;
    degree = deg;
  };
  Sector(Sector& second) {
    this->ShapeId_ = second.ShapeId_;
    this->type_ = second.type_;
    this->center = second.center;
    this->top = second.top;
    this->degree = second.degree;
  };
  Sector operator=(Sector& second) {
    this->ShapeId_ = second.ShapeId_;
    this->type_ = second.type_;
    this->center = second.center;
    this->top = second.top;
    this->degree = second.degree;
    return (*this);
  };
  virtual double Square() { return Circle::Square() * degree / 360; }
  virtual double Perimeter() { return 0; }
  virtual double Volume() { return 0; }
  virtual ~Sector(){};
};