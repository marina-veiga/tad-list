#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"


#define TRUE 1 
#define FALSE 0

//estrutura do filme
typedef struct _Filme_{
    char nome[100];
    int ano;
    float notaLetter;
}Filme; 

//função de comparação por nome
int cmpNome(void *key, void *item){
    char *chaveNome = (char *)key;
    Filme *filme =  (Filme*) item;

    if(strcmp (chaveNome, filme->nome) == 0){
        return TRUE;
    }
    return FALSE;
}

//função de comparacão por ano
int cmpAno(void *key, void* item){
    int *chaveFilme = (int *)key;
    Filme *filme = (Filme *)item;

    if(*chaveFilme == filme->ano){
        return TRUE;
    }
    return FALSE;
}

//comparação por nota no letterboxd 
int cmpNota(void *key, void* item){
    float *chaveNota = (float*) key;
    Filme *filme = (Filme *) item;

    if(*chaveNota == filme->notaLetter){
        return TRUE;
    }
    return FALSE;
}


int main(){
    //criando as 3 listas
    SLList *c1 = sllCreate();
    SLList *c2 = sllCreate();
    SLList *c3 = sllCreate();

    int opcao = -1;
    int flag;
    void* removido;
    void* resultado;

    while(opcao != 0){
        printf("\n----MENU----\n");
        printf("\n1 - Inserir em C1");
        printf("\n2 - Inserir em C2");
        printf("\n3 - Remover de C1");
        printf("\n4 - Remover de C2");
        printf("\n5 - Listar C1");
        printf("\n6 - Listar C2");
        printf("\n7 - Gerar e Listar C3 (Uniao)\n");
        printf("\n8 - Gerar e Listar C3 (Intersecao)\n");
        printf("\n0 - Sair");

        printf("\nqual opcao do menu voce deseja: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:{
                if(c1 != NULL){
                    Filme* filmeC1;
                    filmeC1= (Filme *)malloc(sizeof(Filme));
                    if(filmeC1 != NULL){
                        printf("Nome do filme: ");
                        getchar();
                        fgets(filmeC1->nome, 100, stdin);
                        printf("Ano de Lancamento: ");
                        scanf("%d", &filmeC1->ano);
                        printf("Nota no Letterboxd: ");
                        scanf("%f", &filmeC1->notaLetter);
                    
                        flag = sllInsertAsFirst(c1,(void*)filmeC1);
                        if(flag == TRUE){
                            printf("\nFilme inserido em C1 com sucesso!\n");
                        }else{
                            free(filmeC1);
                            printf("\nErro ao inserir o filme em C1!\n");
                        }
                    }
                }
            }
            break;
            case 2:{
                if(c2 != NULL){
                    Filme * filmeC2;
                    filmeC2 = (Filme*)malloc(sizeof(Filme));
                    if(filmeC2 != NULL){
                        printf("Nome do filme: ");
                        getchar();
                        fgets(filmeC2->nome, 100, stdin);
                        printf("Ano de Lancamento: ");
                        scanf("%d", &filmeC2->ano);
                        printf("Nota no Letterboxd: ");
                        scanf("%f", &filmeC2->notaLetter);

                        flag = sllInsertAsLast(c2, (void*)filmeC2);
                        if(flag == TRUE){
                            printf("\nFilme inserido em C2 com sucesso!\n");
                        }else{
                            free(filmeC2);
                            printf("\nErro ao inserir o filme em C2!\n");
                        }
                    }
                }
            }
            break;
            case 3:{
                if(c1 != NULL){
                    int opcaoRemover;
                    removido = NULL;

                    printf("\nRemover de C1 por:\n 1-Nome \n 2-Ano\n 3-Nota Letterboxd\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoRemover);

                    if(opcaoRemover == 1){
                        char nome[100];
                        printf("Digite o nome do filme: ");
                        getchar();
                        fgets(nome, 100, stdin);

                        removido = sllRemoveSpec(c1, (void*)nome, cmpNome);
                    }else if(opcaoRemover == 2){
                        int ano;
                        printf("Digite o ano de lancamento: ");
                        scanf("%d", &ano);

                        removido = sllRemoveSpec(c1,(void*)&ano, cmpAno);
                    }else if(opcaoRemover == 3){
                        float nota;
                        printf("Digite a nota do Letterboxd: ");
                        scanf("%f", &nota);
                        removido = sllRemoveSpec(c1, (void*)&nota, cmpNota);
                    }

                    if(removido != NULL){
                        free(removido);
                        printf("\nFilme removido de C1 com sucesso!\n");
                    }else{
                        printf("\nFilme nao encontrado em C1!\n");
                    }
                }
            }
            break;
            case 4:{
                if(c2 != NULL){
                    int opcaoRemover;
                    removido = NULL;

                    printf("\nRemover de C2 por:\n 1-Nome \n 2-Ano\n 3-Nota Letterboxd\n");
                    printf("Opcao: ");
                    scanf("%d", &opcaoRemover);

                    if(opcaoRemover == 1){
                        char nome[100];
                        printf("Digite o nome do filme para remover de C2: ");
                        getchar();
                        fgets(nome, 100, stdin);

                        removido= sllRemoveSpec(c2,(void*)nome,cmpNome);
                    }else if(opcaoRemover == 2){
                        int ano;
                        printf("Digite o ano de lancamento: ");
                        scanf("%d", &ano);

                        removido = sllRemoveSpec(c2, (void*)&ano, cmpAno);
                    }else if(opcaoRemover == 3){
                        float nota;
                        printf("Digite a nota do Letterboxd: ");
                        scanf("%f", &nota);

                        removido = sllRemoveSpec(c2, (void*)&nota, cmpNota);
                    }
                        
                    if(removido != NULL){
                        free(removido);
                        printf("\nFilme removido de C2 com sucesso!\n");
                    }else{
                        printf("\nFilme nao encontrado em C2!\n");
                    }
                }
            }
            break;
            case 5:{
                if(c1 != NULL){
                    printf("\n--- LISTANDO C1 ---\n");
                    resultado = sllGetFirst(c1);
                    if(resultado == NULL){
                        printf("Conjunto C1 vazio.\n");
                    }

                    Filme *lista = (Filme*) resultado;
                    while(lista != NULL){
                        printf("Nome: %s", lista->nome);
                        printf("Ano: %d\n", lista->ano);
                        printf("Nota: %.1f\n\n", lista->notaLetter);
                        lista = (Filme*)sllGetNext(c1);
                    }
                }
            }
            break;
            case 6:{
                if(c2 != NULL){
                    printf("\n--- LISTANDO C2 ---\n");
                    resultado = sllGetFirst(c2);
                    if(resultado == NULL){
                        printf("Conjunto C2 vazio.\n");
                    }

                    Filme* lista = (Filme*)resultado;
                    while(lista != NULL){
                        printf("Nome: %s", lista->nome);
                        printf("Ano: %d\n", lista->ano);
                        printf("Nota: %.1f\n\n", lista->notaLetter);
                        lista = (Filme*)sllGetNext(c2);
                    }
                }
            }
            break;
            case 7:{
                if(c1 != NULL && c2 != NULL){
                    printf("\n---LISTANDO C3 (UNIAO)---\n");
                    
                    //se existia uma uniao antiga em c3, limpamos antes de gerar a nova
                    if(c3 != NULL){
                        sllDestroy(c3);
                    }

                    //é gerado uma nova união
                    c3 = sllUniao(c1, c2, cmpNome);

                    resultado = sllGetFirst(c3);
                    if(resultado == NULL){
                        printf("Conjunto C3 vazio.\n");
                    }

                    Filme* lista = (Filme*)resultado;
                    while(lista != NULL){
                        printf("Nome: %s", lista->nome);
                        printf("Ano: %d\n", lista->ano);
                        printf("Nota: %.1f\n\n", lista->notaLetter);
                        lista = (Filme*)sllGetNext(c3);
                    }
                }
            }
            break;
            case 8:{
                if(c1 != NULL && c2 != NULL){
                    printf("\n---LISTANDO C3 (INTERSECAO)---\n");

                    if(c3 != NULL){
                        sllDestroy(c3);
                    }

                    c3 = sllInterseccao(c1, c2, cmpNome);;

                    resultado = sllGetFirst(c3);
                    if(resultado == NULL){
                        printf("Conjunto C3 (Intersecao) vazio.\n");
                    }

                    Filme* lista = (Filme*)resultado;
                    while(lista != NULL){
                        printf("Nome: %s", lista->nome);
                        printf("Ano: %d\n", lista->ano);
                        printf("Nota: %.1f\n\n", lista->notaLetter);
                        lista = (Filme*)sllGetNext(c3);
                    }
                }
            }
            break;
            case 0:{
                if (c1 != NULL && c2 != NULL) {
                    if (sllGetFirst(c1) != NULL || sllGetFirst(c2) != NULL) {
                        printf("\nvoce precisa remover todos os filmes de C1 e C2 antes de fechar o programa!\n");
                        opcao = -1; // altera a opção para o loop while não fechar
                    }else{
                        printf("\nSaindo... ate a proxima!\n");
                    }
                }
            }
            break;
        }
    }
    

    if(c1 != NULL) { 
        sllDestroy(c1);
    }

    if(c2 != NULL){
        sllDestroy(c2);
    }
    
    if(c3 != NULL){
        sllDestroy(c3);
    }

    return 0;


}