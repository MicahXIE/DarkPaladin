/*
Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n,q,e;
    
    cin >> n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    cin >> q;
    
    vector<int>::iterator iter;
    
    for(int j=0; j<q; j++){
        cin >> e;
        iter = lower_bound(v.begin(), v.end(), e);
        
        if(*iter == e){
            cout << "Yes " << iter-v.begin()+1 << endl;
        } else {
            cout << "No "  << iter-v.begin()+1 << endl;
        }
    }

    
    return 0;
}