#include <iostream>

using namespace std;

int fibonacci(int n) {
    int res;
    
    if(n==0) 
        return 0;
    
    if(n==1) 
        return 1;
    
    if(n>1) {
        res = fibonacci(n-1)+fibonacci(n-2);
    }
    
    return res;
        

}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}