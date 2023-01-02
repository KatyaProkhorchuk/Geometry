#include "IShape.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Line.hpp"
#include "Ray.hpp"

/* -----------Ray------------- */

Ray::Ray(const Point& first, const Point& second)
    : start_(first), vector_(second.GetX(), second.GetY()) {}
Ray::Ray(const Point& first, const Vector& vector)
    : start_(first), vector_(vector) {}
IShape& Ray::Move(const Vector& vector) {
  Point point(start_.GetX(), start_.GetY());
  point.Move(vector);
  Point vec(vector_.GetX(), vector_.GetY());
  Vector sdvig(-point.GetX(), -point.GetY());
  vec.Move(vector);
  vec.Move(sdvig);
  start_ = point;
  vector_.SetCoordinate(vec.GetX(), vec.GetY());
  return *this;
}
bool Ray::ContainsPoint(const Point& point) const {
  Point tmp(point.GetX(), point.GetY());
  Line line(start_, Point(vector_.GetX(), vector_.GetY()));
  Vector first_vector(Vector::Point(start_.GetX(), start_.GetY()),
                      Vector::Point(tmp.GetX(), tmp.GetY()));
  Vector second_vector(Vector::Point(start_.GetX(), start_.GetY()),
                       Vector::Point(vector_.GetX(), vector_.GetY()));
  return (first_vector * second_vector >= 0 && line.ContainsPoint(point));
}
bool Ray::CrossSegment(const Segment& segment) const {
  Vector first_vector(Vector::Point(start_.GetX(), start_.GetY()),
                      Vector::Point(vector_.GetX(), vector_.GetY()));
  Vector second_vector(
      Vector::Point(segment.GetA().GetX(), segment.GetA().GetY()),
      Vector::Point(segment.GetB().GetX(), segment.GetB().GetY()));
  Vector third_vector(
      Vector::Point(segment.GetA().GetX(), segment.GetA().GetY()),
      Vector::Point(start_.GetX(), start_.GetY()));
  int64_t mul = first_vector ^ second_vector;
  if (mul == 0) {
    Point segment_start(segment.GetA().GetX(), segment.GetA().GetY());
    Point segment_end(segment.GetB().GetX(), segment.GetB().GetY());
    return ContainsPoint(segment_start) || ContainsPoint((segment_end));
  }
  int64_t mul1 = first_vector ^ third_vector;
  int64_t mul2 = second_vector ^ third_vector;
  const int64_t kNull = 0;
  if (static_cast<int>(mul > kNull) - static_cast<int>(mul < kNull) < 0) {
    mul *= -1;
    mul1 *= -1;
    mul2 *= -1;
  }
  return mul1 <= mul && mul1 >= 0 && mul2 >= 0;
}
IShape* Ray::Clone() const {
  Ray* copy = new Ray(start_, vector_);
  return copy;
}
Point Ray::GetA() const { return start_; }
Vector Ray::GetVector() const { return vector_; }