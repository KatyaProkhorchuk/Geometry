#pragma once

#include "IShape.hpp"
#include "Point.hpp"
class Ray : public IShape {
 public:
  explicit Ray() = default;
  explicit Ray(const Point& first, const Point& second);
  explicit Ray(const Point& first, const Vector& vector);
  IShape& Move(const Vector& vector) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  Point GetA() const;
  Vector GetVector() const;
  ~Ray() = default;

 private:
  Point start_{0, 0};
  Vector vector_{0, 0};
};
