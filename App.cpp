#include<Student.h>

Student create(string s, int a, map<int, string> m) {
	Student inst = Student();
	inst.age = a;
	inst.name = s;
	inst.marks = m;
	return inst;
}

list<Student> write() {
	list<Student> ls;

	ls.push_back(create("Vasile", 21, { {10, "Math"}, {8,"Chem"} }));
	ls.push_back(create("Ioana", 19,{ {9, "Math"}, {10,"Chem"} }));
	ls.push_back(create("Ion", 20, { {8,"Math"},{9,"Chem"} }));

	cout << "You have successfully added 3 records!" << endl;

	return ls;
}

void show(list<Student> ls) {
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
}

int main() {

	show(write());
	
	return 0;
}