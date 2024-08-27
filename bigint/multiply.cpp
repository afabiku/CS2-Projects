#include <fstream>
#include "bigint.hpp"

int main(){
    std::ifstream file("data1-2.txt");

    if(file.is_open()){
        while(!file.eof()){
            bigint firstObject;
            bigint secondObject;
            bigint total;

            file >> firstObject;
            if(file.eof()) break;
            std::cout << "firstObject: " << firstObject << std::endl;
            
            file >> secondObject;
            if(file.eof()) break;
            std::cout << "secondObject: " << secondObject << std::endl;

            total = secondObject * firstObject;
            std::cout << "Total: " << total << std::endl;
        }
        file.close();
    }else{
        std::cout << "Text file issue" << std::endl;
    }
}