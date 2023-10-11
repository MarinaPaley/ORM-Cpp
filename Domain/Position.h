#pragma once
#include <memory>
#include <string>
#include "Employee.h"

// one-to-one   : employee <--> position
namespace rut::cip::paley
{
    class Employee;

    class Position;
    std::ostream& operator <<(std::ostream& out, const Position& position);

    class Position
    {
    public:
        Position(const std::string& position);
        const std::string GetPosition() const noexcept;

        const std::weak_ptr<Employee>& GetEmployees() const noexcept;

        void SetEmployee(std::weak_ptr<Employee> employee);

        std::string ToString() const noexcept;
    private:
        std::string position;

        /**
         * @brief Сотрудник, занимающий данную должность. Если свободна, то \c nullptr.
        */
        std::weak_ptr<Employee> employee;
    };
}

