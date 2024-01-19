#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

Point::Point(const Point& point) : x(point.getX()), y(point.getY())
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
	// 	const_cast<Fixed&>(x) = obj.getX();
	// 	const_cast<Fixed&>(y) = obj.getY();
		this->~Point();
		new(this) Point(obj);
	}
	return *this;
}
