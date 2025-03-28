#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

/*
1. Programe la función `List* createList()`, la cual retorna el puntero del tipo de dato `List` con sus valores inicializados en NULL.
    > Recuerda reservar memoria al puntero usando malloc o calloc.
*/
List * createList() 
{
    List *lista = (List*) malloc(sizeof(List)) ;            // Creo "lista" y asigno memoria con malloc
    lista->head = NULL ;                                    // Inicializo head en NULL
    lista->tail = NULL ;                                    // Inicializo tail en NULL
    lista->current = NULL ;                                 // Inicializo current en NULL

    return lista ;                                          // Retorno la lista
}

/*
2. Programe las funciones `void * firstList(List * list)` y `void * nextList(List * list)`. 
    * La primera retorna el dato del primer nodo de la lista (`head`) y actualiza el current para que apunte a ese nodo. 
    * La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.
*/
void * firstList(List * list) 
{
    list->current = list->head ;                            // A current le asigno head (primera posición en la lista)

    if (list->current != NULL)                              // Pregunto si current no es NULL
        return list->current->data ;                        // Si no lo es, retorna la data

    return NULL ;                                           // Si lo es, retorna NULL
}

void * nextList(List * list) 
{
    if (list->current != NULL)                              // Pregunto si current no es NULL
        list->current = list->current->next ;               // Si no lo es, a current le asigno next (siguiente posición en la lista)
    
    if (list->current != NULL)                              // Vuelvo a preguntar si current no es NULL
        return list->current->data ;                        // Si no lo es, retorna la data

    return NULL ;                                           // Si lo es, retorna NULL
}

/*
3. Programe las funciones `void * lastList(List * list)` y `void * prevList(List * list)`.
    * La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. 
    * La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
*/
void * lastList(List * list) 
{
    list->current = list->tail ;                            // A current le asigno tail (última posición en la lista)

    if (list->current != NULL)                              // Pregunto si current no es NULL
        return list->current->data ;                        // Si no lo es, retorna la data

    return NULL ;                                           // Si lo es, retorna NULL
}

void * prevList(List * list) 
{
    if (list->current != NULL)                              // Pregunto si current no es NULL
        list->current = list->current->prev ;               // Si no lo es, a current le asigno prev (posicion anterior a current en la lista)
    
    if (list->current != NULL)                              // Vuelvo a preguntar si current no es NULL
        return list->current->data ;                        // Si no lo es, retorna la data

    return NULL ;                                           // Si lo es, retorna NULL
}

/*
4. Programe la función `void pushFront(List * list, void * data)`, la cual agrega un dato al comienzo de la lista. 
    > Puede utilizar la función `Node* createNode(void * data)` la cual crea, incializa y retorna un nodo con el dato correspondiente. 
*/
void pushFront(List * list, void * data) 
{
    Node *nuevo_nodo = createNode(data) ;
    nuevo_nodo->next = list->head ;
    
    if (list->head)
        list->head->prev = nuevo_nodo ;
    else
        list->tail = nuevo_nodo ;

    list->head = nuevo_nodo ;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

/*
5. Programe la función `void pushCurrent(List * list, void* data)`, la cual agrega un dato a continuación del nodo apuntado por `list->current`.
*/
void pushCurrent(List * list, void * data) 
{
    //Node *nuevo_nodo = createNode(data) ;
    //nuevo_nodo->next->prev = nuevo_nodo ;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

/*
6. Programe la función `void* popCurrent(List * list)`, la cual elimina el nodo que está en la posición del current de la lista 
enlazada, y además retorna el **dato** del nodo eliminado.
    > **Nota**: El current debe quedar apuntando al nodo siguiente del eliminado.
*/
void * popCurrent(List * list) 
{

    
    return NULL ;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}