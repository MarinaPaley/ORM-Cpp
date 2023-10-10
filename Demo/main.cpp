#include <iostream>
#include <memory>
#include "..\Domain\Employee.h"
#include "..\Domain\Employer.h"
#include "..\Domain\Position.h"
#include "..\Domain\Project.h"

using namespace rut::cip::paley;
using namespace std;

int main()
{
    // Simple Tech Ltd.
    shared_ptr<Employer> er(new Employer("Simple Tech Ltd"));

    shared_ptr<Position> he(new Position("Hardware Engineer"));
    shared_ptr<Position> se(new Position("Software Engineer"));

    shared_ptr<Project> sh(new Project("Simple Hardware"));
    shared_ptr<Project> ss(new Project("Simple Software"));

    shared_ptr<Employee> john(new Employee("John", "Doe", 25, er, he));
    shared_ptr<Employee> jane(new Employee("Jane", "Doe", 30, er, se));

    // Set the inverse side of the employee-Employer relationship.
    //
    er->GetEmployees().push_back(john);
    er->GetEmployees().push_back(jane);

    // Set the inverse side of the employee-position relationship.
    //
    he->SetEmployee(john);
    se->SetEmployee(jane);

    // Set the employee-project relationship (both directions).
    //
    john->GetProjects().push_back(sh);
    john->GetProjects().push_back(ss);
    jane->GetProjects().push_back(ss);

    sh->GetEmployees().push_back(john);
    ss->GetEmployees().push_back(john);
    ss->GetEmployees().push_back(jane);

    std::cout << john << "\n" << jane << "\n";

    shared_ptr<Employer> complexSystems(new Employer("Complex Systems Inc"));

    shared_ptr<Position> hardware(new Position("Hardware Engineer"));
    shared_ptr<Position> software(new Position("Software Engineer"));

    shared_ptr<Project> complexHardware(new Project("Complex Hardware"));
    shared_ptr<Project> complesSoftware(new Project("Complex Software"));

    shared_ptr<Employee> johnSmith(new Employee("John", "Smith", 32, complexSystems, software));
    shared_ptr<Employee> janeSmith(new Employee("Jane", "Smith", 35, complexSystems, hardware));

    // Set the inverse side of the employee-employer relationship.
    //
    complexSystems->GetEmployees().push_back(john);
    complexSystems->GetEmployees().push_back(jane);

    // Set the inverse side of the employee-position relationship.
    //
    hardware->SetEmployee(johnSmith);
    software->SetEmployee(janeSmith);

    // Set the employee-project relationship (both directions).
    //
    johnSmith->GetProjects().push_back(complesSoftware);
    janeSmith->GetProjects().push_back(complexHardware);
    janeSmith->GetProjects().push_back(complesSoftware);

    complexHardware->GetEmployees().push_back(janeSmith);
    complesSoftware->GetEmployees().push_back(johnSmith);
    complesSoftware->GetEmployees().push_back(janeSmith);

    std::cout << johnSmith << "\n" << janeSmith << "\n";

    return 0;
}