#pragma once
#include <cstdint>
#include <iostream>
#include <cmath>

#include "Vector.hpp"
class Point;
class Segment;

class IShape {
 public:
  virtual IShape& Move(const Vector& vector) = 0;
  virtual bool ContainsPoint(const Point& point) const = 0;
  virtual bool CrossSegment(const Segment& segment) const = 0;
  virtual IShape* Clone() const = 0;
  virtual ~IShape() = default;
};

Vector operator-(const Point& point_first, const Point& point_second);