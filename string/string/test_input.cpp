#include "string.hpp"
#include <fstream>
#include <cassert>

int main() {
    std::ifstream file("inputTest.txt");
    if(file.is_open()){
        while(!file.eof()){
            String object("");
            file >> object;
            if(file.eof()) break;

            std::cout << object << std::endl;
            assert(object == "123456;");

            String objectSecond("");
            file >> objectSecond;
            if(file.eof()) break;
            std::cout << objectSecond << std::endl;
            assert(objectSecond == "9393984882;");
        }
    }
}