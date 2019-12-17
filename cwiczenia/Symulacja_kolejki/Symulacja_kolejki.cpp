#include <iostream>
#include "queue.h"
#include <cstdlib>
#include <ctime>
const int MIN_PER_HOUR = 60;
bool new_customer(double x);

int main()
{
    std::srand(std::time(0));
    std::cout << "Sdudium przypadkow: bankomat Banku Stu Kas\n";
    std::cout << "Podaj maksymalna dlugosc kolejki:";
    int qs;
    std::cin >> qs;
    Queue line(qs);
    std::cout << "Podaj symulowany czas (w godzinach): ";
    int hours;
    std::cin >> hours;
    long cyclelimit = MIN_PER_HOUR * hours;
    std::cout << "Podaj srednia liczbe klientow na godzine:";
    double perhour;
    std::cin>> perhour;
    double min_per_cust = MIN_PER_HOUR / perhour;
    Customer  temp;
    long turnaway = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (new_customer(min_per_cust))
        {
            if (line.isfull())
                turnaway++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }

        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }
    if (customers > 0)
    {
        std::cout << "Liczba klientow przyjetych: " << customers << std::endl;
        std::cout << "Liczba klientow obsluzonych: " << served << std::endl;
        std::cout << "Liczba klientow odeslanych: " << turnaway << std::endl;
        std::cout << "    srednia dlugosc kolejki: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout.setf(std::ios_base::showpoint);
        std::cout << (double)sum_line / cyclelimit << std::endl;
        std::cout << "    sredni czas oczekwani: ";
        std::cout << (double)line_wait / served << " minut\n";

    }
      
    else
        std::cout << "brak klientow" << std::endl;

    std::cout << "\n\nGotowe";
}


bool new_customer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

