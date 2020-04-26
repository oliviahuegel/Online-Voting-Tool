/*
 *Name: Olivia Huegel
 *Purpose: This program is an online voting tool for the state of Florida.
 *The program allows a user to vote in a Florida election if they are a
 *United States citizen. The user can vote on the President, the Senator,
 *a City Council Representative, and two Amendments.
 */
#include <iostream>
#include <string>
#include "Person.h"
#include "Citizen.h"
#include <iomanip>
#include <fstream>
#include "Candidates.h"
#include "Amendments.h"

using namespace std;

//polymorphism
void polymorphism(Person &p){
    p.SSN_check();
}
int main() {
    string first, last, month, day, year, SSN;
    //int county, role;
    double role;
    double county;
    string temp_name;
    vector<string> roles;
    char p_char = '\0', sen_char = '\0', cc_char = '\0';
    
    cout << "Welcome to the state of Florida Online Voting System!" << endl
         << "Please enter your name, date of birth, and social security number below." << endl;
    
    cout << "\nFirst name: ";
    cin >> first;
    
    cout << "Last name: ";
    cin.ignore(100, '\n');
    cin >> last;
    
    cout << "Month: ";
    cin.ignore(100, '\n');
    cin >> month;
    
    cout << "Day: ";
    cin.ignore(100, '\n');
    cin >> day;
    
    cout << "Year: ";
    cin.ignore(100, '\n');
    cin >> year;
    
    cout << "SSN: ";
    cin >> SSN;
    
    //objects
    Person p(first, last);
    Citizen c(first, last, SSN);
    
    if(SSN.length() != 9){
        cout << p.full_name(first, last);
        polymorphism(p);
    }
    else{
        cout << c.full_name(first, last);
        polymorphism(c);
        
        cout << "\nWelcome " << p.get_first() << "! Please input the corresponding number of your county from the list below:" << endl;
        
        ifstream input_file;
        vector<string> my_vector;
        input_file.open("counties.txt");
        if(input_file){
            while(!input_file.eof()){
                getline(input_file, temp_name, '\t');
                my_vector.push_back(temp_name);
            }
        }
        
        /***************/
        //Display Counties *(there was a memory issue when I printed out the counties
        //in one single for loop where the program would sometimes return garbage
        //values, so I had to split it into several for loops to display the rows.)
        for(int i = 0; i < 5; ++i){
           //17 minimum
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 5; i < 10; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 10; i < 15; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 15; i < 20; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 20; i < 25; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 25; i < 30; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 30; i < 35; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 35; i < 40; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 40; i < 45; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 45; i < 50; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 50; i < 55; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 55; i < 60; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 60; i < 65; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        for(int i = 65; i < 67; ++i){
            cout << left  << setw(17) << my_vector[i];
        }
        cout << endl;
        /**************/
        
        do{
            try{
                cout << "\nCounty number: ";
                cin >> county;
                
                //if true, throw
                if(cin.fail()){
                    throw invalid_argument("Invalid county number. Please enter a valid county number: ");
                }
                else if (!(county >= 1 && county <= 67)){
                    throw invalid_argument("Invalid county number. Please enter a valid county number: ");
                }
                else{
                    cin.ignore();
                    cin.clear();
                    break;
                }

            }//closes try
            catch(const exception& e){
                cout << e.what();
                cin.clear();
                cin.ignore(1000, '\n');
            }//closes catch
            
        }while(true);
        
        cout << my_vector[county-1] << " county. You will be voting for items on the ballot in this order:"
             << endl << "a. Candidates and Roles"
             << endl << "b. Amendments"
             << endl << "Now voting for: Candidates and Roles."
             << endl;
        
        //object
        Candidates can = Candidates();
        
        //opens the txt files and reads every line into a different vector
        vector<string> print_p = can.get_P_VP("presidents.txt");
        vector<string> print_s = can.get_Senator("senators.txt");
        vector<string> print_cc = can.get_City_Council("city_council.txt");
        
        //the vector "roles" is now filled with 3 things
        roles.push_back("President and Vice President of the United States");
        roles.push_back("United States Senator");
        roles.push_back("City Council Representative");
        
        /***************/
        while(roles.size() != 0){
            //cout << "\nVector size: " << roles.size() << endl;
            cout << "\nTo vote for a candidate, please indicate the number of the corresponding role from the list below:";
            //prints out the vector of roles
            cout << endl;
            
            for(int i = 0; i < roles.size(); i++){
                cout << (i+1) << ". " << roles[i] << endl;
            }
             
            do{
            try{
                //cout << "Role (1-3): ";
                cin >> role;
                
                //if true, throw
                if(cin.fail()){
                    throw invalid_argument("Invalid input. Please input the letter of the corresponding role: ");
                }
                else if(role != 1 && role != 2 && role != 3){
                    throw invalid_argument("Invalid input. Please input the letter of the corresponding role: ");
                }
                else if (role > roles.size()){
                    throw invalid_argument("Invalid input. Please input the letter of the corresponding role: ");
                }
                else{
                    cin.ignore();
                    cin.clear();
                    break;
                }
            }//closes try
                
            catch(const exception& e){
                cout << e.what();
                cin.clear();
                cin.ignore(1000, '\n');
            }//closes catch
            }while(true);
            
            //if the vector is full
            if(roles.size() == 3){
                if(role == 1){
                    for(int i = 0; i < 4; i++){
                    cout << print_p[i] << endl;
                    }
                    //lets the user vote for presidents
                    cin >> p_char;
                    while(p_char != 'a' && p_char != 'b' && p_char != 'c' && p_char != 'd'){
                        cout << "Invalid input. Please try again: ";
                        cin >> p_char;
                        cin.ignore(100, '\n');
                    }
                    cout << "You just cast your vote for: ";
                    if(p_char == 'a')
                        cout << print_p[0];
                    else if(p_char == 'b')
                        cout << print_p[1];
                    else if(p_char == 'c')
                        cout << print_p[2];
                    else if(p_char == 'd')
                        cout << print_p[3];
                }
                else if(role == 2){
                    for(int i = 0; i < 7; i++){
                        cout << print_s[i] << endl;
                    }
                    //lets the user vote for senators
                    cin >> sen_char;
                    while(sen_char != 'a' && sen_char != 'b' && sen_char != 'c' && sen_char != 'd' && sen_char != 'e' && sen_char != 'f' && sen_char != 'g'){
                        cout << "Invalid input. Please try again: ";
                        cin >> sen_char;
                        cin.ignore(100, '\n');
                    }
                    cout << "You just cast your vote for: ";
                    if(sen_char == 'a')
                        cout << print_s[0];
                    else if(sen_char == 'b')
                        cout << print_s[1];
                    else if(sen_char == 'c')
                        cout << print_s[2];
                    else if(sen_char == 'd')
                        cout << print_s[3];
                    else if(sen_char == 'e')
                        cout << print_s[4];
                    else if(sen_char == 'f')
                        cout << print_s[5];
                    else if(sen_char == 'g')
                        cout << print_s[6];
                }

                else if(role == 3){
                    for(int i = 0; i < 2; i++){
                        cout << print_cc[i] << endl;
                    }
                    //lets the user vote for city council
                    cin >> cc_char;
                    while(cc_char != 'a' && cc_char != 'b'){
                        cout << "Invalid input. Please try again: ";
                        cin >> cc_char;
                        cin.ignore(100, '\n');
                    }
                    cout << "You just cast your vote for: ";
                    if(cc_char == 'a')
                        cout << print_cc[0];
                    else if(cc_char == 'b')
                        cout << print_cc[1];
                }
            }
            
            //if 2 elements in vector
            if(roles.size() == 2){
                //checks what the first element is
                //if first element is president (TWO POSSIBILITIES)
                if(find(roles.begin(), roles.end(), "President and Vice President of the United States") != roles.end()){
                    //president
                    if(role == 1){
                        for(int i = 0; i < 4; i++){
                            cout << print_p[i] << endl;
                        }
                        //lets the user vote for presidents
                        cin >> p_char;
                        while(p_char != 'a' && p_char != 'b' && p_char != 'c' && p_char != 'd'){
                            cout << "Invalid input. Please try again: ";
                            cin >> p_char;
                            cin.ignore(100, '\n');
                        }
                        cout << "You just cast your vote for: ";
                        if(p_char == 'a')
                            cout << print_p[0];
                        else if(p_char == 'b')
                            cout << print_p[1];
                        else if(p_char == 'c')
                            cout << print_p[2];
                        else if(p_char == 'd')
                            cout << print_p[3];
                    }
                    //could be either senator or cc (TWO POSSIBILITIES)
                    if(role == 2){
                        //senator
                        if(find((roles.begin() + roles.size() - 1), roles.end(), "United States Senator") != roles.end()){
                            for(int i = 0; i < 7; i++){
                                cout << print_s[i] << endl;
                            }
                            //lets the user vote for senators
                            cin >> sen_char;
                            while(sen_char != 'a' && sen_char != 'b' && sen_char != 'c' && sen_char != 'd' && sen_char != 'e' && sen_char != 'f' && sen_char != 'g'){
                                cout << "Invalid input. Please try again: ";
                                cin >> sen_char;
                                cin.ignore(100, '\n');
                            }
                            cout << "You just cast your vote for: ";
                            if(sen_char == 'a')
                                cout << print_s[0];
                            else if(sen_char == 'b')
                                cout << print_s[1];
                            else if(sen_char == 'c')
                                cout << print_s[2];
                            else if(sen_char == 'd')
                                cout << print_s[3];
                            else if(sen_char == 'e')
                                cout << print_s[4];
                            else if(sen_char == 'f')
                                cout << print_s[5];
                            else if(sen_char == 'g')
                                cout << print_s[6];
                        }
                        //cc
                        else if(find((roles.begin() + roles.size() - 1), roles.end(), "City Council Representative") != roles.end()){
                            for(int i = 0; i < 2; i++){
                                cout << print_cc[i] << endl;
                            }
                            //lets the user vote for city council
                            cin >> cc_char;
                            while(cc_char != 'a' && cc_char != 'b'){
                                cout << "Invalid input. Please try again: ";
                                cin >> cc_char;
                                cin.ignore(100, '\n');
                            }
                            cout << "You just cast your vote for: ";
                            if(cc_char == 'a')
                                cout << print_cc[0];
                            else if(cc_char == 'b')
                                cout << print_cc[1];
                        }
                    }//closes user picks 2nd
                }//closes first element president
                
                //if first element is senator
                else if(find(roles.begin(), roles.end(), "United States Senator") != roles.end()){
                    if(role == 1){
                        for(int i = 0; i < 7; i++){
                            cout << print_s[i] << endl;
                        }
                        //lets the user vote for senators
                        cin >> sen_char;
                        while(sen_char != 'a' && sen_char != 'b' && sen_char != 'c' && sen_char != 'd' && sen_char != 'e' && sen_char != 'f' && sen_char != 'g'){
                            cout << "Invalid input. Please try again: ";
                            cin >> sen_char;
                            cin.ignore(100, '\n');
                        }
                        cout << "You just cast your vote for: ";
                        if(sen_char == 'a')
                            cout << print_s[0];
                        else if(sen_char == 'b')
                            cout << print_s[1];
                        else if(sen_char == 'c')
                            cout << print_s[2];
                        else if(sen_char == 'd')
                            cout << print_s[3];
                        else if(sen_char == 'e')
                            cout << print_s[4];
                        else if(sen_char == 'f')
                            cout << print_s[5];
                        else if(sen_char == 'g')
                            cout << print_s[6];
                    }
                    else if(role == 2){
                        for(int i = 0; i < 2; i++){
                            cout << print_cc[i] << endl;
                        }
                        //lets the user vote for city council
                        cin >> cc_char;
                        while(cc_char != 'a' && cc_char != 'b'){
                            cout << "Invalid input. Please try again: ";
                            cin >> cc_char;
                            cin.ignore(100, '\n');
                        }
                        cout << "You just cast your vote for: ";
                        if(cc_char == 'a')
                            cout << print_cc[0];
                        else if(cc_char == 'b')
                            cout << print_cc[1];
                    }
                }//closes first element senator
                
            }//closes vector size = 2
            
            //if vector size 1
            if(roles.size() == 1){
                //last element is president
                if(find(roles.begin(), roles.end(), "President and Vice President of the United States") != roles.end()){
                    //president
                    for(int i = 0; i < 4; i++){
                        cout << print_p[i] << endl;
                    }
                    cin >> p_char;
                    while(p_char != 'a' && p_char != 'b' && p_char != 'c' && p_char != 'd'){
                        cout << "Invalid input. Please try again: ";
                        cin >> p_char;
                        cin.ignore(100, '\n');
                    }
                    cout << "You just cast your vote for: ";
                    if(p_char == 'a')
                        cout << print_p[0];
                    else if(p_char == 'b')
                        cout << print_p[1];
                    else if(p_char == 'c')
                        cout << print_p[2];
                    else if(p_char == 'd')
                        cout << print_p[3];
                    break;
                }
                
                //last element is senator
                else if(find(roles.begin(), roles.end(), "United States Senator") != roles.end()){
                    for(int i = 0; i < 7; i++){
                        cout << print_s[i] << endl;
                    }
                    cin >> sen_char;
                    while(sen_char != 'a' && sen_char != 'b' && sen_char != 'c' && sen_char != 'd' && sen_char != 'e' && sen_char != 'f' && sen_char != 'g'){
                        cout << "Invalid input. Please try again: ";
                        cin >> sen_char;
                        cin.ignore(100, '\n');
                    }
                    cout << "You just cast your vote for: ";
                    if(sen_char == 'a')
                        cout << print_s[0];
                    else if(sen_char == 'b')
                        cout << print_s[1];
                    else if(sen_char == 'c')
                        cout << print_s[2];
                    else if(sen_char == 'd')
                        cout << print_s[3];
                    else if(sen_char == 'e')
                        cout << print_s[4];
                    else if(sen_char == 'f')
                        cout << print_s[5];
                    else if(sen_char == 'g')
                        cout << print_s[6];
                    break;
                }
                
                else
                    for(int i = 0; i < 2; i++){
                    cout << print_cc[i] << endl;
                }
                //lets the user vote for city council
                cin >> cc_char;
                while(cc_char != 'a' && cc_char != 'b'){
                    cout << "Invalid input. Please try again: ";
                    cin >> cc_char;
                    cin.ignore(100, '\n');
                }
                cout << "You just cast your vote for: ";
                if(cc_char == 'a')
                    cout << print_cc[0];
                else if(cc_char == 'b')
                    cout << print_cc[1];
            }//closes vector size 1
            
            roles.erase(roles.begin() + (role - 1));
         }//closes while loop (while vector size is not 0)
        /***************/
        
        //voting for amendments section
        cout << ". \nYou have completed voting for: Candidates and Roles." << endl
             << "\nNow voting for: Amendments" << endl
        << "Amendments on the ballot: " << endl;
        
        //object
        Amendments am_obj = Amendments();
        
        //opens the amendments txt file and reads every line into a string
        string print_am = am_obj.get_am1("amendments.txt");
        
        //amendments class
        cin >> am_obj;

        /*****
         SUMMARY
         *****/
        //NAME
        cout << "Name: ";
        cout << p.full_name(first, last);
        //DOB
        cout << "\nDOB: ";
        string full_DOB1 = p.full_DOB(month, day, year);
        cout << full_DOB1;
        
        //Summary of candidates
        cout << "\nCandidates and Roles:" << endl << "President and Vice President of the United States: ";
        if(p_char == 'a')
            cout << print_p[0];
        else if(p_char == 'b')
            cout << print_p[1];
        else if(p_char == 'c')
            cout << print_p[2];
        else if(p_char == 'd')
            cout << print_p[3];
        
        cout << "\nUnited States Senator: ";
        if(sen_char == 'a')
            cout << print_s[0];
        else if(sen_char == 'b')
            cout << print_s[1];
        else if(sen_char == 'c')
            cout << print_s[2];
        else if(sen_char == 'd')
            cout << print_s[3];
        else if(sen_char == 'e')
            cout << print_s[4];
        else if(sen_char == 'f')
            cout << print_s[5];
        else if(sen_char == 'g')
            cout << print_s[6];
        
        cout << "\nCity Council Representative: ";
        if(cc_char == 'a')
            cout << print_cc[0];
        else if(cc_char == 'b')
            cout << print_cc[1];
        
        //Summary of amendments
        cout << "\n\nAmendments: " << endl;
        //calls the total
        char dummy = 'y';
        //am_obj.total(dummy);
        Amendments::total(dummy);
        
        //output
        am_obj.display_am1();
        cout << endl;
        am_obj.display_am2();
        cout << endl;
        cout << "Yes/no total: ";
        print(am_obj);
        
    }//closes SSN = 9 else statement
    
    cout << endl;
}//closes main
