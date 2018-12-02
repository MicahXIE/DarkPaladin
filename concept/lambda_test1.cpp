#include<iostream>
#include<functional>

using namespace std;

double g_bb = 11.2;

void foo1()
{
	auto f_add = [&](int a, int b) -> int{return a+b;};

	std::cout<<f_add(1,2);  //3
	std::cout<<std::endl;

	double aa = 5.0;
	auto fun = [aa]()->double{return aa+3;};
	std::cout<<fun();  //8
	std::cout<<"  aa:"<<aa<<std::endl;  //  aa:5
    // add & can change the value for aa
    auto fun2 = [&aa]()->double{aa=7.0; return aa+3;};
    std::cout<<fun2();  //10
    std::cout<<"  aa:"<<aa<<std::endl;  //  aa:7
    auto fun3 = [&]()->double{aa=8.0;g_bb=15;return aa+3;}; 
    std::cout<< fun3();  //11
    std::cout<<"  aa:"<<aa<<" g_bb:"<<g_bb<<std::endl;  //aa:8 g_bb:15
}

int main(){
    foo1();
}