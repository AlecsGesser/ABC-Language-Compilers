# Description

Compiler contains the following steps: lexical analysis, syntactic analysis(parsing) and semantic analysis.

## Build Lexical 

G++ required.

```bash
g++ ./src/lexical.cpp -o lex.exe

```
## Usage
#### Code Sample: code.abc
```cpp
void main {
	var1: integer;
	var2: integer;
	var3: integer;

	var1 = 3;
	var2 = 5;
	var3 = var2 + var1;
	if( var3 >= 7 ){
		return var3;
	}else{
		return 0;
	}
}
```
##### Executing:
```bash
./lex.exe <path/code.abc>
```