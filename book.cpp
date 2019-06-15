#include "book.h"
#include "arquivos.h"

QString Book::getGenero()
{
    return genero;
}

void Book::setGenero(QString &value)
{
    genero = value;
}

void Book::setNome(QString &value)
{
    nome = value;
}

QString Book::getNome()
{
    return nome;
}

void Book::setNomeautor(QString &value)
{
    autor = value;
}

QString Book::getNomeautor()
{
    return autor;
}

void Book::setNota(float value)
{
    nota = value;
}

float Book::getNota()
{
    return nota;
}

void Book::setconcluido(bool concl)
{
    concluido = concl;
}

QString Book::getReleitura()
{
    return rel;
}

void Book::setReleitura(QString &value)
{
    rel = value;
}

bool Book::getconcluido()
{
    return concluido;
}

Book::Book(QString n, QString g, QString na, float nt, bool a)
{
    setNome(n);
    setGenero(g);
    setNomeautor(na);
    setNota(nt);
    setconcluido(a);

}


Book::Book(QString n, QString g, QString na, float nt, bool a, QString r)
{
    setNome(n);
    setGenero(g);
    setNomeautor(na);
    setNota(nt);
    setconcluido(a);
    setReleitura(r);
}

Book::Book()
{

}




