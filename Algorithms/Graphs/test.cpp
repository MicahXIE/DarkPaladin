#include<iostream>
using namespace std;


void test(int a[5][5]) {

	for(int i = 0; i < 5; i++) {
		a[i][4] = 0;
	}

}

void print_a(int a[5][5]) {

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

int main(){
    int Arr[5][5] =  { { 1, 1, 0, 0, 0 }, 
                       { 0, 1, 0, 0, 1 }, 
                       { 1, 0, 0, 1, 1 }, 
                       { 0, 0, 0, 0, 0 }, 
                       { 1, 0, 1, 0, 1 } }; 

    test(Arr);
    print_a(Arr);

}