#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle cir({1.0, 2.0}, 5.0);
  std::cout << "CIRCLE" << std::endl;

  cir.printInformation();

  cir.move({3.0, 4.0});
  std::cout << "Move to the point (" << cir.getFrameRect().pos.x << ", " << cir.getFrameRect().pos.y << ")" << std::endl;

  cir.move(7.0, 6.0);
  std::cout << "Move on (" << cir.getFrameRect().pos.x << ", " << cir.getFrameRect().pos.y << ")" << std::endl;

  Rectangle rect({1.0, 2.0}, 5.0, 8.0);
  std::cout << "RECTANGLE" << std::endl;

  rect.printInformation();

  rect.move({3.0, 4.0});
  std::cout << "Move to the point (" << rect.getFrameRect().pos.x << ", " << rect.getFrameRect().pos.y << ")" << std::endl;

  rect.move(7.0, 6.0);
  std::cout << "Move on (" << rect.getFrameRect().pos.x << ", " << rect.getFrameRect().pos.y << ")" << std::endl;

  return 0;
}