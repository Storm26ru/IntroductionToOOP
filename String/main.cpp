#include<iostream>
using namespace std;

class String
{
	char* string;
	int size;


public:
	const char* Get_string()const
	{
		return string;
	}
	char* Get_string()
	{
		return string;
	}
	int Get_size()const
	{
		return size;
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
		this->size = strlen(string)+1;
		this->string = new char[this->size]{};
		for (int i = 0; string[i]; i++) this->string[i] = string[i];
		cout << "Constructor" << "\t" << this << endl;
	}
	
	String(const String& other)
	{
		this->size = other.size;
		this->string = new char[size] {};
		for (int i = 0; other.string[i]; i++) this->string[i] = other.string[i];
		cout << "CopyConstructor" << "\t" << this << endl;
	}
	String(String&& other)
	{
		this->string = other.string;
		this->size = other.size;
		other.string = nullptr;
		other.size = 0;
		cout << "MoveConstructor" << "\t" << this << endl;
	}


	~String()
	{
		delete[] string;
		cout << "Destructor" << "\t" << this << endl;
	}

	//					Operator
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->string;
		this->size = other.size;
		for (int i = 0; other.string[i]; i++) this->string[i] = other.string[i];
		cout << "CopyAssigment " << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->string;
		this->string = other.string;
		this->size = other.size;
		other.string = nullptr;
		other.size = 0;
		cout << "MoveAssigment" << "\t" << this << endl;
		return *this;
	}
	
	char operator[](int i)const
	{
		return string[i];
	}
	char& operator[](int i)
	{
		return string[i];
	}
};


String operator+(const String& left, const String& right)
{
	String concatenation(left.Get_size() + right.Get_size()-1);
	for (int i = 0; i < left.Get_size(); i++) concatenation[i] = left[i];
	for (int i = 0; i < right.Get_size(); i++) concatenation[left.Get_size() - 1 + i] = right[i];
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
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	
	
	



}