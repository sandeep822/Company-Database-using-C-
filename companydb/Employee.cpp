#include "Employee.h"

#include "Person.h"
Employee::Employee():Person(){

}

Employee::Employee(const std::string& name,const std::string& email,const std::string& phone, const double& salary): Person(name,email,phone){
   // _name=name;
   // _email=email;
    //_phone=phone;
    _salary=salary;
}
double Employee::salary() const{
    return _salary;
}
void Employee::salary (const double& salary){
    _salary=salary;
}

