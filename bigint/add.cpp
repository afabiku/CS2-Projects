#include "bigint.hpp"
#include <fstream>

int main(){
    std::ifstream file("data1-1.txt");
    
    if(file.is_open()){
        while(!file.eof()){
            bigint firstObject;
            file >> firstObject;
            if(file.eof()) break;
            std::cout << "First Object: " << firstObject << std::endl;

            bigint secondObject;
            file >> secondObject;
            if(file.eof()) break;
            std::cout <<"Second Object: " << secondObject << std::endl;

            bigint result;
            result = firstObject + secondObject;
            std::cout <<"Total: " << result << std::endl;
        }
        file.close();
    }else{
        std::cout << "Text file issue" << std::endl;
    }
}

