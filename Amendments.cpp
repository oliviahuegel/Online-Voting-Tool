#include "Amendments.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
int Amendments::count_yes = 0;
int Amendments::count_no = 0;

//getters
string Amendments::get_am1(string filename){
    string temp_string1;
    ifstream input_am1;
    input_am1.open(filename);
    while(!input_am1.eof()){
        getline(input_am1, temp_string1, '\n');
        //displays amendments
        cout << temp_string1 << endl;
    }
    return temp_string1;
}
