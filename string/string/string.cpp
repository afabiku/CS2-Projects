#include "string.hpp"

String::String(){
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

String::String(char input){
    if(input == '\0' ){
        stringSize = 1;
        str = new char[stringSize];
        str[0] = '\0';
    }else{
        stringSize = 2;
        str = new char[stringSize];
        str[0] = input;
        str[1] = '\0';
    }
}

std::ostream& operator<<(std::ostream&out, const String&input){
    for(int i = 0; i < input.length(); ++i){
        out << input.str[i];
    }
    return out; 
}

String::~String(){
    stringSize = 0;
    delete [] str;
}


String::String(const String& actual) { 
    int i = 0;  
    stringSize  = actual.stringSize;
    str   = new char[stringSize];
    while (actual.str[i] != 0) {
        str[i] = actual.str[i];
        ++i;
    }
    str[i] = '\0';
}

String::String(const char array[]){ 
    int size = 0;
    while (array[size] != '\0') {
        size += 1;
    }

    str = new char[size+1];

    for(int i = 0; i < size; ++i){
        str[i] = array[i];
    }
    str[size] = '\0';

    stringSize = size + 1;
}



int String::capacity() const {
    return stringSize-1;
}

int String::length() const{
    return stringSize - 1;
}


char&String::operator[](int index){
    for(int i = 0; i < length(); ++i){
        if(i == index){
            return str[index];
        }
    }
    return str[this->length()];
}


char String::operator[](int index) const {
    for(int i = 0; i < length(); ++i){
        if(i == index){
            return str[index];
        }
    }
    return str[this->length()];
}

String& String::operator=(String input){
    stringSize = input.stringSize;
    delete [] str;

    str = new char[stringSize];
    for(int i = 0; i < stringSize; ++i){
        str[i] = input.str[i];
    }
    str[stringSize-1] = '\0';

    return *this;
}



String& String::operator+=(const String& input) {
    int inputLength = input.length();
    int currentLength = length();

    char temp[currentLength + 1]; 
    for (int i = 0; i < currentLength; ++i) {
        temp[i] = str[i];
    }
    temp[currentLength] = '\0';

    delete [] str;
    stringSize = currentLength + inputLength + 1;  
    str = new char[stringSize];

    int index = 0;
    for (int i = 0; temp[i] != '\0'; ++i) {
        str[index] = temp[i];
        ++index;
    }

    for (int i = 0; i < inputLength; ++i) {
        str[index] = input.str[i];
        ++index;
    }

    str[index] = '\0';

    return *this;
}




String operator+(String leftInput,const String&rightInput){
    String anwser = leftInput;
    anwser += rightInput;
    return anwser;
}

bool String::operator==(const String&input) const {
    if(input.length() != this->length()) return false;
    for(int i = 0; i < input.length(); ++i){
        if(input.str[i] != str[i]){
            return false;
        }
    }
    return true;
}

bool operator==(const char leftInput[],const String&rightInput){
    String arrayToString = String(leftInput);
    return (arrayToString == rightInput);
}



bool String::operator<(const String& input) const {
    int length = (input.length() < this->length()) ? input.length() : this->length(); 
    for(int i = 0; i < length; ++i) {
        if(str[i] < input.str[i]) {
            return true;
        } else if (str[i] > input.str[i]) {
            return false;
        }
    }
    return (this->length() < input.length());
}

bool operator<(const char leftInput[], const String&rightInput){
   return String(leftInput) < rightInput;
}

bool operator<(char leftInput, const String&rightInput){
   return String(leftInput) < rightInput;
}



bool operator==(char leftInput,const String&rightInput){
    return String(leftInput) == rightInput;
}

bool operator<=(const String&leftInput, const String&rightInput){
    if((leftInput == rightInput) || (leftInput < rightInput)){
        return true;
    }
    return false;
}

bool operator>(const String&leftInput, const String&rightInput){
    return !(leftInput < rightInput);
}

bool operator>=(const String&leftInput, const String&rightInput){
    if((leftInput > rightInput) || (leftInput == rightInput)){
        return true;
    }
    return false;
}

bool operator!=(const String&leftInput, const String&rightInput){
    return !(leftInput == rightInput);
}


String String::substr(int start,int end) const{
    String result("");

    int stringLength = this->length();
    int mainStart = start;
    int mainEnd = end;
    if(mainStart < 0){mainStart = 0;}
    if(mainEnd > stringLength){mainEnd = stringLength;}
    if(mainStart == mainEnd){
        return String(str[start]);
    }
    for(int i = mainStart; i<= mainEnd; ++i){
        result += String(str[i]);
    }
    return result;
}

int String::findch(int index,  char Value) const{
    int stringLength = this->length();
    if(index > stringLength || index < 0){return -1;}
    for(int i = index; i< stringLength; ++i){
        //std::cout << i;
        if(str[i] == Value){
            return i;
        }
    }
   //std::cout << std::endl;
    return -1;
}

int String::findstr(int start,  const String&Value) const{
    int currentLength = length();
    int valueLength = Value.length();

    int increment = 0;
    int totalFound = 0;
    int index = start;
    for (int i = start; i < currentLength; ++i) {
        int characterIndex = findch(index, Value[increment]);
        if(characterIndex != -1 ){
            index = characterIndex;
            totalFound += 1;
            index += 1;
            increment += 1;
        }
        else{
            totalFound = 0;
        }
        if(totalFound == valueLength){
            return (characterIndex - valueLength)+1; 
            break;
        }
    }
    return -1;
}


std::istream& operator>>(std::istream&file, String&object){
    char text;
    object = String("");
    while(!file.eof()){  
        file.get(text);
        if(file.eof() || text == '\n' || text == ' ') {object += '\0'; break;}
        object += text;
    }
    return file;
}


void String::swap(String& input) {
    int tempSize = input.stringSize;
    input.stringSize = stringSize;
    stringSize = tempSize;

    char* tempPtr = input.str;
    input.str = str;
    str = tempPtr;
}


std::vector<String> String::split(char input) const{
    std::vector<String> output;
    int index = 0;
    int inputLocation = findch(index,input);
    while(inputLocation != -1){
        String sub = substr(index,inputLocation-1);
        output.push_back(sub);
        index = inputLocation + 1;
        inputLocation = findch(index,input);
    }
    output.push_back(substr(index,length()-1));
    return output;
}

// int main(){
//     String a("-a--b-");
//     std::vector<String> b = a.split('-');
//     std::cout << b.size();
//     for(size_t i = 0; i < b.size(); ++i){
//         //std::cout << b[i] << std::endl;
//     }
// }

// const int String::stringToInt() const{

// }