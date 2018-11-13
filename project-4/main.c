//Compiladores: Atividade 3
//Jose Pedro Teles Costa - 22116018-7
//Cainã de Jesus Marciano - 22116026-0

#include <stdio.h>
#include <stdlib.h>

void initPilha(char TempS[]){
	for(int i = 0; i < 100; i++){
		TempS[i] = '0';
	}
}

int checkPilha(char TempS[]){
	for(int i = 0; i < 100; i++){
		if(TempS[i] != '0'){
			return 0;
		}
	}
	return 1;
}

int main() {

	printf("--------------------------------------\nBem-vindo ao Analisador Sintatico de Expressao\n--------------------------------------\nInsira:\n");

    int TempN;
    char TempS[100] = "";
	initPilha(TempS);
    int aux = 0;
    char str[100];    
    int numLinhas = 0;
	int i = 0;
	int p = 0;	
    gets(str);
    puts("");

    goto A;
    
    A:
    	if(str[i] >= '0' && str[i] <= '9'){    		
    		i++;
    		goto B;
		}
		else if(str[i] == ' '){
			i++;
			goto A;
		}
		else if(str[i] == '('){
			i++;
			goto C;
		}
		else if(str[i] == ')' && p > 0){
			i++;
			goto D;
		} else {
			goto REJEITA;
		}
		
		
	B:
		if (str[i+1] == ')'){
			goto REJEITA;
		} else if(str[i] == '+'  || str[i] == '-' || str[i] == '/' || str[i] == '*'){
			i++;
			goto A;
		} else if(str[i] == ')' && p > 0){
			i++;
			goto D;
		} else if(str[i] ==  '\0'){
			if(checkPilha(TempS) == 0){
				goto REJEITA;
			}
			goto ACEITA;
		}
		
	C:
		if(str[i] == ')'){
			goto REJEITA;
		} else {
			TempS[p] = 'D';	
			p++;		
			goto A;
		}
		
	D:
		if(TempS[aux] == 'D'){
			TempS[aux] = '0';
			aux++;
			goto B;
		} else {
			goto REJEITA;
		}
		
		
	ACEITA:
		printf("Expressao aceita...\n");
		system("pause");
		return 0;
		
	REJEITA:
		printf("Expressao rejeitada...\n");
		system("pause");
		return 0;
		
		

	system("pause");
	return 0;

}
