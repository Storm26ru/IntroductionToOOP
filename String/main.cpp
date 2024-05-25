#include<iostream>
using namespace std;

class String
{
	char* string;
	int size;

	String& create_string(const char* string, int size = 0)
	{
		if (size) this->size = size;
		else this->size = strlen(string)+1;
		this->string = new char[this->size]{};
		for (int i = 0; string[i]; i++) this->string[i] = string[i];
		//for (int i = 0; i<this->size; i++) this->string[i] = string[i];
		return *this;
	}
public:
	char* Get_string()const
	{
		return string;
	}
	int Get_size()const
	{
		return size;
	}
	void Set_string(const char* string)
	{
		delete[] this->string;
		create_string(string);
	}

	//					Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		string = new char[size] {};
		cout << "DefultConstructor" << " " << this << endl;
	}
	String(const char* string)
	{
		create_string(string);
		cout << "Constructor" << "\t" << this << endl;
	}
	
	String(const String& other)
	{
		create_string(other.string,other.Get_size());
		cout << "CopyConstructor" << "\t" << this << endl;
	}

	~String()
	{
		delete[] string;
		cout << "Destructor" << "\t" << this << endl;
	}

	//					Operator
	String& operator=(const String& other)
	{
		delete[] this->string;
		create_string(other.string,other.Get_size());
		cout << "CopyAssigment " << this << endl;
		return *this;
	}
	/*char operator[](int i)
	{
		return string[i];
	}*/
};


String operator+(const String& left, const String& right)
{
	String concatenation(left.Get_size() + right.Get_size()-1);
	for (int i = 0; i < left.Get_size(); i++) concatenation.Get_string()[i] = left.Get_string()[i];
	for (int i = 0; i < right.Get_size(); i++) concatenation.Get_string()[left.Get_size() - 1 + i] = right.Get_string()[i];
	return concatenation;
	
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.Get_string();
}




void main()
{
	setlocale(LC_ALL, "");
	String str1 = "Hellow";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
	
	



}