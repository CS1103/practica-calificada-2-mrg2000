
#ifndef CS1103_PC2_201902_METODOS_GENERALES_H
#define CS1103_PC2_201902_METODOS_GENERALES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "heap.h"

using namespace std;

void AbreArchivo(string nombreFisico, fstream &archivo, ios_base::openmode modo)
{//-------------------------------------------------------------------------------------
    archivo.open(nombreFisico,modo);
    if(!archivo.is_open())
    {
        cout << "Error no se puedo abrir el archivo";
        exit(EXIT_FAILURE);
    }
}


template<class T, template<class...> class container, typename ...Types>
void insert(heap<T,container> &cont,T firstA, Types ... args) {
    cont.insert(firstA);
    (cont.insert(args),...);
}


template <class T>
void load_from (const string& file_name, heap<T>& hp){
    fstream archivo;
    string linea;
    T valor;

    borrar(hp); //Limpia el heap

    AbreArchivo(file_name,archivo,ios::in);
    while(getline(archivo,linea)){
        valor = stoi(linea);
        hp.insert(valor);
    }
}


template <class T>
void borrar (heap<T>& hp){
    hp.vector().clear();
}




#endif //CS1103_PC2_201902_METODOS_GENERALES_H
