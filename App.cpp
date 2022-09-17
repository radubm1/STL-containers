#include<Student.h>

list<Student> write() {
	list<Student> ls;
	ls.push_back(Student("Vasile", 21, { {"Math", 10}, {"Chem", 9} , {"Bio",10} }));
	ls.push_back(Student("Ioana", 19,{ {"Math", 9}, {"Chem", 8}, {"Geo", 10}, {"Bio", 8} }));
	ls.push_back(Student("Rares", 20, { {"Math", 10},{"Chem", 10} }));

	cout << "You have successfully added 3 records!" << endl;

	return ls;
}

void show(list<Student> ls) {

	ls.sort();

	for (list<Student>::iterator _i = ls.begin();_i != ls.end();_i++) {
		cout << _i->name << endl;
		cout << _i->age << endl;
		cout << _i->avg << endl;
		for (map<string, int>::iterator _j = _i->marks.begin();_j != _i->marks.end(); _j++) {
			cout << _j->first << endl;
			cout << _j->second << endl;
		}
		_i->marks.clear();
	}
	ls.clear();
}

void save(list<Student> ls) {

	int count = 0;
	x1._out.open(str);
	x2._out.open(str1);

	for (list<Student>::iterator _i = ls.begin();_i != ls.end();_i++) {
		x1._out << ++count << "\t" << _i->name << "\t" <<_i->age << "\t" << _i->avg << endl;
		for (map<string, int>::iterator _j = _i->marks.begin();_j != _i->marks.end(); _j++) {
			x2._out << _j->first << "\t" << _j->second << "\t" << count << endl;
		}
	}
	x1._out.close(); x2._out.close();

	ls.clear();
}

list<Student> import() {
	list<Student> ls;
	int cnt = 0;
	x1._in.open(str);
	while (getline(x1._in,x1.line)) {
		stringstream sData(x1.line);
		string name; int age;
		map<string, int> marks;
		sData >> cnt;
		sData >> name;
		sData >> age;

		x2._in.open(str1);// To do...
		while(getline(x2._in, x2.line)) {
			stringstream sData(x2.line);
			int val=0, mcnt = 0;
			string key;

			sData >> key;
			sData >> val;
			sData >> mcnt;

			if (cnt==mcnt) marks.insert(pair<string, int>(key, val));
		}
		ls.push_back(Student(name, age, marks));
		x2._in.close();
	}
	x1._in.close(); 
	cout << "You've loaded " << cnt << " records into memory!" << endl;
	return ls;
}

int main() {

	save(write());
	//show(write());
	show(import());
	
	return 0;
}
