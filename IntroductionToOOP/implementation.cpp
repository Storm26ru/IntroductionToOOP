#include"function.h"


double Point::get_x() const
	{
		return x;
	}

	double Point::get_y() const
	{
		return y;
	}
	void Point::set_x(double x)
	{
		this->x = x;
	}
	void Point::set_y(double y)
	{
		this->y = y;
	}
	double Point::distance(const Point& second_point)
	{
		return sqrt(pow(this->x - second_point.x, 2) + pow(this->y - second_point.y, 2));
	}

	double distance(const Point& A, const Point& D)
	{
		return sqrt(pow(A.get_x() - D.get_x(), 2) + pow(A.get_y() - D.get_y(), 2));
	}