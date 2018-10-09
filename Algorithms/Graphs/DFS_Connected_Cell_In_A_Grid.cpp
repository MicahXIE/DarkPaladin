/*
Sample Input
4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0

Sample Output
5
*/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int getRegion(vector<vector<int>> &a, int i, int j, int n, int m) {

    if (i >= n || i<0 || j>=m || j < 0) return 0;
    if (a[i][j] == 0) return 0;

    // same as int count=1; a[i][j]--
    // prevent recursion searching back
    int count = a[i][j]--;
    
    count += getRegion(a, i + 1, j + 1, n, m);
    count += getRegion(a, i - 1, j - 1, n, m);
    count += getRegion(a, i - 1, j, n, m);
    count += getRegion(a, i + 1, j, n, m);
    count += getRegion(a, i, j - 1, n, m);
    count += getRegion(a, i, j + 1, n, m);
    count += getRegion(a, i - 1, j + 1, n, m);
    count += getRegion(a, i + 1, j - 1, n, m);

    return count;
}

int dfs(vector<vector<int>> a, int n, int m) {
    int res = INT_MIN;

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m;j++) {
            if (a[i][j] == 1) {
                res = max(res, getRegion(a, i, j, n, m));
            }
        }
    }
    return res;
}


int main()
{
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>>v(n, vector<int>(m));

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m;j++) {
            int num; cin >> num;
            v[i][j] = num;
        }
    }
    cout << dfs(v, n, m)<<endl;

    //system("pause");
    return 0;
}