#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iterator>

using namespace std;

struct Student {
	string name;
	int age;
	map<int, string> marks;
};

list<Student> ls;

int main() {

	Student s0 = Student();
	s0.age = 20;
	s0.name = "Ion";
	s0.marks = { {10,"Math"},{8,"Chem"} };

	ls.push_back(s0);

	Student s1 = Student();
	s1.age = 21;
	s1.name = "Vasile";
	s1.marks = { {9,"Math"},{9,"Chem"} };

	ls.push_back(s1);

	Student s2 = Student();
	s2.age = 19;
	s2.name = "Ioana";
	s2.marks = { {9,"Math"},{10,"Chem"} };

	ls.push_back(s2);

	list<Student>::iterator i;
	map<int, string>::iterator j;

	for (i = ls.begin();i != ls.end();i++) {
		cout << i->name << endl;
		cout << i->age << endl;
		for (j = i->marks.begin();j != i->marks.end(); j++) {
			cout << j->second << endl;
			cout << j->first << endl;
		}
		i->marks.clear();
	}
	ls.clear();
	return 0;
}