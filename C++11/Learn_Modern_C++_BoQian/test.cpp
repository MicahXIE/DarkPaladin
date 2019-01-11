#include<iostream>
using namespace std;

int main() {
    cout << [](int x, int y) {return x+y;}(3,4) << endl;
}
