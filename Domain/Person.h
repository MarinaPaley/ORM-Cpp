#pragma once
#include <string>
#include <ostream>
namespace rut::cip::paley
{
    class Person;
    std::ostream& operator <<(std::ostream& out, const Person& person);

    class Person
    {
    public:
        Person(const std::string& first,
            const std::string& last,
            short age);

        const std::string& GetFirstName() const noexcept;
        const std::string& GetLastName() const noexcept;

        unsigned short GetAge() const noexcept;
        void SetAge(const short age);

        std::string ToString() const noexcept;

        virtual ~Person() = 0;

    private:
        std::string firstName;
        std::string lastName;
        unsigned short age;
    };
}