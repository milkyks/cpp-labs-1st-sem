#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

using namespace babintseva;

int main()
{
  Circle cir({1.0, 2.0}, 5.0);
  std::cout << "CIRCLE" << std::endl;

  cir.printInformation();

  cir.move({3.0, 4.0});
  cir.move(7.0, 6.0);
  cir.scale(4.0);

  std::cout << "After moving to point (3, 4), moving on (7, 6) and scaling 4: " << std::endl;
  cir.printInformation();

  std::cout << std::endl;

  Rectangle rect({1.0, 2.0}, 5.0, 8.0);
  std::cout << "RECTANGLE" << std::endl;

  rect.printInformation();

  rect.move({3.0, 4.0});
  rect.move(7.0, 6.0);
  rect.scale(4.0);

  std::cout << "After moving to point (3, 4), moving on (7, 6) and scaling 4: " << std::endl;
  rect.printInformation();

  return 0;
}
