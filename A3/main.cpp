#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

using namespace babintseva;

int main()
{
  auto cir = std::make_shared<Circle>(point_t {1.0, 3.0}, 1.0);
  std::cout << "CIRCLE" << std::endl;

  cir->printInformation();

  cir->move({3.0, 4.0});
  cir->move(7.0, 6.0);
  cir->scale(4.0);

  std::cout << "After moving to point (3, 4), moving on (7, 6) and scaling 4: " << std::endl;
  cir->printInformation();

  std::cout << std::endl;

  auto rect = std::make_shared<Rectangle>(point_t {3.0, 1.0}, 2.0, 2.0);
  std::cout << "RECTANGLE" << std::endl;

  rect->printInformation();

  rect->move({3.0, 4.0});
  rect->move(7.0, 6.0);
  rect->scale(4.0);

  std::cout << "After moving to point (3, 4), moving on (7, 6) and scaling 4: " << std::endl;
  rect->printInformation();

  std::cout << std::endl;

  CompositeShape comp_shape(cir);
  std::cout << "Composite Shape" << std::endl;

  comp_shape.addShape(rect);
  comp_shape.move({5.0, 3.0});
  comp_shape.scale(2.0);

  std::cout << "After moving to point (5, 3) and scaling 2: " << std::endl;
  comp_shape.printInformation();

  return 0;
}
