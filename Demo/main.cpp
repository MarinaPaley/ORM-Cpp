#include <iostream>
#include <memory>
#include <locale>
#include "../Domain/Employee.h"
#include "../Domain/Employer.h"
#include "../Domain/Position.h"
#include "../Domain/Project.h"

// The employee class holds shared pointers
// to employer, position, and projects. All other objects hold weak
// pointers back to the employee object. The weak sides are also the
// ones that are made inverse.
//
// The following bidirectional relationships are used:
//
// many-to-one  : employee <--> employer
// one-to-one   : employee <--> position
// many-to-many : employee <--> project

using namespace rut::cip::paley;
using namespace std;

int main()
{
    //setlocale(LC_ALL, "ru");
    // Simple Tech Ltd.
    auto simpleTech(std::make_shared<Employer>("Simple Tech Ltd"));

    auto hardwareEngeneering(std::make_shared<Position>("Hardware Engineer"));
    auto softwareEngeneering(std::make_shared<Position>("Software Engineer"));

    auto simpleHardware(std::make_shared<Project>("Simple Hardware"));
    auto simpleSoftware(std::make_shared<Project>("Simple Software"));

    auto john(std::make_shared<Employee>("John", "Doe", 25, simpleTech, hardwareEngeneering));
    auto jane(std::make_shared<Employee>("Jane", "Doe", 30, simpleTech, softwareEngeneering));

    // Set the inverse side of the employee-Employer relationship.
    //
    simpleTech->GetEmployees().push_back(john);
    simpleTech->GetEmployees().push_back(jane);

    // Set the inverse side of the employee-position relationship.
    //
    hardwareEngeneering->SetEmployee(john);
    softwareEngeneering->SetEmployee(jane);

    // Set the employee-project relationship (both directions).
    //
    john->GetProjects().push_back(simpleHardware);
    john->GetProjects().push_back(simpleSoftware);
    jane->GetProjects().push_back(simpleSoftware);

    simpleHardware->GetEmployees().push_back(john);
    simpleSoftware->GetEmployees().push_back(john);
    simpleSoftware->GetEmployees().push_back(jane);

    std::cout << *john << "\n" << *jane << "\n";

    auto complexSystems(std::make_shared<Employer>("Complex Systems Inc"));

    auto hardware(std::make_shared<Position>("Hardware Engineer"));
    auto software(std::make_shared<Position>("Software Engineer"));

    auto complexHardware(std::make_shared<Project>("Complex Hardware"));
    auto complesSoftware(std::make_shared<Project>("Complex Software"));

    auto johnSmith(std::make_shared<Employee>("John", "Smith", 32, complexSystems, software));
    auto janeSmith(std::make_shared<Employee>("Jane", "Smith", 35, complexSystems, hardware));

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

    std::cout << *johnSmith << "\n" << *janeSmith << "\n";

    return 0;
}