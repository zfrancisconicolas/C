#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
	Node* returnAux = NULL;
	int T;
	int i;
	if(this != NULL){
		 T = ll_len(this);
		 if(nodeIndex >= 0 && nodeIndex < T){
			for(i = 0 ; i < T ; i++){
				if(i == 0){
					returnAux = this->pFirstNode;
				}
				else{
					returnAux = returnAux->pNextNode;
				}
				if(nodeIndex == i){
					break;
				}
			}
		 }
	}
	return returnAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement){
    int returnAux = -1;
	Node* nodoAnterior = NULL;
	Node* nuevoNodo = NULL;
	Node* auxNodo = NULL;
	int len = ll_len(this);
	if(this != NULL){
		nuevoNodo = (Node*) malloc(sizeof(Node));
		auxNodo = getNode(this, nodeIndex);
		nuevoNodo->pNextNode = NULL;
		nodoAnterior = getNode(this, nodeIndex-1);
		if(nodeIndex > 0 && nodeIndex < len){
			if(nodoAnterior != NULL){
				nodoAnterior->pNextNode = nuevoNodo;
			}
			nuevoNodo->pElement = pElement;
			nuevoNodo->pNextNode = auxNodo;
			returnAux = 0;
		}
		else if(nodeIndex == 0){
			this->pFirstNode = nuevoNodo;
			nuevoNodo->pElement = pElement;
			nuevoNodo->pNextNode = auxNodo;
			returnAux = 0;
		}
		else if(nodeIndex == len){
			nuevoNodo->pElement = pElement;
			nodoAnterior->pNextNode = nuevoNodo;
			returnAux = 0;
		}
	}
	if(returnAux == 0){
		this->size++;
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;
    if(this != NULL){
		returnAux = addNode(this, ll_len(this), pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){
	void* returnAux = NULL;
	Node* auxNodo = NULL;
	int len = ll_len(this);
	if(this != NULL && index >= 0 && index < len){
		auxNodo = getNode(this, index);
		if(auxNodo != NULL){
			returnAux = (void*)auxNodo->pElement;
		}
	}
	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement){
	Node* auxNode;
    int returnAux = -1;
	int len = ll_len(this);
    if(this != NULL && index >= 0 && index < len){
    	auxNode = getNode(this, index);
		auxNode->pElement = pElement;
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */

int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    Node* previousNode;
    Node* auxNode;
    int len = ll_len(this);
    if(this!=NULL && index >= 0 && index < len){
    	if(index==0){
    		auxNode = getNode(this, index);
    		if(auxNode != NULL){
    			this->pFirstNode = auxNode->pNextNode;
    			returnAux = 0;
    			this->size--;
    		}
    	}
    	else{
    		previousNode = getNode(this, index-1);
    		if(previousNode != NULL){
    			auxNode = getNode(this, index);
   				if(auxNode != NULL){
   					previousNode->pNextNode = auxNode->pNextNode;
       				returnAux = 0;
       				this->size--;
   				}
    		}
   		}
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this){
    int returnAux = -1;
    int i;
    if(this != NULL){
		int T = ll_len(this);
		for(i = 0 ; i < T ; i++){
			ll_remove(this, i);
		}
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int i;
    Node* auxNode = NULL;
    if(this != NULL){
		int T = ll_len(this);
		for(i = 0 ; i < T ; i++){
			auxNode = getNode(this, i);
			if(auxNode->pElement == pElement){
				returnAux = i;
			}
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
    	int T = ll_len(this);
    	if(T == 0){
    		returnAux = 1;
    	}
    	else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;
    if(this != NULL){
    	returnAux = addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index){
    void* returnAux = NULL;
    Node* auxNode;
    if(this != NULL){
		auxNode = ll_get(this, index);
		if(auxNode != NULL){
			ll_remove(this, index);
		}
		returnAux = auxNode;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = 0;
    int i;
	Node* auxNode = NULL;
	if(this != NULL){
		int T = ll_len(this);
		for(i = 0 ; i < T ; i++){
			//reutilizar funcion
			auxNode = getNode(this, i);
			if(auxNode->pElement == pElement){
				returnAux = 1;
			}
		}
	}
	else{
		returnAux = -1;
	}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2){
	int i;
    int returnAux = -1;
    Node* auxNode;
    if(this != NULL && this2 != NULL){
    	returnAux = 0;
    	int T2 = ll_len(this2);
		for(i = 0 ; i < T2 ; i++){
			auxNode = getNode(this2, i);
			if(auxNode != NULL){
				returnAux = ll_contains(this, auxNode->pElement);
				if(returnAux == 0){
					return returnAux;
				}
			}
		}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to){
    LinkedList* cloneArray = NULL;
    Node* auxNode;
    if(this != NULL){
    	int len = ll_len(this);
    	if(!(from < 0 || from > len) && !(to <= from || to > len)){
        	cloneArray = ll_newLinkedList();
    		for(int i = from ; i < to ; i++){
    			auxNode = getNode(this, i);
    			if(auxNode != NULL){
        			addNode(cloneArray, i, auxNode->pElement);
    			}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    int i;
    Node* auxNode;
    if(this != NULL){
    	cloneArray = ll_newLinkedList();
    	for(i = 0 ; i < len ; i++){
    		auxNode = getNode(this, i);
    		//modificar por add
    		addNode(cloneArray, i, auxNode->pElement);
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    int len = ll_len(this);
    Node* firstNode;
    Node* secondNode;
    void* auxElement;
    //agregar verificacion de nulidad del elemento
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)){
    	int orderReturn;
    	for(int i = 0; i < len - 1 ; i++){
    		for(int j = i + 1 ; j < len ; j++){
    			firstNode = getNode(this, i);
    			secondNode = getNode(this, j);
    			orderReturn = pFunc(firstNode->pElement, secondNode->pElement);
    			if(order == 1){
    				if(orderReturn == 1){
    					auxElement = firstNode->pElement;
						ll_set(this, i, secondNode->pElement);
						ll_set(this, j, auxElement);
    				}
    			}
    			if(order == 0){
    				if(orderReturn == -1){
		    			auxElement = firstNode->pElement;
						ll_set(this, i, secondNode->pElement);
						ll_set(this, j, auxElement);
    				}
    			}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;

}

