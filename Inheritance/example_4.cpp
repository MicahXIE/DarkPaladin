#include<iostream>
using namespace std;

class Department {

public:
	int building;

};

class Division {

public:
	char building;

};

class HeadQuarters : public Department, public Division {

};

int main() {
	HeadQuarters hq;
	hq.Division::building = 'A';
	cout << hq.Division::building << endl;
}
