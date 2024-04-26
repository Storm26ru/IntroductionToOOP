#include<iostream>
using namespace std;

class Point //Создаем структуру которая будет описывать точки на плоскости;
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
    }
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	double distance(const Point& second_point)
	{
		return sqrt(pow(this->x-second_point.x, 2) + pow(this->y-second_point.y, 2));
    }
};

double distance(const Point& A, const Point& B);

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef STRUCT_POINT
	Point A; //ОбЪявление переменной типа Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x;
#endif STRUCT_POINT
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point D;
	D.set_x(5);
	D.set_y(6);
	cout <<"Расстояние от точки А до точки D: "<< A.distance(D) << endl;
	cout <<"Расстояние между точками A и D: "<< distance(A, D) << endl;
	

}
double distance(const Point& A, const Point& D)
{
	return sqrt(pow(A.get_x() - D.get_x(), 2) + pow(A.get_y() - D.get_y(), 2));
}