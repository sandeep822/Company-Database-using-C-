#include<string>

#include "fstream" 
#include "vector" 
#include "iomanip" 
#include "Customer.h" 
#include "Company.h" 
#include "Employee.h" 
#include "iostream"

using namespace std;

void  displayemployee(Company& company)
{
    for( auto std::vector<Employee>::iterator itr=company.employee_begin();itr!=company.employee_end();itr++)
    {
        cout<<itr->name()<<" <"<<itr->email()<<"> Phone: "<<itr->phone()<<" Salary: $"<<std::fixed << std::setprecision(2)<<itr->salary()<<endl;
    }
}
 int main()
{
    string name;
    cout<< "Company Name:";
    cin>>name;
    cout << endl ;
    Company company(name);
    
    ifstream employees(company.name() + ".dat");
    if (!employees.is_open()) {
        ofstream employees(company.name() + ".dat");    
    }
    else{

    //employees
    int no_of_employees;
    employees >> no_of_employees;
    for (int i = 0; i < no_of_employees; i++) {
        string name, email, phone;
        double salary;
        employees.ignore(); 
        getline(employees, name);  
        employees >> email >> phone >> salary;
        //employees.ignore(); 
        Employee employee(name, email, phone, salary);
        company.add_employee(employee);
    }

    //customers
    int no_of_customers;
    employees >> no_of_customers; 
    for (int i = 0; i < no_of_customers; i++) {
        string name, email, phone;
        employees.ignore(); 
        getline(employees, name); 
        employees >> email >> phone;

        //purchases
        int no_of_purchases;
        employees >> no_of_purchases; 
        Customer customer(name, email, phone);
    
        for (int j = 0; j < no_of_purchases; j++) {
            string item;
            int quantity;
            double cost;
            employees.ignore(); 
            getline(employees, item); 
            employees  >> quantity >> cost  ;
            Purchase purchase(item, quantity, cost);
            customer.add_purchase(purchase);
        }
        company.add_customer(customer);
    }
    }

    while(1){
        cout<<"MAIN MENU "<<endl;
        cout<<"1.) Employees"<<endl;
        cout<<"2.) Sales"<<endl;
        cout<<"3.) Quit"<<endl;
        cout<<endl<<"choice? ";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            while(1){
            displayemployee(company);
            cout<<"(A)dd Employee or (M)ain Menu? ";
            char ch;
            cin >>ch;
            if(ch=='M')
            {
                break;
            }
            else if(ch=='A')
            {
                string name,email,phone;
                double salary;
                cout<<"Name: ";
                cin.ignore();
                std::getline(std::cin, name);

                //cout<<endl;
                cout<<"Email: ";
                cin>> email;
                //cout<<endl;
                cout<<"Phone: ";
                cin>> phone;
                //cout<<endl;
                cout<<"Salary: ";
                cin>> salary;
                //cout<<endl;
                Employee employee(name, email, phone, salary);
                company.add_employee(employee);
            }
            else{
                cout<<"Error: choice"<<endl;
                break;
            }
        
          }
        }
        else if(choice==2)
        {
            while(1)
            {
                cout<<"(A)dd Customer, Enter a (S)ale, (V)iew Customer, or (M)ain Menu? ";
                char ch2;
                cin>>ch2;
                if(ch2=='M')
                {
                    break;
                }
                else if(ch2=='A')
                {
                    string name2,email2,phone2;
                    cout<<"Name: ";
                    cin.ignore();
                    std::getline(std::cin, name2);
                    
                    cout<<"Email: ";
                    cin >> email2;
                    
                    cout <<"Phone: ";
                    cin >> phone2;
                    
                    Customer customer(name2 , email2, phone2 );
                    company.add_customer(customer);
                }
                else if(ch2=='S')
                {
                    int i = 1;
                    for (auto std::vector<Customer>::iterator itr2 = company.customer_begin();itr2 != company.customer_end(); itr2++) 
                    {
                        cout << i;
                        cout << ".) ";
                        cout << itr2->name() << endl;
                        i++;
                    }
                    if(i==1)
                    {
                        cout<<"Error: No Customers."<<endl;
                    }
                    else{
                        cout << "Choice? ";
                        int choice2;
                        cin >>choice2 ;
                        cout<<endl;
                        string item2;
                        int quantity2;
                        double cost2;
                        cout<<"Item: ";
                        cin.ignore();
                        std::getline(std::cin, item2);
                        cout<<endl;
                        cout<<"Quantity:";
                        cin>>quantity2;
                        cout<<endl;
                        cout<<"Cost: ";
                        cin>>cost2;
                        cout<<endl;
                        int j=1;
                        std::vector<Customer>::iterator itr22 = company.customer_begin()+choice2-1;
                        Purchase purchase(item2, quantity2, cost2);
                        itr22->add_purchase(purchase);
                    }
                }
                else if(ch2=='V')
                {
                    int i = 1;
                    for (auto std::vector<Customer>::iterator itr3 = company.customer_begin();itr3 != company.customer_end(); itr3++) 
                    {
                        cout << i;
                        cout << ".) ";
                        cout << itr3->name() << endl;
                        i++;
                    }
                    if(i==1)
                    {
                        cout<<"Error: No Customers."<<endl;
                    }
                    else
                    {
                    cout << "Choice? ";
                    int choice3;
                    cin >>choice3 ;
                    cout<<endl;
                    cout << setprecision(2) << fixed;
                    std::vector<Customer>::iterator itr33=company.customer_begin() +choice3-1;
                    
                        cout << itr33 -> name() << " <" << itr33->email() << "> " << "Phone: " <<itr33->phone() << endl;
                        cout << endl;
                        cout << "Order History"<<endl;
                        cout  <<std::left<< std::setw(27)<< "Item" << setw(8) << "Price" << setw(10) << "Quantity" << setw(8) << "Total" << endl;
                        for(auto std::vector<Purchase>::iterator itr4=itr33->purchase_begin();itr4!=itr33->purchase_end();itr4++){
                        cout <<std::left<< std::setw(27)<< itr4->item() << setw(8) << itr4->cost() << setw(10) << itr4->qty() << setw(8) << itr4->total() << endl;
                       }    
                    cout<<endl;
                    }
    
                }
                else if (choice == 'M') {
                    break;
                }
                else {
                    break;
                }
            }
                
        }
        else if(choice==3)
        {
            ifstream employees(company.name() + ".dat");
           if(employees.is_open())
           {
            std::ofstream employees(company.name() + ".dat");
            //int  num_of_employees= company.employee_end() - company.employee_begin();
            std::vector<Employee> employee;
            employees << company.employee_end() - company.employee_begin() << endl;
            for(auto std::vector<Employee>::iterator employee_itr=company.employee_begin();employee_itr!=company.employee_end();employee_itr++){
                employees << employee_itr->name()<<endl;
                employees << employee_itr->email()<<endl;
                employees << employee_itr->phone()<<endl;
                employees << employee_itr->salary()<<endl;
            }
            
            std::vector<Customer> customer;
            employees << company.customer_end() - company.customer_begin() << endl;
            //int number_of_customers = company.customer_end() - company.customer_begin();
            
            for(auto std::vector<Customer>::iterator customer_itr=company.customer_begin();customer_itr!=company.customer_end();customer_itr++)
            {
                employees << customer_itr->name()<<endl;
                employees << customer_itr->email()<<endl;
                employees << customer_itr->phone()<<endl;
                std::vector<Purchase> purchase;
                //int number_of_purchases = customer_itr->purchase_end() - customer_itr->purchase_begin();
                employees << customer_itr->purchase_end() - customer_itr->purchase_begin() << endl; 
                
                    for(auto std::vector<Purchase>::iterator purchase_itr=customer_itr->purchase_begin();purchase_itr!=customer_itr->purchase_end();purchase_itr++){
                        employees << purchase_itr->item()<<endl;
                        employees << purchase_itr->qty()<<endl;
                        employees << purchase_itr->cost()<<endl;
                        
                    }
            }
            
            
            employees.close();
           }
           else{
            cout<<"file is created but not opened";
           }
            return 0;
    
        }
        else{
            cout<<"Error: choice"<<endl;
            //break;
        }
    
    }
 
return 0;
}



