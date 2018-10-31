#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(point_t pos, double radius);
  double getRadius() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t pos) override;
  void move(const double dx, const double dy) override;
  void printInformation() const override;

private:
  point_t pos_;
  double radius_;
};
#endif
