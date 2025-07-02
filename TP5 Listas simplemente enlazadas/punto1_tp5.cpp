#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
    int dato;
    pnodo siguiente;
};

struct tlista{
    pnodo inicio;
    int contador;
};

void crear_nodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
    else{
        cout << "Memoria insuficiente" << endl;
    }
}

void iniciar(tlista &lista){
    lista.inicio = NULL;
    lista.contador = 0;
}

void agregar_inicio(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        nuevo -> siguiente = lista.inicio;
		lista.inicio = nuevo;
    }else{
        nuevo->siguiente = lista.inicio;
        lista.inicio = nuevo;
    }
    lista.contador++;
}

void insertar_inicio(tlista &lista, int valor){
    pnodo nuevo;
    crear_nodo(nuevo, valor);
    if(nuevo != NULL){
        agregar_inicio(lista, nuevo);
    }
}

void mostrar(tlista lista){
    pnodo i;
    if(lista.inicio != NULL){
        for(i = lista.inicio; i != NULL; i = i->siguiente){
            cout << "Nodo: " << i->dato << endl;
        }
    }
    else{
        cout << "Lista vacía" << endl;
   }
}

int minimo(tlista lista){
    if(lista.inicio == NULL){
        cout << "La lista está vacía." << endl;
        return -1;
    }
    
    int min_valor = lista.inicio->dato;
    pnodo i;
    for(i = lista.inicio->siguiente; i != NULL; i = i->siguiente){
        if(i->dato < min_valor){
            min_valor = i->dato;
        }
    }
    return min_valor;
}

void liberar_nodo(pnodo nodo){
    if(nodo != NULL){
        delete nodo;
        nodo = NULL;
    }
}

int main(){
    tlista lista;
    pnodo nuevo;
    
    iniciar(lista);
    
    crear_nodo(nuevo, 8);
    if(nuevo != NULL){
        agregar_inicio(lista, nuevo);
    }
    
    crear_nodo(nuevo, 3);
    if(nuevo != NULL){
        agregar_inicio(lista, nuevo);
    }
    
    crear_nodo(nuevo, 15);
    if(nuevo != NULL){
        agregar_inicio(lista, nuevo);
    }
    
    crear_nodo(nuevo, 1);
    if(nuevo != NULL){
        agregar_inicio(lista, nuevo);
    }
    
    crear_nodo(nuevo, 20);
    if(nuevo != NULL){
        agregar_inicio(lista, nuevo);
    }
    
    mostrar(lista);
    
    int min = minimo(lista);
    if(min != -1){
        cout << "El valor mínimo de la lista es: " << min << endl;
    }
    
    return 0;
}
