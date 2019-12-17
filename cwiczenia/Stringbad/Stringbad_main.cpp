#include <iostream>
#include "Stringbad.h"
#include <ctime>
const int ArSize = 10;
const int MaxLen = 81;
void callme1(Stringbad &);
void callme2(Stringbad);
int main()
{

    Stringbad temp = "Dominik Momot";
    Stringbad temp2 = " Programista";
    Stringbad temp3;
    temp3 = temp + temp2;
    std::cout << temp3;
    /*
    Stringbad name;
    std::cout << "Czesc jak masz na imię?\n";
    std::cin >> name;
    std::cout << name << ", wpisz do " << ArSize
        << " krotkich powiedzonek, pustywiersz konczy wprowadzanie\n";
    Stringbad sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin.get(temp, MaxLen);
        while (std::cin && std::cin.get() != '\n')
            continue;
        if (!std::cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;

    }
    int total = i;
    if (total > 0)
    {
        std::cout << "Oto Twoje powiedzonka:\n";
        for (i = 0; i < total; i++)
            std::cout << sayings[i][0] << ": " << sayings[i] << std::endl;
        Stringbad* shortest = &sayings[0];
        Stringbad* first = &sayings[0];

        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
              
            if (sayings[i] < *first)
                first = &sayings[i];
        }
        std::cout << "Najkrotsze " << *shortest << std::endl;
        std::cout << "Pierwsze " << *first << std::endl;
        srand(time(0));
        int losowe = rand() % total;
        std::cout << "Ulubine: " << sayings[losowe];
    }
    else
        std::cout << "Brak danych\n";
    return 0;
    */
    




    /*
    {
        std::cout << "Zaczynamy blok wewentrzny\n";
        Stringbad headline1("Spiew skowronka - nowe zwrotki usypiaja?");
        Stringbad headline2("Kogutom smierc");
        Stringbad sports("Brzask wypada z ligi, skandal sedziowski");
        std::cout << "Z ostatniej chwili: " << headline1 << std::endl;
        std::cout << "Temat dnia: " << headline2 << std::endl;
        std::cout << "Wiadomosci sportowe: " << sports << std::endl;
        callme1(headline1);
        std::cout << "Z ostatniej chwili: " << headline1 << std::endl;
        callme2(headline2);
        std::cout << "Temat dnia: " << headline2 << std::endl;
        std::cout << "Inicjalizacja ciagu innym obiektem\n";
        Stringbad sailor = sports;
        std::cout << "Z kraju: " << sailor << std::endl;
        std::cout << "Przypisanie obiektu do innego obiekty\n";
        Stringbad knot;
        knot = headline1;
        std::cout << "Ze swiata" << knot << std::endl;
        std::cout << "koniec\n";
    }
    std::cout << "Koniec main()\n";
    return 0;
    */
}

void callme1(Stringbad& s)
{
    std::cout << "Obiekt przekazany przez referencje:\n";
    std::cout << "    \"" << s << "\"\n";
}
void callme2(Stringbad s)
{
    std::cout << "Obiekt przekazany przez wartosc:\n";
    std::cout << "    \"" << s << "\"\n";
}

