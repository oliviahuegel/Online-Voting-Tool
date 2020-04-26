#ifndef Candidates_h
#define Candidates_h

#include <stdio.h>
#include <vector>
#include <string>

class Candidates{
private:
    //vectors will hold all of the candidates in a category
    std::vector<std::string>P_VP;
    std::vector<std::string>Senator;
    std::vector<std::string>City_Council;
    
    std::string p_txt, sen_txt, cc_txt;
public:
    //getters to get the candidate names from the text file
    std::vector<std::string> get_P_VP(std::string filename);
    std::vector<std::string> get_Senator(std::string filename);
    std::vector<std::string> get_City_Council(std::string filename);
    
};
#endif /* Candidates_h */
