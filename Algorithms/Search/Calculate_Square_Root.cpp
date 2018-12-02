#include<iostream>
#include<math.h>
using namespace std;

double calculate_Square_Root(int n)
{
    double mid =(double (n ))/ 2;
    double l = 0.0, r = 1.0;
    while (fabs((mid*mid - (double)n)) > 0.000001)
    {

        if ((mid*mid - (double)n) > 0.000001)
        {
            r = mid;
            mid = l + (r - l) /2;
        }

        else
        {

            l = mid;
            mid = l + (r - l) / 2;
        }

    }
    return mid;

}

int main(){
    
    double res = calculate_Square_Root(7);
    cout << "result: " << res << endl;
}
