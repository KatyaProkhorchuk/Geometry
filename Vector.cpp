#include "IShape.hpp"
/* -----------Vector------------ */
Vector::Vector() = default;
Vector::Vector(const int64_t& coord_x, const int64_t& coord_y)
    : coordinate_(coord_x, coord_y) {}
Vector::Vector(const Vector::Point& first, const Vector::Point& second) {
  coordinate_.x = second.x - first.x;
  coordinate_.y = second.y - first.y;
}
Vector::Vector(const Point& point) : coordinate_(point) {}
Vector& Vector::operator+=(const Vector& other) {
  coordinate_.x += other.coordinate_.x;
  coordinate_.y += other.coordinate_.y;
  return *this;
}
Vector& Vector::operator*=(const int64_t& other) {
  coordinate_.x *= other;
  coordinate_.y *= other;
  return *this;
}
Vector& Vector::operator-=(const Vector& other) {
  coordinate_.x -= other.coordinate_.x;
  coordinate_.y -= other.coordinate_.y;
  return *this;
}
Vector operator+(const Vector& vector_first, const Vector& vector_second) {
  Vector copy = vector_first;
  copy += vector_second;
  return copy;
}
Vector operator-(const Vector& vector_first, const Vector& vector_second) {
  Vector copy = vector_first;
  copy -= vector_second;
  return copy;
}
int64_t operator^(const Vector& vector_first, const Vector& vector_second) {
  return (vector_first.GetX() * vector_second.GetY() -
      vector_first.GetY() * vector_second.GetX());
}
int64_t operator*(const Vector& vector_first, const Vector& vector_second) {
  return (vector_first.GetX() * vector_second.GetX() +
      vector_first.GetY() * vector_second.GetY());
}
Vector operator*(const int64_t& number, const Vector& vector) {
  Vector copy = vector;
  copy *= number;
  return copy;
}
Vector operator*(const Vector& vector, const int64_t& number) {
  Vector copy = vector;
  copy *= number;
  return copy;
}
Vector Vector::operator-() const {
  Point result(-coordinate_.x, -coordinate_.y);
  return Vector(result);
}
void Vector::SetCoordinate(int64_t coord_x, int64_t coord_y) {
  coordinate_.x = coord_x;
  coordinate_.y = coord_y;
}
int64_t Vector::GetX() const { return coordinate_.x; }
int64_t Vector::GetY() const { return coordinate_.y; }
double Vector::GetLen() const {
  return sqrt(coordinate_.x * coordinate_.x + coordinate_.y * coordinate_.y);
}