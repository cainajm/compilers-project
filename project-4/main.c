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

void desempilha(char TempS[], int i ){
	for(int j = i; j >= 0; j--){
		TempS[j] = TempS[j+1];
	}
}

int main() {

	printf("--------------------------------------\nBem-vindo ao Analisador Sintatico de Expressao\n--------------------------------------\nInsira:\n");

    int TempN;
    char TempS[100] = "";
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
			p++;
			i++;
			goto C;
		}
		else if(str[i] ==  '\0'){
		
		}
		
	B:
		if(str[i] == '+'  || str[i] == '-' || str[i] == '/' || str[i] == '*'){
			i++;
			goto A;
		}
		
	C:
		TempS[p] = 'D';
		p++;			
		goto A;
		
	D:
		if(str[i] == ')'){
						
		}
		
	ACEITA:
		printf("Expressao aceita...");
		
	REJEITA:
		printf("Expressao rejeitada...");
		
		

	system("pause");
	return 0;

}
