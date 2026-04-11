#include "lista.h"

void concatenar_arquivos(No **inicio, int entrada){

	if(entrada == SISTEMA){
	//esse if é para que quando o sistema abrir ja carregue o arquivo LISTA, para que o resto do programa dependa dele para outras funções	
		DIR *d;
        struct dirent *dir;
        d = opendir("Base de Dados");

        if(d == NULL ){
            printf("ERRO : Nao foi possivel abrir pasta Base de Dados");
            exit(1);
        }
        
        FILE *p_lista = fopen("Arquivo_Geral\\LISTA_TAD.csv", "w");
        if (p_lista == NULL) {
            printf("ERRO : Nao foi possivel criar LISTA_TAD.csv\n");
            closedir(d);
            return;
        }
		
		DadosTribunal dados_arq;
		
		fprintf(p_lista, "sep=;\n"); 
        fprintf(p_lista, "sigla_tribunal;procedimento;ramo_justica;sigla_grau;uf_oj;municipio_oj;id_ultimo_oj;nome;mesano_cnm1;mesano_sent;casos_novos_2026;julgados_2026;prim_sent2026;suspensos_2026;dessobrestados_2026;cumprimento_meta1;distm2_a;julgm2_a;suspm2_a;cumprimento_meta2a;distm2_ant;julgm2_ant;suspm2_ant;desom2_ant;cumprimento_meta2ant;distm4_a;julgm4_a;suspm4_a;cumprimento_meta4a;distm4_b;julgm4_b;suspm4_b;cumprimento_meta4b\n");
    
        char caminhoFull[300];

        while ((dir = readdir(d)) != NULL){
            // Filtro de arquivos reais
            if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 && strcmp(dir->d_name, "TratamentoNULL.R") != 0){
                
                sprintf(caminhoFull, "Base de Dados/%s", dir->d_name);
                FILE *p_arq = fopen(caminhoFull, "r");
                
                int lido = 0;
                
                if(p_arq != NULL){
                	fscanf(p_arq, "%*[^\n]\n"); // Pula cabeçalho
 	
                	do{
                		No *novo = (No*)malloc(sizeof(No));
                		if (novo == NULL){
					        printf("Erro de memoria!\n");
					        break;
					    }
		
						lido = fscanf(p_arq, 
						    " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
						    novo->dados.sigla_tribunal, novo->dados.procedimento, novo->dados.ramo_justica,
						    novo->dados.sigla_grau, novo->dados.uf_oj, novo->dados.municipio_oj,
						    novo->dados.id_ultimo_oj, novo->dados.nome, novo->dados.mesano_cnm1,
						    novo->dados.mesano_sent, &novo->dados.casos_novos_2026, &novo->dados.julgados_2026,
						    &novo->dados.prim_sent2026, &novo->dados.suspensos_2026, &novo->dados.dessobrestados_2026,
						    &novo->dados.cumprimento_meta1, &novo->dados.distm2_a, &novo->dados.julgm2_a,
						    &novo->dados.suspm2_a, &novo->dados.cumprimento_meta2a, &novo->dados.distm2_ant,
						    &novo->dados.julgm2_ant, &novo->dados.suspm2_ant, &novo->dados.desom2_ant,
						    &novo->dados.cumprimento_meta2ant, &novo->dados.distm4_a, &novo->dados.julgm4_a,
						    &novo->dados.suspm4_a, &novo->dados.cumprimento_meta4a, &novo->dados.distm4_b,
						    &novo->dados.julgm4_b, &novo->dados.suspm4_b, &novo->dados.cumprimento_meta4b
						);//fscanf lido
						
						if(lido == 33){//sucesso o fscanf conseguiu ler todos os campos
	                		fprintf(p_lista, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
				                novo->dados.sigla_tribunal, novo->dados.procedimento, novo->dados.ramo_justica,
				                novo->dados.sigla_grau, novo->dados.uf_oj, novo->dados.municipio_oj,
				                novo->dados.id_ultimo_oj, novo->dados.nome, novo->dados.mesano_cnm1,
				                novo->dados.mesano_sent, novo->dados.casos_novos_2026, novo->dados.julgados_2026,
				                novo->dados.prim_sent2026, novo->dados.suspensos_2026, novo->dados.dessobrestados_2026,
				                novo->dados.cumprimento_meta1, novo->dados.distm2_a, novo->dados.julgm2_a,
				                novo->dados.suspm2_a, novo->dados.cumprimento_meta2a, novo->dados.distm2_ant,
				                novo->dados.julgm2_ant, novo->dados.suspm2_ant, novo->dados.desom2_ant,
				                novo->dados.cumprimento_meta2ant, novo->dados.distm4_a, novo->dados.julgm4_a,
				                novo->dados.suspm4_a, novo->dados.cumprimento_meta4a, novo->dados.distm4_b,
				                novo->dados.julgm4_b, novo->dados.suspm4_b, novo->dados.cumprimento_meta4b
				            );
				            inserir_na_lista(inicio, novo);

						}//final if de impressao no arquivo lista
						else  
                            free(novo);// Falha! Provavelmente chegou na linha em branco ou fim do arquivo.
                        
					}while(lido == 33);//final do-while da leitura e escrita dos campos
					
					fclose(p_arq); // Fecha o arquivo do estado atual para abrir o próximo
					
				}//final if de verificação de ponteiro nulo
                else{
                	printf("ERRO : Nao foi possivel abrir o arquivo Base de Dados/%s\n", dir->d_name);
		            closedir(d);
		            fclose(p_lista);
		            return;
				}//final else em caso de erro na abertura do arquivo
                	
			}//final do filtro de busca por arquivo no diretorio da pasta Base de dados

        }//final do while readdir
    
        // --- CRUCIAL: Sem isso o Excel não abre direito ---
        fclose(p_lista); 
        closedir(d);

        printf("Sistema carregado com sucesso!\n\n");
        
	}//final if de entrada pelo sistema
	else
		printf("\nArquivos concatenados, para vizualiza-los acesse a pasta Arquivo_Geral!\n\n");
	
}//final função concatenar arquivos

void resumo_arquivos(){
	printf("NADA");
}

void dados_municipio(){
	printf("NADA");
}

//um ** na declaração de uma função é um ponteiro de um ponteiro, p1 -> p2
void inserir_na_lista(No **inicio, No *novo_no){
    // A função assume o controle dos ponteiros
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

void criar_pastas(){
	
	system("if not exist Arquivo_Geral mkdir Arquivo_Geral");
    system("if not exist Arquivos_resumo mkdir Arquivos_resumo");
    system("if not exist Arquivos_municipios mkdir Arquivos_municipios");

}//final função criar pasta

void clear_buffer(){
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF);//Consumes characters until EOF
}//end function clear_buffer