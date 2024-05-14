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
	Point& operator++()	//Prefix increment
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)//Suffix increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	Point operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
double distance(const Point& A, const Point& B);
bool operator==(const Point& left, const Point& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}
std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >>x>>y;
	//obj.set_x(x);
	//obj.set_y(y);
	obj(x, y);
	return is;
}

//#define STRUCT_POINT
//#define DISTANS_CHEK
//#define DEF_CHEK
//#define ASSIGMENT_CHEK
//#define OPERATOR_CHEK

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
#ifdef ASSIGMENT_CHEK
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.Print();
	B.Print();
	C.Print();
#endif // ASSIGMENT_CHEK

#ifdef OPERATOR_CHEK
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.Print();
	C++;
	C.Print();
	cout << (C == B) << endl;
#endif // OPERATOR_CHEK

	Point A(2, 3);
	cout << "Введите кординаты точки :"; cin >> A;
	cout << A << endl;
}
double distance(const Point& A, const Point& D)
{
	return sqrt(pow(A.get_x() - D.get_x(), 2) + pow(A.get_y() - D.get_y(), 2));
}