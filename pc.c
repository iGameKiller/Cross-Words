#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

	FILE *arq;
	int op;

	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("arq.txt", "r");

	char ch;
	char superstring[999], **matriz = NULL, **matdica = NULL;
	int mainnum, linhas, *maincoluna = NULL, contador = 0,contador1 = 0,tampalavra = 0, i = 0,*wordlength = NULL, *tamdicas = NULL;
	

	do{
		fscanf(arq,"%c",&ch);//pegando o primeiro caractere da linha

		if(feof(arq)){//verifica se o ponteiro tá no fim do arquivo, e se o caractere for o EOF, a execução do app para
			break;
		}

		getc(arq);//pegando o caractere de espaço

		if(ch == 't'){
			fscanf(arq,"%d",&mainnum);//me conta qual a quantidade de matriz do jogo
			matriz = malloc(mainnum * (sizeof(char)));//aloca um vetor com 10 linhas
			maincoluna = malloc(mainnum * (sizeof(int)));//aloca um vetor independente
			wordlength = malloc(mainnum * (sizeof(int)));//vetor que guarda o tamamho de cada palavra
			tamdicas = malloc(mainnum * (sizeof(int)));
			matdica = malloc(mainnum * (sizeof(char)));
		}

		if(ch == 'p'){
			
			fscanf(arq,"%s",superstring);//salvando a palavra dentro da string
			fscanf(arq,"%d",&maincoluna[contador]);//coordenadas da palavra principal
			tampalavra = strlen(superstring);//o tamanho da palavra será determinado pelo strlen
			wordlength[contador] = tampalavra;
			matriz[contador] = malloc(tampalavra * sizeof(char));//alocando o tamanho da palavra 1 na primeira posição do vetor

			for (i = 0; i < tampalavra; i++){//laço de repetição de 1 até o tamanho da palavra

				matriz[contador][i] = toupper(superstring[i]);//no primeiro vetor de vetores, será salva a superstring 

			}
			contador++;
		}

		if(ch == 'd'){//se o primeiro caractere da linha for o 'd' então executa o if
			fscanf(arq,"%d",&tamdicas[contador]);//aloca um vetor na primeira posição do vetor de vetor
			matdica[contador1] = malloc(tamdicas[contador1] * sizeof(char));//o vetor de vetor terá o tamanho do tamdicas
			fscanf(arq,"%[^\n]",matdica[contador1]);//então eu salvo a string dentro do vetor
			contador1++;
		}

	}while(!feof(arq));

	fclose(arq);

	
}
