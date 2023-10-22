#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por gerenciar as strings

int registro() //fun��o para o menu de inclus�o de dados.
{
	setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem e caracteres em portugu�s
	//in�cio de cira��o de var�aveis /strings	
	char arquivo [40];
	char CPF [40];
	char Nome [40];
	char Sobrenome [40];
	char Cargo [40];
	//final da cria��o de var�aveis
	
	printf ("Insira o CPF a ser cadastrado: "); //coleta de informa��es da vari�vel
	scanf ("%s", CPF); //%s cria um registro sobre o string relacionado
	
	strcpy (arquivo, CPF); // realiza a c�pia da informa��o de um string para outro
	
	FILE *file; // Determina a cria��o de um arquivo em um banco de dados
	file = fopen(arquivo, "w"); //determina que os dados que est�o sendo inseridos ser�o para criar um novo arquivo "file" (w = writing)
	fprintf(file,CPF); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualiza��o ("a")
	fprintf (file, ","); //insere a v�rgula para separar os elementos
	fclose (file); //fecha o arquivo
	
	printf ("Digite o nome: "); //coleta de informa��o da vari�vel
	scanf ("%s", Nome); //%s cria o registro sobre a string relacionada
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualiza��o
	fprintf(file, Nome); //salva o valor da vari�vel
	fclose (file); //fecha a vari�vel atualizada
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualiza��o
	fprintf (file, ","); //insere uma v�rgula para separa��o de elementos
	fclose (file); // fecha o arquivo
	
	printf ("Digite o Sobrenome: "); //coleta de informa��o de vari�vel
	scanf ("%s", Sobrenome); //%s cria o registro sobre a string relacionada
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualiza��o
	fprintf(file, Sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo atualizado
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualiza��o
	fprintf (file, ","); //insere uma v�rgula para separa��o de elementos
	fclose (file); //fecha o arquivo
	
	printf ("Digite o Cargo: "); //coleta de informa��o de vari�vel
	scanf ("%s", Cargo); //%s cria o registro sobre a string relacionada
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualiza��o
	fprintf (file, Cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf ("\n Usu�rio cadastrado com sucesso!\n\n "); //mensagem para conclus�o do cadastro
	
	system ("pause"); //pausa para visualiza��o do usu�rio
	

}

int consulta() //fun��o para o menu de consulta de registros.
{
	setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem e caracteres em portugu�s
	
	//abertura das strings
	char CPF[40];
	char conteudo [200];
	//fechamento das strings
	
	printf ("Digite o CPF para consulta: "); //coleta de informa��o para a string
	scanf ("%s", CPF); //%s cria o registro sobre a spring relacionada
	
	FILE *file; //Determina a cria��o de um arquivo em banco de dados
	file = fopen(CPF, "r"); // sigla "r" para leitura (reading)
	
	if (file == NULL) //regra para inexist�ncia do arquivo pesquisado
	{
		printf ("\n Registro n�o localizado.\n\n"); //retorno ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //regra para leitura do arquivo enquanto obter os dados pesquisados
	{
		printf("\n As informa��es encontradas foram: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause"); //pausa para a leitura do usu�rio
	
}

int deletar() //fun��o para o menu de exclus�o de registros.
{
	char CPF[40];
	
	printf ("Digite o CPF que ser� deletado: ");
	scanf ("%s", CPF);
	
	remove (CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf ("\n Usu�rio n�o se encontra no sistema.\n\n");
	}
	
	system ("pause");
		
}


int main () // in�cio da fun��o
{ //indicador de in�cio das instru��es gerais

	int opcao=0; //indica que o espa�o alocado na mem�ria (op��o) � 0, ou seja, � parte do programa 
	int laco=1; //vari�vel criada para repeti��o
	
	for (laco=1;laco=1; ) //repeti��o criada para o "la�o", sem necessidade de incrementa��es
	{
	
		system("cls"); //apagar� as informa��es da tela quando executar o la�o
		
		setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem e caracteres em portugu�s
	
		printf("### Registro de alunos da EBAC ###\n\n"); //T�tulo principal do programa
		printf("Escolha a op��o desejada do menu:\n\n"); // mensagem de exposi��o a primeira intera��o com o usu�rio
		printf("\t1 - Incluir Registros\n");
		printf("\t2 - Consultar Registros\n");
		printf("\t3 - Deletar Registros\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Digite a op��o desejada: "); //fim do menu
	
	
		scanf("%d",&opcao); //scanf permite a escolha do menu (scanear o que o usu�rio escolhe), ja o %d permite o armazenamento de uma vari�vel inteira (int) e o & referencia a vari�vel "opcao"
	
		system ("cls"); //deleta as mensagens anteriores na tela, ap�s a escolha do menu anterior, permitindo uma melhor visualiza��o do sistema
	
		switch(opcao) //abre as op��es de sele��o ao usu�rio
		{
			case 1:
			registro (); //chamada de fun��es
			break;
			
			case 2:
			consulta (); //chamada de fun��es
			break;
			
			case 3:
			deletar (); //chamada de fun��es
			break;
			
			case 4:
			printf ("At� Logo!\n");
			return 0;
			break;
			
			default: //apresenta o que sistema far� em caso caso de n�o verdadeiro
			printf ("Op��o n�o dispon�vel.\n\n");
			system("pause");
			break;	
		} // encerra as instru��es de op��es
		

	} //final do la�o, indicando a repeti��o
	
} //indicador de finaliza��o das instru��es gerais
