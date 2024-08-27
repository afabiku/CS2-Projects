#include "bigint.hpp"

bigint::bigint() {
    for (int i = 0; i < inputCapacity; ++i) {
        inputStorage[i] = 0;
    }
}

bigint::bigint(int Input) : bigint() {
    //std::cout << "Called" << std::endl;
    int inputSize = 1;
    int userInput = Input;
    while(true){
        userInput = userInput/10;
        if(userInput != 0){
            inputSize += 1;
        }
        else{
            break;
        }
    }
    
    if(inputSize < inputCapacity){
        int inputIndex = inputCapacity -1;
        int inputValue = Input;

        for(int i = 0; i < inputSize; ++i){
            int value = inputValue%10;
            inputStorage[inputIndex] = value;  
            inputValue = inputValue/10;
            inputIndex -= 1;
        }
    }else{
        std::cout << "Capacity Reached";
    }
}

bigint::bigint(const char CharacterList[]) : bigint() {
    int totalElement = 0;
    for (int i = 0; CharacterList[i] != '\0'; ++i) {
        totalElement += 1;
    }

    if(totalElement < inputCapacity){
        int startingPosition = inputCapacity - totalElement;
        for (int i = 0; i < totalElement; ++i) {
            int inputValue = int(CharacterList[i]) - int('0');
            inputStorage[startingPosition] = inputValue;
            startingPosition += 1;
        }
        inputStorage[startingPosition] = '\0';
    }else{
        std::cout << "Capacity Reached" << std::endl;
    }
}

void bigint::debugPrint(std::ostream& cout) const {
    for (int i = 0; i < inputCapacity; ++i) {
        cout << inputStorage[i] << "|";
    }
    cout << std::endl;
}

std::ostream& operator<<(std::ostream& cout, const bigint& input) {
    int index = 0;
    while(input.inputStorage[index] == 0 && index < inputCapacity){
        index += 1;
    }

    for(int i = index; i < inputCapacity; ++i){
        std::cout << input.inputStorage[i];
    }

    if(index == inputCapacity){
        std::cout << 0;
    }

    return cout;
}

bool bigint::operator==(const bigint& rightObject) const {
    int currentIndex = 0;
    while(inputStorage[currentIndex] == 0 && currentIndex < inputCapacity - 1){
        currentIndex += 1;
    }

    int rightIndex = 0;
    while(rightObject.inputStorage[rightIndex] == 0 && rightIndex < inputCapacity - 1){
        rightIndex += 1;
    }


    if(rightIndex == currentIndex){
        for(int i = rightIndex; i < inputCapacity; ++i){
            if(inputStorage[rightIndex] == rightObject.inputStorage[currentIndex]){
                return true;
            }
        }
    }


    return false;
}

bigint bigint::operator+(const bigint&rightObject){
    bigint sum;
    int currentTotal = 0;
    while(inputStorage[currentTotal] == 0 && currentTotal < inputCapacity - 1){
        currentTotal += 1;
    }

    int rightTotal = 0;
    while(rightObject.inputStorage[rightTotal] == 0 && rightTotal < inputCapacity - 1){
        rightTotal += 1;
    }


    int increment = inputCapacity - 1;
    int remainder = 0;
    if(currentTotal >= rightTotal){
        for(int i = 0; i < currentTotal; ++i){
            int total = inputStorage[increment] + rightObject.inputStorage[increment] + remainder;
            int value = total % 10;
            sum.inputStorage[increment] = value;

            increment -= 1;
            remainder = total/10;
        }
    }
    else{
        for(int i = 0; i < rightTotal; ++i){
            int total = inputStorage[increment] + rightObject.inputStorage[increment] + remainder;
            int value = total % 10;
            sum.inputStorage[increment] = value;

            increment -= 1;
            remainder = total/10;
        }
    }

    return sum;
}


int bigint::operator[](int index){
    int currentTotal = 0;
    while(inputStorage[currentTotal] == 0){
        currentTotal += 1;
    }

    int max = inputCapacity - 1;
    int offsetIndex = max - index;
    int maxIndex = max - currentTotal;
    if(index > (maxIndex)) {
        offsetIndex = currentTotal;
    }

    if(index < 0){
        offsetIndex = max;
    }
    return inputStorage[offsetIndex];
}




