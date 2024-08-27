#include <iostream>

int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int tailFibonacci(int input, int previous, int last){
    if(input == 1) return last;
    if (input == 0) {return previous;}
    return tailFibonacci(input - 1,last,last + previous);
}

int main(){
    for(int i = 0; i<4;++i){
        std::cout << tailFibonacci(i,0,1);
    }
    std::cout << " " << std::endl;
    for(int i = 0; i<4;++i){
        std::cout << fibonacci(i);
    }
}