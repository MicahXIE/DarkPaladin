/*
Sample Input

5
1 6 10 8 4
Sample Output

1 4 6 8 10
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    cin >> n;
    vector<int> p(n);
    
    for(int i=0; i < n; i++){
        cin >> p[i];
    }
    
    sort(p.begin(), p.end());
    
    for(auto iter = p.begin(); iter != p.end(); iter++){
        cout << *iter << ' ';
    }
    
    return 0;
}