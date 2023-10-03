#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include "Person.h"

#include<string>

class Employee:public Person{

    private:
    double _salary;
    //std::string _name;
    //std::string _email;
    //std::string _phone;

    public:
    Employee(); 
    Employee(const std::string& name,const std::string& email,const std::string& phone, const double& salary); 
    double salary() const;
    void salary (const double& salary);

};

#endif