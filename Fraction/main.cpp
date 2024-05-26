#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator+(Fraction Left, Fraction Right);
Fraction operator-(Fraction Left, Fraction Right);
Fraction operator*(Fraction Left, Fraction Right);
Fraction operator/(Fraction Left, Fraction Right);

class Fraction
{
	int integer; //целое
	int numerator; //числитель
	int denominator;//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//					Constructions:

	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 0;
		cout << "DefaultConstructor:\t" << this << endl;

	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;


	}
	Fraction(double number)
	{
		integer = 0; //целую часть выделит метод proper
		numerator = number*10000+0.1; //Точность 4 знака после запятой
		denominator = 10000;
		proper();
		cout << "DoubleConstructor:\t" << this << endl;


	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;

	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstruction: \t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}
	Fraction& operator++()
	{
		++integer;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		++integer;
		return old;
	}
	Fraction& operator--()
	{
		if (integer) --integer;
		else numerator -= denominator;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		if (integer) --integer;
		else numerator -= denominator;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//					Type-cast operators:
	operator int()
	{
		return integer;
	}
	operator double()
	{
		return integer + (double)numerator / denominator;
	}
	
	//					Methods:
	std::ostream& print(std::ostream& os=std::cout)const
	{
		if (integer)os << integer;
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denominator;
			if (integer)os << ")";

		}
		else if (integer == 0)os << 0;
		//os << endl;
		return os;
	}
	Fraction& noproper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& proper()
	{
		int bufer_numerator, bufer_denominator, gcd;
		if (numerator / denominator)
		{
			integer += numerator / denominator;
			numerator %= denominator;
		}
		if (numerator == 0) return *this ;
		bufer_numerator = numerator; bufer_denominator = denominator;
		while (bufer_denominator%bufer_numerator)
		{
			gcd = bufer_denominator % bufer_numerator;//наибольший общий делитель (алгоритм Евклида)
			bufer_denominator = bufer_numerator; bufer_numerator = gcd;
		}
		numerator /= bufer_numerator;
		denominator /= bufer_numerator;
		return *this;
	}
	Fraction& to_reverse()
	{
		int bufer = numerator;
		numerator = denominator;
		denominator = bufer;
		return *this;
	}
	

	
};

Fraction operator+(Fraction Left, Fraction Right)
{
	
	return Fraction(Left.noproper().get_numerator() * Right.get_denominator() + Right.noproper().get_numerator() * Left.get_denominator(),
		Left.get_denominator() * Right.get_denominator()).proper();
}
Fraction operator-(Fraction Left, Fraction Right)
{
	return Fraction(Left.noproper().get_numerator() * Right.get_denominator() - Right.noproper().get_numerator() * Left.get_denominator(),
		Left.get_denominator() * Right.get_denominator()).proper();
}
Fraction operator*(Fraction Left, Fraction Right)
{
	return Fraction(Left.noproper().get_numerator() * Right.noproper().get_numerator(), Left.get_denominator() * Right.get_denominator()).proper();
}
Fraction operator/(Fraction Left, Fraction Right)
{
	return Left * Right.noproper().to_reverse();
}
bool operator==(Fraction Left, Fraction Right)
{
	return Left.noproper().get_numerator() *Right.get_denominator() == Right.noproper().get_numerator() * Left.get_denominator();
}
bool operator !=(Fraction Left, Fraction Right)
{
	return !(Left == Right);
}
bool operator >(Fraction Left, Fraction Right)
{
	return Left.noproper().get_numerator() * Right.get_denominator() > Right.noproper().get_numerator() * Left.get_denominator();
}
bool operator <(Fraction Left, Fraction Right)
{
	return Left != Right && !(Left > Right);
}
bool operator >=(Fraction Left, Fraction Right)
{
	return Left == Right || Left > Right;
}
bool operator <=(Fraction Left, Fraction Right)
{
	return Left == Right || Left < Right;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";

	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char bufer[SIZE]{};
	is >> bufer;
	int n = 0;
	int numbers[3];
	char delimiters[] = "(/ )";
	for (char* pch = strtok(bufer, delimiters); pch; pch = strtok(NULL, delimiters)) numbers[n++] = std::atoi(pch);
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(numbers[0]); break;
	case 2: 
		obj.set_numerator(numbers[0]);
		obj.set_denominator(numbers[1]); break;
	case 3:
		obj.set_integer(numbers[0]);
		obj.set_numerator(numbers[1]);
		obj.set_denominator(numbers[2]);
	}
	return is;
}
void main()
{
	setlocale(LC_ALL, "");

	/*Fraction A; // Default constructor
	A.print();
	Fraction B = 5; //Single - argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D; //Copy constructor
	E.print();
	Fraction F;
	F = E; //Copy assignment
	F.print();*/
	/*Fraction A(3, 1, 2);
	Fraction B(5, 4, 5);
	cout << "Арифметические операторы" << endl; cout << A + B << "\t" << B - A << "\t" << A * B << "\t" << A / B << endl;
	cout << "Икремент/ Дикремент" << endl; cout << ++A << endl; cout << A++ << endl; cout << --A << endl; cout << A-- << endl;
	cout << "Составные операторы " << endl; cout << (A += B) << endl; cout << (A -= B) << endl; cout << (A *= B) << endl; cout << (A /= B) << endl;
	cout << "Операторы сравнения" << endl; cout << (A == B) << endl; cout << (A != B) << endl; cout << (A > B) << endl; cout << (A < B) << endl;
	cout << (A >= B) << endl; cout << (A <= B) << endl;
	cout << "Введите правильную дробь: "; cin >> A;
	cout << A << endl;*/
	
	Fraction A(2, 3, 4);
	double a = A;
	cout << A << " = " << a << endl;
	Fraction B = 2.75;
	cout << B << endl;
	
	
}