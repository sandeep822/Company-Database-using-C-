#include "Person.h"
#include<string>
Person::Person(){

}
Person::Person(const std::string& name, const std::string& email, const std::string& phone){
    _name=name;
    _email=email;
    _phone = phone;
}
std::string Person::name() const{
    return _name;
}
void Person::name(const std::string& name){
    _name=name;
}
std::string Person::email() const{
    return  _email;
}
void Person::email(const std::string& email){
    _email=email;
}
std::string Person::phone() const{
    return   _phone;
}
void Person::phone(const std::string& phone){
    _phone=phone;
}