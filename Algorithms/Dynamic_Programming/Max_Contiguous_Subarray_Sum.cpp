/*
Maximum Contiguous Subarray Problem (Kadane's algorithm)

Given an array of integers, find contiguous subarray within it which has the 
largest sum

For example,
Input: {-2, 1, -3, 4, -1, 2, 1, -5, 4}

Output: subarray {4, -1, 2, 1} with the largest sum 6

https://www.techiedelight.com/maximum-subarray-problem-kadanes-algorithm/
*/

#include<iostream>
using namespace std;

int kadane(int arr[], int n){
	int max_current, max_global;

	max_current = arr[0];
	max_global = arr[0];

	for(int i=1; i<n; i++){
		max_current = max(arr[i], max_current+arr[i]);

		if(max_current > max_global){
			max_global = max_current;
		}
	}

	return max_global;
}


int main(){
	//int arr[] = {-8, -3, -6, -2, -5, -4};  
	//int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int arr[] = {-2, 3, 2, -1};
	int n = sizeof(arr)/sizeof(int);

	cout << "The max sum of contiguous subarry is: " << kadane(arr, n) << endl;

	return 0;
}

