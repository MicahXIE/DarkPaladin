#include<iostream>

using namespace std;

int getLength(){
    return 10;
}

int main(){
    //int size = getLength();
    const int size = 10;
    char message[size];
    
    bool ok=true;

    if(!ok){
       cout << "not ok" << endl;
    }
   
    int n,d;
    n = 10.0;
    d = 3.0;
    float q = n / d;
   
    for(char idx=0; idx<250; idx++){
        cout << "hello world" << endl;
    }
}
