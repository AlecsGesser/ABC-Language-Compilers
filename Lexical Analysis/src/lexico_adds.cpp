#include "lexico.hpp"

bool isNumber(char a){
	for(int i = 0 ; i < 10 ; i++){
		if( a == numbers[i] ){
			return true;
		}
	}
	return false;
}

bool isLetter(char a){
	for(int i = 0 ; i < 52 ; i++){
		if( a == letters[i] ){
			return true;
		}
	}
	return false;
}
int isReservado(string a){
	for(int i = 0 ; i <  18; i++){
		if( a.compare( reservado[i]) ==0 ){
			return i;
		}
	}
	return -1;
}
int isSymbol(char a){
	for(int i = 0 ; i <  8; i++){
		if( a == symbols[i] ){
			return i;
		}
	}
	return -1;
}	