// read from file and 
std::istream& operator>>(std::istream& file,bigint& input){
    char text;
    int data[inputCapacity];
    for(int i = 0; i < inputCapacity; ++i){
        data[i] = -1;
    }


    int index = 0;
    while(!file.eof() && index < inputCapacity - 1){  
        file.get(text);
        if(file.eof() || text == ';') break;
        if(text == '\n' || text == ' ') continue;
        int value = text - '0';
        data[index] = value;
        index+= 1;
    }
    
    if(!file.eof()){
        if(text == ';'){
            file.get(text);
        }

        int currentTotal = 0;
        while(data[currentTotal] != -1){
            currentTotal += 1;
        }
        
        int startIndex = inputCapacity -1;
        for(int i = currentTotal -1; i >= 0; --i){
            input.inputStorage[startIndex] = data[i];
            startIndex -= 1;
        }
    }
    return file;
}

// bigint bigint::operator*(const bigint & input) const{

// }

bigint bigint::timesDigit(int input) const{
    bigint anwser;

    if(input > 9){
        std::cout << "Number must be less than 9" << std::endl;
        return anwser;
    }

    int tempArray[inputCapacity];

    for(int i = 0; i < inputCapacity;++i){
        tempArray[i] = -1;
    }

    int inputLength = 1;
    int userInput = input;

    while(true){
        userInput = userInput/10;
        if(userInput != 0){
            inputLength += 1;
        }
        else{
            break;
        }
    }


    int currentLength = 0;
    while(inputStorage[currentLength] == 0 && currentLength < inputCapacity - 1){
        currentLength += 1;
    }
    currentLength = (inputCapacity) - currentLength;

    int index = (inputCapacity - 1);
    int remainder = 0;

    userInput = input;

    int tempIndex = 0;
    if(currentLength >= inputLength){
        int inputDigit = userInput%10;
        for(int i = 0; i < currentLength; ++i){
            int currentDigit = inputStorage[index];
            int multiplied = inputDigit * currentDigit;
            int value =  multiplied + remainder;

            int valueDigit;
            if(i != currentLength - 1){
                valueDigit = value%10;
            }
            else{
                valueDigit = value;
            }

            //std::cout << valueDigit << " " << valueDigit/10 << std::endl;
            if(valueDigit != 0 && valueDigit/10 != 0){
                tempArray[tempIndex] = valueDigit%10;
                valueDigit = valueDigit/10;
                tempIndex += 1;
                tempArray[tempIndex] = valueDigit;
            }else{
                tempArray[tempIndex] = valueDigit;
            }

            remainder = value/10;
            tempIndex += 1;
            index -= 1;
        }
    }

    int totalElement = 0;
    while(tempArray[totalElement] != -1){
        totalElement += 1;
    }

    int arrayIndex = inputCapacity-1;
    for(int i = 0; i < totalElement; ++i){
        anwser.inputStorage[arrayIndex] = tempArray[i];
        arrayIndex -= 1;
    }
    return anwser;
}

bigint bigint::times10(int input) const{
    bigint anwser;
    int currentIndex = 1;
    while(inputStorage[currentIndex] == 0 && currentIndex < inputCapacity - 1){
        currentIndex += 1;
    }

    int newIndex = currentIndex;
    for(int i = 0; i < input; ++i){
        newIndex -= 1;
    }

    int incrementSize = (inputCapacity - currentIndex);
    for(int i = 0; i < incrementSize ; ++i){
        anwser.inputStorage[newIndex] = inputStorage[currentIndex];
        newIndex += 1;
        currentIndex += 1;
    }

    for(int i = 0; i < input; ++i){
        anwser.inputStorage[newIndex] = 0;
        newIndex += 1;
    }

    return anwser;
}

bigint bigint::operator*(const bigint& input) {
    bigint product; // Initialize the product bigint object

    int currentLength = 0;
    while(inputStorage[currentLength] == 0 && currentLength < inputCapacity - 1){
        currentLength += 1;
    }
    currentLength = (inputCapacity - currentLength);

    int inputSize = 0;
    while(input.inputStorage[inputSize] == 0 && inputSize < inputCapacity - 1){
        inputSize += 1;
    }
    inputSize = (inputCapacity - inputSize);

    int incrementSize = currentLength;
    if(inputSize > incrementSize){
        incrementSize = inputSize;
    }

    int totalCharacters = incrementSize + inputSize;

    if(totalCharacters < inputCapacity-1){
        int zeros = 0;
        int arrayIndex = inputCapacity - 1;
        for (int i = 0; i < incrementSize; ++i) {
            bigint temp = timesDigit(input.inputStorage[arrayIndex]);
            product = product + temp.times10(zeros);
            zeros += 1;
            arrayIndex -= 1;
        }
    }else{
        std::cout << "Size too big" << std::endl;
    }

    return product;
}


