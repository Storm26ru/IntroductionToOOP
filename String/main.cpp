#include<iostream>
using namespace std;

class String
{
	char* string;
	int size;

	String& create_string(const char* string)
	{
		size = strlen(string);
		this->string = new char[size+1];
		for (int i = 0; i <= size; i++) this->string[i] = string[i];
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
	String()
	{
		string = new char[80]; string[79] = 0;
		cout << "DefultConstructor" << " " << this << endl;
	}
	String(const char* string)
	{
		create_string(string);
		cout << "Constructor" << "\t" << this << endl;
	}
	
	String(const String& other)
	{
		create_string(other.string);
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
		create_string(other.string);
		cout << "CopyAssigment " << this << endl;
		return *this;
	}
};


String operator+(const String& left, const String& right)
{
	char* bufer = new char[left.Get_size() + right.Get_size()+2];
	for (int i = 0; i <= (left.Get_size() + right.Get_size()+1); i++)
	{
		if (i <=left.Get_size())
		{
			bufer[i] = left.Get_string()[i];
			if (bufer[i] == 0)bufer[i] = ' ';
		}
		else bufer[i] = right.Get_string()[i-(left.Get_size()+1)];
	}
	String Split(bufer);
	delete[] bufer;
	return Split;
	
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
	cout << str3<<endl;



}