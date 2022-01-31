#include<stdio.h>
int max = 100;
int qtd = 0;

typedef struct eletrodomestico {
	char nome[100];
	double pot;
	double tempoMedio;
}   xeletrodomestico;

int menu()
{
	int op;
	printf("*** SISTEMA DE CONTROLE DE CONSUMO DE ENERGIA****\n");
	printf("1- Inserira um novo eletrodomestico \n");
	printf("2- Mostre todos os eletrodomesticos \n");
	printf("3- Salvar em um arquivo txt \n");
	printf("4- Carregar um arquivo txt \n");
	printf("5- Buscar por um  nome \n");
	printf("6- Eletrodomesticos com potencia mais forte que um valor X\n");
	printf("7- Consumos diarios e mensais \n");
	
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
void cadastrarEletrodomestico(xeletrodomestico eletrodomestico[]){
	printf("***** Dados para eletrodomestico %d *****\n",qtd+1);
	
	printf("Nome:\n");
	fflush(stdin);
	gets(eletrodomestico[qtd].nome);
	
	printf("Potencia (kW):\n");
	scanf("%lf",&eletrodomestico[qtd].pot);
	
	printf("Tempo medio de uso por dia (horas): \n");
	scanf("%lf",&eletrodomestico[qtd].tempoMedio);
	
	qtd++;
}

void mostraEletrodomesticos(xeletrodomestico eletrodomestico[]){
	int k;
	for(k=0;k<qtd;k++){
		printf("\n***** DADOS PARA ELETRODOMESTICOS %d *****\n",k+1);
		printf("Nome: %s\n",eletrodomestico[k].nome);
		printf("Potencia: %.2lf kW\n",eletrodomestico[k].pot);
		printf("Tempo Medio: %.2lf horas\n",eletrodomestico[k].tempoMedio);
	}
}

void salvarDados(xeletrodomestico eletrodomestico[]){
	int k;
	FILE *arq;
	arq = fopen("eletrodomesticos.txt","w");
	fprintf(arq,"%d\n",qtd);
	
	for(k=0;k<qtd;k++){
		fprintf(arq,"%s\n",eletrodomestico[k].nome);
		fprintf(arq,"%lf\n",eletrodomestico[k].pot);
		fprintf(arq,"%lf\n",eletrodomestico[k].tempoMedio);
	}
	printf("Os dados foram salvos:)");
}

void carregaDados(xeletrodomestico eletrodomestico[]){
	FILE *arq;
	int k;
	arq = fopen("eletrodomesticos.txt","r");
	if(arq==NULL){
		printf("Arquivo NAO encontrado :(\n");
		return;
	}
	fscanf(arq,"%d",&qtd);
	for(k=0;k<qtd;k++){
		fscanf(arq,"%s",&eletrodomestico[k].nome);
		fscanf(arq,"%lf",&eletrodomestico[k].pot);
		fscanf(arq,"%lf",&eletrodomestico[k].tempoMedio);
	}
	fclose(arq);
	printf("Dados carregados com sucesso :)\n");
}

void buscarNome(xeletrodomestico eletrodomestico[]){
	int k;
	char nome[50];
	printf("\nDigite o nome do eletrodomestico: \n");
	fflush(stdin);
	gets(nome);
	for(k=0;k<qtd;k++){
		if(strcmp(strupr(nome),strupr(eletrodomestico[k].nome)) == 0){
			printf("\n***** Dados para eletrodomestico %d *****\n",k+1);
			printf("Nome: %s\n",eletrodomestico[k].nome);
			printf("Potencia: %.2lf kW\n",eletrodomestico[k].pot);
			printf("Tempo Medio: %.2lf horas\n",eletrodomestico[k].tempoMedio);	

		}
}
}

void buscarValorMaior(xeletrodomestico eletrodomestico[]){
	int k;
	double x;
	printf("\nDigite o valor x:\n");
	scanf("%lf",&x);
		if(x < eletrodomestico[k].pot){
			printf("\n***** DADOS PARA OS ELETRODOMESTICOS %d *****\n",k+1);
			printf("Nome: %s\n",eletrodomestico[k].nome);
			printf("Potencia: %.2lf kW\n",eletrodomestico[k].pot);
			printf("Tempo Medio: %.2lf horas\n",eletrodomestico[k].tempoMedio);	
			
		}
		
		
	}



void consumo(xeletrodomestico eletrodomestico[]){
	int k;
	double valorkW,valor=0,total=0;
	printf("Digite o valor do kW/h: \n");
	scanf("%lf\n",&valorkW);
	
	for(k=0;k<qtd;k++){
		valor = eletrodomestico[k].pot*eletrodomestico[k].tempoMedio;
		printf("Total de kW/h do %s (%.2lf Kw * %.2lf horas): %.2lf kW/h\n",eletrodomestico[k].nome,eletrodomestico[k].pot,eletrodomestico[k].tempoMedio,valor);
		printf("Total em reais do %s (%.2lf kW/h * R$%.2lf): R$%.2lf\n\n",eletrodomestico[k].nome,valor,valorkW,valor*valorkW);
		total+=valor;
	}
	printf("\n Total gasto por dia (%.2lf Kw/h * R$%.2lf): R$%.2lf",total,valorkW,total*valorkW);
	printf("\nTotal gasto no mes (R$%.2lf * 30): R$%.2lf",total*valorkW,total*valorkW*30);
}

int main(){
	int op=0;
	xeletrodomestico eletrodomestico[max];
	
	do{
		op = menu();
		switch(op){
			case 1:
				cadastrarEletrodomestico(eletrodomestico);
				break;
			case 2:
				mostraEletrodomesticos(eletrodomestico);
				break;
				
			case 3:
				salvarDados(eletrodomestico);
				break;
			case 4:
				carregaDados(eletrodomestico);
				break;
			case 5:
				buscarNome(eletrodomestico);
				break;
			case 6:
				buscarValorMaior(eletrodomestico);
				break;
			case 7:
				consumo(eletrodomestico);
				break;	
			case 8:
			
				break;
		}
		
      	getch();
      	system("cls");
      	
	}while(op!=0);
	
	return 0;
}
