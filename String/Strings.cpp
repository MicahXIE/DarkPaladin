/*
Sample Input

abcd
ef
Sample Output

4 2
abcdef
ebcd af
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string s,s1;
    cin >> s;
    cin >> s1;
    
    string ss,ss1;
    ss = s;
    ss1 = s1;
    
    cout << s.length() << " " << s1.length() << endl;
    cout << s+s1 << endl;
    cout << ss.replace(0,1,s1.substr(0,1)) << " " << ss1.replace(0,1,s.substr(0,1)) << endl;
    
    return 0;
}

