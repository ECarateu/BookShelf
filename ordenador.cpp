#include "ordenador.h"
#include <algorithm>

//bool comp(Book a, Book b){

   // return a.CalcularMedia() > b.CalcularMedia();
//}

bool cimp(Book a, Book b){
    return a.getNome() < b.getNome();
}
ordenador::ordenador()
{

}

void ordenador::inserirlivro(Book b)
{
    lista.push_back(b);
}

void ordenador::ordenarListaNota()
{
    //std::stable_sort(lista.begin(), lista.end(), comp);
}

void ordenador::ordenarListaNome()
{
    std::stable_sort(lista.begin(), lista.end(), cimp);
}

void ordenador::clear()
{
    lista.clear();
}

int ordenador::size()
{
    return lista.size();
}

void ordenador::erase(int index)
{
    lista.erase(lista.begin()+index);
}

Book ordenador::find(int index)
{
    return lista[index];
}


Book ordenador::operator[](int i)
{
    return lista[i];
}






