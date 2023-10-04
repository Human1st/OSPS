#include "CountryCode.hpp"

PhoneScan::CountryCode::CountryCode()
{

}

void PhoneScan::CountryCode::setCountryCode(std::string countryCode)
{
    _countryCode = countryCode;
}

void PhoneScan::CountryCode::setCountryPrefix(std::string countryPrefix)
{
    _countryPrefix = countryPrefix;
}

void PhoneScan::CountryCode::setCountryName(std::string countryName)
{
    _countryName = countryName;
}

std::string PhoneScan::CountryCode::getCountryCode()
{
    return _countryCode;
}

std::string PhoneScan::CountryCode::getCountryPrefix()
{
    return _countryPrefix;
}

std::string PhoneScan::CountryCode::getCountryName()
{
    return _countryName;
}

std::string PhoneScan::CountryCode::toString()
{
    return "{\n\t\"countryCode\":\""+_countryCode+"\",\n\t\"countryPrefix\":\""+_countryPrefix+"\",\n\t\"countryName\":\""+_countryName+"\",\n}";
}

PhoneScan::CountryCode::~CountryCode()
{

}