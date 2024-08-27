#ifndef bigint_hpp
#define bigint_hpp
#include <iostream>
const int inputCapacity = 200;

class bigint {
public:
    bigint();
    bigint(int);
    bigint(const char[]);
    void debugPrint(std::ostream&) const;
    bool operator==(const bigint&) const;

    bigint operator+(const bigint&);   
    //bigint operator*(const bigint&) const;
    friend std::istream & operator >>(std::istream&,bigint&);
    friend std::ostream& operator <<(std::ostream&, const bigint&);
    bigint operator*(const bigint&);

    bigint timesDigit(int) const;
    bigint times10(int) const;

    int operator[](int index);
    int operator[](int index) const;
    //x[1]
private:
    int inputStorage[inputCapacity];
};

#endif