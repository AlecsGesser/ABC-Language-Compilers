#ifndef tabParse_hpp
#define tabParse_hpp
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void init_tab(vector<vector<int> >& tabParsing){
	int size_H = 85, size_W = 60;

	for(int i = 0 ; i < size_H ; i++){
		vector<int> temp;
		for(int j = 0 ; j < size_W ; j++){
			temp.push_back(-1);
		}
		tabParsing.push_back(temp);
	}



	tabParsing[51][2] = 1;
	tabParsing[52][2] = 3;
	tabParsing[52][3] = 3;
	tabParsing[52][7] = 2;
	tabParsing[52][13] = 3;
	tabParsing[52][15] = 3;
	tabParsing[52][19] = 3;
	tabParsing[52][26] = 3;
	tabParsing[52][47] = 3;
	tabParsing[53][2] = 13;
	tabParsing[53][3] = 13;
	tabParsing[53][13] = 13;
	tabParsing[53][15] = 19;
	tabParsing[53][19] = 13;
	tabParsing[53][26] = 13;
	tabParsing[54][15]  = 31;
	tabParsing[55][41] = 4;
	tabParsing[55][43] = 5;
	tabParsing[56][3] = 8;
	tabParsing[56][13] = 6;
	tabParsing[56][19] = 7;
	tabParsing[56][26] = 9;
	tabParsing[57][2] = 10;
	tabParsing[57][3] = 10;
	tabParsing[57][7] = 11;
	tabParsing[57][13] = 10;
	tabParsing[57][15] = 10;
	tabParsing[57][19] = 10;
	tabParsing[57][26] = 10;
	tabParsing[57][47] = 10;
	tabParsing[59][7] = 12;
	tabParsing[60][2] = 15;
	tabParsing[60][3] = 18;
	tabParsing[60][13] = 14;
	tabParsing[60][19] = 17;
	tabParsing[60][26] = 16;
	tabParsing[61][39] = 26;
	tabParsing[61][46] = 27;
	//tabParsing[62][3] = 24;
	tabParsing[62][5] = 20;
	tabParsing[62][6] = 21;
	tabParsing[62][7] = 22;
	tabParsing[62][8] = 23;
	tabParsing[62][10] = 24;
	tabParsing[62][45] = 25;
	tabParsing[63][3] = 28;
	tabParsing[63][13] = 28;
	tabParsing[63][19] = 28;
	tabParsing[63][26] = 28;
	tabParsing[64][40] = 29;
	tabParsing[64][45] = 30;
	tabParsing[65][1] = 52;
	
	
	tabParsing[65][7] = 34;
	tabParsing[65][8] = 36;
	tabParsing[65][10] = 35;
	tabParsing[65][16] = 49;
	tabParsing[65][18] = 64;
	tabParsing[65][23] = 67;
	tabParsing[65][24] = 69;
	tabParsing[65][25] = 68;
	tabParsing[65][27] = 39;
	tabParsing[65][40] = 38;


	tabParsing[66][1] = 33;
	tabParsing[66][7] = 33;
	tabParsing[66][8] = 33;
	tabParsing[66][10] = 33;
	tabParsing[66][16] = 33;
	tabParsing[66][18] = 33;
	tabParsing[66][20] = 32;
	tabParsing[66][23] = 33;
	tabParsing[66][24] = 33;
	tabParsing[66][25] = 33;
	tabParsing[66][27] = 33;
	tabParsing[66][38] = 32;
	tabParsing[66][40] = 33;

	
	tabParsing[67][5] = 75;
	tabParsing[67][6] = 75;
	tabParsing[67][7] = 75;
	tabParsing[67][8] = 75;
	tabParsing[67][10] = 75;
	tabParsing[67][27] = 76;
	tabParsing[67][46] = 75;

	tabParsing[68][40] = 40;
	tabParsing[68][45] = 40;
	tabParsing[68][46] = 41;

	tabParsing[69][5] = 44;
	tabParsing[69][6] = 46;
	tabParsing[69][7] = 48;
	tabParsing[69][8] = 47;
	tabParsing[69][10] = 45;

	tabParsing[70][43] = 43;
	tabParsing[70][45] = 42;

	tabParsing[71][29] = 56;
	tabParsing[71][30] = 55;
	tabParsing[71][31] = 53;
	tabParsing[71][33] = 58;
	tabParsing[71][35] = 57;
	tabParsing[71][48] = 54;

	tabParsing[72][21] = 50;
	tabParsing[72][40] = 51;

	tabParsing[73][5] = 59;
	tabParsing[73][6] = 60;
	tabParsing[73][7] = 63;
	tabParsing[73][8] = 62;
	tabParsing[73][10] = 61;

	tabParsing[74][36] = 65;
	tabParsing[74][49] = 66;

	tabParsing[75][34] = 71;
	tabParsing[75][40] = 70;

	tabParsing[76][34] = 73;
	tabParsing[76][40] = 73;
	tabParsing[76][43] = 74;

	tabParsing[79][5] = 80;
	tabParsing[79][6] = 80;
	tabParsing[79][7] = 80;
	tabParsing[79][8] = 80;
	tabParsing[79][10] = 80;
	tabParsing[79][46] = 80;

	tabParsing[80][37] = 77;
	tabParsing[80][40] = 79;
	tabParsing[80][45] = 79;
	tabParsing[80][50] = 78;

	tabParsing[81][5] = 84;
	tabParsing[81][6] = 85;
	tabParsing[81][7] = 86;
	tabParsing[81][8] = 88;
	tabParsing[81][10] = 87;
	tabParsing[81][46] = 89;

	tabParsing[82][37] = 81;
	tabParsing[82][40] = 81;
	tabParsing[82][42] = 83;
	tabParsing[82][44] = 82;
	tabParsing[82][45] = 81;
	tabParsing[82][50] = 81;



}

#endif