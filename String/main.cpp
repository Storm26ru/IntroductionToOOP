#include<iostream>
using namespace std;

class String
{
	int size;	
	char* string;	
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return string;
	}
	char* get_str()
	{
		return string;
	}

	//				Constructors:
	explicit String(int size = 80) :size(size), string(new char[size] {})
	{
		
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* stirng) :size(strlen(stirng) + 1), string(new char[size] {})
	{
		for (int i = 0; stirng[i]; i++)this->string[i] = stirng[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	
	String(const String& other) :size(other.size), string(new char[size] {})
	{
		
		for (int i = 0; other.string[i]; i++)this->string[i] = other.string[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other) :size(other.size), string(other.string)
	{
		
		other.string = nullptr;
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] string;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		
		if (this == &other)return *this;
		delete[] this->string;
		this->size = other.size;
		this->string = new char[size] {};
		for (int i = 0; i < size; i++)this->string[i] = other.string[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->string;
		this->size = other.size;
		this->string = other.string;
		other.string = nullptr;
		other.size = 0;
		cout << "MoveAssignment:\t\t" << this << endl;
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

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String concatenation(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) concatenation[i] = left[i];
	for (int i = 0; i < right.get_size(); i++) concatenation[left.get_size() - 1 + i] = right[i];
	return concatenation;
}




void main()
{
	setlocale(LC_ALL, "");
	String str1 = "Hellow";
	String str2 = "World";
	String str3; str3 = str1 + str2;
	cout << str3 << endl;
	
	
	



}