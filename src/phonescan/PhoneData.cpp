#include "PhoneData.hpp"

PhoneScan::PhoneData::PhoneData(std::string range, std::string phoneOperator, std::string attributionDate)
{
    _range = range;
    _phoneOperator = phoneOperator;
    _attributionDate = attributionDate;
}

PhoneScan::PhoneData::PhoneData()
{
    _countryCode = PhoneScan::CountryCode();
    _range = "";
    _phoneOperator = "";
    _attributionDate = "";
}

std::string PhoneScan::PhoneData::getRange()
{
    return _range;
}

std::string PhoneScan::PhoneData::getOperator()
{
    return _phoneOperator;
}

std::string PhoneScan::PhoneData::getAttributionDate()
{
    return _attributionDate;
}

std::string PhoneScan::PhoneData::getLocalisation()
{
    return _localisation;
}

void PhoneScan::PhoneData::setRange(std::string range)
{
    _range = range;
}

void PhoneScan::PhoneData::setOperator(std::string phoneOperator)
{
    _phoneOperator = phoneOperator;
}

void PhoneScan::PhoneData::setAttributionDate(std::string attributionDate)
{
    _attributionDate = attributionDate;
}

void PhoneScan::PhoneData::setLocalisation(std::string localisation)
{
    _localisation = localisation;
}

std::string PhoneScan::PhoneData::toString()
{
    return "{\n\t\"countryCode\":\""+_countryCode.toString()+"\",\n\t\"range\":\""+_range+"\",\n\t\"operator\":\""+_phoneOperator+"\",\n\t\"attributionDate\":\""+_attributionDate+"\",\n\t\"localisation\":\""+_localisation+"\"\n}";
}

PhoneScan::PhoneData::~PhoneData()
{

}