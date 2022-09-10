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

	ls.push_back(create("Vasile", 21, { {10, "Math"}, {8,"Chem"} , {9,"Bio"} }));
	ls.push_back(create("Ioana", 19,{ {9, "Math"}, {10,"Chem"}, {8,"Geo"}, {8,"Bio"} }));
	ls.push_back(create("Rares", 20, { {8,"Math"},{9,"Chem"} }));
	ls.push_back(create("Ion", 22, { {8,"Math"},{9,"Chem"} }));
	ls.push_back(create("Matilda", 20, { {8,"Math"},{9,"Chem"} , {10,"Draw"} , {10,"Sport"} }));
	ls.push_back(create("Clotilde", 18, { {8,"Math"},{9,"Chem"} , {8,"Geo"} }));
	ls.push_back(create("Mihai", 20, { {8,"Math"},{9,"Chem"}, {9,"Psych"}, {10,"Lit"} }));
	ls.push_back(create("Gabriel", 24, { {8,"Math"},{9,"Chem"}, {8,"Sport"}, {8,"Lit"}, {8,"Bio"} }));
	ls.push_back(create("Costica", 19, { {8,"Math"} }));
	ls.push_back(create("Matei", 20, { {8,"Math"},{9,"Chem"} }));

	cout << "You have successfully added 10 records!" << endl;

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

void save(list<Student> ls) {
	int count = 0;
	ofstream data, data1;
	data.open("C:\\Users\\Radu\\Desktop\\file.dat");
	data1.open("C:\\Users\\Radu\\Desktop\\file1.dat");
	list<Student>::iterator i;
	map<int, string>::iterator j;

	for (i = ls.begin();i != ls.end();i++) {
		data << ++count << "\t" << i->name << "\t" << i->age << endl;
		for (j = i->marks.begin();j != i->marks.end(); j++) {
			data1 << j->second << "\t" << j->first << "\t" << count << endl;
		}
	}
	data.close(); data1.close();

}

int main() {

	save(write());

	show(write());
	
	return 0;
}
