#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo{
                    int dato;
                    pnodo sig;
                    pnodo ant;
                    };
struct tlista{
                    pnodo inicio;
                    pnodo fin;
                    };

void IniciarLista(tlista &lista)
{
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        nuevo -> dato = valor;
        nuevo -> sig = NULL;
        nuevo -> ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

pnodo QuitarInicio(tlista &lista){
    pnodo extraido;
	
	if(lista.inicio == NULL){
		extraido = NULL;
	}else{
		if(lista.inicio->sig == NULL){
			extraido = lista.inicio;
			lista.inicio = NULL;
			lista.fin = NULL;
		}else {
			extraido = lista.inicio;
			lista.inicio = lista.inicio->sig;
			lista.inicio->ant = NULL;
			extraido->sig = NULL;
		}
	}
	return extraido;
}

pnodo QuitarFinal(tlista &lista){
	pnodo extraido;
	
	if(lista.inicio == NULL){
		extraido = NULL;
	}else{
		if(lista.inicio->sig == NULL){
			extraido = lista.inicio;
			lista.inicio = NULL;
			lista.fin = NULL;
		}else{
			
			extraido = lista.fin;
			lista.fin = lista.fin->ant;
			lista.fin->sig = NULL;
			extraido->ant = NULL;
		}
	}
	return extraido;
}
void convertir(tlista &lista, int valor){
	pnodo i,encontrado = NULL;
	if(lista.inicio != NULL){
		for(i=lista.inicio; i != NULL;i=i->sig){
			if(i->dato == valor){
				encontrado = i;
			}
		}
	}
	if(encontrado == NULL){
		cout<< "El número " << valor << " no se encuentra en la lista." <<endl;
	}else{
		int num_original=encontrado->dato;
		if(num_original == 0){
			encontrado -> dato = 0;
			cout<< "El número 0 en binario es 0" <<endl;
			cout<<"El nodo fue actualizado con el valor binario."<<endl;
		}else{
			int numero=encontrado->dato;
			int binario = 0;
			int mult = 1;
			while(numero > 0){
				int residuo = numero%2;
				binario=binario+(residuo*mult);
				mult = mult*10;
				numero = numero/2;
			}
			cout<<"El numero " << num_original <<" en binario es: "<< binario <<endl;
			encontrado->dato = binario;
			cout<<"El nodo fue actualizado con el valor binario."<<endl;
		}
	}	
}

void mostrar_lista(tlista lista){
	pnodo i;
	if(lista.inicio != NULL){
		for(i=lista.inicio; i != NULL; i= i->sig){
			cout<< i->dato <<endl;
		}
	}else{
		cout<< "La lista esta vacia." <<endl;
	}
}

int main(){
	tlista lista;
	pnodo nuevoNodo, nodoEliminado;
	//completado main para verificar que las funciones funcionen
	
	IniciarLista(lista);
	
	//agregar elementos 
	CrearNodo(nuevoNodo, 1);
	if(nuevoNodo != NULL){
		AgregarInicio(lista, nuevoNodo);
		cout<< "Elemento " << nuevoNodo->dato << " agregado al inicio." <<endl;
    }
    CrearNodo(nuevoNodo, 0);
	if(nuevoNodo != NULL){
		AgregarInicio(lista, nuevoNodo);
		cout<< "Elemento " << nuevoNodo->dato << " agregado al inicio." <<endl;
    }
    CrearNodo(nuevoNodo, 6);
	if(nuevoNodo != NULL){
		AgregarFinal(lista, nuevoNodo);
		cout<< "Elemento " << nuevoNodo->dato << " agregado al final." <<endl;
    }
    CrearNodo(nuevoNodo, 13);
	if(nuevoNodo!= NULL){
		AgregarFinal(lista, nuevoNodo);
		cout<< "Elemento " << nuevoNodo->dato << " agregado al final." <<endl;
    }
    //mostrar lista para verificar que los elementos se hayan agregado correctamente
    
    cout << "\nLista inicial:" << endl; mostrar_lista(lista);
    
    //conversion de numero con base decimal a binario
    
    int valor;
    cout << "\nIngrese elemento a convertir a binario: "; cin>>valor;
    convertir(lista,valor);
    
    cout << "\nLista después de la conversión: "<<endl; mostrar_lista(lista);
      
    //eliminar elementos 
    nodoEliminado = QuitarInicio(lista);
    if(nodoEliminado != NULL){
		cout<< "\nElemento " << nodoEliminado->dato <<" eliminado del inicio"<<endl;
    }
    
    nodoEliminado = QuitarFinal(lista);
    if(nodoEliminado != NULL){
		cout<< "Elemento " << nodoEliminado->dato <<" eliminado del final"<<endl;
    }
    
    cout << "\nLista final:" << endl; mostrar_lista(lista);
    return 0;
}

