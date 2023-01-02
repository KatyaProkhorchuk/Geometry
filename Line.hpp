#pragma once

#include "IShape.hpp"
#include "Point.hpp"

class Line : public IShape {
 public:
  explicit Line();
  explicit Line(const Point& first, const Point& second);
  explicit Line(int64_t arg_a, int64_t arg_b, int64_t arg_c);
  IShape& Move(const Vector& vector) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossSegment(const Segment& segment) const override;
  double DistToLine(const Point& point) const;
  IShape* Clone() const override;
  int64_t GetA() const;
  int64_t GetB() const;
  int64_t GetC() const;
  ~Line() = default;

 private:
  int64_t A_{0};
  int64_t B_{0};
  int64_t C_{0};
  Point start_{0, 0};
  Point end_{0, 0};
};
