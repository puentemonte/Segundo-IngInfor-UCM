// Estibaliz Zubimendi
// A79

#include <iostream>
#include <fstream>

#include "queue_eda.h"

class propSerPar {
public:
    bool operator() (int n) {
        return n % 2 == 0;
    }
};

template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    template <class comp>
    int contarElementos(comp propiedad) const {

        // Aqui el c�digo del alumno

        // Para comprobar que un elemento a cumple una propiedad
        // se utiliza la funci�n recibida como par�metro
        // if (propiedad(a)) ...
        int cuenta = 0;
        auto it = this->prim;
        for (int i = 0; i < this->nelems; ++i) {
            if (propiedad((*it).elem))
                ++cuenta;
            it = (*it).sig;
        }
            
        return cuenta;
    }
};



bool resuelveCaso() {
    int numElem;
    std::cin >> numElem;
    if (numElem == 0) return false;

    ListaAmpliada<int> lista;
    for (size_t i = 0; i < numElem; ++i) {
        int n;
        std::cin >> n;
        lista.push(n);
    }
    int cont = lista.contarElementos(propSerPar());

    std::cout << cont << '\n';

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample-08A.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
