#include<iostream>
using namespace std;

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
	Fraction( int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" <<this<< endl;
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

	//					Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";

		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction noproper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction proper()
	{
		int n, d, r;
		if (numerator / denominator)
		{
			integer = numerator / denominator;
			numerator %= denominator;
		}
		n = numerator; d = denominator;
		while (d%n)
		{
			r = d % n;
			d = n; n = r;
		}
		numerator /= n;
		denominator /= n;
		return *this;
	}
	

	
};
Fraction operator+(Fraction Left, Fraction Right)
{
	return Fraction(Left.noproper().get_numerator() * Right.noproper().get_denominator() + Right.noproper().get_numerator() * Left.get_denominator(),
		Left.noproper().get_denominator() * Right.noproper().get_denominator()).proper();
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
	Fraction A(3, 1, 2);
	Fraction B(5, 4, 5);
	Fraction C = A + B;
	C.print();





}