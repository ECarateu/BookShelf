#ifndef BOOK_H
#define BOOK_H
#include <QObject>

class Book
{
private:
    QString nome;
    QString genero;
    QString autor;
    float nota;
    bool concluido;
    QString rel;
public:
    Book();
    Book(QString n, QString g, QString na, float nt, bool a);
    Book(QString n, QString g, QString na, float nt, bool a, QString r);


    QString getNome();
    void setNome(QString &value);

    QString getGenero();
    void setGenero(QString &value);

    QString getNomeautor();
    void setNomeautor(QString &value);

    float getNota();
    void setNota(float value);

    bool getconcluido();
    void setconcluido(bool concl);

    QString getReleitura();
    void setReleitura(QString &value);


};

#endif // BOOK_H
