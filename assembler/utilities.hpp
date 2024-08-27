#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <fstream>
#include "stack.hpp"
#include "../string/string.hpp"

String infixToPostfix(String&);
String postfixToAssembly(String&,std::ostream&);
String evaluate(String&,String&,String&,std::ostream&);

#endif