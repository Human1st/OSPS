#ifndef FRANCEPHONESCAN_HPP_
#define FRANCEPHONESCAN_HPP_

#include "phonescan/CountryPhoneScan.hpp"
#include "phonescan/PhoneData.hpp"

namespace PhoneScan::France{
    class FrancePhoneScan : public CountryPhoneScan{
        public:
            FrancePhoneScan(std::string folderBase);
            ~FrancePhoneScan();
            PhoneData scan(std::string num);
        private:
            std::string findProviderName(std::string code);
            bool isInRange(std::string phone, std::string rangeStart, std::string rangeStop);
            std::string _rangesFile;
            std::string _operatorsFile;

    };
}

#endif