/*
Sample Input 1

6
0 0 0 0 1 0
Sample Output 1

3
Explanation 1: 
The only thundercloud to avoid is c[4]. Emma can win the game in 3 jumps
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    
    int count = 0;
    int len = c.size();
    
    for(int i=0; i<len;){
        if(c[i] == 0){
            count += 1;
            cout<<i<< ":" <<count << endl;
            if(i < (len-2) && c[i+2] == 0){
                i = i+2;
            } else if(i < (len-1) && c[i+1] == 0) {
                i = i+1;
            } else {
                i = i+1;
            }
        } else {
            i = i+1;
        }
    }
    
    return (count-1);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
