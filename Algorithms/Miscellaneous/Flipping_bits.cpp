/*
给你一个32-bits位无符号整数的列表，要求你输出你把它们中每个数二进制表示中的每位翻转之后的结果得到的新列表
（即0变成1，1变成0）。
*/

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
     
    return (pow(2,32)-1-n);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
