#include "tabParse.hpp"
#include "regras.hpp"

vector<vector<int> > tabParse ;	
vector<vector<int>>  regras;

bool findRule( int X, int a );
void push_vec(vector<int>& stack, vector<int>& regra);
void print_vec(vector<int> vec);


int main(int argc, char** argv){

	if( argc != 3){
		cout<<" <tokens.txt> "<<endl;
	}

	ifstream ftokens;
	ftokens.open(argv[1]);


	init_tab(tabParse);
	init_regras(regras, argv[2]);

	int token;
	

	vector<int> stack;
	vector<int> entrada;
	vector<int> temp;	
	

	if(!ftokens){
		return -7;
	}

	while( ftokens >> token  ){
		// lendo arquivo de tokens do lexico
		temp.push_back(token);
	}

	for (size_t i = 0; i < temp.size(); i++){
		// invertendo pilha de tokens 
		entrada.push_back( temp.at(temp.size() - i -1) );
	}
	temp.clear();

	stack.push_back(47); // cifrão ->> simbolo inicial adicionado
	stack.push_back(51); // bloco add

	int X = stack.back();
	int a = entrada.back();

	while(true){
		cout<<"X: "<<X<<" a: "<<a<<endl;
		if( X == 17 ){
			stack.pop_back();
			X = stack.back();
		}else if( X <= 50 ) {
			if( X == a ){
				stack.pop_back();
				entrada.pop_back();
				X = stack.back(); // update var
				a = entrada.back();
			}else{
				cout<<"Erro"<<endl;
				return -1;
			}
		}else{
			if( findRule(X,a) ){ // se existe regra
				cout<<"regra: "<<tabParse[X][a]<<endl;
				stack.pop_back();
				push_vec( stack, regras.at(tabParse[X][a]-1) );
				print_vec( stack );
				X = stack.back();
			}else{
				cout<<"Erro regra nao encontrada"<<endl;
				return -2;
			}
		}		
		if( X == 47 ){
			cout<<"Sucess, analise concluida"<<endl;
			return -3;
		}
	}
	return 0;
}	


bool findRule( int X, int a ){
	if( tabParse[X][a] == -1 ) return false;
	else return true;	
}

void push_vec(vector<int>& stack, vector<int>& regra){
	for (size_t i = 0; i < regra.size(); i++){
		stack.push_back(regra[i]);
	}	
}

void print_vec(vector<int> vec){
	for (size_t i = 0; i < vec.size(); i++){
		cout<<"i: "<<i<<"||"<<vec[i]<<endl;
	}	
}




