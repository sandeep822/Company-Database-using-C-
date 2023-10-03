#ifndef PERSON_H
#define	PERSON_H



#include <string>

class Person{
    private:
    std::string _name;
    std::string _email;
    std::string _phone;

    public:
    Person();
    Person(const std::string& name, const std::string& email, const std::string& phone);
    std::string name() const;
    void name(const std::string& name);
    std::string email() const;
    void email(const std::string& email);
    std::string phone() const;
    void phone(const std::string& phone);


};
#endif