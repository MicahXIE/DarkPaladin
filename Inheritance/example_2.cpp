#include<iostream>
using namespace std;

//multiple inheritance

class Base {
private:
	int b;
public:
	Base(int x){
		b = x;
	}
    void print(){
    	cout<<"Base: b="<<b<<endl;
    }
};

class Derived1: public Base {
private:
	int d1;
public:
	Derived1(int x, int y):Base(x){
		d1 = y;
	}
};

class Derived2: public Base {
private:
	int d2;
public:
	Derived2(int x, int z):Base(x){
		d2 = z;
	}
};

class Derived3: public Derived1, public Derived2 {
private:
	int d3;
public:
	Derived3(int x, int y, int z, int w):Derived1(x,y),Derived2(x,z){
		d3 = w;
	}
};

int main() {
	Base bs = Base(10);
    Derived1 dr1 = Derived1(10, 20);
    Derived2 dr2 = Derived2(10, 30);
    Derived3 dr3 = Derived3(10, 20, 30, 40);
    bs.print();
    dr1.print();
    dr2.print();
    //dr3 can't use Base print method
    //dr3.print();
}




