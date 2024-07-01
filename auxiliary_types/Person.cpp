#include "Person.h"

//---PersonID implementation---
PersonID::PersonID(std::string  series, std::string  number) :
        series(std::move(series)), number(std::move(number)) {}

std::string PersonID::GetSeries() const
{
    return series;
}

void PersonID::SetSeries(const std::string& newSeries)
{
    this->series = newSeries;
}

std::string PersonID::GetNumber() const
{
    return number;
}

void PersonID::SetNumber(const std::string& newNumber)
{
    this->number = newNumber;
}

//---Person implementation---
Person::Person() : birthDate(0) {}

Person::Person(PersonID  id,
               std::string firstName,
               std::string  middleName,
               std::string lastName,
               time_t birthDate) :
               id(std::move(id)),
               firstName(std::move(firstName)),
               middleName(std::move(middleName)),
               lastName(std::move(lastName)),
               birthDate(birthDate) {}

PersonID Person::GetID() const
{
    return id;
}

void Person::SetID(const PersonID& newID)
{
    id = newID;
}

std::string Person::GetFirstName() const
{
    return firstName;
}

void Person::SetFirstName(const std::string& newFirstName)
{
    firstName = newFirstName;
}

std::string Person::GetMiddleName() const
{
    return middleName;
}

void Person::SetMiddleName(const std::string& newMiddleName)
{
    middleName = newMiddleName;
}

std::string Person::GetLastName() const
{
    return lastName;
}

void Person::SetLastName(const std::string& newLastName)
{
    lastName = newLastName;
}

time_t Person::GetBirthDate() const
{
    return birthDate;
}

void Person::SetBirthDate(const time_t& newBirthDate)
{
    birthDate = newBirthDate;
}
