#pragma once

#include "IShape.hpp"
#include "Point.hpp"
class Circle : public IShape {
 public:
  explicit Circle() = default;
  explicit Circle(const Point& center, size_t radius);
  IShape& Move(const Vector& vector) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  Point GetCentre() const;
  size_t GetRadius() const;
  ~Circle() = default;

 private:
  Point center_{0, 0};
  int64_t radius_{0};
};
