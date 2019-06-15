#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "book.h"
#include "ordenador.h"

class arquivos
{
public:
    arquivos();
    ordenador a, n;
    static bool salvarLista(QString &arquivo, ordenador &lista);
    static bool carregarLista(QString &arquivo, ordenador &lista);

};

#endif // ARQUIVOS_H
