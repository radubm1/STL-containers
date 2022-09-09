#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iterator>

using namespace std;

struct Student {
	string name;
	int age = 0;
	map<int, string> marks;
};