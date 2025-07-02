#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo {
    int dato;
    pnodo siguiente;
};

struct tlista {
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

void iniciar(tlista &lista) {
    lista.inicio = NULL;
    lista.fin = NULL;
    lista.contador = 0;
}

void agregar_final(tlista &lista, pnodo nuevo) {
    if(lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else {
        lista.fin->siguiente = nuevo;
        lista.fin = nuevo;
    }
    lista.contador++;
}

void insertar_final(tlista &lista, int valor) {
    pnodo nuevo;
    crear_nodo(nuevo, valor);
    if(nuevo != NULL) {
        agregar_final(lista, nuevo);
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

void ordenar_por_seleccion(tlista &lista) {
    pnodo i, j, min;
    int temp;
    
    if(lista.inicio == NULL) {
        return;
    }
    
    for(i = lista.inicio; i != NULL; i = i->siguiente) {
        min = i;
        for(j = i->siguiente; j != NULL; j = j->siguiente) {
            if(j->dato < min->dato) {
                min = j;
            }
        }
        if(min != i) {
            temp = i->dato;
            i->dato = min->dato;
            min->dato = temp;
        }
    }
}

void combinar_listas_desordenadas(tlista &resultado, tlista lista1, tlista lista2) {
    pnodo i;
    
    for(i = lista1.inicio; i != NULL; i = i->siguiente) {
        insertar_final(resultado, i->dato);
    }

    for(i = lista2.inicio; i != NULL; i = i->siguiente) {
        insertar_final(resultado, i->dato);
    }
}

void combinar_listas_ordenadas(tlista &resultado, tlista lista1, tlista lista2) {
    pnodo i1, i2;
    
    i1 = lista1.inicio;
    i2 = lista2.inicio;

    while(i1 != NULL && i2 != NULL) {
        if(i1->dato <= i2->dato) {
            insertar_final(resultado, i1->dato);
            i1 = i1->siguiente;
        }
        else {
            insertar_final(resultado, i2->dato);
            i2 = i2->siguiente;
        }
    }

    while(i1 != NULL) {
        insertar_final(resultado, i1->dato);
        i1 = i1->siguiente;
    }

    while(i2 != NULL) {
        insertar_final(resultado, i2->dato);
        i2 = i2->siguiente;
    }
}

void liberar_nodo(pnodo nodo) {
    if(nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }
}

int main() {
    tlista lista1, lista2, lista_combinada;
    
    iniciar(lista1);
    iniciar(lista2);
    iniciar(lista_combinada);
    
    // Cargar lista 1
    insertar_final(lista1, 7);
    insertar_final(lista1, 9);
    insertar_final(lista1, 4);
    
    
    // Cargar lista 2
    insertar_final(lista2, 2);
    insertar_final(lista2, 1);
    insertar_final(lista2, 4);
    
    cout << "=== LISTAS ORIGINALES ===" << endl;
    cout<<"Lista 1"<<endl; mostrar(lista1); cout<<endl;
    cout<<"Lista 2"<<endl; mostrar(lista2); cout<<endl;
    
    // Ordenar ambas listas
    ordenar_por_seleccion(lista1);
    ordenar_por_seleccion(lista2);
    
    cout << endl << "=== LISTAS ORDENADAS ===" << endl;
    cout<<"Lista 1"<<endl; mostrar(lista1); cout<<endl;
    cout<<"Lista 2"<<endl; mostrar(lista2); cout<<endl;
    
    // Combinar listas ordenadas
    combinar_listas_ordenadas(lista_combinada, lista1, lista2);
    
    cout << endl << "=== LISTA COMBINADA ORDENADA ===" << endl;
    mostrar(lista_combinada);
    
    return 0;
}
