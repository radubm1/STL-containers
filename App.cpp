#include<Student.h>

Student create(string name, int age, map<int, string> mark) {
	Student inst = Student();
	inst.age = age;
	inst.name = name;
	inst.marks = mark;
	return inst;
}

list<Student> write() {
	c.ls.push_back(create("Vasile", 21, { {10, "Math"}, {8,"Chem"} , {9,"Bio"} }));
	c.ls.push_back(create("Ioana", 19,{ {9, "Math"}, {10,"Chem"}, {8,"Geo"}, {8,"Bio"} }));
	c.ls.push_back(create("Rares", 20, { {8,"Math"},{9,"Chem"} }));
	c.ls.push_back(create("Ion", 22, { {8,"Math"},{9,"Chem"} }));
	c.ls.push_back(create("Matilda", 20, { {8,"Math"},{9,"Chem"} , {10,"Draw"} , {10,"Sport"} }));
	c.ls.push_back(create("Clotilde", 18, { {8,"Math"},{9,"Chem"} , {8,"Geo"} }));
	c.ls.push_back(create("Mihai", 20, { {8,"Math"},{9,"Chem"}, {9,"Psych"}, {10,"Lit"} }));
	c.ls.push_back(create("Gabriel", 24, { {8,"Math"},{9,"Chem"}, {8,"Sport"}, {8,"Lit"}, {8,"Bio"} }));
	c.ls.push_back(create("Costica", 19, { {8,"Math"} }));
	c.ls.push_back(create("Matei", 20, { {8,"Math"},{9,"Chem"} }));

	cout << "You have successfully added 10 records!" << endl;

	return c.ls;
}

void show(list<Student> ls) {

	for (c._i = ls.begin();c._i != ls.end();c._i++) {
		cout << c._i->name << endl;
		cout << c._i->age << endl;
		for (c._j = c._i->marks.begin();c._j != c._i->marks.end(); c._j++) {
			cout << c._j->second << endl;
			cout << c._j->first << endl;
		}
		c._i->marks.clear();
	}
	c.ls.clear();
}

void save(list<Student> ls) {

	int count = 0;
	x1._out.open(str);
	x2._out.open(str1);

	for (c._i = ls.begin();c._i != ls.end();c._i++) {
		x1._out << ++count << "\t" << c._i->name << "\t" <<c._i->age << endl;
		for (c._j = c._i->marks.begin();c._j != c._i->marks.end(); c._j++) {
			x2._out << c._j->second << "\t" << c._j->first << "\t" << count << endl;
		}
	}
	x1._out.close(); x2._out.close();

	c.ls.clear();
}

list<Student> import() {

	int cnt = 0;
	x1._in.open(str);
	while (getline(x1._in,x1.line)) {
		stringstream sData(x1.line);

		sData >> cnt;
		sData >> s.name;
		sData >> s.age;

		x2._in.open(str1);// To do...
		while(getline(x2._in, x2.line)) {
			stringstream sData(x2.line);
			int key=0, mcnt = 0;
			string val;

			sData >> val;
			sData >> key;
			sData >> mcnt;

			if (cnt==mcnt) s.marks.insert(pair<int,string>(key, val));
		}
		c.ls.push_back(s);
		s = Student();
		x2._in.close();
	}
	x1._in.close(); 
	cout << "You've loaded " << cnt << " records into memory!" << endl;
	return c.ls;
}

int main() {

	//save(write());
	//--show(write());
	show(import());
	
	return 0;
}
