/*
Sample Input

8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6
Sample Output

Yes
No
No
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    cin >> n;
    int type,value;
    set<int> s;
    
    for(int i(0); i<n; i++){
        cin >> type >> value;
        if(type == 1){
            s.insert(value);
        } else if(type == 2){
            s.erase(value);
        } else {
            auto iter = s.find(value);
            if (iter != s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    
    return 0;
}

