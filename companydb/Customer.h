#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Purchase.h"
#include "Company.h"

#include <vector>
#include <string>

class Customer: public Person{

    private:
    std::vector<Purchase> _history;
    std::string _name;
    std::string _email;
    std::string _phone;

    public:
    Customer();
    Customer(const std::string& name,const std::string& email,const std::string& phone); 
    void add_purchase(const Purchase& purchase);
    std::vector<Purchase>::iterator purchase_begin();
    std::vector<Purchase>::iterator purchase_end();
};
#endif