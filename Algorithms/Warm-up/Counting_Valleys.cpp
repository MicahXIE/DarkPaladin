/*
Sample Input

8
UDDDUDUU
Sample Output

1
Explanation

If we represent _ as sea level, a step up as /, and a step down as \, Gary's hike can be drawn as:

_/\      _
   \    /
    \/\/
He enters and leaves one valley.
*/


#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {


    int level = 0;
    int start = 0;
    int count = 0;
    
    for(int i=0; i<n; i++){
        if(s[i] == 'D'){
            level = level - 1;
            if(level < 0 && start == 0){
                start = 1;   
            }
        }
        
        if(s[i] == 'U'){
            level = level + 1;
            if(level == 0 && start == 1){
                count += 1;
                start = 0;
            }
        }
    }
    
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
