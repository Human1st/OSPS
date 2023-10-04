#ifndef COUNTRYPHONESCAN_HPP_
#define COUNTRYPHONESCAN_HPP_

#include "PhoneData.hpp"

namespace PhoneScan{
    class CountryPhoneScan{
        public:
            virtual PhoneData scan(std::string number) = 0;
    };
}

#endif