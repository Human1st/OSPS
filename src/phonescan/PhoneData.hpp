#ifndef PHONEDATA_HPP_
#define PHONEDATA_HPP_

#include <string>
#include "CountryCode.hpp"

namespace PhoneScan{
    class PhoneData{
        public:
            PhoneData(std::string, std::string, std::string);
            PhoneData();
            std::string getRange();
            std::string getOperator();
            std::string getAttributionDate();
            std::string getLocalisation();
            void setRange(std::string);
            void setOperator(std::string);
            void setAttributionDate(std::string);
            void setLocalisation(std::string);
            std::string toString();
            PhoneScan::CountryCode _countryCode;
            std::string _range;
            std::string _phoneOperator;
            std::string _attributionDate;
            std::string _localisation;
            ~PhoneData();
        private:
            
            
    };
}

#endif