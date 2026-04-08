#include "lista.h"

int main(){
	
	int opcao_usuario;
	do{
		printf("----- Abrindo menu de manipulacao de arquivo -----\n");
		printf("\n[1] = Concatenar arquivos da Base de Dados");
		printf("\n[2] = Resumo dos arquivos da Base de Dados");
		printf("\n[3] = Dados por Municipio");
		printf("\n[4] = Sair do Programa\nOpcao: ");
		
		scanf("%d", &opcao_usuario);

		switch(opcao_usuario){
			case 1: concatenar_arquivos();
				break;
			case 2: resumo_arquivos();
				break;
			case 3: dados_municipio();
				break;
			case 4: printf("\nEncerrando programa!");
				return 0;
			default: printf("\nERRO : Opcao invalida, digite uma das opcoes!");
		}
	}while(opcao_usuario >= 1 && opcao_usuario <= 4);//verifica se usuario digitou uma das opçoes
	
	return 0;
}