#ifndef Person_h
#define Person_h

#include <stdio.h>
#include <string>
//#include <string.h>

class Person{
    //data members
private:
    std::string first;
    std::string last;
    std::string month;
    std::string day;
    std::string year;
    int SSN;
    
    
public:
    //getters
    std::string get_first();
    std::string get_last();
    std::string get_month();
    std::string get_day();
    std::string get_year();
    
    //virtual function to print an error message if the SSN is not 9 digits
    virtual std::string SSN_check();
    
    
    //setters
    void set_first(std::string);
    void set_last(std::string);
    void set_month(std::string);
    void set_day(std::string);
    void set_year(std::string);
    

    //member function
    std::string full_name(std::string first, std::string last);
    std::string full_DOB(std::string month, std::string day, std::string year);
    
    //person constructor declaration
    Person(std::string first, std::string last);
};
#endif /* Person_h */
