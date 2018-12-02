#include<iostream>
#include<functional>
#include<vector>

int main(){
    std::vector<double> a;
    a.push_back(3);
    a.push_back(1.666);
    a.push_back(4.5);
    a.push_back(6.7);
    a.push_back(1.66);
    a.push_back(6.66);

    std::for_each(a.begin(),a.end(),[&](double d){std::cout<<d<<"  ";});
    std::cout<<std::endl;

}