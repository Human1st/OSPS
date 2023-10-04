#ifndef COUNTRYCODE_HPP_
#define COUNTRYCODE_HPP_

#include <string>

namespace PhoneScan{
    class CountryCode{
        public:
            CountryCode();
            ~CountryCode();
            void setCountryCode(std::string);
            void setCountryPrefix(std::string);
            void setCountryName(std::string);
            std::string getCountryCode();
            std::string getCountryPrefix();
            std::string getCountryName();
            std::string toString();
        private:
            std::string _countryCode;
            std::string _countryPrefix;
            std::string _countryName;
    };
}

#endif