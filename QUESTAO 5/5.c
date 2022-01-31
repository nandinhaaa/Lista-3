#include<stdio.h>
int max = 100;
int qtd = 0;

struct emprestimo{
	char data[30];
	char nomePessoa[30];
	char emprestado[1];
}temprestimo;

typedef struct jogo{
	char titulo[30];
	char console[30];
	int ano;
	int ranking;
	struct emprestimo emprestimo;

}tjogo;

int menu(){
	int op;
	printf("*** SISTEMA PARA CATALOGO E CONTROLE DE COLECOES DE JOGOS****\n");
	printf("1-Inserir um novo jogo\n");
	printf("2-Mostrar todos os jogos \n");
	printf("3-Salvar em arquivo txt \n");
	printf("4-Carregar um arquivo txt\n");
	printf("5-Buscar por um titulo\n");
	printf("6-Buscar consoles \n");
	printf("7-Realizar um emprestimo\n");
	printf("8-Realizar uma devolucao\n");
	printf("9-Lista de jogos que foram emprestados \n");
	
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}

void cadastrarJogo(tjogo jogo[]){
	printf("***** DADOS PARA JOGO %d *****\n",qtd+1);
	
	printf("Titulo:\n");
	fflush(stdin);
	gets(jogo[qtd].titulo);
	
	printf("Console:\n");
	fflush(stdin);
	gets(jogo[qtd].console);
	
	printf("Ano:\n");
	scanf("%i",&jogo[qtd].ano);
	
	printf("ranking:\n");
	scanf("%i",&jogo[qtd].ranking);
	
	
	strcpy(jogo[qtd].emprestimo.data,"NAO-EMPRESTADO");
	strcpy(jogo[qtd].emprestimo.emprestado,"N");
	strcpy(jogo[qtd].emprestimo.nomePessoa,"NAO-EMPRESTADO");
	
	qtd++;
}

void mostraJogo(tjogo jogo[]){
	int k;
	for(k=0;k<qtd;k++){
		printf("\n***** DADOS PARA JOGO %d *****\n",k+1);
		printf("Titulo: %s\n",jogo[k].titulo);
		printf("Console: %s\n",jogo[k].console);
		printf("Ano: %i\n",jogo[k].ano);
		printf("ranking: %i\n\n",jogo[k].ranking);
		printf("- Emprestimos -\n");
		printf("Emprestado: %s\n",jogo[k].emprestimo.emprestado);
		printf("Nome da pessoa: %s\n",jogo[k].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[k].emprestimo.data);
	}
}

void salvarDados(tjogo jogo[]){
	int k;
	FILE *arq;
	arq = fopen("jogos.txt","w");
	fprintf(arq,"%d\n",qtd);
	
	for(k=0;k<qtd;k++){
		fprintf(arq,"%s\n",jogo[k].titulo);
		fprintf(arq,"%s\n",jogo[k].console);
		fprintf(arq,"%i\n",jogo[k].ano);
		fprintf(arq,"%i\n",jogo[k].ranking);
		fprintf(arq,"%s\n",jogo[k].emprestimo.emprestado);
		fprintf(arq,"%s\n",jogo[k].emprestimo.nomePessoa);
		fprintf(arq,"%s\n",jogo[k].emprestimo.data);
	}
	printf("Dados salvos :)");
}

void carregaDados(tjogo jogo[]){
	FILE *arq;
	int k;
	arq = fopen("jogos.txt","r");
	if(arq==NULL){
		printf("Arquivo nao encontrado :(\n");
		return;
	}
	fscanf(arq,"%d",&qtd);
	for(k=0;k<qtd;k++){
		
		fscanf(arq,"%s",&jogo[k].titulo);
		fscanf(arq,"%s",&jogo[k].console);
		fscanf(arq,"%i",&jogo[k].ano);
		fscanf(arq,"%i",&jogo[k].ranking);
		fscanf(arq,"%s",&jogo[k].emprestimo.emprestado);
		fscanf(arq,"%s",&jogo[k].emprestimo.nomePessoa);
		fscanf(arq,"%s",&jogo[k].emprestimo.data);
		
	}
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}

void buscarTitulo(tjogo jogo[]){
	
	int k;
	char nome[50];
	printf("\n Digite o titulo que deseja: \n");
	fflush(stdin);
	gets(nome);
	for(k=0;k<qtd;k++){
		if(strcmp(strupr(nome),strupr(jogo[k].titulo)) == 0){
		printf("\n***** DADOS PARA JOGO %d *****\n",k+1);
		printf("Titulo: %s\n",jogo[k].titulo);
		printf("Console: %s\n",jogo[k].console);
		printf("Ano: %i\n",jogo[k].ano);
		printf("Ranking: %i\n\n",jogo[k].ranking);
		printf("- Emprestimo -\n");
		printf("Emprestado: %s\n",jogo[k].emprestimo.emprestado);
		printf("Nome Pessoa: %s\n",jogo[k].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[k].emprestimo.data);

		}
}
}

