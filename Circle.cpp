#include "IShape.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Circle.hpp"
/* ---------------Circle--------------------- */
Circle::Circle(const Point& center, size_t radius)
    : center_(center), radius_(radius) {}
IShape& Circle::Move(const Vector& vector) {
  center_.Move(vector);
  return *this;
}
bool Circle::ContainsPoint(const Point& point) const {
  if (std::abs(point.GetX() - center_.GetX()) > radius_) {
    return false;
  }
  if (std::abs(point.GetY() - center_.GetY()) > radius_) {
    return false;
  }
  if (std::abs(point.GetX() - center_.GetX()) +
      std::abs(point.GetY() - center_.GetY()) <=
      radius_) {
    return true;
  }
  int64_t coord_x = std::abs(point.GetX() - center_.GetX());
  int64_t coord_y = std::abs(point.GetY() - center_.GetY());
  return (coord_x * coord_x + coord_y * coord_y <= radius_ * radius_);
}
bool Circle::CrossSegment(const Segment& segment) const {
  Point first(segment.GetA().GetX(), segment.GetA().GetY());
  Point second(segment.GetB().GetX(), segment.GetB().GetY());

  Vector first_vector(
      Vector::Point(center_.GetX(), center_.GetY()),
      Vector::Point(segment.GetA().GetX(), segment.GetA().GetY()));
  Vector second_vector(
      Vector::Point(center_.GetX(), center_.GetY()),
      Vector::Point(segment.GetB().GetX(), segment.GetB().GetY()));
  double distant = segment.DistToSegment(center_);
  return distant <= radius_ && (first_vector.GetLen() >= radius_ ||
      second_vector.GetLen() >= radius_);
}

IShape* Circle::Clone() const {
  Circle* copy = new Circle(center_, radius_);
  return copy;
}
Point Circle::GetCentre() const { return center_; }
size_t Circle::GetRadius() const { return radius_; }