#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iterator>
#include <fstream>
#include <sstream>

constexpr auto str = "C:\\Users\\Radu\\Desktop\\file.dat";
constexpr auto str1 = "C:\\Users\\Radu\\Desktop\\file1.dat";

using namespace std;

struct Student {
	string name;
	int age = 0;
	map<string, int> marks;
	double avg = 0.0;
	Student(string _name, int _age, map<string, int> _mark) : name(_name), age(_age), marks(_mark) {
		int sum = 0, cnt = 0;
		for (map<string, int>::iterator i = marks.begin(); i != marks.end(); i++)
		{
			sum += i->second;cnt++;
		}
		avg = static_cast<double>(sum) / cnt;
	};
	bool operator <(const Student& studObj) const
	{
		return avg < studObj.avg;
	}
};

struct IO {
	ifstream _in;
	ofstream _out;
	string line, field;
} x1,x2;
