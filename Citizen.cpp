#include "Citizen.h"
#include <iostream>

using std::string;

Citizen::Citizen(string first_, string last_, string SSN_)
:Person(first_, last_){
    SSN = SSN_;
}

string Citizen::get_SSN(){
    return SSN;
}

//setter for the SSN
void Citizen::set_SSN(string SSN_){
    SSN = SSN_;
}

//member function
string Citizen::SSN_check(){
    std::cout << " is a US citizen. Cleared to vote in the US election";
    return "\nBye!";
}
