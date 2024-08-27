#include "utilities.hpp"

int main(int argc, char*argv[]){
    std::vector<String> option(1);
    option[0] = "assembler";
    
    std::ifstream file(argv[1]);
    if(!file.is_open()){std::cout << "Can't Open InPut File" << std::endl; exit(1);}

    std::ofstream output;
    if(argc >= 3){
        output.open(argv[2]);
        if(!output.is_open()){std::cout << "Cant Open OutPut File" << std::endl; exit(1);}
    }


    char token;
    String expression;
    while(file.get(token)){
        if(token == '\n'){  
            file.get(token);
            if(output.is_open()){
                output << "Infix Expression: " << expression << std::endl;
                String result = infixToPostfix(expression);
                output << "Postfix  Expression: " <<  result << std::endl;
                output << std::endl;
                postfixToAssembly(result,output);
                output << std::endl;
            }
            else{
                std::cout << "Infix Expression: " << expression << std::endl;
                String result = infixToPostfix(expression);
                std::cout << "Postfix  Expression: " <<  result << std::endl;
                std::cout << std::endl;
                postfixToAssembly(result,std::cout);
                std::cout << std::endl;
            }
            expression = "";
        }
        if(token != ';')
            expression += token;
    }   
    output.close();
    file.close(); 
}


