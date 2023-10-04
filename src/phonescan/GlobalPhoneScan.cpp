#include <stdio.h>
#include <curl/curl.h>
#include <fstream>

#include "GlobalPhoneScan.hpp"
#include "france/FrancePhoneScan.hpp"
#include "utils/StringOperation.hpp"

PhoneScan::GlobalPhoneScan::GlobalPhoneScan(std::string folder)
{
    _folder = folder;
    _countryPhoneScanners.insert({"FRA", std::make_shared<PhoneScan::France::FrancePhoneScan>(folder)});
}

PhoneScan::PhoneData PhoneScan::GlobalPhoneScan::scan(std::string num)
{
    PhoneScan::CountryCode country = getCountryCode(num);
    PhoneScan::PhoneData phoneData = PhoneScan::PhoneData();

    for (const auto &countryPhoneScanner : _countryPhoneScanners) {
        if (countryPhoneScanner.first.compare(country.getCountryPrefix()) == 0)
            phoneData = countryPhoneScanner.second->scan("0"+num.erase(0, country.getCountryCode().length()+1));
    }
    
    phoneData._countryCode = country;
    return phoneData;
}

PhoneScan::CountryCode PhoneScan::GlobalPhoneScan::getCountryCode(std::string number)
{
    PhoneScan::CountryCode countryCode = PhoneScan::CountryCode();
    std::ifstream file(_folder+"/"+PHONESCAN_COUNTRYCODE_FILE);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> splitedLine = StringOperation::split(line, ',');
            if (splitedLine[1].compare(" ") == 0)
                break;
            if (splitedLine[1].compare("") == 0)
                break;
            if (number.rfind("+"+splitedLine[1], 0) == 0) {
                countryCode.setCountryCode(splitedLine[1]);
                countryCode.setCountryPrefix(splitedLine[0]);
                countryCode.setCountryName(splitedLine[21]);
                file.close();
                return countryCode;
            }
                
        }
        file.close();
    }
    return countryCode;
}

void PhoneScan::GlobalPhoneScan::downloadDatabases()
{
    //downloadFile("MAJPORTA.xls", "https://extranet.arcep.fr/portail/Portals/0/Documents/Arcep/Num%C3%A9rotation/MAJPORTA.xls?ver=2023-10-03-102152-350");
    //downloadFile("MAJNUM.xls", "https://extranet.arcep.fr/portail/Portals/0/Documents/Arcep/Num%C3%A9rotation/MAJNUM.xls?ver=2023-10-03-101653-427");
}

void PhoneScan::GlobalPhoneScan::downloadFile(std::string destination, std::string originUrl)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();                                                                                                                                                                                                                                                           
    if (curl)
    {   
        fp = fopen(destination.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, originUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }   
}

PhoneScan::GlobalPhoneScan::~GlobalPhoneScan()
{

}