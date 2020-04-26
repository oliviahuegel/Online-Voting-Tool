#include "Candidates.h"
#include <iostream>
#include <fstream>


using std::string;
using std::ifstream;

//getters
std::vector<string> Candidates::get_P_VP(string filename){
    ifstream input_presidents;
    input_presidents.open(filename);
    while(!input_presidents.eof()){
        getline(input_presidents, p_txt, '\n');
        P_VP.push_back(p_txt);
    }
    return P_VP;
}
std::vector<string> Candidates::get_Senator(string filename){
    ifstream input_senators;
    input_senators.open(filename);
    while(!input_senators.eof()){
        getline(input_senators, sen_txt, '\n');
        Senator.push_back(sen_txt);
    }
    return Senator;
}
std::vector<string> Candidates::get_City_Council(string filename){
    ifstream input_city_council;
    input_city_council.open(filename);
    while(!input_city_council.eof()){
        getline(input_city_council, cc_txt, '\n');
        City_Council.push_back(cc_txt);
    }
    return City_Council;
}
