#pragma once
#include <cstdint>
#include <iostream>

class Vector {
 public:
  struct Point {
    int64_t x{0};
    int64_t y{0};
    Point(int64_t coord_x, int64_t coord_y) : x(coord_x), y(coord_y){};
    Point(const Point& point) : x(point.x), y(point.y){};
  };
  explicit Vector();
  explicit Vector(const int64_t& coord_x, const int64_t& coord_y);
  explicit Vector(const Vector::Point& first, const Point& second);
  Vector(const Point& point);
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector& operator*=(const int64_t& other);
  int64_t GetX() const;
  int64_t GetY() const;
  double GetLen() const;
  Vector operator-() const;
  void SetCoordinate(int64_t coord_x, int64_t coord_y);
  ~Vector() = default;

 private:
  Point coordinate_{0, 0};
};
int64_t operator^(const Vector& vector_first, const Vector& vector_second);
int64_t operator*(const Vector& vector_first, const Vector& vector_second);
Vector operator*(const int64_t& number, const Vector& vector);
Vector operator*(const Vector& vector, const int64_t& number);
