#include "string.hpp"

String::String(){
    str[0] = '\0';
}


String::String(char input){
    str[0] = input;
    str[1] = '\0';
}

String::String(const char array[]){
    int index = 0;
    while (index < STRING_SIZE -1 && array[index] != '\0') {
        str[index] = array[index];
        index += 1;
    }
    str[index] = '\0';
}

int String::capacity() const {
    return STRING_SIZE - 1;
}

int String::length() const{
    int index = 0;
    while(str[index] != '\0'){
        index += 1;
    }
    return index;
}

char&String::operator[](int index){
    for(int i = 0; str[i] != '\0'; ++i){
        if(i == index){
            return str[index];
        }
    }
    return str[this->length()];
}

char String::operator[](int index) const {
    for(int i = 0; str[i] != '\0'; ++i){
        if(i == index){
            return str[index];
        }
    }
    return str[this->length()];
}

String& String::operator+=(const String& input){
    int currentLength = this->length();
    int inputLength = input.length();
    int index = currentLength;
    for(int i = 0; i < inputLength; ++i){
        if(!(index < STRING_SIZE - 1)){break;}
        str[index] = input.str[i];
        index += 1;
    }
    str[index] = '\0';
    return *this;
}

String operator+(String leftInput,const String&rightInput){
    String anwser = leftInput;
    anwser += rightInput;
    return anwser;
}


std::ostream& operator<<(std::ostream&cout, const String&input){
    for(int i = 0; input.str[i] != '\0'; ++i){
        std::cout << input.str[i];
    }
    return cout;
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

bool operator==(const char leftInput[],const String&rightInput){
    String arrayToString = String(leftInput);
    return (arrayToString == rightInput);
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
    
    for(int i = mainStart; i<= mainEnd; ++i){
        result += String(str[i]);
    }
    return result;
}



int String::findch(int index,  char Value) const{
    int stringLength = this->length();
    if(index > stringLength || index < 0){return -1;}
    for(int i = index; i< stringLength; ++i){
        if(str[i] == Value){
            //std::cout << i << " " << Value << std::endl;
            return i;
        }
    }
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
    int index = 0;
    char text;
    while(!file.eof() && index < STRING_SIZE - 1){  
        file.get(text);

        if(file.eof() || object[index] == ' ' || text == '\n' ) {object[index] = '\0'; break;}
        object[index] = text;
        index+= 1;
    }
    return file;
}