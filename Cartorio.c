#include <stdio.h> // Biblioteca de comunicação com o usuário.
#include <stdlib.h> // Biblioteca de alocação de espaço em memória.
#include <locale.h> // Biblioteca de alocações de texto por região.
#include <string.h> // Biblioteca responsÃ¡vel por cuidar das string.

int registro() // Função responsável por cadastrar os usuários no sistema.
{
	// Início da criação de variáveis/string.
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string.
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando CPF do usuário.
	scanf("%s", cpf); // Escaneia valor digitado em uma string.
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string.
	
	FILE *file; // Cria o arquivo.
	file = fopen(arquivo, "w"); // Abre o arquivo para escrever ("w").
	fprintf(file,cpf); // Salva o valor da variavel no arquivo.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização.
	fprintf(file,","); // Salva vírgula (,) no arquivo.
	fclose(file); // Fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); // Solicita nome do usuário.
	scanf("%s",nome); // Escaneia valor digitado em uma string.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização.
	fprintf(file,nome); // Salva o valor da variável "nome" dentro do arquivo.
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização.
	fprintf(file,","); // Salva vírgula (,) no arquivo.
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Solicita sobrenome do usuário.
	scanf("%s",sobrenome); // Escaneia valor digitado em uma string.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização.
	fprintf(file,sobrenome); // Salva o valor da variável "sobrenome" dentro do arquivo.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização.
	fprintf(file,","); // Salva vírgula (,) no arquivo.
	fclose(file); // Fecha o arquivo.
	
	printf("Digite o cargo a ser cadastrado: "); // Solicita cargo do usuário.
	scanf("%s",cargo); // Escaneia valor digitado em uma string.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualização.
	fprintf(file,cargo); // Salva o valor da variável "cargo" dentro do arquivo.
	fclose(file); // Fecha o arquivo.
	
    system("pause"); // Pausa o programa.
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
	
	// Início da criação de variáveis/string.
	char cpf[40];
	char conteudo[200];
	// Final da criação de variáveis/string.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // Escaneia valor digitado em uma string.
	
	FILE *file; // Acessa o arquivo.
	file = fopen(cpf, "r"); // Abre o arquivo para ler ("r").
	
	if(file == NULL) // Validação para o caso de o arquivo não existir.
	{
		printf("Não foi possível abrir o aqrquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Validação para enquanto houver valores no arquivo a serem mostrados.
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause"); // Pausa o programa.
}

int deletar()
{
	char cpf[40]; // Criação de variável/string.
	
	printf("Digite o CPF do usuário a ser deletado"); // Solicita o CPF do usuário a ser deletado.
	scanf("%s",cpf);; // Escaneia valor digitado em uma string.
	
	remove(cpf); // Remove a variável/string
	
	FILE *file; // Acessa o arquivo.
	file = fopen(cpf,"r"); // Abre o arquivo para ler ("r").
	
	if(file == NULL)) // Validação para o caso de o arquivo não existir.
	{
		printf("O usuário não se encontra no sistema!.\n");
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
		
		printf("### Cartório da EBAC ###\n\n"); // Início do menu.
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); // Armazenando a escolha do usuario.
		
		system("cls"); // Responsável por limpar a tela.
		
		switch(opcao) // Início da seleção do menu.
		{
			case 1:
				registro(); // Chamada de função "registro".
				break;
			
			case 2:
				consulta(); // Chamada de função "consulta".
				break;
			
			case 3:
				deletar(); // Chamada de função "deletar".
				break;
			
			default:
				printf("Esta opção não esta disponível!\n");
				system("pause");
				break;
		} // Fim da seleção.
	}
}
