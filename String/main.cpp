#include<iostream>
using namespace std;

class String
{
	int size;	
	char* str;	
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
	{
		
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	
	String(const String& other) :size(other.size), str(new char[size] {})
	{
		
		for (int i = 0; other.str[i]; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other) :size(other.size), str(other.str)
	{
		
		other.str = nullptr;
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);		
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}




void main()
{
	setlocale(LC_ALL, "");
	String str1 = "Hellow";
	String str2 = "World";
	String str3; str3 = str1 + str2;
	cout << str3 << endl;
	
	
	



}