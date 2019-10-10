
#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include <vector>
#include <iostream>

using namespace std;


template<class T, template<class...> class container = std::vector>
class heap{
private:
    container<T> contenedor;

public:
    heap();
    void subir();
    void bajar();
    void swap(T child, T parent);
    T getIzquierdo(T parent);
    T getDerecho(T parent);
    T getPadre(T child);
    container<T> &vector() {return contenedor;};


    void insert(T);
    T getMax();
    int getSize();

};

template<class T, template<class...> class container>
heap<T,container>::heap(){
}

template<class T, template<class...> class container>
int heap<T,container> :: getSize(){
    return contenedor.size();
}

template<class T, template<class...> class container>
void heap<T,container>::swap(T child, T parent) {
    T temp;
    temp = contenedor[child];
    contenedor[child] = contenedor[parent];
    contenedor[parent] = temp;
}

template<class T, template<class...> class container>
T heap<T,container> :: getPadre(T child) {
    if (child % 2 == 0)
        return (child /2 ) -1;
    else
        return child/2;

}

template<class T, template<class...> class container>
T heap<T,container> ::getIzquierdo(T parent){
    return 2*parent +1;
}

template<class T, template<class...> class container>
T heap<T,container> ::getDerecho(T parent){
    return 2 * parent + 2;
}

template<class T, template<class...> class container>
void heap<T,container> :: insert(T value) {
    contenedor.push_back(value);
    subir();
}

template<class T, template<class...> class container>
void heap <T,container>:: subir() {
    auto child = contenedor.size() - 1;
    T parent = getPadre(child);

    while (contenedor[child] > contenedor[parent] && child >=0 && parent >= 0) {

        swap(child, parent);
        child = parent;
        parent = getPadre(child);

    }
}

template<class T, template<class...> class container>
void heap<T,container> :: bajar() {
    int parent = 0;

    while (1) {
        int izq = getIzquierdo(parent);
        int der = getDerecho(parent);
        auto length = contenedor.size();
        int largest = parent;

        if (izq < length && contenedor[izq] > contenedor[largest])
            largest = izq;

        if (der < length && contenedor[der] > contenedor[largest])
            largest = der;

        if (largest != parent) {
            swap(largest, parent);
            parent = largest;
        }
        else
            break;
    }
}


template<class T, template<class...> class container>
T heap<T,container> :: getMax() {
    auto child = contenedor.size()  - 1;
    swap(child, 0);
    T value = contenedor.back();
    contenedor.pop_back();

    bajar();
    return value;

}


template <typename T>
ostream& operator<< (ostream& out, heap<T>& heap){

    int size = heap.vector().size();
    for(auto i=0;i<size;i++){
        out << heap.vector()[i] << endl;
    }
    return out;
}



template <class T>
istream& operator>> (istream& in, heap<T>& heap){
    T valor;
    in >> valor;
    heap.insert(valor);
    return in;
}


#endif //CS1103_PC2_201902_HEAP_H
