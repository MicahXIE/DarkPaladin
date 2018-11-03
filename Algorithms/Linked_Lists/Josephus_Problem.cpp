/*

In computer science and mathematics, the Josephus Problem (or Josephus permutation) 
is a theoretical problem. Following is the problem statement:
There are n people standing in a circle waiting to be executed. The counting out begins 
at some point in the circle and proceeds around the circle in a fixed direction. In each 
step, a certain number of people are skipped and the next person is executed. The elimination 
proceeds around the circle (which is becoming smaller and smaller as the executed people 
are removed), until only the last person remains, who is given freedom. 
Given the total number of persons n and a number k which indicates that k-1 persons are 
skipped and kth person is killed in circle. The task is to choose the place in the initial 
circle so that you are the last one remaining and so survive.

The problem has following recursive structure.

  josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
  josephus(1, k) = 1

After the first person (kth from begining) is killed, n-1 persons are left. 
So we call josephus(n – 1, k) to get the position with n-1 persons. But the 
position returned by josephus(n – 1, k) will consider the position starting 
from k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1, k).

seq 1: 1, 2, 3, 4, ... , n-2, n-1, n
seq 2: 1, 2, 3, 4, ... , k-1, k+1, ..., n-2, n-1, n
seq 3: k+1, k+2, k+3, ..., n-2, n-1, n, 1, 2, 3, .., k-2, k-1
seq 4: 1, 2, 3, 4, ... , 7, 8, ..., n-2, n-1

∵ k = m%n; 　　

∴ x' = x+k = x+ m%n ; 而 x+ m%n 可能大于n

∴x'= (x+ m%n)%n = (x+m)%n 　　

得到 x' is the value start from 0. final result need to add 1

https://blog.csdn.net/qq_25973267/article/details/50405616

*/




#include <stdio.h> 
#include <iostream>
  
int josephus(int n, int m) 
{ 
  if (n == 1) 
    return 0; 
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the 
       recursive call josephus(n - 1, k) considers the original position  
       k%n + 1 as position 1 */
    return (josephus(n - 1, m) + m) % n; 
}

// Driver Program to test above function 
int main() 
{ 
  int n = 14; 
  int m = 2; 
  printf("The chosen place is %d\n", josephus(n, m)+1); 
  return 0; 
} 



