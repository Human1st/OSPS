#include <fstream>
#include <vector>

#include "FrancePhoneScan.hpp"
#include "utils/StringOperation.hpp"

PhoneScan::France::FrancePhoneScan::FrancePhoneScan(std::string folderBase)
{
    _rangesFile = folderBase+"/france/france_ranges.csv";
    _operatorsFile = folderBase+"/france/france_providers.csv";
}

PhoneScan::PhoneData PhoneScan::France::FrancePhoneScan::scan(std::string num)
{
    PhoneScan::PhoneData phoneData = PhoneScan::PhoneData();
    std::ifstream file(_rangesFile);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> splitedLine = StringOperation::split(line, ',');
            if (isInRange(num, splitedLine[1], splitedLine[2])) {
                phoneData.setRange(splitedLine[0]);
                phoneData.setOperator(findProviderName(splitedLine[3]));
                phoneData.setLocalisation(splitedLine[4]);
                phoneData.setAttributionDate(splitedLine[5]);
            }
        }
    }
    return phoneData;
}

std::string PhoneScan::France::FrancePhoneScan::findProviderName(std::string code)
{
    std::ifstream file(_operatorsFile);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> splitedLine = StringOperation::split(line, ',');
            if (splitedLine[0] == code)
                return splitedLine[1];
        }
        file.close();
    }
    return "PROVIDER_NOT_FOUND";
}

bool PhoneScan::France::FrancePhoneScan::isInRange(std::string phone, std::string rangeStart, std::string rangeStop)
{
    for (int i = 0; i != phone.length(); i++) {
        int digit = (int)phone.at(i) - 48;
        int digitStart = (int)rangeStart.at(i) - 48;
        int digitStop = (int)rangeStop.at(i) - 48;
        if (digit < digitStart || digit > digitStop)
            return false;
    }
    return true;
}

PhoneScan::France::FrancePhoneScan::~FrancePhoneScan()
{

}