#include "composite-shape.hpp"
#include <memory>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace babintseva;

CompositeShape::CompositeShape(const std::shared_ptr<Shape> &shape):
  shapes_(new std::shared_ptr<Shape>[1]),
  size_(1)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Your shape is empty!");
  }

  shapes_[0] = shape;
}

void CompositeShape::addShape(const std::shared_ptr<Shape> &shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Your shape is empty!");
  }

  std::unique_ptr<std::shared_ptr<Shape>[]> temp_shapes (new std::shared_ptr<Shape>[size_ + 1]);

  for (size_t i = 0; i < size_; i++)
  {
    temp_shapes[i] = shapes_[i];
  }

  temp_shapes[size_] = shape;
  size_++;

  shapes_.swap(temp_shapes);
}

double CompositeShape::getArea() const
{
  double sum_of_areas = 0.0;

  for (size_t i = 0; i < size_; i++)
  {
    sum_of_areas += shapes_[i]->getArea();
  }

  return sum_of_areas;
}

rectangle_t CompositeShape::getFrameRect() const
{
  double max_y = shapes_[0]->getFrameRect().pos.y;
  double min_x = shapes_[0]->getFrameRect().pos.x;
  double max_x = shapes_[0]->getFrameRect().pos.x;
  double min_y = shapes_[0]->getFrameRect().pos.y;

  double min_y_height = shapes_[0]->getFrameRect().height;
  double max_y_height = shapes_[0]->getFrameRect().height;
  double min_x_width = shapes_[0]->getFrameRect().width;
  double max_x_width = shapes_[0]->getFrameRect().width;

  for (size_t i = 0; i < size_; i++)
  {
    if (shapes_[i]->getFrameRect().pos.y > max_y)
    {
      max_y = shapes_[i]->getFrameRect().pos.y;
      max_y_height = shapes_[i]->getFrameRect().height;
    }

    if (shapes_[i]->getFrameRect().pos.x < min_x)
    {
      min_x = shapes_[i]->getFrameRect().pos.x;
      min_x_width = shapes_[i]->getFrameRect().width;
    }

    if (shapes_[i]->getFrameRect().pos.x > max_x)
    {
      max_x = shapes_[i]->getFrameRect().pos.x;
      max_x_width = shapes_[i]->getFrameRect().width;
    }

    if (shapes_[i]->getFrameRect().pos.y < min_y)
    {
      min_y_height = shapes_[i]->getFrameRect().height;
      min_y = shapes_[i]->getFrameRect().pos.y;
    }
  }

  double height = (max_y + max_y_height / 2) - (min_y - min_y_height / 2);
  double width = (max_x + max_x_width / 2) - (min_x - min_x_width / 2);

  double x = max_x - min_x;
  if (x == 0)
  {
    x = max_x;
  }
  else
  {
    x = (width / 2 + (width - (width - (min_x - min_x_width / 2))));
  }

  double y = max_y - min_y;
  if (y == 0)
  {
    y = max_y;
  }
  else
  {
    y = (height / 2 + (height - (height - (min_y - min_y_height / 2))));
  }

  point_t centre = {x, y};

  return{centre, width, height};
}

void CompositeShape::move(const point_t &shape_pos)
{
  point_t current_pos = getFrameRect().pos;
  move(shape_pos.x - current_pos.x, shape_pos.y - current_pos.y);
}

void CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void CompositeShape::printInformation() const
{
  std::cout << "Composite Shape consists of " << size_ << " figures" << std::endl
            << "Area : " << getArea() << std::endl
            << "Frame Rectangle is : pos(" << getFrameRect().pos.x << ", " << getFrameRect().pos.y
            << "). Width = " << getFrameRect().width << ", height = " << getFrameRect().height << std::endl;
}

void CompositeShape::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient must be > 0!");
  }

  point_t current_pos_of_comp_shape = getFrameRect().pos;

  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move({current_pos_of_comp_shape.x + coefficient * (shapes_[i]->getFrameRect().pos.x - current_pos_of_comp_shape.x),
                     current_pos_of_comp_shape.y + coefficient * (shapes_[i]->getFrameRect().pos.y - current_pos_of_comp_shape.y)});
    shapes_[i]->scale(coefficient);
  }
}
