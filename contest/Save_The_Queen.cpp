/*
Sample Input 0
3 4
1000 100 100 100

Sample Output 0
150.000000000

Sample Input 1
3 4
10 15 10 100

Sample Output 1
17.500000000


*/

//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
using namespace std;


int n,k,a[10007];

int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }   
    double lo = 0.0, hi = 1e15, mid; 
    for(int i = 0; i < 400; i++){ 
        mid = (lo+hi)/2; 
        int inv = n; 
        double req = 0.0; 
        for (int j = 0; j < k; j++) 
          if(a[j] >= mid){ 
            inv--; 
          }else{ 
            req += a[j]; 
          } 
        if(inv <= 0){
            lo = mid; 
            continue;
        } 
        req /= inv; 
        if (req < mid) hi = mid; else lo = mid; 
    } 

    cout<<fixed<<setprecision(9)<<mid<<endl;
}