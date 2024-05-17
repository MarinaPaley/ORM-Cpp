#include <sstream>
#include <memory>
#include <vector>
#include "Employee.h"
#include "Employer.h"

namespace rut::cip::paley 
{
    Employee::Employee(
        const std::string& first, 
        const std::string& last, 
        short age, 
        std::shared_ptr<Employer> employer, 
        std::shared_ptr<Position> position)
       : firstName { first }, lastName{ last }, employer{ employer }, position{position}
    {
        this->SetAge(age);
    }

    const std::string& Employee::GetFirstName() const noexcept
    {
        return this->firstName;
    }

    const std::string& Employee::GetLastName() const noexcept
    {
        return this->lastName;
    }

    unsigned short Employee::GetAge() const noexcept
    {
        return this->age;
    }

    void Employee::SetAge(const short age)
    {

        if (age < 0)
        {
            throw std::logic_error("Неправильный возраст!");
        }

        this->age = age;
    }

    const std::shared_ptr<Employer>& Employee::GetEmployer() const noexcept
    {
        return this->employer;
    }

    void Employee::SetEmployer(std::shared_ptr<Employer> Employer)
    {
        this->employer = Employer;
    }

    const std::shared_ptr<Position>& Employee::GePosition() const noexcept
    {
        return this->position;
    }

    void Employee::SetPosition(std::shared_ptr<Position> position)
    {
        this->position = position;
    }

    const std::vector<std::shared_ptr<Project>>& Employee::GetProjects() const noexcept
    {
        return this->projects;
    }

    std::vector<std::shared_ptr<Project>>& Employee::GetProjects() noexcept
    {
        return this->projects;
    }

    std::string Employee::ToString() const noexcept
    {
        std::stringstream buffer{};
        buffer << this->GetFirstName() << " " << this->GetLastName() << " " << this->GetAge() << "\n";
        buffer << "Работодатель " << this->employer->ToString() << "\n";
        buffer << "Должность " << this->position->ToString() << "\n";

        buffer << "Проекты: " << "\n\t{ ";
        for (auto it = this->GetProjects().cbegin(); it != this->GetProjects().cend(); ++it)
        {
            buffer << (*it)->ToString() << " ";
        }
        buffer << " }\n";

        return buffer.str();
    }

    std::ostream& operator<<(std::ostream& out, const Employee& employee)
    {
        out << employee.ToString();
        return out;
    }
}