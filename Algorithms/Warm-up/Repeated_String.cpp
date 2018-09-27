/*

Sample Input 0

aba
10
Sample Output 0

7
Explanation 0 
The first n=10 letters of the infinite string are abaabaabaa. 
Because there are 7 a's, we print 7 on a new line.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    
    long count = 0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a'){
            count++;
        }
    }
    
    long t,r;
    t = n / s.length();
    r = n % s.length();
    
    count = count * t;
    
    for(int j=0; j<r; j++){
        if(s[j] == 'a'){
            count++;
        }
    }
    
    return count;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}


