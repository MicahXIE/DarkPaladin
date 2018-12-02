#include<iostream>
#include<memory>
#include<utility>

void foo(int* p){
    std::cout << *p << std::endl;
}

void bar(std::shared_ptr<int> p){
	++(*p);
}

int main(){
	//allocate two times and may cause memory leak
    std::shared_ptr<int> p1(new int(42));
    std::shared_ptr<int> p2 = p1;
    // allocate one time
    auto p3 = std::make_shared<int>(42);
    
    bar(p1);
    foo(p2.get());
    foo(p3.get());
}


