#include "Customer.h"
#include "Purchase.h"

Customer::Customer() : Person(){

}
Customer::Customer(const std::string& name,const std::string& email,const std::string& phone):Person(name, email, phone){
    //_name=name;
    //_email=email;
    //_phone=phone;
}
void Customer::add_purchase(const Purchase& purchase){
    _history.push_back(purchase);

}
std::vector<Purchase>::iterator Customer::purchase_begin(){
    return  _history.begin();
}
std::vector<Purchase>::iterator Customer::purchase_end(){
    return   _history.end() ;
}

