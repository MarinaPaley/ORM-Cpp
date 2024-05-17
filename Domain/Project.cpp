#include <sstream>
#include "Project.h"

namespace rut::cip::paley 
{
    Project::Project(const std::string& name)
        :name{ name }
    {
    }

    const std::vector<std::weak_ptr<Employee>>& Project::GetEmployees() const noexcept
    {
        return this->employees;
    }

    std::vector<std::weak_ptr<Employee>>& Project::GetEmployees()
    {
        return this->employees;
    }

    std::string Project::ToString() const noexcept
    {
        std::stringstream buffer{};
        buffer << this->name;
        return buffer.str();
    }

    std::ostream& operator<<(std::ostream& out, const Project& project)
    {
        out << project.ToString();
        return out;
    }
}