#include "lista.h"

int main(){
	
	No *inicio = NULL;
	
	criar_pastas();
	concatenar_arquivos(&inicio, SISTEMA);
	
	int opcao_usuario = 0;
	
	do{
		printf("----- Abrindo menu de manipulacao de arquivo -----\n");
		printf("\n[1] = Concatenar arquivos da Base de Dados");
		printf("\n[2] = Resumo dos arquivos da Base de Dados");
		printf("\n[3] = Dados por Municipio");
		printf("\n[4] = Sair do Programa\nOpcao: ");
		
		if(scanf("%d", &opcao_usuario) != 1) {//Proteção contra entrada de caracteres (letras)
            printf("\n[!] Erro: Digite apenas numeros.\n\n");
            clear_buffer();
            opcao_usuario = 0;//Força uma opção invalida para repetir o menu
            continue;
        }

		switch(opcao_usuario){
			case 1: concatenar_arquivos(&inicio, USUARIO);
				break;
			case 2: resumo_arquivos();
				break;
			case 3: dados_municipio();
				break;
			case 4: printf("\nEncerrando programa!");
				return 0;
			default: printf("\nERRO : Opcao invalida, digite uma das opcoes!\n");
				break;
		}
		
	}while(opcao_usuario != 4);//verifica se usuario digitou uma das opçoes
	
	return 0;
}


