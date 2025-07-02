7.Analice los siguientes fragmentos de código, describa las acciones que realizan y determine sus propósitos.

void enigma(Nodo* nodo)
{
    if(nodo!=nullptr){
        if(nodo->getSiguiente() == nullptr)
            cout << nodo->getDato() << endl;
        else{
            enigma(nodo->getSiguiente());
            cout << nodo->getDato() << endl;
        }
    }
}

    Propósito: Imprime los elementos de la lista en orden inverso (de atrás hacia adelante).

    Funcionamiento: Utiliza recursión para llegar hasta el último nodo de la lista. Una vez que encuentra el nodo final (cuando    siguiente == nullptr), lo imprime y luego va "desenrollando" la recursión, imprimiendo cada nodo en el camino de vuelta. 

    Resultado con la lista 6->4->9->5->8->NULL:
                    8
                    5
                    9
                    4
                    6


int misterio (Nodo* nodo)
{
    if(nodo == nullptr)
        return 0;
    else
        return misterio(nodo->getSiguiente()) + 1;
}

    Propósito: Cuenta la cantidad total de nodos en la lista.

    Funcionamiento: Recorre recursivamente toda la lista. Cada llamada recursiva suma 1 al resultado final. Cuando llega al final (nodo == nullptr), retorna 0 y comienza a sumar hacia atrás.

    Resultado con la lista: Retorna 5 (hay 5 nodos en la lista).


Nodo* desconocido(Nodo* nodo)
{
    if(nodo == nullptr || nodo ->getSiguiente() == nullptr)
        return nodo;
    else
        return desconocido(nodo->getSiguiente());
}

    Propósito: Encuentra y retorna un puntero al último nodo de la lista.

    Funcionamiento: Avanza recursivamente por la lista hasta encontrar el nodo que no tiene siguiente (siguiente == nullptr) o hasta llegar a una lista vacía. Retorna el puntero a ese último nodo.

    Resultado con la lista: Retorna el puntero al nodo que contiene el valor 8.

*Utilice la lista que se muestra a continuación para probar los algoritmos:

Lista-> 6 -> 4 -> 9 -> 5 -> 8 -> NULL        
