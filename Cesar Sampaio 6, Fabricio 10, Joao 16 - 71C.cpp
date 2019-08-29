#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <cstdlib>

# define LIMPAMENS " "
#define ACIMA 72
#define ABAIXO 80
#define ENTER 13
#define ESC 27



//		Integrantes do trabalho: Cesar Sampaio - Nº 6, Fabricio - Nº 10, João - Nº 16
//		Fizemos com o tema "Sistema de avaliação de serviço automotivo"
//
//		usuário para "admin" é: comin
//		senha para ser "admin" é: lindão

FILE *fp;
//---------------------------------------------------------------------------------------------------------------------------------
void modo_abrir(const char modo[])
{
	if((fp = fopen("arq.bin",modo)) == NULL)
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo");
		 exit(1);
	}
}
struct cadastro
{
	char nEmpresa[35], desc[100], tServico[40], excluidoEMP;
	long idE, idU;
	char nome[50], login[20],email[35], senha[12], excluidoUSER;
}cad;
void gotoxy( int x, int y )
{
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Menu_Principal()
{
	int aux;
	int posicao = 6, tecla;
		do{
			system("cls");	
			gotoxy(24,5);printf("____________MENU____________");
			gotoxy(23,6);printf("| Cadastrar |");
			gotoxy(23,7);printf("| Editar Cadastro |");
			gotoxy(23,8);printf("| Listar |");
			gotoxy(23,9);printf("| Deletar Cadastro |");
			gotoxy(23,10);printf("| Importar BD |");
			gotoxy(23,11);printf("| Exportar BD |");
			gotoxy(23,12);printf("| relação |");
			gotoxy(23,13);printf("| Fechar Programa |");
			for(int i=24;i<52;i++)
			{
				gotoxy(i,14);printf("%c", 238);
			}
			gotoxy(24,posicao);printf("%c%c",16,16);gotoxy(50,posicao);printf("%c%c",17,17);
			tecla=getch();
			if(tecla == ABAIXO)
			{
				posicao=posicao+1;
				if(posicao==14)
				{
					posicao=6;
				}
			
			}
			if (tecla == ACIMA)
			{
				posicao=posicao-1;
				if(posicao==5)
				{
					posicao=13;
				}
			}
			
		}while(tecla!= ENTER);
		return posicao;
}
void cEmpresa()
{
	int i=0;
	i++;
	system("cls");
	cad.idE+=i;
	gotoxy(10,4);printf("Codigo: %d",cad.idE);
	gotoxy(10,5);printf("Nome da Empresa:");
	gets(cad.nEmpresa);
	/*while(cad.nEmpresa<1)
	{
		printf("Redigite:");
		gets(cad.nEmpresa);
	}*/
	gotoxy(23,6);printf("Descricao:");
	gets(cad.desc);
	printf("Tipo de Servico");
	gets(cad.tServico);
}
void salvar_dados()
{
	if(fwrite(&cad, sizeof(cadastro), 1, fp) != 1) /* Escreve a estrutura no arquivo */
	{
		 gotoxy(18,11);printf("Erro na escrita do arquivo");
	}
	else
	{
		 fflush( fp );//descarrega o buffer no disco
		gotoxy(18,11);printf("Dados salvos com sucesso!");
	}
	getch();
}
void mostrar_dados()
{
	fclose(fp);
	if((fp=fopen("arq.bin","rb"))==NULL)
	{
		gotoxy(18,11);exit(1);
	}
	else
	{
		if(fread(&cad, sizeof(cad), 1, fp) != 1) /* Lê agenda */
		{
			gotoxy(18,11);printf("Erro na leitura do arquivo");
			getch();
		}
		else
		{
			//tela_dados("CONSULTA");
			//gotoxy(18,5);printf("%d",agenda.codigo);
			gotoxy(18,6);puts(cad.nEmpresa);
			gotoxy(18,7);puts(cad.desc);
			gotoxy(42,7);puts(cad.tServico);
			gotoxy(18,11);printf("Pressione uma tecla para continuar...");
			fflush(stdin);
			getch();
			fclose(fp);
		}
	}	
}
void cUsuario()
{
	system("cls");
	//cad.idE++;
	gotoxy(10,5);printf("Nome:");
	gets(cad.nome);
	/*while(cad.nEmpresa<1)
	{
		printf("Redigite:");
		gets(cad.nEmpresa);
	}*/
	gotoxy(23,6);printf("Email:");
	gets(cad.email);
	gotoxy(23,7);printf("Nome de Login:");
	gets(cad.senha);
	gotoxy(23,8);printf("Senha");
	gets(cad.senha);
	
}
main()
{
	modo_abrir("ab+");
	//Menu_Principal();
	cEmpresa();
	///salvar_dados();
	//mostrar_dados();
	//cUsuario();
	
	
}
