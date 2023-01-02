#include "IShape.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Line.hpp"

/* ------------Segment----------- */
Segment::Segment() = default;
Segment::Segment(const Point& first, const Point& second)
    : start_(first), end_(second) {}
IShape& Segment::Move(const Vector& vector) {
  start_ += vector;
  end_ += vector;
  return *this;
}

bool Segment::ContainsPoint(const Point& point) const {
  Vector vector_first =
      Vector(point.GetX() - start_.GetX(), point.GetY() - start_.GetY());
  Vector vector_second = Vector(Vector::Point(start_.GetX(), start_.GetY()),
                                Vector::Point(end_.GetX(), end_.GetY()));
  return (vector_second ^ vector_first) == 0 &&
          point.GetX() <= std::max(start_.GetX(), end_.GetX()) &&
          point.GetX() >= std::min(start_.GetX(), end_.GetX()) &&
          point.GetY() <= std::max(start_.GetY(), end_.GetY()) &&
          point.GetY() >= std::min(start_.GetY(), end_.GetY());
}

double Segment::DistToSegment(const Point& point) const {
  Vector first_vector(Vector::Point(start_.GetX(), start_.GetY()),
                      Vector::Point(point.GetX(), point.GetY()));
  Vector second_vector(Vector::Point(start_.GetX(), start_.GetY()),
                       Vector::Point(end_.GetX(), end_.GetY()));
  Vector third_vector(Vector::Point(point.GetX(), point.GetY()),
                      Vector::Point(end_.GetX(), end_.GetY()));
  int64_t mul_12 = first_vector * second_vector;
  int64_t mul_32 = second_vector * third_vector;
  Line line(start_, end_);
  if (mul_12 >= 0 && mul_32 >= 0) {
    return line.DistToLine(point);
  }
  return std::min(first_vector.GetLen(), third_vector.GetLen());
}

int64_t Segment::Area(const Point& a_point, const Point& b_point,
                      const Point& c_point) {
  return (b_point.GetX() - a_point.GetX()) * (c_point.GetY() - a_point.GetY()) -
      (b_point.GetY() - a_point.GetY()) * (c_point.GetX() - a_point.GetX());
}
bool Segment::Intersect(int64_t a_point, int64_t b_point, int64_t c_point,
                        int64_t d_point) {
  if (a_point > b_point) {
    std::swap(a_point, b_point);
  }
  if (c_point > d_point) {
    std::swap(c_point, d_point);
  }
  return std::max(a_point, c_point) <= std::min(b_point, d_point);
}

bool Segment::CrossSegment(const Segment& segment) const {
  return Intersect(start_.GetX(), end_.GetX(), segment.start_.GetX(),
                   segment.end_.GetX()) &&
      Intersect(start_.GetY(), end_.GetY(), segment.start_.GetY(),
                segment.end_.GetY()) &&
      Area(start_, end_, segment.start_) *
          Area(start_, end_, segment.end_) <=
          0 &&
      Area(segment.start_, segment.end_, start_) *
          Area(segment.start_, segment.end_, end_) <=
          0;
}
IShape* Segment::Clone() const {
  Segment* segment = new Segment(start_, end_);
  return segment;
}
Point Segment::GetA() const { return start_; }
Point Segment::GetB() const { return end_; }

