 #ifndef function
 #define function

typedef struct palavras{

	char palavra0[30];
	char palavra1[30];
	char palavra2[30];
	char palavra3[30];
	char palavra4[30];
	char palavra5[30];
	char palavra6[30];
	char palavra7[30];
	char palavra8[30];
	char palavra9[30];
}PALAVRAS;

PALAVRAS palavras;

void PrintaDica(FILE *ptr){//função responsável por printar as dicas

	char ch;
	int tamanho;
	char superstring[999];
	int i = 1;

	do{
		fscanf(ptr,"%c",&ch);//pegando o primeiro caractere da linha

		if(feof(ptr)){//verifica se o ponteiro tá no fim do arquivo, e se o caractere for o EOF, a execução do app para
			break;
		}

		getc(ptr);//pegando o caractere de espaço

		if(ch == 'd'){//se o primeiro caractere da linha for o 'd' então executa o if

			fscanf(ptr,"%d",&tamanho);//scaneando o número contido na linha

			char str[tamanho];//variável com o 

			getc(ptr);

			fscanf(ptr,"%[^\n]s",str);
			printf("%d - %s\n",i,str);
			getc(ptr);
			i++;

		}else{//se o if não achar o 'd' ele tem que pular toda a linha desnecessária
			fscanf(ptr,"%[^\n]s",superstring);
			getc(ptr);
		}

	}while(!feof(ptr));
}

void captura_resp(FILE *ptr){

	char resp_sys[100];
	char superstring[999];
	char ch;
	int i = 0;
	int cont_palavras;

	do{

		fscanf(ptr,"%c",&ch);

		if(feof(ptr)){
			break;
		}

		getc(ptr);

		if(ch == 'p'){

			cont_palavras++;
			
			for (i = 0; i < cont_palavras; i++){

				fscanf(ptr,"%[^ ]s",resp_sys);
				fscanf(ptr,"%[^\n]s",superstring);
				printf("%s\n",resp_sys);
			
				getc(ptr);

			}
			
			
		}else{
			fscanf(ptr,"%[^\n]s",superstring);
			getc(ptr);
		}

	}while(!feof(ptr));
}

#endif