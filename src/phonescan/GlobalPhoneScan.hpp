#ifndef GLOBALPHONESCAN_HPP_
#define GLOBALPHONESCAN_HPP_

#include <map>
#include <memory>

#include "PhoneData.hpp"
#include "CountryCode.hpp"
#include "CountryPhoneScan.hpp"

#define PHONESCAN_COUNTRYCODE_FILE "country_codes.csv"

namespace PhoneScan{

    class GlobalPhoneScan{
        public:
            GlobalPhoneScan(std::string folder);
            ~GlobalPhoneScan();
            PhoneData scan(std::string num);
            void downloadDatabases();
        private:
            std::map<std::string, std::shared_ptr<CountryPhoneScan>> _countryPhoneScanners;
            PhoneScan::CountryCode getCountryCode(std::string countryShort);
            void downloadFile(std::string destination, std::string originUrl);
            std::string _folder;
    };
}

#endif