#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(const point_t pos, const double width, const double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Width must be > 0.0!");
  }

  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Height must be > 0.0!");
  }
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void Rectangle::move(const point_t pos)
{
  pos_.x = pos.x;
  pos_.y = pos.y;
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::printInformation() const
{
  std::cout << "Width - " << getFrameRect().width << ", height - " << getFrameRect().height << std::endl
            << "Position - (" << pos_.x << ", " << pos_.y << ")" << std::endl
            << "Area : " << getArea() << std::endl
            << "Frame Rectangle is : " << getFrameRect().width << ", " << getFrameRect().height << std::endl;
}
