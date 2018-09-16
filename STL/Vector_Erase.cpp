/*

Sample Input

6
1 4 6 2 8 9
2
2 4
Sample Output

3
1 8 9
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
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int p1,p2,p3;
    cin >> p1;
    v.erase(v.begin()+(p1-1));
    cin >> p2 >> p3;
    v.erase(v.begin()+(p2-1), v.begin()+(p3-1));
    
    cout << v.size() << endl;
    
    for(auto iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << " ";
    }
    
    
    return 0;
}