#include <iostream>

#include "phonescan/france/FrancePhoneScan.hpp"
#include "phonescan/GlobalPhoneScan.hpp"

int main(int ac, char **av)
{
    //PhoneScan::France::FrancePhoneScan fps = PhoneScan::France::FrancePhoneScan("resources");
    //std::cout << fps.scan("0695939179").toString()<< std::endl;

    PhoneScan::GlobalPhoneScan gps = PhoneScan::GlobalPhoneScan("resources");
    //gps.scan("+33695939179");
    std::cout << gps.scan("+33695939179").toString()<<std::endl;
}