void buscarConsole(tjogo jogo[]){
	
	int k;
	char nome[50];
	printf("\n Digite o console:\n");
	fflush(stdin); 
	gets(nome);
	for(k=0;k<qtd;k++){
		if(strcmp(strupr(nome),strupr(jogo[k].console)) == 0){
		printf("\n***** DADOS PARA JOGO %d *****\n",k+1);
		printf("Titulo: %s\n",jogo[k].titulo);
		printf("Console: %s\n",jogo[k].console);
		printf("Ano: %i\n",jogo[k].ano);
		printf("Ranking: %i\n\n",jogo[k].ranking);
		printf("- Emprestimo -\n");
		printf("Emprestado: %s\n",jogo[k].emprestimo.emprestado);
		printf("Nome Pessoa: %s\n",jogo[k].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[k].emprestimo.data);

		}
}
}

void emprestar(tjogo jogo[]){
	int k;
	char nome[50],opcao[1];
	printf("\nDigite o nome do jogo que deseja emprestar: \n");
	fflush(stdin);
	gets(nome);
	for(k=0;k<qtd;k++){
		if(strcmp(strupr(nome),strupr(jogo[k].titulo)) == 0){
			printf("Deseja emprestar o jogo %i - %s?(S/N):\n",k,jogo[k].titulo);
			fflush(stdin);
			gets(opcao);
			if(strcmp(strupr(opcao),strupr("S")) == 0){
				printf("Digite a data do emprestimo:\n");
				fflush(stdin);
				gets(jogo[k].emprestimo.data);
				
				printf("Digite o nome da pessoa :\n");
				fflush(stdin);
				gets(jogo[k].emprestimo.nomePessoa);
				
				strcpy(jogo[k].emprestimo.emprestado,"S");
			}


		}
}
}

void devolver(tjogo jogo[]){
	int k;
	char nome[50],opcao[1];
	printf("\nDigite o nome do jogo que deseja fazer a devolucao :\n");
	fflush(stdin);
	gets(nome);
	for(k=0;k<qtd;k++){
		if(strcmp(strupr(nome),strupr(jogo[k].titulo)) == 0){
			printf("Deseja fazer a devolucao do jogo %i - %s?(S/N):\n",k,jogo[k].titulo);
			fflush(stdin);
			gets(opcao);
			if(strcmp(strupr(opcao),strupr("S")) == 0){
				strcpy(jogo[k].emprestimo.data,"NAO - EMPRESTADO");
				strcpy(jogo[k].emprestimo.emprestado,"N");
				strcpy(jogo[k].emprestimo.nomePessoa,"NAO - EMPRESTADO");
				
				printf("\nJogo que foi devolvido");
			}


		}
}
}

void listaEmprestados(tjogo jogo[]){
	int k;
	printf("\n***Jogos Emprestados***\n");
	for(k=0;k<qtd;k++){
		if(strcmp(jogo[k].emprestimo.emprestado,"S") == 0){
			printf("\n**** DADOS PARA O JOGO %d *****\n",k+1);
			printf("Titulo: %s\n",jogo[k].titulo);
			printf("Console: %s\n",jogo[k].console);
			printf("Ano: %i\n",jogo[k].ano);
			printf("Ranking: %i\n\n",jogo[k].ranking);
			printf("- Emprestimo -\n");
			printf("Emprestado: %s\n",jogo[k].emprestimo.emprestado);
			printf("Nome DA Pessoa: %s\n",jogo[k].emprestimo.nomePessoa);
			printf("Data: %s\n",jogo[k].emprestimo.data);
		}
}
}

int main(){
	int op=0;
	tjogo jogo[max];
	
	do{
		op = menu();
		switch(op){
			case 1:
				cadastrarJogo(jogo);
				break;
			case 2:
				mostraJogo(jogo);
				break;				
			case 3:
				salvarDados(jogo);
				break;
			case 4:
				carregaDados(jogo);
				break;
			case 5:
				buscarTitulo(jogo);
				break;
			case 6:
				buscarConsole(jogo);
				break;
			case 7:
				emprestar(jogo);
				break;	
			case 8:
				devolver(jogo);
				break;
			case 9:
				listaEmprestados(jogo);
				break;
		}
		
      	getch();
      	system("cls");
      	
	}while(op!=0);
	
	return 0;
}
