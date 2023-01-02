#include "IShape.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Line.hpp"
/* ---------------Line---------------- */
Line::Line() = default;
Line::Line(const Point& first, const Point& second)
    : start_(first), end_(second) {
  A_ = second.GetY() - first.GetY();
  B_ = first.GetX() - second.GetX();
  C_ = first.GetY() * (second.GetX() - first.GetX()) -
      first.GetX() * (second.GetY() - first.GetY());
}
Line::Line(int64_t arg_a, int64_t arg_b, int64_t arg_c)
    : A_(arg_a), B_(arg_b), C_(arg_c) {}
IShape& Line::Move(const Vector& vector) {
  C_ = C_ - A_ * vector.GetX() - B_ * vector.GetY();
  return *this;
}
bool Line::ContainsPoint(const Point& point) const {
  return (A_ * point.GetX() + B_ * point.GetY() + C_) == 0;
}
bool Line::CrossSegment(const Segment& segment) const {
  Vector direction({0, 0}, {B_, -A_});
  Vector::Point point(start_.GetX(), start_.GetY());
  Vector first_vector(
      point, Vector::Point(segment.GetA().GetX(), segment.GetA().GetY()));
  Vector second_vector(
      point, Vector::Point(segment.GetB().GetX(), segment.GetB().GetY()));
  return (direction ^ first_vector) * (direction ^ second_vector) <= 0;
}
IShape* Line::Clone() const {
  Line* copy = new Line(A_, B_, C_);
  return copy;
}
double Line::DistToLine(const Point& point) const {
  double res = std::abs(A_ * point.GetX() + B_ * point.GetY() + C_);
  return res / sqrt(A_ * A_ + B_ * B_);
}

int64_t Line::GetA() const { return A_; }
int64_t Line::GetB() const { return B_; }
int64_t Line::GetC() const { return C_; }