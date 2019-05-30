#ifndef regras_HPP
#define regras_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

void init_regras(vector<vector<int> >& regras, string file_regras){
    ifstream frules;
	frules.open( file_regras );

    int rule;

    if (frules.good())
    {
        string str;
        while( (getline(frules, str)) )
        {
            istringstream ss(str);
            int num;
            vector<int> aux;
            vector<int> invert;

            while(ss >> num)
            {
                aux.push_back(num);
            }
            for (size_t i = 0; i < aux.size(); i++)
            {
                invert.push_back(aux.at(aux.size()- 1 - i));
            }
            regras.push_back(invert);
            aux.clear();
            invert.clear();

        }
    }

    
    


    
}


#endif

