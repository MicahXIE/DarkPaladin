/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset.

For example, given an array arr = [-2,1,3,-4,5] we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is 8.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    
    int n = arr.size();
    vector<int> dp(n);
    
    dp[0] = arr[0];
    dp[1] = max(arr[1], dp[0]);
    
    for(int i=2; i<n; i++){
        // dp[i] records the current max value
        dp[i] = max(max(arr[i], arr[i] + dp[i-2]),dp[i-1]);
    }
    
    return dp[n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

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
