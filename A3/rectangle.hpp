#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace babintseva
{
 class Rectangle : public Shape
 {
 public:
   Rectangle(const point_t &pos, const double width, const double height);
   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(const point_t &pos) override;
   void move(const double dx, const double dy) override;
   void printInformation() const override;
   void scale(const double coefficient) override;

 private:
   point_t pos_;
   double width_;
   double height_;
 };
}

#endif
