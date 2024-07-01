#pragma once
#include <string>
#include <ctime>

//---PersonID declaration---
class PersonID
{
private:
    std::string series;
    std::string number;
public:
    //---Constructors---
    PersonID() = default;
    PersonID(std::string series, std::string number);
    //---Getters---
    [[nodiscard]] std::string GetSeries() const;
    [[nodiscard]] std::string GetNumber() const;
    //---Setters---
    void SetSeries(const std::string& newSeries);
    void SetNumber(const std::string& newNumber);
};

//---Person declaration---
class Person
{
private:
    PersonID id;
    std::string firstName;
    std::string middleName;
    std::string lastName;
    time_t birthDate;

public:
    //---Constructors---
    Person();
    Person(PersonID  id, std::string  firstName, std::string  middleName, std::string lastName, time_t birthDate);
    //---Getters---
    [[nodiscard]] PersonID GetID() const;
    [[nodiscard]] std::string GetFirstName() const;
    [[nodiscard]] std::string GetMiddleName() const;
    [[nodiscard]] std::string GetLastName() const;
    [[nodiscard]] time_t GetBirthDate() const;
    //---Setters---
    void SetID(const PersonID& newID);
    void SetFirstName(const std::string& newFirstName);
    void SetMiddleName(const std::string& newMiddleName);
    void SetLastName(const std::string& newLastName);
    void SetBirthDate(const time_t& newBirthDate);
};
