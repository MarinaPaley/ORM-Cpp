#include <sstream>
#include "Employer.h"
namespace rut::cip::paley
{
    Employer::Employer(const std::string& name)
        : name{name}
    {
    }

    const std::vector<std::weak_ptr<Employee>>& Employer::GetEmployees() const noexcept
    {
        return this->employees;
    }

    std::vector<std::weak_ptr<Employee>>& Employer::GetEmployees()
    {
        return this->employees;
    }

    std::string Employer::ToString() const noexcept
    {
        std::stringstream buffer{};
        buffer << this->name << "\n{ ";
       
        return buffer.str();
    }

    std::ostream& operator<<(std::ostream& out, const Employer& employer)
    {
        out << employer.ToString();
        return out;
    }
}