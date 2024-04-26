#include"function.h"

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
