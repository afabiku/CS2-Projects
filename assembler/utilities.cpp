#include "utilities.hpp"

String infixToPostfix(String&input){
    std::vector<String> tokens = input.split(' ');
    stack<String> Stack;
    for(size_t i = 0; i != tokens.size()-1; ++i){
        if(tokens[i] != '('){
            if(tokens[i] == ')'){
                String rightOperand = Stack.pop();
                String op = Stack.pop();
                String leftOperand = Stack.pop();
                Stack.push(leftOperand+" "+rightOperand+" "+op);
            }
            if(tokens[i] != ')'){
                Stack.push(tokens[i]);
            }   
        }
    }
    return Stack.pop();
}




String evaluate(String&right,String&left,String&op,std::ostream&out){
    out << "    LD" << " " << left << std::endl;
    if(op == '*' ){
        out << "    MU";
    }
    else if(op == '+'){
        out << "    AD";
    }
    else if(op == '-'){
        out << "    SB";
    }
    else if(op == '/'){
        out << "    DV";
    }
    out << " " << right << std::endl;
    return left + op + right;
}


String postfixToAssembly(String&input,std::ostream&out){
    std::vector<String> tokens = input.split(' ');
    stack<String> storage;
    char index = 49;
    String temp;
    for(size_t i = 0; i != tokens.size(); ++i){
        if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "/" || tokens[i] == "-"){
            String right = storage.pop();
            String left = storage.pop();
            String evalExpr = evaluate(right,left,tokens[i],out);
            temp = "TMP" + String(index);
            storage.push(temp);
            index +=1;
            out <<"    ST" << " " << temp << std::endl;
        }else{
            storage.push(tokens[i]);
        }
    }
    return storage.top();
}

