/*
Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
Sample Output

4 6 6 4
8 8 8 10
Explanation

For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. 
The 4 maximum elements of subarray of size 2 are: 4 6 6 4. 

For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. 
The 4 maximum element of subarray of size 4 are: 8 8 8 10.
*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq;
    
    int max=0;
    int pop=-1;
    
    for(int i(0); i<n; i++){
        
        dq.push_front(arr[i]); 
        
        if(dq.size() == k){
            if((max == 0 && pop == -1)||(pop == max)){
                max = 0;
                for(auto iter = dq.begin(); iter != dq.end(); iter++){
                    if(*iter > max){
                        max = *iter;
                    }
                } 
            } else {
                if(max < dq.front()){
                    max = dq.front();
                }
            }
            cout << max << " ";
            pop = dq.back();
            dq.pop_back();
        }

    }
    cout << endl;
    
    
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

