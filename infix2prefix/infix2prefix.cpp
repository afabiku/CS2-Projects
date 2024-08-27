#include "infix2prefix.hpp"

String infixToPostfix(String&input){
    std::vector<String> tokens = input.split(' ');
    stack<String> Stack;
    for(size_t i = 0; i != tokens.size()-1; ++i){
        if(tokens[i] != '('){
            if(tokens[i] == ')'){
                String rightOperand = Stack.pop();
                String op = Stack.pop();
                String leftOperand = Stack.pop();
                Stack.push(op+leftOperand+rightOperand);
            }
            if(tokens[i] != ')'){
                Stack.push(tokens[i]);
            }   
        }
    }
    return Stack.pop();
}


int main(){
    std::ifstream file("data3-1.txt");
    if(!file.is_open()){std::cout << "Can't Open InPut File" << std::endl; exit(1);}

    char token;
    String expression;
    while(file.get(token)){
        if(token == '\n'){  
            file.get(token);
            std::cout << infixToPostfix(expression) << std::endl;
            expression = "";
        }
        if(token != ';')
            expression += token;
    }   
    file.close(); 
}


