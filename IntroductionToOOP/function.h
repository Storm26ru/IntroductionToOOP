#pragma once
#include<iostream>
using namespace std;

class Point 
{
	double x;
	double y;
public:
	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);
	double distance(const Point& second_point);
	
};

double distance(const Point& A, const Point& B);