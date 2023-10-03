#include "Company.h"
#include "Employee.h" 
#include "Customer.h" 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Company::Company(const std::string& name){
    _name = name;
}

std::string Company::name() const{
    return _name;
}

    void Company::add_employee(const Employee& employee){
        _employees.push_back(employee);
    }
    void Company::add_customer(const Customer& customer){
        _customers.push_back(customer);
    }

    std::vector<Employee>::iterator Company::employee_begin(){
        return _employees.begin();
    }
    std::vector<Employee>::iterator Company::employee_end(){
        return _employees.end();
    }
    std::vector<Customer>::iterator Company::customer_begin(){
        return _customers.begin();

    }
    std::vector<Customer>::iterator Company::customer_end()
    {
        return _customers.end();
    }



