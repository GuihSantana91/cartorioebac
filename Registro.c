#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por gerenciar as strings

int registro() //função para o menu de inclusão de dados.
{
	setlocale(LC_ALL, "Portuguese"); //definição de linguagem e caracteres em português
	//início de ciração de varíaveis /strings	
	char arquivo [40];
	char CPF [40];
	char Nome [40];
	char Sobrenome [40];
	char Cargo [40];
	//final da criação de varíaveis
	
	printf ("Insira o CPF a ser cadastrado: "); //coleta de informações da variável
	scanf ("%s", CPF); //%s cria um registro sobre o string relacionado
	
	strcpy (arquivo, CPF); // realiza a cópia da informação de um string para outro
	
	FILE *file; // Determina a criação de um arquivo em um banco de dados
	file = fopen(arquivo, "w"); //determina que os dados que estão sendo inseridos serão para criar um novo arquivo "file" (w = writing)
	fprintf(file,CPF); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualização ("a")
	fprintf (file, ","); //insere a vírgula para separar os elementos
	fclose (file); //fecha o arquivo
	
	printf ("Digite o nome: "); //coleta de informação da variável
	scanf ("%s", Nome); //%s cria o registro sobre a string relacionada
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualização
	fprintf(file, Nome); //salva o valor da variável
	fclose (file); //fecha a variável atualizada
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualização
	fprintf (file, ","); //insere uma vírgula para separação de elementos
	fclose (file); // fecha o arquivo
	
	printf ("Digite o Sobrenome: "); //coleta de informação de variável
	scanf ("%s", Sobrenome); //%s cria o registro sobre a string relacionada
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualização
	fprintf(file, Sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo atualizado
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualização
	fprintf (file, ","); //insere uma vírgula para separação de elementos
	fclose (file); //fecha o arquivo
	
	printf ("Digite o Cargo: "); //coleta de informação de variável
	scanf ("%s", Cargo); //%s cria o registro sobre a string relacionada
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualização
	fprintf (file, Cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf ("\n Usuário cadastrado com sucesso!\n\n "); //mensagem para conclusão do cadastro
	
	system ("pause"); //pausa para visualização do usuário
	

}

int consulta() //função para o menu de consulta de registros.
{
	setlocale(LC_ALL, "Portuguese"); //definição de linguagem e caracteres em português
	
	//abertura das strings
	char CPF[40];
	char conteudo [200];
	//fechamento das strings
	
	printf ("Digite o CPF para consulta: "); //coleta de informação para a string
	scanf ("%s", CPF); //%s cria o registro sobre a spring relacionada
	
	FILE *file; //Determina a criação de um arquivo em banco de dados
	file = fopen(CPF, "r"); // sigla "r" para leitura (reading)
	
	if (file == NULL) //regra para inexistência do arquivo pesquisado
	{
		printf ("\n Registro não localizado.\n\n"); //retorno ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //regra para leitura do arquivo enquanto obter os dados pesquisados
	{
		printf("\n As informações encontradas foram: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause"); //pausa para a leitura do usuário
	
}

int deletar() //função para o menu de exclusão de registros.
{
	char CPF[40];
	
	printf ("Digite o CPF que será deletado: ");
	scanf ("%s", CPF);
	
	remove (CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf ("\n Usuário não se encontra no sistema.\n\n");
	}
	
	system ("pause");
		
}


int main () // início da função
{ //indicador de início das instruções gerais

	int opcao=0; //indica que o espaço alocado na memória (opção) é 0, ou seja, é parte do programa 
	int laco=1; //variável criada para repetição
	
	for (laco=1;laco=1; ) //repetição criada para o "laço", sem necessidade de incrementações
	{
	
		system("cls"); //apagará as informações da tela quando executar o laço
		
		setlocale(LC_ALL, "Portuguese"); //definição de linguagem e caracteres em português
	
		printf("### Registro de alunos da EBAC ###\n\n"); //Título principal do programa
		printf("Escolha a opção desejada do menu:\n\n"); // mensagem de exposição a primeira interação com o usuário
		printf("\t1 - Incluir Registros\n");
		printf("\t2 - Consultar Registros\n");
		printf("\t3 - Deletar Registros\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Digite a opção desejada: "); //fim do menu
	
	
		scanf("%d",&opcao); //scanf permite a escolha do menu (scanear o que o usuário escolhe), ja o %d permite o armazenamento de uma variável inteira (int) e o & referencia a variável "opcao"
	
		system ("cls"); //deleta as mensagens anteriores na tela, após a escolha do menu anterior, permitindo uma melhor visualização do sistema
	
		switch(opcao) //abre as opções de seleção ao usuário
		{
			case 1:
			registro (); //chamada de funções
			break;
			
			case 2:
			consulta (); //chamada de funções
			break;
			
			case 3:
			deletar (); //chamada de funções
			break;
			
			case 4:
			printf ("Até Logo!\n");
			return 0;
			break;
			
			default: //apresenta o que sistema fará em caso caso de não verdadeiro
			printf ("Opção não disponível.\n\n");
			system("pause");
			break;	
		} // encerra as instruções de opções
		

	} //final do laço, indicando a repetição
	
} //indicador de finalização das instruções gerais
