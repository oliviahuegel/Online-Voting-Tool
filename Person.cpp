#include "Person.h"
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

using std::string;


//constructor
Person::Person(string first_, string last_){
    first = first_;
    last = last_;
}

//getters
string Person::get_first(){
    return first;
}
string Person::get_last(){
    return last;
}
string Person::get_month(){
    return month;
}
string Person::get_day(){
    return day;
}
string Person::get_year(){
    return year;
}

string Person::SSN_check(){
    std::cout << " is NOT a US citizen. Not cleared to vote in the US election";
    return "\nBye!";
}


//setters
void Person::set_first(string first_){
    first = first_;
}
void Person::set_last(string last_){
    last = last_;
}
void Person::set_month(string month_){
    month = month_;
}
void Person::set_day(string day_){
    day = day_;
}
void Person::set_year(string year_){
    year = year_;
}

//member function
string Person::full_name(string first, string last){
    string full_name = first + " " + last;
    return full_name;
}

string Person::full_DOB(string month, string day, string year){
    string full_DOB = month + " " + day + ", " + year;
    return full_DOB;
}
