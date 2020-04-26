#ifndef Amendments_h
#define Amendments_h

#include <stdio.h>
#include <string>
#include <iostream>

class Amendments{
private:
    std::string am1;
    char am1_char;
    char am2_char;
public:
    static int count_yes;
    static int count_no;
    //getters to get the candidate names from the text file
    std::string get_am1(std::string filename);
    
     //member function
    static void total(char count){
        //count
            if(tolower(count) == 'y'){
                Amendments::count_yes++;
            }
            else if (tolower(count) == 'n') {
                Amendments::count_no++;
            }
    }//closes total member function
    
    //member function
    friend void print(Amendments count){
        if(Amendments::count_yes == 3)
            std::cout << "2 yeses";
        else if(Amendments::count_no == 2)
            std::cout << "2 no's";
        else
            std::cout << "1 yes, 1 no";
    }
    
    //member function am1
    void display_am1(){
        if(am1_char == 'y')
            std::cout << "1. yes";
        else
            std::cout << "1. no";
    }

    void display_am2(){
        if(am2_char == 'y')
            std::cout << "2. yes";
        else
            std::cout << "2. no";
    }
    
    //istream overload
    friend std::istream& operator >> (std::istream& in_key, Amendments& am){
        std::cout << "Please indicate yes (y) or no (n) on 1: ";
        in_key >> am.am1_char;
        in_key.ignore(100, '\n');
        
        //input validation
        while(am.am1_char != 'y' && am.am1_char != 'n'){
            std::cout << "Invalid input. Please indicate yes (y) or no (n) on 1: ";
            in_key >> am.am1_char;
            in_key.clear();
            in_key.ignore(100, '\n');
        }
        
        am.total(am.am1_char);
            
        std::cout << "Please indicate yes (y) or no (n) on 2: ";
        in_key >> am.am2_char;
            
        //input validation
        while(am.am2_char != 'y' && am.am2_char != 'n'){
            std::cout << "Invalid input. Please indicate yes (y) or no (n) on 2: ";
            in_key >> am.am2_char;
            in_key.clear();
            in_key.ignore(100, '\n');
        }
        
        am.total(am.am2_char);
        
        std::cout << "________________________________________________________________________________________" << std::endl;
        std::cout << "You have successfully completed voting in the 2019 Florida Election. Here is a summary of your votes today.\n";
        std::cout << "________________________________________________________________________________________" << std::endl;
        
        return in_key;
    }//closes istream
    
};//closes the class
#endif /* Amendments_h */
