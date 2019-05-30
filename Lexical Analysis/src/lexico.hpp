#pragma once
#ifndef LEX_HPP
#define LEX_HPP_DEF

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <float.h>

#define st_compare 0
#define st_reserved 1
#define st_variable 2

using namespace std;

bool isNumber(char a);
int isReservado(string a);
bool isLetter(char a);
int isSymbol(char a);


int int_max_v = 2147483647;
int max_string_size = 10;
int line_counter = 1;

string reservado[18] = {"while","void", "string", "return", "main", "integer",
						"inicio", "if","for", "float", "fim" ,"else", "double", "do", "cout",
						"cin", "char", "function"};
int index_res[18] = {1, 2, 3, 4, 11, 13, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };

char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char letters[52] = { 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I',
					'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R',
					's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z' };

char symbols[8] = {'}', '{', ';', ':', ',', ')', '(', '$' };
int index_sym[8] = {38, 39, 40, 41, 43, 45, 46, 47 };



#endif