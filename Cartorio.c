#include <stdio.h> // Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o.
#include <string.h> // Biblioteca responsável por cuidar das string.

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	// In�cio da cria��o de vari�veis/string.
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string.
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando CPF do usu�rio.
	scanf("%s", cpf); // Escaneia valor digitado em uma string.
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string.
	
	FILE *file; // Cria o arquivo.
	file = fopen(arquivo, "w"); // Abre o arquivo para escrever ("w").
	fprintf(file,cpf); // Salva o valor da variavel no arquivo.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o.
	fprintf(file,","); // Salva v�rgula (,) no arquivo.
	fclose(file); // Fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); // Solicita nome do usu�rio.
	scanf("%s",nome); // Escaneia valor digitado em uma string.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o.
	fprintf(file,nome); // Salva o valor da vari�vel "nome" dentro do arquivo.
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o.
	fprintf(file,","); // Salva v�rgula (,) no arquivo.
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Solicita sobrenome do usu�rio.
	scanf("%s",sobrenome); // Escaneia valor digitado em uma string.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o.
	fprintf(file,sobrenome); // Salva o valor da vari�vel "sobrenome" dentro do arquivo.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o.
	fprintf(file,","); // Salva v�rgula (,) no arquivo.
	fclose(file); // Fecha o arquivo.
	
	printf("Digite o cargo a ser cadastrado: "); // Solicita cargo do usu�rio.
	scanf("%s",cargo); // Escaneia valor digitado em uma string.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualiza��o.
	fprintf(file,cargo); // Salva o valor da vari�vel "cargo" dentro do arquivo.
	fclose(file); // Fecha o arquivo.
	
    system("pause"); // Pausa o programa.
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
	// In�cio da cria��o de vari�veis/string.
	char cpf[40];
	char conteudo[200];
	// Final da cria��o de vari�veis/string.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // Escaneia valor digitado em uma string.
	
	FILE *file; // Acessa o arquivo.
	file = fopen(cpf, "r"); // Abre o arquivo para ler ("r").
	
	if(file == NULL) // Valida��o para o caso de o arquivo n�o existir.
	{
		printf("N�o foi poss�vel abrir o aqrquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Valida��o para enquanto houver valores no arquivo a serem mostrados.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause"); // Pausa o programa.
}

int deletar()
{
	char cpf[40]; // Cria��o de vari�vel/string.
	
	printf("Digite o CPF do usu�rio a ser deletado"); // Solicita o CPF do usu�rio a ser deletado.
	scanf("%s",cpf);; // Escaneia valor digitado em uma string.
	
	remove(cpf); // Remove a vari�vel/string
	
	FILE *file; // Acessa o arquivo.
	file = fopen(cpf,"r"); // Abre o arquivo para ler ("r").
	
	if(file == NULL)) // Valida��o para o caso de o arquivo n�o existir.
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system ("pause"); // Pausa o programa.
	}
}

int main() 
{
	int opcao=0; // Definindo variaveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
		
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu.
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); // Armazenando a escolha do usuario.
		
		system("cls"); // Respons�vel por limpar a tela.
		
		switch(opcao) // In�cio da sele��o do menu.
		{
			case 1:
				registro(); // Chamada de fun��o "registro".
				break;
			
			case 2:
				consulta(); // Chamada de fun��o "consulta".
				break;
			
			case 3:
				deletar(); // Chamada de fun��o "deletar".
				break;
			
			default:
				printf("Esta op��o n�o esta dispon�vel!\n");
				system("pause");
				break;
		} // Fim da sele��o.
	}
}
