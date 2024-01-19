#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool ret = false;

	if (a.getY() > point.getY() != b.getY() > point.getY())
	{
		if ((b.getX() - a.getX()) / (b.getY() - a.getY()) * (point.getY() - a.getY()) + a.getX() >= point.getX())
		{
			if (ret)
				ret = false;
			else
				ret = true;
		}
	}
	if (a.getY() > point.getY() != c.getY() > point.getY())
	{
		if ((a.getX() - c.getX()) / (a.getY() - c.getY()) * (point.getY() - a.getY()) + a.getX() >= point.getX())
		{
			if (ret)
				ret = false;
			else
				ret = true;
		}
	}
	if (b.getY() > point.getY() != c.getY() > point.getY())
	{
		if ((b.getX() - c.getX()) / (b.getY() - c.getY()) * (point.getY() - c.getY()) + c.getX() >= point.getX())
		{
			if (ret)
				ret = false;
			else
				ret = true;
		}
	}
	return (ret);
}