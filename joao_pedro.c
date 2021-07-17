#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 3

void limpaStdin() {
	char c;
	while (((c = getchar()) != '\n')&&(c != EOF));
}

struct data {
  int dia;
  int mes;
  int ano;
};

struct identifica_user {
  long int id;
  struct data data_nasc;
  int t;
  char *paisOrig;
  int n;
};

struct identifica_user {
  long int id;
  struct data data_nasc;
  int t;
  char *paisOrig;
  int n;
};

void identificacao(struct identifica_user *identificar)  //FUNÇÃO 1
{
  setlocale(LC_ALL,"");

	printf("\n\n\n====================================");
	printf("\n\n  	 BEM VINDO!!!   ");
  printf("\n\n   JOGOS OLÍMPICOS DE VERÃO   \n");
  printf(" 	   2020/2021   \n\n");
  printf("  SISTEMA DE ACOMPANHAMENTO   \n\n");
  printf("====================================\n\n\n");
  printf("\n\n-------- CADASTRO DE USUÁRIO --------\n\n");

  printf("\nDigite seu número de identificação (ID):\n ");
  scanf("%ld", &identificar->id);

	while(identificar->id < 0)
  {
    printf("ID invalido!!! Digite seu número de Identificação: \n");
    scanf("%li", &identificar->id);
  }

  printf("\nDigite sua data de nascimento neste formato: dd/mm/aaaa\n");
  scanf("%d/%d/%d", &identificar->data_nasc.dia, &identificar->data_nasc.mes, &identificar->data_nasc.ano);

	if (identificar->data_nasc.mes != (02 || 2))
  {
		while(
      (identificar->data_nasc.dia > 29 || identificar->data_nasc.dia < 0) || 
      (identificar->data_nasc.mes < 0 || identificar->data_nasc.mes > 12) || 
      (identificar->data_nasc.ano < 1890 || identificar->data_nasc.ano > 2020)
    )
    {
      printf("\nDigite sua data de nascimento neste formato: dd/mm/aaaa\n");
      scanf("%d/%d/%d", &identificar->data_nasc.dia, &identificar->data_nasc.mes, &identificar->data_nasc.ano);
    }

	} 
    else if (identificar->data_nasc.mes != (((04 || 4) || (06 || 6) || (9) || 11)))
  {
		while(
      (identificar->data_nasc.dia > 30 || identificar->data_nasc.dia < 0) || 
      (identificar->data_nasc.mes < 0 || identificar->data_nasc.mes > 12) || 
      (identificar->data_nasc.ano < 1890 || identificar->data_nasc.ano > 2020)
    )
    {
      printf("Data inválida!!!\n");
      printf("\nDigite sua data de nascimento neste formato: dd/mm/aaaa\n");
      scanf("%d/%d/%d", &identificar->data_nasc.dia, &identificar->data_nasc.mes, &identificar->data_nasc.ano);
    }	
	}
    else
  {
    while(
      (identificar->data_nasc.dia > 31 || identificar->data_nasc.dia < 0) ||
      (identificar->data_nasc.mes < 0 || identificar->data_nasc.mes > 12) || 
      (identificar->data_nasc.ano < 1890 || identificar->data_nasc.ano > 2020)
    )
    {
      printf("Data inválida!!!\n");
      printf("\nDigite sua data de nascimento neste formato: dd/mm/aaaa\n");
      scanf("%d/%d/%d", &identificar->data_nasc.dia, &identificar->data_nasc.mes, &identificar->data_nasc.ano);
    }
	}
	
	printf("\nDigite o número de caracteres do nome de seu país de origem:\n ");
  scanf("%d", &identificar->t);
  	
  identificar->paisOrig = (char*)malloc((identificar->t + 1) * sizeof(char));
  	
  if(identificar->paisOrig == NULL)
  {
    printf("\nERRO de alocação de memoria!!!!");
    system("pause");
    exit(1);
	}
	
	limpaStdin();
	
	printf("\n\nDigite o nome de seu país de Origem:\n ");
	gets(identificar->paisOrig);
	
	printf("\nInsira o número de paises que deseja acompanhar no quadro de medalhas:\n ");
	scanf("%d", &identificar->n);
	
  while (identificar->n >206)
  {
    printf("Numero de paises invalido!!!!!");
    printf("\nInsira o número de paises que deseja acompanhar no quadro de medalhas:\n ");
    
	  scanf("%d", &identificar->n);
  }

	printf("\n====================================\n");
	printf("\nID\n%d\n", identificar->id);
	printf("\nDATA NASCIMENTO\n%d/%d/%d\n", identificar->data_nasc.dia, identificar->data_nasc.mes, identificar->data_nasc.ano);
	printf("\nT CARACTERES\n%d\n", identificar->t);
	printf("\nPAÍS ORIGEM\n%s\n", identificar->paisOrig);
	printf("\nNUMERO DE PAÍSES PARA ACOMPANHAR\n%d\n", identificar->n);
	printf("\n====================================\n");
}

struct criar_quadro {
  char *nome_pais;
  int ouro;
  int prata;
  int bronze;
};      

