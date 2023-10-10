#pragma once
#include <memory>
#include <vector>
#include <string>
#include <ostream>
#include "Employee.h"

// many-to-one  : employee <--> Employer
namespace rut::cip::paley
{
    class Employer;
    std::ostream& operator<<(std::ostream& out, const Employer& employer);

    /**
     * @brief Работодатель.
    */
    class Employer
    {
    public:
        Employer(const std::string& name);

        const std::vector<std::weak_ptr<Employee>>& GetEmployees() const noexcept;
        std::vector<std::weak_ptr<Employee>>& GetEmployees();

        std::string ToString() const noexcept;

    private:
        std::string name;

        /**
         * @brief Сотрудники этого работодателя.
        */
        std::vector<std::weak_ptr<Employee>> employees;
    };
}
