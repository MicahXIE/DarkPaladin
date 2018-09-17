/*
Sample Input

7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
Sample Output

30
20
0
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    
    int n = 0;
    cin >> n;
    
    int type, mark;
    string name;
    map<string, int> m;
    
    for (int i=0; i<n; i++){
        cin >> type >> name;
        if(type == 1) {
            cin >> mark;
            m[name] += mark;
        } else if (type == 2) {
            m.erase(name);
        } else {
            cout << m[name] << endl;
        }
    }

    
    return 0;
}