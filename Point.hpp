#pragma once

#include "IShape.hpp"
class IShape;
class Segment;
class Point : public IShape {
 public:
  explicit Point();
  explicit Point(int64_t coord_x, int64_t coord_y);
  IShape& Move(const Vector& vector) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  int64_t GetX() const;
  int64_t GetY() const;
  Point operator+=(const Vector& vector);
  Point operator-();
  ~Point() override = default;

 private:
  int64_t x_ = 0;
  int64_t y_ = 0;
};

Vector operator-(const Point& point_first, const Point& point_second);