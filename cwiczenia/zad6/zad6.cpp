#include <iostream>
#include "queue.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
const int MIN_PER_HOUR = 60;
bool new_customer(double x);

int main()
{
    std::ofstream file;
    file.open("text1.txt");
    std::srand(std::time(0));
    std::cout << "Sdudium przypadkow: bankomat Banku Stu Kas\n";
    //std::cout << "Podaj maksymalna dlugosc kolejki:";
    int qs = 10;
    // std::cin >> qs;
    Queue line(qs);
    //std::cout << "Podaj symulowany czas (w godzinach): ";
    int hours = 100;
    //std::cin >> hours;
    long cyclelimit = MIN_PER_HOUR * hours;
    //std::cout << "Podaj srednia liczbe klientow na godzine:";
    double perhour = 0;
    //std::cin >> perhour;



    while (perhour < 100)
    {
        double min_per_cust = MIN_PER_HOUR / perhour;
        file << "Liczba klientow: " << perhour << std::endl;
        long turnaway = 0;
        long customers = 0;
        long served = 0;
        long sum_line = 0;
        long sum_line2 = 0;
        long wait_time = 0;
        long wait_time2 = 0;
        long line_wait = 0;
        Customer  temp;
        Queue line(qs);
        Queue line2(qs);

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (new_customer(min_per_cust))  // have newcomer
            {
                if (line.isfull() && line2.isfull())
                    turnaway++;
                else
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line.queuecount() < line2.queuecount() ? line.enqueue(temp) : line2.enqueue(temp);
                    //line.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time == 0 && !line.isempty())
            {
                line.dequeue(temp);      // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                //if (cycle - temp.when() < 0)
                //    std::cout << "blad " << customers << " " << perhour << " " << cycle << " " << temp.when() << std::endl;
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 == 0 && !line2.isempty())
            {
                line2.dequeue(temp);      // attend next customer
                wait_time2 = temp.ptime(); // for wait_time minutes
                //if (cycle - temp.when() < 0)
                //    std::cout << "blad " << customers << " " << perhour << " " << cycle << " " << temp.when() << std::endl;
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line.queuecount();
            sum_line2 += line2.queuecount();
        }
        if (customers > 0)
        {
            file << "Liczba klientow przyjetych: " << customers << std::endl;
            file << "Liczba klientow obsluzonych: " << served << std::endl;
            file << "Liczba klientow odeslanych: " << turnaway << std::endl;
            file << "    srednia dlugosc kolejki 1: ";
            file.precision(2);
            file.setf(std::ios_base::fixed, std::ios_base::floatfield);
            file.setf(std::ios_base::showpoint);
            file << (double)sum_line / cyclelimit << std::endl;
            file << "    srednia dlugosc kolejki 1: ";
            file << (double)sum_line2 / cyclelimit << std::endl;
            file << "    sredni czas oczekwania obu  kolejek: ";
            file << (double)line_wait / served << " minut\n";

        }

        else
            file << "brak klientow" << std::endl;
        perhour += 1;
    }
    std::cout << "\n\nGotowe";
}


bool new_customer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

