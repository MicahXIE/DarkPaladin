/*
Sample Input 2

123 3
Sample Output 2

9
Explanation 2

Here n=123  and k=3, so P=123123123.

super_digit(P) = super_digit(123123123) 
               = super_digit(1+2+3+1+2+3+1+2+3)
               = super_digit(18)
               = super_digit(1+8)
               = super_digit(9)
               = 9

tips:
1) read this , you will learn something new : http://applet-magic.com/digitsummod9.htm
2) remember property : (a+b)%x = ((a%x)+(b%x))%x
*/

#include <bits/stdc++.h>
using namespace std;

int digit_sum_finder(string s){
	int rem=0;
	for(int i=0;i<s.length();++i){
		rem = (rem + (s[i]-'0'))%9;
	}
	return rem%9;
}

int main(){
	string s;
	cin>>s;

	int k;
	cin>>k;
	k = k%9;

	if(k == 0){
		cout<<"9";
		return 0;
	}
	else{
		int digit_sum = digit_sum_finder(s);
		digit_sum = (digit_sum * k)%9;

		if(digit_sum != 0){
			cout<<digit_sum;
		}
		else{
			cout<<"9";
		}
	}
}


