/*
Sample Input

3
{[()]}
{[(])}
{{[[(())]]}}
Sample Output

YES
NO
YES
Explanation

1. The string {[()]} meets both criteria for being a balanced string, so we print YES on a new line.
2. The string {[(])} is not balanced because the brackets enclosed by the matched pair { and } are not balanced: [(]).
3. The string {{[[(())]]}} meets both criteria for being a balanced string, so we print YES on a new line.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    
    map<char,char> mp = {{'{','}'},{'[',']'},{'(',')'}};
    stack<char> st;
    
    for(int i=0; i<s.length(); i++){
        if(!st.empty() && s[i] == mp[st.top()]){
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    
    if(st.empty()){
        return "YES";
    } else {
        return "NO";
    }


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
