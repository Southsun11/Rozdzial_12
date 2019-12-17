#include <iostream>
#include "../Stringbad/Stringbad.cpp"
#include "../Stringbad/Stringbad.h"
int main()
{

    Stringbad temp = "Dominik Momot";
    Stringbad temp2 = " Programista";
    Stringbad temp3;
    temp3 = temp + temp2;
    std::cout << temp3 << std::endl;
    temp.stringlow();
    std::cout << temp << std::endl;
    temp.stringupper();
    std::cout << temp << std::endl;
    int number;
    number = temp.howmany('M');
    std::cout << number << std::endl;
}
