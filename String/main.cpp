#include<iostream>
using namespace std;

class String
{
	char* string;
	int size=0;
	void create_string(const char* string, const int size)
	{
		this->size = size;
		this->string = new char[size+1];
		for (int i = 0; i <= size; i++) this->string[i] = string[i];
	}
public:
	//					Constructors:
	String()
	{
		size = 80;
		string = new char[size];
		cout << "DefultConstructor" << "\t" << this << endl;
	}
	String(const char* string)
	{
		create_string(string, strlen(string));
		cout << "Constructor" << "\t" << this << endl;
	}
	String(const String& other)
	{
		create_string(other.string, other.size);
		cout << "CopyConstructor" << "\t" << this << endl;
	}

	~String()
	{
		delete[] string;
		cout << "Destructor" << "\t" << this << endl;
	}

	//					Methods:
	char* Get_string()const
	{
		return string;
	}

	//					Operators:
	
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.Get_string();
}




void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hellow";
	String str2 = str1;
	cout << str2<<endl;



}