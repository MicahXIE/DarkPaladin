/*
13+62*7+*

stack       operation
1,3         +
4,6,2       *
4,12,7      +
4,19        *
76          return

*/
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int len=S.length();
    stack<int> n;
    int num1,num2,num_sum,num_mul;

    for(int i=0; i<len; i++){
        if(isdigit(S[i])){
            //cout << S[i] <<":" <<int(S[i]) << endl;
            n.push((int(S[i])-48));
        } else{
            if(n.size() >= 2){
                num1 = n.top();
                n.pop();
                num2 = n.top();
                n.pop();
                if(S[i] == '+'){
                    num_sum = num1 + num2;
                    n.push(num_sum);
                }
                if(S[i] == '*'){
                    num_mul = num1 * num2;
                    n.push(num_mul);
                }
            } else {
                return -1;
            }
        }
    }
    
    return n.top();
}