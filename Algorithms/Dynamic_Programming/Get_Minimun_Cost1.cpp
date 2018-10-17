#include<iostream>
using namespace std;

int getMinCost(int* A, int length){

	cout << length << endl;

	int* dp = new int[length];

	dp[0] = 2;

	int oneday, sevenday, prev;

	for(int i=1; i<length; i++){
        oneday = 2+dp[i-1];
        prev = i-1;

        while(prev>=0 && A[prev]>=(A[i]-6))
        	prev--;

        sevenday = 7;

        if(prev >= 0)
        	sevenday += dp[prev];

        dp[i] = min(oneday, sevenday);

	}

	return dp[length-1];
}

int main(){
	int A[] = {1, 2, 4, 5, 7, 8, 9, 10, 11, 12, 29, 30};
	int length = sizeof(A)/sizeof(int);
	int res = getMinCost(A, length);
	res = min(res, 25);

	cout << res << endl;

	return 0;
}