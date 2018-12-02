#include<iostream>
#include<memory>
#include<utility>

int main(){

    auto p = std::make_shared<int>(42);
    std::weak_ptr<int> wp = p;

    auto sp = wp.lock();
    std::cout << *sp << std::endl;

    p.reset();

    if(wp.expired())
        std::cout << "expired" << std::endl;
}


