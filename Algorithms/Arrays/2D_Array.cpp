/*
For example, given the 2D array:

-9 -9 -9  1 1 1 
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0
We calculate the following 16 hourglass values:

-63, -34, -9, 12, 
-10, 0, 28, 23, 
-27, -11, -2, 10, 
9, 17, 25, 18
Our highest hourglass value is 28 from the hourglass:

0 4 3
  1
8 6 6
*/

#include <bits/stdc++.h>

using namespace std;


// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max = INT_MIN;
    int sum;
    
    for(int i=0; i<=3; i++){
        for(int j=0; j<=3; j++){
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + 
                  arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if(sum > max){
                max = sum;
            }
        }
    }

    return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}


