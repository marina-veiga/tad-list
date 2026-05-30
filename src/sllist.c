#include <stdio.h> 
#include <stdlib.h>
#include "sllist.h"

// Estrutura que aponta pro proximo da lista
typedef struct _slnode_{
    void *data;
    struct _slnode_ *next;
} SLNode;


// Estrutura que aponta pro primeiro da lista
typedef struct _sllist_{
    SLNode *first;
    SLNode *cur;
}SLList;


//Cria uma nova lista vazia
SLList *sllCreate() {
    SLList *l;
    l = (SLList*) malloc(sizeof(SLList));
    
    if (l != NULL) {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

//Destroi uma lista 
int sllDestroy(SLList *l){
    if(l!= NULL){
        if(l->first == NULL){ 
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

//Insere como primeiro elemento da lista
int sllInsertAsFirst(SLList *l, void *data){
    SLNode* newnode;
    if(l!=NULL){
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next= l->first;
            l->first= newnode;
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

//Insere como ultimo elemento da lista
int sllInsertAsLast(SLList *l, void *data){
    SLNode *last;
    SLNode* newnode;
    if(l != NULL){
        newnode = (SLNode*) malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next= NULL;

            if(l->first!=NULL){
                last= l->first;
                while(last->next!= NULL){
                    last = last->next;
                }
                last->next= newnode;
            }else{
                l->first = newnode;
            }
        }

        return TRUE;
    }

    return FALSE;
}

//Remove spec da lista 
void *sllRemoveSpec(SLList *l, void *key, int(*cmp)(void*,void*)){
    SLNode* spec, *penultimo, *next;
    void* data;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            penultimo = NULL;
            spec = l->first;
            stat = cmp(key,spec->data);
            while(stat!= TRUE && spec->next != NULL){
                penultimo = spec;
                spec = spec->next;
                stat=cmp(key, spec->data);
            }

            if(stat == TRUE){
                next= spec->next;
                data= spec->data;
                if(penultimo != NULL){
                    penultimo->next = next;
                }else{
                    l->first= next;
                }
                free(spec);
                return data;
            }
        }
    }

    return NULL;
}

//Procura por Query na lista
void *sllQuery(SLList *l, void *key, int(*cmp)(void*,void*)){
    SLNode* cur;
    int stat;

    if(l!=NULL){
        if(l->first != NULL){
            cur= l->first;
            stat= cmp(key,cur->data);
            while(stat!= TRUE && cur->next != NULL){
                cur = cur->next;
                stat = cmp(key,cur->data);
            }
            if(stat == TRUE){
                return cur->data;
            }
        }
    }
    return NULL;

}

//Pega o dado do primeiro elemento da lista
void *sllGetFirst(SLList *l);

//Pega o dado do próximo elemento da lista
void *sllGetNext(SLList *l);

//Retorna uma nova lista que é a intersecção de l1 e l2
SLList* sllInterseccao(SLList *l1, SLList *l2, int(*cmp)(void*,void*)){
    SLNode *spec1, *spec2;
    SLList *l3;
    int stat;

    if(l1!= NULL && l2!= NULL){
        if(l1->first != NULL && l2->first != NULL){
            l3= sllCreate();
            if(l3 != NULL){
                spec1 = l1->first;
                while(spec1 != NULL){
                    spec2= l2->first;
                    while(spec2 != NULL){
                        stat= cmp(spec1->data, spec2->data);
                        if(stat == TRUE){
                            sllInsertAsFirst(l3, spec1->data);
                        }
                        spec2 = spec2-> next;
                    }
                spec1= spec1->next;
                }
                
            }

            return l3;
        }
    }
    return NULL;
}

//Retorna uma nova lista que é a união de l1 e l2
SLList* sllUniao(SLList *l1, SLList *l2, int(*cmp)(void*,void*));