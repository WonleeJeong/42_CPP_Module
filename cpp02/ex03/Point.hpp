#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const _x, float const _y);
		~Point();
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif