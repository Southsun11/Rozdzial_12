

#include <iostream>
#include "Stock.h"
int main()
{
    Stock sparametryzowany(5);
    unsigned int temp;
    char choice;
    std::cout << "D)Dodaj\nU)Usun\nK)Koniec\n";
    while (std::cin >> choice && choice != 'K')
    {
        switch (choice)
        {
        case'D':
            std::cout << "Podaj liczbe dodana na stos\n";
            std::cin >> temp;
            if (!sparametryzowany.push(temp))
                std::cout << "Stos pelny\n";
            else
                std::cout << "Dodano\n";
            break;
        case 'U':
            if (!sparametryzowany.pop(temp))
                std::cout << "Stos pusty\n";
            else
                std::cout << "Zdjeto " << temp << std::endl;
            break;
        default:
            std::cout << "Zly argument\n";
            
        }
      std::cout << "D)Dodaj\nU)Usun\nK)Koniec\n";
                
    }

    Stock kopiujacy = sparametryzowany;
    Stock bazowy;
    bazowy = kopiujacy;
    while (kopiujacy.pop(temp))
        std::cout << "kopiujacy: " << temp << std::endl;
    while (bazowy.pop(temp))
        std::cout << "kopiujacy: " << temp << std::endl;

}

