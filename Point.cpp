#include "IShape.hpp"
#include "Point.hpp"
#include "Segment.hpp"

/* ------------Point-------------- */
Point::Point() = default;
Point::Point(int64_t coord_x, int64_t coord_y) : x_(coord_x), y_(coord_y) {};
IShape& Point::Move(const Vector& vector) {
  x_ += vector.GetX();
  y_ += vector.GetY();
  return *this;
}
bool Point::ContainsPoint(const Point& point) const {
  return (x_ == point.GetX() && y_ == point.GetY());
}
bool Point::CrossSegment(const Segment& segment) const {
  return segment.ContainsPoint(*this);
}
IShape* Point::Clone() const {
  Point* clone = new Point(x_, y_);
  return clone;
}
Vector operator-(const Point& point_first, const Point& point_second) {
  Vector::Point first(point_first.GetX(), point_first.GetY());
  Vector::Point second(point_second.GetX(), point_second.GetY());
  Vector vector(second, first);
  return vector;
}
Point Point::operator+=(const Vector& vector) {
  x_ += vector.GetX();
  y_ += vector.GetY();
  return *this;
}
Point Point::operator-() {
  x_ *= -1;
  y_ *= -1;
  return *this;
}
int64_t Point::GetX() const { return x_; }
int64_t Point::GetY() const { return y_; }
