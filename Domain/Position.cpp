#include <sstream>
#include "Position.h"

namespace rut::cip::paley
{
    Position::Position(const std::string & position)
        : position{ position }
    {
    }

    std::string Position::GetPosition() const noexcept
    {
        return this->position;
    }

    const std::weak_ptr<Employee>& Position::GetEmployees() const noexcept
    {
        return this->employee;
    }
    void Position::SetEmployee(std::weak_ptr<Employee> employee)
    {
        this->employee = employee;
    }

    std::string Position::ToString() const noexcept
    {
        std::stringstream buffer{};
        buffer << this->position;
        return buffer.str();
    }

    std::ostream& operator<<(std::ostream& out, const Position& position)
    {
        out << position.ToString();
        return out;
    }
}