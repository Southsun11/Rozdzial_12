#include <iostream>
#include <string>
#include <new>

const int Size = 512;

class JustTesting
{
private:
    std::string words;
    int number;
public:
    JustTesting(const std::string& s = "Obiekt testowy", int n = 0) { words = s, number = n; std::cout << "Utowrzono obiekt " << words; }
    ~JustTesting() { std::cout << "Destruktor " << words << std::endl; }
    void show()const { std::cout << words << ", " << number << std::endl; }
};
int main()
{
    char * buffer = new char[Size];
    JustTesting* s1, * s2;
    s1 = new JustTesting("Sterta1",20);
    s2 = new(buffer) JustTesting;
    std::cout << "Adresy pamiecie\nsterta: " << s1 << "\nbuffor: " << (void*)buffer;
    std::cout << "Zawarotsc pamieci:\n";
    std::cout << s1 << ": ";
    s1->show();
    std::cout << s2 << ": ";
    s2->show();
    JustTesting* s3, *s4;
    s3 = new JustTesting("Sterta2", 10);
    s4 = new(buffer + sizeof(JustTesting)) JustTesting("Lepszy pomysl", 6);
    std::cout << "Zawartosc pamieci: \n";
    std::cout << s3 << ": ";
    s3->show();
    std::cout << s4 << ": ";
    s4->show();
    delete s1;
    delete s3;
    s4->~JustTesting();
    s2->~JustTesting();
    delete [] buffer;
    return 0;

}

