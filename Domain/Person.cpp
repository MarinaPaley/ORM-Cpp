#include <stdexcept>
#include <sstream>
#include "Person.h"

rut::cip::paley::Person::Person(const std::string& first, const std::string& last, short age)
    : firstName{first}, lastName{last}
{
    this->SetAge(age);
}

rut::cip::paley::Person::~Person()
{
}

const std::string& rut::cip::paley::Person::GetFirstName() const noexcept
{
    return this->firstName;
}

const std::string& rut::cip::paley::Person::GetLastName() const noexcept
{
    return this->lastName;
}

unsigned short rut::cip::paley::Person::GetAge() const noexcept
{
    return this->age;
}

void rut::cip::paley::Person::SetAge(const short age)
{
    if (age < 0)
    {
        throw std::logic_error("Wrong age!");
    }

    this->age = age;
}

std::string rut::cip::paley::Person::ToString() const noexcept
{
    std::stringstream buffer{};
    buffer << this->GetFirstName() << " " << this->GetLastName() << " " << this->GetAge() << "\n";
    return buffer.str();
}

std::ostream& rut::cip::paley::operator<<(std::ostream& out, const Person& person)
{
    return out << person.ToString();
}
