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
} s;

struct Collection {
	list<Student> ls;
	list<Student>::iterator _i;
	map<string, int>::iterator _j;
} c;

struct IO {
	ifstream _in;
	ofstream _out;
	string line, field;
} x1,x2;
