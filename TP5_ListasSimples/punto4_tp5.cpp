#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo {
    int dato;
    pnodo siguiente;
};

// Estructura para PILA
struct tpila {
    pnodo tope;
    int contador;
};

// Estructura para COLA
struct tcola {
    pnodo inicio;
    pnodo fin;
    int contador;
};

void crear_nodo(pnodo &nuevo, int valor) {
    nuevo = new tnodo;
    if(nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
    else {
        cout << "Memoria insuficiente" << endl;
    }
}

void liberar_nodo(pnodo nodo) {
    if(nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }
}

// FUNCIONES DE PILA
void iniciar_pila(tpila &pila) {
    pila.tope = NULL;
    pila.contador = 0;
}

void push(tpila &pila, int valor) {
    pnodo nuevo;
    crear_nodo(nuevo, valor);
    if(nuevo != NULL) {
        nuevo->siguiente = pila.tope;
        pila.tope = nuevo;
        pila.contador++;
    }
}

pnodo pop(tpila &pila) {
    pnodo borrado;
    if(pila.tope == NULL) {
        borrado = NULL;
    }
    else {
        borrado = pila.tope;
        pila.tope = pila.tope->siguiente;
        borrado->siguiente = NULL;
        pila.contador--;
    }
    return borrado;
}

void mostrar_pila(tpila pila) {
    pnodo i;
    if(pila.tope != NULL) {
        cout << "Pila:" << endl;
        for(i = pila.tope; i != NULL; i = i->siguiente) {
            cout << "| " << i->dato << " |" << endl;
        }
        cout << "-----" << endl;
        cout << "Elementos en la pila: " << pila.contador << endl;
    }
    else {
        cout << "Pila vacía" << endl;
    }
}

// FUNCIONES DE COLA
void iniciar_cola(tcola &cola) {
    cola.inicio = NULL;
    cola.fin = NULL;
    cola.contador = 0;
}

void encolar(tcola &cola, int valor) {
    pnodo nuevo;
    crear_nodo(nuevo, valor);
    if(nuevo != NULL) {
        if(cola.inicio == NULL) {
            cola.inicio = nuevo;
            cola.fin = nuevo;
        }
        else {
            cola.fin->siguiente = nuevo;
            cola.fin = nuevo;
        }
        cola.contador++;
    }
}

pnodo desencolar(tcola &cola) {
    pnodo borrado;
    if(cola.inicio == NULL) {
        borrado = NULL;
    }
    else {
        if(cola.inicio == cola.fin) {
            borrado = cola.inicio;
            cola.inicio = NULL;
            cola.fin = NULL;
        }
        else {
            borrado = cola.inicio;
            cola.inicio = cola.inicio->siguiente;
            borrado->siguiente = NULL;
        }
        cola.contador--;
    }
    return borrado;
}

void mostrar_cola(tcola cola) {
    pnodo i;
    if(cola.inicio != NULL) {
        cout << "Cola: ";
        for(i = cola.inicio; i != NULL; i = i->siguiente) {
            cout << i->dato << " -> ";
        }
        cout << "NULL" << endl;
        cout << "Elementos en la cola: " << cola.contador << endl;
    }
    else {
        cout << "Cola vacía" << endl;
    }
}

int main() {
    tpila pila;
    tcola miCola;
    pnodo nodoEliminado;
    
    // PILA
    iniciar_pila(pila);
    cout << "Iniciar pila, llenar, eliminar un elemento y mostrar" << endl;
    
    push(pila, 6);
    push(pila, 23);
    push(pila, 17);
    mostrar_pila(pila);
    
    nodoEliminado = pop(pila);
    if(nodoEliminado != NULL) {
        cout << "Elemento desapilado: " << nodoEliminado->dato << endl;
        liberar_nodo(nodoEliminado);
    }
    else {
        cout << "La pila está vacía." << endl;
    }
    mostrar_pila(pila);
    
    // COLA
    cout << endl << "Iniciar cola, llenar, desencolar un elemento y mostrar" << endl;
    iniciar_cola(miCola);
    
    encolar(miCola, 3);
    encolar(miCola, 8);
    encolar(miCola, 5);
    mostrar_cola(miCola);
    
    nodoEliminado = desencolar(miCola);
    if(nodoEliminado != NULL) {
        cout << "Elemento desencolado: " << nodoEliminado->dato << endl;
        liberar_nodo(nodoEliminado);
    }
    else {
        cout << "La cola está vacía." << endl;
    }
    mostrar_cola(miCola);
    
    return 0;
}

