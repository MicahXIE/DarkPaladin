/*
假设有 1 元，3 元，5 元的硬币若干（无限），现在需要凑出 11 元，问如何组合才能使硬币的数量最少？
https://www.cnblogs.com/snowInPluto/p/5992846.html
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getMinCoins(int value, vector<int> &coins){
 	int n = coins.size();
	vector<int> dp(n);
	int min;

	dp[0] = 0;
	for(int i=1; i<(value+1); i++){
		min = INT_MAX;
		for(int coin : coins){
			if(i>=coin && (dp[i-coin]+1)<min){
				min = dp[i-coin]+1;
			}
		}
		dp[i] = min;
		cout << "value: " << i << " min coins: " << min << endl;
	}

	return dp[value];
}

int main(){
	vector<int> c = {1, 3, 5};
	int value = 11;
	int res = getMinCoins(value,c);

	cout << "the minimum coins needed for " << value << " is " << res << endl;
}