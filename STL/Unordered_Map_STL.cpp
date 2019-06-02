#include <iostream>
#include <unordered_map>
#include <string>
int main(int argc, char **argv) {
    std::unordered_map<int, std::string> map;
    map.insert(std::make_pair(1, "Scala"));
    map.insert(std::make_pair(2, "Haskell"));
    map.insert(std::make_pair(3, "C++"));
    map.insert(std::make_pair(6, "Java"));
    map.insert(std::make_pair(14, "Erlang"));
    std::unordered_map<int, std::string>::iterator it;
    if ((it = map.find(6)) != map.end()) {
        std::cout << it->second << std::endl;
    }
    return 0;
}
