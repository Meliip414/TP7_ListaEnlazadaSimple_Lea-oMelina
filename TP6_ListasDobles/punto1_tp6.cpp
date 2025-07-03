#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
void iniciarLista(pnodo &lista){
	lista=NULL;
}

void crearNodo(pnodo &nuevo){
	nuevo = new tnodo;
	if(nuevo != NULL){
		cout << "Ingrese valor: ";
		cin >> nuevo -> dato;
		nuevo-> sig = NULL;
		nuevo-> ant = NULL;
	}
}

void agregar_Inicio(pnodo &lista, pnodo nuevo){
	if(lista == NULL){
		lista = nuevo;
	}else{
		nuevo -> sig = lista;
		lista -> ant = nuevo;
		lista = nuevo;
	}
}

void agregar_Final(pnodo &lista, pnodo nuevo){
	pnodo i;
	if(lista == NULL){
		lista = nuevo;
	}else{
		for(i=lista;i->sig != NULL; i = i->sig);
		i->sig = nuevo;
		nuevo->ant = i;
	}
}

void agregar_Orden(pnodo &lista, pnodo nuevo){
	pnodo i;
	if(lista == NULL){
		lista = nuevo;
	}else{
		if(nuevo->dato < lista->dato){
			nuevo-> sig = lista;
			lista-> ant = nuevo;
			lista = nuevo;
		}else{
			for(i=lista;(i->sig != NULL) && ((i -> sig)->dato < nuevo->dato);i= i->sig);
			if(i->sig != NULL){
				nuevo->sig = i->sig;
				nuevo->ant = i;
				(i->sig) ->ant = nuevo;
				i->sig = nuevo;
			}else {
				i->sig = nuevo;
				nuevo->ant = i;
			}
		}
	}
}

pnodo quitar_inicio(pnodo &lista) {
	pnodo extraido;
	
	if(lista == NULL){
		extraido = NULL;
	}else{
		if(lista->sig == NULL){
			extraido = lista;
			lista = NULL;
		}else {
			extraido = lista;
			lista = lista->sig;
			lista->ant = NULL;
			extraido->sig = NULL;
		}
	}
	return extraido;
}

pnodo quitar_final(pnodo &lista){
	pnodo extraido, i;
	
	if(lista == NULL){
		extraido = NULL;
	}else{
		//agregado al codigo de la teoria: si hay un solo elemento
		if(lista->sig == NULL){
			extraido = lista;
			lista = NULL;
		}else{
			for(i=lista; i->sig != NULL; i = i->sig);
			extraido = i;
			(i->ant)->sig = NULL;
			i->ant = NULL;
		}
	}
	return extraido;
}
//quita un nodo ingresado por el usuario
pnodo quitar_nodo(pnodo &lista, int valor){
	pnodo extraido, i;
	
	if(lista == NULL){
		extraido = NULL;
	}else{                          
		if(lista->dato == valor){
			extraido = lista;
			//agregado al codigo de la teoria: toma en cuenta cuando el nodo sea el primero y el UNICO
			
			if(lista->sig == NULL){  //unico nodo
				lista = NULL;
			}else{                   // mas de un nodo
				lista = lista -> sig;
				lista->ant = NULL;
			}
			extraido->sig = NULL;
		}else{                      
			for(i=lista;(i != NULL) && (i->dato != valor);i = i->sig);
			if(i != NULL){            
				extraido = i;
				if(i->sig == NULL){
					(i->ant)->sig = NULL;
				}else{
					(i->ant)->sig = i->sig; 
					(i->sig)->ant = i->ant;
				}
				i->sig = NULL;
				i->ant = NULL;
			}else{
				extraido = NULL;
			}
		}
	}
	return extraido;
}

bool buscar_nodo(pnodo lista, int valor){
	pnodo i;
	bool encontrado = false;
	if(lista != NULL){
		for(i=lista; i != NULL && encontrado == false;i=i->sig){
			if(i->dato == valor){
				encontrado = true;
			}
		}
	}
	return encontrado;
}

