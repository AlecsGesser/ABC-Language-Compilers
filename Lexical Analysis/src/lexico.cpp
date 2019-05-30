#include "lexico.hpp"
#include "lexico_adds.cpp"

int main(int argc, char** argv){

	if(argc != 2){
		cout<<" code.abc argument"<<endl;
		exit(-1);
	}

	ifstream code;
	code.open(argv[1]);

	int state = -1;
	string palavra;
	int flag_return = 0;
	char atual = code.get();

	while( atual != EOF ){
		// verificação variaveis e palavras reservadas
		if( isLetter(atual) ){
			palavra+=atual;
			atual = code.get();
			while( isNumber(atual) || isLetter(atual) ){
				palavra+=atual;
				atual = code.get();
			}
			int res = isReservado(palavra);
			if( res !=-1){
				if( res == 3){ // if res == return 
					flag_return = 1;
				}
				cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<" -- Token: "<<index_res[res]<<endl;
			}else{
				if( flag_return == 1){
					if( palavra.size() <= max_string_size){
						cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<" -- Token: 9"<<endl;
						flag_return = 0;
					}else{
						cout << "\033[1;31mError(line: "<<line_counter<<"): variable name exceeds 10 characters:"<<palavra<<" \033[0m\n";
						return -1;
					}
				}else{
					if( palavra.size() <= max_string_size){
						cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<" -- Token: 7"<<endl;
						flag_return = 0;
					}else{
						cout << "\033[1;31mError(line: "<<line_counter<<"): variable name exceeds 10 characters:"<<palavra<<" \033[0m\n";
						return -1;
					}
				}
			}
			palavra.clear();
		}else{ 			// verificacao de numeros
			if( isNumber(atual)){
				while( isNumber(atual)){
					palavra+=atual;
					atual = code.get();

				}
			
				if( atual == '.'){
					palavra+=atual;
					atual = code.get();
					while( isNumber(atual)){
						palavra+=atual;
						atual = code.get();
					}
					if( atof(palavra.c_str()) <= FLT_MAX  && atof(palavra.c_str()) >= FLT_MIN ){
						cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<" -- Token: 6"<<endl;
					}else{
						cout << "\033[1;31mError(line: "<<line_counter<<"): of float limits:"<<palavra<<" \033[0m\n";
						return -1;
					}

				}else{
					if( atoi(palavra.c_str()) <= int_max_v  ){
						cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<" -- Token: 5"<<endl;
					}else{
						cout << "\033[1;31mError(line: "<<line_counter<<"): of integer limits:"<<palavra<<" \033[0m\n";
						return -1;
					}					
					palavra.clear();
				}

			}else{ 		// espaço
				if( atual == ' ') {
					atual = code.get();
				}else{		// verificação de simbolos
					int f = isSymbol(atual);
					if( f != -1){
						cout<<"Line: "<<line_counter<<"-- Lexema: "<<atual<<" -- Token: "<<index_sym[f]<<endl;
						palavra.clear();
						atual = code.get();
					}else{
					// quebra de lina 
						if( atual == '\n' ){
							line_counter++;
							palavra.clear();
							flag_return = 0;
							atual = code.get();
						}else{
							if( atual == '\t'){
								palavra.clear();
								atual = code.get();
							}else{

								// operadores

								if( atual == '>' ){
									atual = code.get();
									if( atual == '>'){
										cout<<"Line: "<<line_counter<<"-- Lexema: >> -- Token: 28"<<endl;
										atual = code.get();
										palavra.clear();
									}else {
										if( atual == '='){
											cout<<"Line: "<<line_counter<<"-- Lexema: >= -- Token: 29"<<endl;
											atual = code.get();
											palavra.clear();
										}
										else{
											cout<<"Line: "<<line_counter<<"-- Lexema: > -- Token: 30"<<endl;
										}
									}
								}else{
									if( atual == '<' ){
										atual = code.get();
										if( atual == '<'){
											cout<<"Line: "<<line_counter<<"-- Lexema: << -- Token: 34"<<endl;
											atual = code.get();
											palavra.clear();
										}else{
											if( atual == '='){
												cout<<"Line: "<<line_counter<<"-- Lexema: <= -- Token: 33"<<endl;
												atual = code.get();
												palavra.clear();
											}
											else{
												cout<<"Line: "<<line_counter<<"-- Lexema: < -- Token: 35"<<endl;
											}
										}
									}else{
										if( atual == '='){
											atual = code.get();
											if( atual == '='){
												cout<<"Line: "<<line_counter<<"-- Lexema: == -- Token: 31"<<endl;
												atual = code.get();
												palavra.clear();
											}else{
												cout<<"Line: "<<line_counter<<"-- Lexema: =  -- Token: 32"<<endl;
											}
										}else{
											if( atual == '+'){
												atual = code.get();
												if( atual == '+'){
													cout<<"Line: "<<line_counter<<"-- Lexema: ++ -- Token: 36"<<endl;
													atual = code.get();
													palavra.clear();
												}else{
													cout<<"Line: "<<line_counter<<"-- Lexema: +  -- Token: 37"<<endl;
												}
											}else{
												if( atual == '-'){
													atual = code.get();
													if( atual == '-'){
														cout<<"Line: "<<line_counter<<"-- Lexema: (--) Token: 49"<<endl;
														atual = code.get();
														palavra.clear();
													}else{
														cout<<"Line: "<<line_counter<<"-- Lexema: (-)  Token: 50"<<endl;
													}
												}else{
													if( atual == '!'){
														atual = code.get();
														if( atual == '='){
															cout<<"Line: "<<line_counter<<"-- Lexema: != --Token: 48"<<endl;
															atual = code.get();
															palavra.clear();
														}else{
															cout << "\033[1;31mError(line: "<<line_counter<<"): at (!), expected (=) after (!) \033[0m\n";
															return -1;
														}
													}else{					// char ou strings
														if( atual == '\"' ){
															atual = code.get();
															if( atual != '\"' ){
																if( atual == '\n'){
																	cout << "\033[1;31mError(line: "<<line_counter<<"): Missing Matching Quotes (\") \033[0m\n";
																	return -1;
																}
																palavra+= atual;
																atual = code.get();
																if( atual == '\"'){
																	cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<"  Token: 8"<<endl;
																	palavra.clear();
																	atual = code.get();
																}else{
																	while(atual != '\"'){
																		palavra+= atual;
																		atual = code.get();
																		if( atual == '\n'){
																			cout << "\033[1;31mError(line: "<<line_counter<<") Missing Matching Quotes (\") \033[0m\n";
																			return -1;
																		}
																	}
																	if( palavra.size() < max_string_size ){
																		cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<"-- Token: 10"<<endl;
																		atual = code.get();
																		palavra.clear();																		
																	}else{
																		cout << "\033[1;31mError(line: "<<line_counter<<"): string name exceeds 10 characters:"<<palavra<<" \033[0m\n";
																		return -1;
																	}
																}			
															}else{
																cout<<"Line: "<<line_counter<<"-- Lexema: \0"<<"-- Token: 8"<<endl;
																atual = code.get();
																palavra.clear();
															}
														}else{		// literal
															if( atual == '\''){
																atual = code.get();
																if( atual != '\''){
																	if( atual == '\n'){
																		cout << "\033[1;31mError(line: "<<line_counter<<"): Missing Matching Quotes ( ' ) \033[0m\n";
																		return -1;
																	}
																	palavra+= atual;
																	atual = code.get();
																	
																	while( atual != '\''){
																		palavra+= atual;
																		atual =code.get();
																		if( atual == '\n'){
																			cout << "\033[1;31mError(line: "<<line_counter<<") Missing Matching Quotes ( ' ) \033[0m\n";
																			return -1;
																		}
																	}
																	cout<<"Line: "<<line_counter<<"-- Lexema: "<<palavra<<"-- Token: 12"<<endl;
																	atual = code.get();
																	palavra.clear();
																}	
															}else{ //comentarios somente em bloco caso contrario = erro
																if( atual == '#'){
																atual = code.get();
																	while( atual != '#' ){
																		if( atual == '\n'){
																			line_counter++;
																		}
																		if( atual == EOF){
																			cout << "\033[1;31mError(line: "<<line_counter<<") Missing Matching (#) \033[0m\n";
																			return -1;
																		}
																		atual = code.get();
																	}
																	atual = code.get();
																}else{
																	cout << "\033[1;31mError(line: "<<line_counter<<") Invalid Character: ( "<<atual<<" )\033[0m\n";
																	return -1;
																}
															}	
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << "\033[1;32mCode LexAnalyzed Successfully !!!\033[0m\n";

	code.close();
}