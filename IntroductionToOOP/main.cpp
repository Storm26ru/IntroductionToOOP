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
	void Print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	double distance(const Point& second_point)const
	{
		return sqrt(pow(this->x-second_point.x, 2) + pow(this->y-second_point.y, 2));
    }
	
	//  CONSTRUCTOR

	//Point()
	//{
		//x = y = 0;
		//cout << "Constructor \t" << this << endl;
	//}

	//Point(double x)
	//{
		//this->x = x;
		//this->y = 0;
		//cout << "SingleArgumentConstructor: " << this << endl;
	//}
	Point(double x= 0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor  " << this << endl;

	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstruction " << this << endl;
	}





	~Point()
	{

		cout << "Deststructor \t" << this << endl;
	}

	// 

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment " << this << endl;
		return *this;
	}

};

double distance(const Point& A, const Point& B);

//#define STRUCT_POINT
//#define DISTANS_CHEK
//#define DEF_CHEK

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
#endif// STRUCT_POINT
#ifdef DISTANS_CHEK
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point D;
	D.set_x(5);
	D.set_y(6);
	cout << "Расстояние от точки А до точки D: " << A.distance(D) << endl;
	cout << "Расстояние между точками A и D: " << distance(A, D) << endl;
#endif // DISTANS_CHEK
#ifdef DEF_CHEK
	Point A;
	A.Print();
	Point B = 5;
	B.Print();
	Point C(2, 3);
	C.Print();
	Point D = C;
	D.Print();
#endif // DEF_CHEK
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.Print();
	B.Print();
	C.Print();

}
double distance(const Point& A, const Point& D)
{
	return sqrt(pow(A.get_x() - D.get_x(), 2) + pow(A.get_y() - D.get_y(), 2));
}