void quadro_medalhasPais(struct criar_quadro *pais_selecionado) //FUNÇÃO 2
{
  setlocale(LC_ALL,"");

  char aloc[56];

  limpaStdin();
  printf("\n\n\nOpção 2: Preencher quadro de medalhas de um país específico.\n\n");
  printf("\n\nInsira o nome de um país: ");
  gets(aloc);

  pais_selecionado->nome_pais = (char*)malloc((strlen(aloc)+1) * sizeof(char));
  strcpy(pais_selecionado->nome_pais, aloc);

  if(pais_selecionado->nome_pais == NULL){
    printf("\nERRO de alocação de memoria!!!!");
    system("pause");
    exit(1);
	}

  printf("Insira o número de medalhas de ouro desse país: ");
  scanf("%d", &pais_selecionado->ouro);

  printf("Insira o número de medalhas de prata desse país: ");
  scanf("%d", &pais_selecionado->prata);

  printf("Insira o número de medalhas de bronze desse país: ");
  scanf("%d", &pais_selecionado->bronze);
  printf("\n------------------------\n");
  printf("\n%s\n", pais_selecionado->nome_pais);
  printf("Quantidade de medalhas de ouro\n%d\n", pais_selecionado->ouro);
  printf("Quantidade de medalhas de prata\n%d\n", pais_selecionado->prata);
  printf("Quantidade de medalhas de bronze\n%d\n", pais_selecionado->bronze);
}


void quadro_medalhasGeral(struct criar_quadro *pais_selecionado, int **quadroMedalha, int sz1)
{
	int i, j;

  //preenchimento genérico
  srand(time( NULL ) ); 

	for (i=0;i<sz1;i++){
    if(i == 1) {
      quadroMedalha[1][0] = pais_selecionado->ouro;
      quadroMedalha[1][1] = pais_selecionado->prata;
      quadroMedalha[1][2] = pais_selecionado->bronze;
    } else {
	    for (j=0;j<N;j++){
			  quadroMedalha[i][j] = ((int)rand()% 50);
      }
		}

		  for (j=0;j<N;j++){
        printf("         //  %d", quadroMedalha[i][j]);
      }
		  printf("\n-------------------------------------------------\n");
	}
}

void atualizarQuadro (struct criar_quadro *pais_selecionado, int **quadroMedalha) //FUNÇÃO 4
{
// setlocale(LC_ALL,"");

// int k, novaM, i, j;
// //k: número do pais;
// //novaM: variável para indicar o tipo de medalha a ser acrescentada de +1;

// printf("\n\nDigite o número do país a ser modificado:\n\n");
// scanf("pais %d", &k);

// printf("\nDigite 1 para acrescentar +1 medalha de ouro\n");
// printf("\nDigite 2 para acrescentar +1 medalha de prata\n");
// printf("\nDigite 3 para acrescentar +1 medalha de bronze\n");
// scanf("%d", &novaM);

// quadroMedalha[k][novaM] = quadroMedalha[i][j] + 1;

// printf("\n\nQuadro atualizado com sucesso!\n\n");

}

int main() 
{
  setlocale(LC_ALL,"");

  struct identifica_user identificar;
  struct criar_quadro pais_selecionado;
  pais_selecionado.bronze = 0;
  pais_selecionado.ouro = 0;
  pais_selecionado.prata = 0;
  int **quadroMedalha;
  int menu = 1;
  int i;

  identificacao(&identificar);

  quadroMedalha = malloc(sizeof(int*)*identificar.n);
  printf("[%d][%d]", identificar.n, N);

  for(i = 0; i < identificar.n; i++) 
  {
    quadroMedalha[i] = malloc(sizeof(int) * N);
  }

  while (menu != 6)
  {
    printf("\n\n====================================");
    printf("\n\n\n    MENU DE OPÇOES\n\n\n");
    printf("SELECIONE UMA OPÇÃO: \n");
    printf("1- Configuração de perfil\n");
    printf("2- Preencher quadro de medalhas de um pais específico\n");
    printf("3- Preencher quadro de medalhas com valores randômicos\n");  
    printf("4- Atualizar quadro de medalhas com +1 medalha para um país específico\n");
    printf("5- Exibir quadro de medalhas\n");
    printf("6- Finalizar programa \n");
    printf("\n\n====================================");
    printf("\n \n");
    scanf("%d", &menu);
    printf("\n====================================\n");
    
    switch(menu)
    {
      case 1:
        identificacao(&identificar);
        break;

      case 2:
        quadro_medalhasPais(&pais_selecionado);
        break;

      case 3:
        quadro_medalhasGeral(&pais_selecionado, quadroMedalha, identificar.n);
        break;
        
      case 4:
        atualizarQuadro(&pais_selecionado, quadroMedalha);
        break;
      /*
      case 5:
        func5();
        break;
      */

      default:
        printf("\n ");
    }
  }

  printf("\n\n Programa finalizado. Obrigado por utilizar o nosso sitema!\n\n");

  for(i = 0; i < identificar.n; i++)
  {
    free(quadroMedalha[i]);
  }

  free(quadroMedalha);
  free(identificar.paisOrig);
  free(pais_selecionado.nome_pais);

  return 0;
}