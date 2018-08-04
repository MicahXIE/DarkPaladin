#include<iostream>
using namespace std;

class Base {
private:
	int b_number;
public:
	Base(){
		cout<<"Base default constructor"<<endl;
	}
	Base(int i):b_number(i){
        cout<<"Base initialized constructor"<<endl;
	}
	~Base(){
		cout<<"Base default destructor"<<endl;
	}
	int get_number(){
		return b_number;
	}
	void print() {
		cout <<"Base Class: "<< b_number << endl;
	}
};

class Derived: public Base {
private:
	int d_number;
public:
	Derived(){
		cout<<"Derived default constructor"<<endl;		
	}
	//constructor used to initialize the Base and Derived
	Derived(int i, int j): Base(i), d_number(j){
		cout<<"Derived initialized constructor"<<endl;				
	}

	~Derived() {
		cout<<"Derived default destructor"<<endl;
	}

	void print(){
		cout << "Derived Class: "<<get_number() << " ";
		cout << "Derived Class: "<<d_number << endl;
	}
};

int main() {
	Base a(2);

	//constructor base first, destructor derived first
	Derived b(3,4);
    
    a.print();
    b.print();
    b.Base::print();

}

/* result as below:

Matthews-MacBook-Pro:Inheritance matthew$ g++ exmpale_1.cpp -o example_1
Matthews-MacBook-Pro:Inheritance matthew$ ./example_1 
Base initialized constructor
Base initialized constructor
Derived initialized constructor
Base Class: 2
Derived Class: 3 Derived Class: 4
Base Class: 3
Derived default destructor
Base default destructor
Base default destructor

*/















