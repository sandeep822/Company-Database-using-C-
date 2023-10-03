#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"
#include "Customer.h"


#include <vector>
#include <string>
class Employee; 
class Customer;

class Company {
private:
    std::vector<Employee> _employees;
    std::vector<Customer> _customers;
    std::string _name;
public:
    Company(const std::string& name);
    std::string name() const;
    void add_employee(const Employee& employee);
    void add_customer(const Customer& customer);
    std::vector<Employee>::iterator employee_begin();
    std::vector<Employee>::iterator employee_end();
    std::vector<Customer>::iterator customer_begin();
    std::vector<Customer>::iterator customer_end();
};
#endif


