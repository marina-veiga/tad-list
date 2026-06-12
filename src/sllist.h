#ifndef _SLLIST_H 
#define _SLLIST_H
#define TRUE 1
#define FALSE 0

typedef struct _sllist_ SLList; 
typedef struct _slnode_ SLNode;

//Cria uma nova lista vazia
SLList *sllCreate();

//Destroi uma lista 
int sllDestroy(SLList *l);

//Insere como primeiro elemento da lista
int sllInsertAsFirst(SLList *l, void *data);

//Insere como ultimo elemento da lista
int sllInsertAsLast(SLList *l, void *data);

//Remove spec da lista 
void *sllRemoveSpec(SLList *l, void *key, int(*cmp)(void*,void*));

//Procura por Query na lista
void *sllQuery(SLList *l, void *key, int(*cmp)(void*,void*));

//Pega o dado do primeiro elemento da lista
void *sllGetFirst(SLList *l);

//Pega o dado do próximo elemento da lista
void *sllGetNext(SLList *l);

//Retorna uma nova lista que é a intersecção de l1 e l2
SLList* sllInterseccao(SLList *l1, SLList *l2, int(*cmp)(void*,void*));

//Retorna uma nova lista que é a união de l1 e l2
SLList* sllUniao(SLList *l1, SLList *l2, int(*cmp)(void*,void*));

#endif