#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace babintseva;

Circle::Circle(const point_t &pos, const double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius must be > 0.0!");
  }
}

double Circle::getRadius() const
{
  return radius_;
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, 2 * radius_, 2 * radius_};
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::printInformation() const
{
  std::cout << "Radius - " << getRadius() << std::endl
            << "Position - (" << pos_.x << ", " << pos_.y << ")" << std::endl
            << "Area : " << getArea() << std::endl
            << "Frame Rectangle is : " << getFrameRect().width << ", " << getFrameRect().height << std::endl;
}

void Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient must be > 0.0!");
  }

  radius_ *= coefficient;
}
