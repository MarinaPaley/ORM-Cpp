#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Employee.h"

// many-to-many : employee <--> project

namespace rut::cip::paley
{
    class Project;

    std::ostream& operator <<(std::ostream& out, const Project& project);

    class Project
    {
    public:
        Project(const std::string& name);

        const std::vector<std::weak_ptr<Employee>>& GetEmployees() const noexcept;
        std::vector<std::weak_ptr<Employee>>& GetEmployees();

        std::string ToString() const noexcept;

    private:
        std::string name;
        std::vector<std::weak_ptr<Employee>> employees;
    };
}
