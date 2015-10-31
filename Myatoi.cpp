#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
private:
	bool isNum(char c) { return c >= '0' && c <= '9'; }	
public:
	int myAtoi(string str) {
		unsigned int idx = 0;
		int flag = 1;
		int havenum = false;
		double ans = 0;
		while (isspace(str[idx])) idx++;
		if (str[idx] == '-' || str[idx] == '+')
		{
			if (str[idx] == '-') flag = -1;
			idx++;
		}
		while (isNum(str[idx]))
		{			
			ans = ans * 10 + (str[idx] - '0');
			idx++;
		}	
		ans = flag*ans;
		if (ans > INT_MAX)
		{
			return INT_MAX;
		}
		if (ans < INT_MIN)
		{
			return INT_MIN;
		}
		return ans;
		
	}
};


void main()
{
	Solution sol;
	int a = sol.myAtoi("9223372036854775809");
	cout << a << endl;
	cout << "type: \t\t" << "************size**************" << endl;
	cout << "bool: \t\t" << "byte(sizeof)£º" << sizeof(bool);
	cout << "\t max£º" << (numeric_limits<bool>::max)();
	cout << "\t\tmin£º" << (numeric_limits<bool>::min)() << endl;
	cout << "char: \t\t" << "byte(sizeof)£º" << sizeof(char);
	cout << "\tmax£º" << (numeric_limits<char>::max)();
	cout << "\t\tmin£º" << (numeric_limits<char>::min)() << endl;
	cout << "signed char: \t" << "byte(sizeof)£º" << sizeof(signed char);
	cout << "\tmax£º" << (numeric_limits<signed char>::max)();
	cout << "\t\tmin£º" << (numeric_limits<signed char>::min)() << endl;
	cout << "unsigned char: \t" << "byte(sizeof)£º" << sizeof(unsigned char);
	cout << "\tmax£º" << (numeric_limits<unsigned char>::max)();
	cout << "\t\tmin£º" << (numeric_limits<unsigned char>::min)() << endl;
	cout << "wchar_t: \t" << "byte(sizeof)£º" << sizeof(wchar_t);
	cout << "\tmax£º" << (numeric_limits<wchar_t>::max)();
	cout << "\t\tmin£º" << (numeric_limits<wchar_t>::min)() << endl;
	cout << "short: \t\t" << "byte(sizeof)£º" << sizeof(short);
	cout << "\tmax£º" << (numeric_limits<short>::max)();
	cout << "\t\tmin£º" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "byte(sizeof)£º" << sizeof(int);
	cout << "\tmax£º" << (numeric_limits<int>::max)();
	cout << "\tmin£º" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "byte(sizeof)£º" << sizeof(unsigned);
	cout << "\tmax£º" << (numeric_limits<unsigned>::max)();
	cout << "\tmin£º" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "byte(sizeof)£º" << sizeof(long);
	cout << "\tmax£º" << (numeric_limits<long>::max)();
	cout << "\tmin£º" << (numeric_limits<long>::min)() << endl;
	cout << "unsigned long: \t" << "byte(sizeof)£º" << sizeof(unsigned long);
	cout << "\tmax£º" << (numeric_limits<unsigned long>::max)();
	cout << "\tmin£º" << (numeric_limits<unsigned long>::min)() << endl;
	cout << "long long: \t" << "byte(sizeof)£º" << sizeof(long long);
	cout << "\tmax£º" << (numeric_limits<long long>::max)();
	cout << "\tmin£º" << (numeric_limits<long long>::min)() << endl;
	cout << "double: \t" << "byte(sizeof)£º" << sizeof(double);
	cout << "\tmax£º" << (numeric_limits<double>::max)();
	cout << "\tmin£º" << (numeric_limits<double>::min)() << endl;
	cout << "long double: \t" << "byte(sizeof)£º" << sizeof(long double);
	cout << "\tmax£º" << (numeric_limits<long double>::max)();
	cout << "\tmin£º" << (numeric_limits<long double>::min)() << endl;
	cout << "float: \t\t" << "byte(sizeof)£º" << sizeof(float);
	cout << "\tmax£º" << (numeric_limits<float>::max)();
	cout << "\tmin£º" << (numeric_limits<float>::min)() << endl;
	cout << "size_t: \t" << "byte(sizeof)£º" << sizeof(size_t);
	cout << "\tmax£º" << (numeric_limits<size_t>::max)();
	cout << "\tmin£º" << (numeric_limits<size_t>::min)() << endl;
	cout << "string: \t" << "byte(sizeof)£º" << sizeof(string) << endl;
	// << "\tmax£º" << (numeric_limits<string>::max)() << "\tmin£º" << (numeric_limits<string>::min)() << endl;  
	cout << "type: \t\t" << "************size**************" << endl;
}
