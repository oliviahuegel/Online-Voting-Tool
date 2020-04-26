#ifndef Citizen_h
#define Citizen_h

#include <stdio.h>
#include <string>
#include "Person.h"

class Citizen: public Person{
private:
    std::string SSN;
public:
    //getter for the SSN
    std::string get_SSN();
    
    //setter for the SSN
    void set_SSN(std::string);
    
    //Citizen constructor (first, last, SSN)
    Citizen(std::string, std::string, std::string);
    
    //member function
    std::string SSN_check();
};
#endif /* Citizen_h */
