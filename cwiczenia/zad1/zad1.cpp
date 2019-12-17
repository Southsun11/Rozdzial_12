
#include <iostream>
#include "Cow.h"

int main()
{
    {
        Cow bazowy;
        bazowy.show();
        Cow jeden("Dominik Momot", "Programowanie", 30);
        Cow trzy("aaa", "bbb", 30);
        jeden.show();
        Cow dwa = jeden;
        dwa.show();
        dwa = trzy;
        dwa.show();

    }
    
    
}

