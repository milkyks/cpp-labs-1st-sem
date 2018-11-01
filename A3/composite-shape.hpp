#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include "shape.hpp"
#include <memory>

namespace babintseva
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape(const std::shared_ptr<Shape> &shape);
    void addShape(const std::shared_ptr<Shape> &shape);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &shape_pos) override;
    void move(const double dx, const double dy) override;
    void printInformation() const override;
    void scale(const double coefficient) override;

  private:
    size_t size_;
    std::unique_ptr <std::shared_ptr<Shape>[]> shapes_;
  };
};
#endif