void mostrar_lista(pnodo lista){
	pnodo i;
	if(lista != NULL){
		for(i=lista; i != NULL; i= i->sig){
			cout<< i->dato <<endl;
		}
	}else{
		cout<< "La lista esta vacia." <<endl;
	}
}

void liberar_nodo(pnodo nodo){
    if(nodo != NULL){
        delete nodo;
        nodo=NULL;
    }
}
int main(){
	pnodo Lista;
	pnodo nuevoNodo;
	pnodo nodoEliminado;
	int op;
	
	iniciarLista(Lista);
	
	do{
        cout<<endl<< " ====== MENU ======" <<endl;
        cout<< "1. Agregar al inicio" <<endl;
        cout<< "2. Agregar al final" <<endl;
        cout<< "3. Agregar en orden" <<endl;
        cout<< "4. Eliminar del inicio" <<endl;
        cout<< "5. Eliminar del final" <<endl;
        cout<< "6. Eliminar nodo especifico" <<endl;
        cout<< "7. Buscar" <<endl;
        cout<< "8. Mostrar lista" <<endl;
        cout<< "0. Salir" <<endl;
        cout<< "Seleccione una opcion: ";
        cin>> op;
        
        switch(op){
            case 1:
                crearNodo(nuevoNodo);
                if(nuevoNodo != NULL){
                    agregar_Inicio(Lista, nuevoNodo);
                    cout<< "Elemento agregado al inicio." <<endl;
                }
                break;
                
            case 2:
				//cout<<"Ingrese elemento a agregar: "; cin>>valor;
                crearNodo(nuevoNodo);
                if(nuevoNodo != NULL){
                    agregar_Final(Lista, nuevoNodo);
                    cout<< "Elemento agregado al final." <<endl;
                }
                break;
                
            case 3:
				crearNodo(nuevoNodo);
				if(nuevoNodo != NULL){
					agregar_Orden(Lista, nuevoNodo);
					cout<< "Elemento agregado segun el orden de la lista." <<endl;
				}
                break;
                
            case 4:
				if(Lista == NULL){
					cout<< "La lista está vacía." <<endl;
				}else{
					nodoEliminado = quitar_inicio(Lista);
					if(nodoEliminado != NULL){
						cout<< "Elemento eliminado del inicio: " << nodoEliminado->dato <<endl;
						liberar_nodo(nodoEliminado);
					}
				}
       
                break;
                
            case 5:
				if(Lista == NULL){
					cout<< "La lista está vacía." <<endl;
				}else{
					nodoEliminado = quitar_final(Lista);
					if(nodoEliminado != NULL){
						cout<< "Elemento eliminado del final: " << nodoEliminado->dato <<endl;
						liberar_nodo(nodoEliminado);
					}
				}
                break;
            case 6: 
				int valor;
				if(Lista == NULL){
					cout<< "La lista está vacía." <<endl;
				}else{
					cout<< "Ingrese valor a eliminar: "; cin>>valor;
					nodoEliminado = quitar_nodo(Lista,valor);
					
					if(nodoEliminado != NULL){
						cout<< "Elemento ingresado eliminado de la lista: "<< nodoEliminado->dato <<endl;
						liberar_nodo(nodoEliminado);
					}else{
						cout<< "elemento no encontrado."<<endl;
					}
				}
				
                break;
            case 7:
				int buscado;
				if(Lista==NULL){
					cout<<"La lista esta vacia."<<endl;
				}else{
					cout<< "Ingrese numero a buscar: "; cin>> buscado;
					if(buscar_nodo(Lista,buscado)){
						cout<< "Valor " << buscado << " encontrado."<<endl;
					}else{
						cout<< "Valor " << buscado << " no encontrado."<<endl;
					}
				}
                break;
                
            case 8: 
				mostrar_lista(Lista);
                break;
            case 0:
                cout<< "Saliendo..." <<endl;
                break;
                
            default:
                cout<< "Opción inválida." <<endl;
                break;
        }
    } while(op != 0);
	
	return 0;
}
