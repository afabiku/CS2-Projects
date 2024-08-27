#include <iostream>
#include <fstream>

void readLine(){
    std::ifstream file("fileio-text.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file";
    }
    
    char text = ' ';
    while(true){
        if(!file.get(text)) break;
        if(text == ' ') std::cout << std::endl;
        std::cout << text;
        if(file.eof()) break;
    }
    file.close();
}

void addLine(){
    std::ifstream file("fileio-data-1.txt");
    if(!file.is_open()) {
        std::cout << "Unable to open file";
    }
    char ignore;
    int number;
    int numb2;
    while(file >> number){
        int total = 0;
        total += number;
        file >> ignore;
        file >> numb2;
        total += numb2;
        file >> ignore;
        std::cout << total << std::endl;
    }
    file.close();
}

int main(){
    readLine();
    addLine();
}