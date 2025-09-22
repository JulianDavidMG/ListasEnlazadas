//Abecedario en una lista enlazada en código ASCII

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista
struct Node{
    char data; // Almacenará los datos del nodo (en este caso, un caracter)
    struct Node* next; // Apuntador al siguiente nodo en la lista
};

// Función para crear un nuevo nodo
struct Node* createNode(char data){
    // Asignar memoria para un nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Verificar si la memoria se reservó correctamente
    if (newNode == NULL){
        printf("Error: Memoria no reservada");
        exit(1); // Si no hay memoria, terminamos el programa
    }

    // Asignamos el valor de 'data' al nuevo nodo y el puntero 'next' a NULL
    newNode->data = data;
    newNode->next = NULL; // Este nodo no apunta a ningún otro nodo aún
    return newNode; // Devolvemos el nuevo nodo creado
}

// Función para imprimir la lista de nodos
void printlist(struct Node* head){
    struct Node* temp = head; // Empezamos desde el primer nodo

    // Recorremos la lista hasta llegar al final (NULL)
    while (temp != NULL){
        printf("%d -> ", temp->data); // Imprimimos el valor del nodo actual en codigo ASCII
        temp = temp->next; // Avanzamos al siguiente nodo
    }
    printf("NULL\n"); // Imprimimos NULL al final de la lista para indicar que es el fin
}

int main(){
    // Crear el primer nodo con el valor a
    struct Node* head = createNode('a'); 

    // Creamos un puntero que nos ayudará a recorrer la lista (empezando desde el primer nodo)
    struct Node* current = head; 
    
    // Bucle para crear 26 nodos adicionales (en total 26 nodos)
    for (int i = 1; i < 26; i++) {
        // Creamos un nuevo nodo con el valor 'a' + i (es decir, valores de 'a' a 'z')
        struct Node* newNode = createNode('a' + i); 

        // Enlazamos el nodo previo con el nuevo nodo
        current->next = newNode;

        // Ahora 'current' apunta al nuevo nodo, para seguir construyendo la lista
        current = newNode; 
    }

    // Imprimir la lista completa de nodos
    printlist(head);

    // Liberar la memoria de todos los nodos (importante para evitar fugas de memoria)
    struct Node* temp;
    while (head != NULL) {
        // Guardamos la dirección del nodo actual
        temp = head;

        // Avanzamos al siguiente nodo en la lista
        head = head->next;

        // Liberamos la memoria del nodo guardado en 'temp'
        free(temp); 
    }

    return 0; // Terminamos el programa
}