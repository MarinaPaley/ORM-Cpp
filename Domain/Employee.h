#pragma once
#include <memory>
#include <vector>
#include "Person.h"
#include "Employer.h"
#include "Position.h"
#include "Project.h"

// many-to-many : employee <--> project
// one-to-one   : employee <--> position

namespace rut::cip::paley
{
    class Employer;
    class Position;
    class Project;

    /**
     * @brief Сотрудник.
    */
    class Employee
    {
    public:
        Employee(const std::string& first,
            const std::string& last,
            short age,
            std::shared_ptr<Employer> employer,
            std::shared_ptr<Position> position);

        const std::string& GetFirstName() const noexcept;
        const std::string& GetLastName() const noexcept;

        unsigned short GetAge() const noexcept;
        void SetAge(const short age);

        const std::shared_ptr<Employer>& GetEmployer() const noexcept;
        void SetEmployer(std::shared_ptr<Employer> Employer);

        const std::shared_ptr<Position>& GePosition() const noexcept;
        void SetPosition(std::shared_ptr<Position> position);

        const std::vector<std::shared_ptr<Project>>& GetProjects() const noexcept;
        std::vector<std::shared_ptr<Project>>& GetProjects() noexcept;

        std::string ToString() const noexcept;
        friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

    private:
        std::string firstName;
        std::string lastName;
        unsigned short age;
        std::shared_ptr<Employer> employer;
        std::shared_ptr<Position> position;
        std::vector<std::shared_ptr<Project>> projects;
    };
}
