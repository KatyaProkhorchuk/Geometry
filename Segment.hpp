#pragma once

#include "IShape.hpp"
#include "Point.hpp"
class Segment : public IShape {
 public:
  explicit Segment();
  explicit Segment(const Point& first, const Point& second);
  IShape& Move(const Vector& vector) override;
  bool ContainsPoint(const Point& point) const override;
  bool CrossSegment(const Segment& segment) const override;
  IShape* Clone() const override;
  double DistToSegment(const Point& point) const;
  Point GetA() const;
  Point GetB() const;
  static int64_t Area(const Point& a_point, const Point& b_point,
                      const Point& c_point);
  static bool Intersect(int64_t a_point, int64_t b_point, int64_t c_point,
                        int64_t d_point);
  ~Segment() override = default;

 private:
  Point start_{0, 0};
  Point end_{0, 0};
};
