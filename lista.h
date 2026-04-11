#ifndef LISTA_H
#define LISTA_H

//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>	//Essa biblioteca usaremos para caminhar sobre a base de dados

//definiões
#define USUARIO 1
#define SISTEMA 2

//structs

typedef struct {
    // Identificadores e Localização (Strings)
    char sigla_tribunal[15];    // Ex: TJSP, TRF1 
    char procedimento[100];     // Tipo de processo 
    char ramo_justica[50];      // Estadual, Federal, etc. 
    char sigla_grau[10];        // 1º grau, 2º grau 
    char uf_oj[5];              // Unidade da federação 
    char municipio_oj[100];     // Nome do município 
    char id_ultimo_oj[50];      // Identificador numérico 
    char nome[150];             // Nome do órgão julgador 
    char mesano_cnm1[15];       // Mês/ano referência Meta 1 
    char mesano_sent[15];       // Mês/ano da sentença 

    // Dados Numéricos para Cálculos (Inteiros) [cite: 8, 12]
    int casos_novos_2026;       // Campo 11
    int julgados_2026;          // Campo 12
    int prim_sent2026;          // Campo 13
    int suspensos_2026;         // Campo 14
    int dessobrestados_2026;    // Campo 15
    int cumprimento_meta1;      // Campo 16 (Indicador)
    
    // Meta 2 - Ano Atual [cite: 12]
    int distm2_a;               // Campo 17
    int julgm2_a;               // Campo 18
    int suspm2_a;               // Campo 19
    int cumprimento_meta2a;     // Campo 20
    
    // Meta 2 - Estoque Antigo [cite: 12]
    int distm2_ant;             // Campo 21
    int julgm2_ant;             // Campo 22
    int suspm2_ant;             // Campo 23
    int desom2_ant;             // Campo 24
    int cumprimento_meta2ant;   // Campo 25
    
    // Meta 4 - Grupo A [cite: 12]
    int distm4_a;               // Campo 26
    int julgm4_a;               // Campo 27
    int suspm4_a;               // Campo 28
    int cumprimento_meta4a;     // Campo 29
    
    // Meta 4 - Grupo B [cite: 12]
    int distm4_b;               // Campo 30
    int julgm4_b;               // Campo 31
    int suspm4_b;               // Campo 32
    int cumprimento_meta4b;     // Campo 33
    
} DadosTribunal;

typedef struct No{
	DadosTribunal dados;
	struct No *proximo;
} No;

//funções principais

void concatenar_arquivos(No **inicio, int entrada);
void resumo_arquivos();
void dados_municipio();

//funções de encadeamento

void inserir_na_lista(No **inicio, No *novo_no);

//funções auxiliares

void criar_pastas();
void clear_buffer();

#endif