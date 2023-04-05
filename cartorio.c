#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro() //Funcao responsavel por cadastrar usuarios
{
	//Inicio da criacao de variaveis/string
     char arquivo[40];
	 char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     
     printf("Digite o CPF a ser cadastrado: "); //coletando informacoes do usuario
     scanf("%s", cpf); //%s refere-se a string
     
     strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
     
     FILE *file; //cria o arquivo
     file = fopen(arquivo, "w");
     fprintf(file,cpf); //salvar o valor da variavel
     fclose(file); //fecha o arquivo 
     
     file = fopen(arquivo, "a"); //separar as informações 
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o nome a ser cadastrado: ");
     scanf("%s", nome);
     
     file = fopen(arquivo, "a");
     fprintf(file,nome);
     fclose(file);
     
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o sobrenome a ser cadastrado: ");
     scanf("%s", sobrenome);
     
     file = fopen(arquivo, "a");
     fprintf(file,sobrenome);
     fclose(file);
     
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o cargo a ser cadastrado: ");
     scanf("%s", cargo);
     
     file = fopen(arquivo, "a");
     fprintf(file, cargo);
     fclose(file);
     
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}  
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sisitema! \n");
		system("pause");
	}
}

int main()
{   int opcao=0;
    int laco=1;
    
    for(laco=1;laco=1;)
   {
	
	   system("cls");
	 
	 
	   setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	   printf("###cartório da EBAC ###\n\n"); //Começo do menu
	   printf("Escolha uma opção desejada do menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
 	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("\t4 - sair do sistema \n\n");
	   printf("Opção: "); //Fim do menu 
	 
	   scanf("%d", &opcao); //Armazenando a escolha do usuario
       	 
	   system("cls"); //limpar a tela 
	   
	   switch(opcao)
	   {
	    case 1:
	    registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:	
		deletar();
		break;
		
		case 4:
	    printf("obrigado por utilizar o sitema!");
	    return 0;
	    break;
		
		default:
	    printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
		
		}
	 
	 } //Fim da seleção
        
   }  
  

