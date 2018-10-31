#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

const double epsilon = 1e-4;
const double coefficient = 4.0;

BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(IncorrectRadius)
{
  BOOST_CHECK_THROW(babintseva::Circle cir({5.0, 4.0}, -3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectCoefficient)
{
  babintseva::Circle cir({5.0, 4.0}, 3.0);
  BOOST_CHECK_THROW(cir.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(AreaAndPositionAfterScaling)
{
  babintseva::Circle cir({5.0, 4.0}, 5.0);

  cir.scale(coefficient);

  BOOST_CHECK_CLOSE(cir.getArea(), M_PI * coefficient * coefficient * 5.0 * 5.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getFrameRect().pos.x, 5.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getFrameRect().pos.y, 4.0, epsilon);
}

BOOST_AUTO_TEST_CASE(ParametersAfterRealtiveMoving)
{
  babintseva::Circle cir({5.0, 4.0}, 5.0);

  cir.move(5.0, 4.0);

  BOOST_CHECK_CLOSE(cir.getFrameRect().width, 10.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getFrameRect().height, 10.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getRadius(), 5.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getArea(), M_PI * 5.0 * 5.0, epsilon);
}

BOOST_AUTO_TEST_CASE(ParametersAfterMovingToPoint)
{
  babintseva::Circle cir({5.0, 4.0}, 5.0);

  cir.move({5.0, 4.0});

  BOOST_CHECK_CLOSE(cir.getFrameRect().width, 10.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getFrameRect().height, 10.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getRadius(), 5.0, epsilon);
  BOOST_CHECK_CLOSE(cir.getArea(), M_PI * 5.0 * 5.0, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(RectangleTest)

BOOST_AUTO_TEST_CASE(IncorrectWidth)
{
  BOOST_CHECK_THROW(babintseva::Rectangle rect({4.0, 4.0}, -3.0, 5.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectHeight)
{
  BOOST_CHECK_THROW(babintseva::Rectangle rect({4.0, 4.0}, 3.0, -5.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(IncorrectCoefficientInScaling)
{
  babintseva::Circle cir({5.0, 4.0}, 3.0);
  BOOST_CHECK_THROW(cir.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(AreaAndPositionAfterScaling)
{
  babintseva::Rectangle rect({4.0, 4.0}, 5.0, 3.0);

  rect.scale(coefficient);

  BOOST_CHECK_CLOSE(rect.getArea(), coefficient * coefficient * 5.0 * 3.0, epsilon);
  BOOST_CHECK_CLOSE(rect.getFrameRect().pos.x, 4.0, epsilon);
  BOOST_CHECK_CLOSE(rect.getFrameRect().pos.y, 4.0, epsilon);

}
BOOST_AUTO_TEST_CASE(ParametersAfterRealtiveMoving)
{
  babintseva::Rectangle rect({4.0, 4.0}, 5.0, 3.0);

  rect.move(5.0, 4.0);

  BOOST_CHECK_CLOSE(rect.getFrameRect().width, 5.0, epsilon);
  BOOST_CHECK_CLOSE(rect.getFrameRect().height, 3.0, epsilon);
  BOOST_CHECK_CLOSE(rect.getArea(), 5.0 * 3.0, epsilon);
}

BOOST_AUTO_TEST_CASE(ParametersAfterMovingToPoint)
{
  babintseva::Rectangle rect({4.0, 4.0}, 5.0, 3.0);

  rect.move({5.0, 4.0});

  BOOST_CHECK_CLOSE(rect.getFrameRect().width, 5.0, epsilon);
  BOOST_CHECK_CLOSE(rect.getFrameRect().height, 3.0, epsilon);
  BOOST_CHECK_CLOSE(rect.getArea(), 5.0 * 3.0, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShape)

BOOST_AUTO_TEST_CASE(IncorrectCreation)
{
  BOOST_CHECK_THROW(babintseva::CompositeShape comp_shape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(AdditionEmptyShape)
{
  auto cir = std::make_shared<babintseva::Circle>(babintseva::point_t{1.0, 1.0}, 3.0);
  babintseva::CompositeShape comp_shape(cir);

  BOOST_CHECK_THROW(comp_shape.addShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(InccorrectCoefficientInScaling)
{
  auto cir = std::make_shared<babintseva::Circle>(babintseva::point_t{1.0, 1.0}, 3.0);
  babintseva::CompositeShape comp_shape(cir);

  BOOST_CHECK_THROW(comp_shape.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(AreaAndPositionAfterScaling)
{
  auto cir = std::make_shared<babintseva::Circle>(babintseva::point_t{1.0, 3.0}, 1.0);
  auto rect = std::make_shared<babintseva::Rectangle>(babintseva::point_t{3.0, 1.0}, 2.0, 2.0);
  babintseva::CompositeShape comp_shape(cir);
  comp_shape.addShape(rect);

  comp_shape.scale(coefficient);

  BOOST_CHECK_CLOSE(comp_shape.getArea(), (M_PI * 1.0 * 1.0 + 2.0 * 2.0)  * coefficient * coefficient, epsilon);
  BOOST_CHECK_CLOSE(comp_shape.getFrameRect().pos.x, 2.0, epsilon);
  BOOST_CHECK_CLOSE(comp_shape.getFrameRect().pos.y, 2.0, epsilon);
}

BOOST_AUTO_TEST_CASE(ParametersAfterRelativeMoving)
{
  auto cir = std::make_shared<babintseva::Circle>(babintseva::point_t{1.0, 3.0}, 1.0);
  auto rect = std::make_shared<babintseva::Rectangle>(babintseva::point_t{3.0, 1.0}, 2.0, 2.0);
  babintseva::CompositeShape comp_shape(cir);
  comp_shape.addShape(rect);

  comp_shape.move(1.0, 1.0);

  BOOST_CHECK_CLOSE(comp_shape.getArea(), M_PI * 1.0 * 1.0 + 2.0 * 2.0, epsilon);
  BOOST_CHECK_CLOSE(comp_shape.getFrameRect().width, 4.0, epsilon);
  BOOST_CHECK_CLOSE(comp_shape.getFrameRect().height, 4.0, epsilon);
}

BOOST_AUTO_TEST_CASE(ParametersAfterMovingToPoint)
{
  auto cir = std::make_shared<babintseva::Circle>(babintseva::point_t{1.0, 3.0}, 1.0);
  auto rect = std::make_shared<babintseva::Rectangle>(babintseva::point_t{3.0, 1.0}, 2.0, 2.0);
  babintseva::CompositeShape comp_shape(cir);
  comp_shape.addShape(rect);

  comp_shape.move({1.0, 1.0});

  BOOST_CHECK_CLOSE(comp_shape.getArea(), M_PI * 1.0 * 1.0 + 2.0 * 2.0, epsilon);
  BOOST_CHECK_CLOSE(comp_shape.getFrameRect().width, 4.0, epsilon);
  BOOST_CHECK_CLOSE(comp_shape.getFrameRect().height, 4.0, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()
