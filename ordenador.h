#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <QVector>
#include <QObject>
#include "book.h"

class ordenador
{
private:
    QVector <Book> lista;
    Book b;
public:
    ordenador();
    void inserirlivro (Book b);
    void ordenarListaNota ();
    void ordenarListaNome ();
    void setNota(int index, float value);
    void setNome(int index, QString value);

    void clear();
    int size();
    void erase(int index);
    Book find(int index);

    Book operator[](int i);
};

#endif // ORDENADOR_H
