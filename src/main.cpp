#include <iostream>

#include "phonescan/france/FrancePhoneScan.hpp"
#include "phonescan/GlobalPhoneScan.hpp"

int main(int ac, char **av)
{
    //PhoneScan::France::FrancePhoneScan fps = PhoneScan::France::FrancePhoneScan("resources");
    //std::cout << fps.scan("0695939179").toString()<< std::endl;

    PhoneScan::GlobalPhoneScan gps = PhoneScan::GlobalPhoneScan("resources");
    if(ac == 2)
	    std::cout << gps.scan(av[1]).getOperator()<<std::endl;
    else {
    	std::string lin = "";
    	while(std::getline (std::cin,lin)) {
    		std::cout << gps.scan(lin).getOperator()<<std::endl;
    	}
    }
}
