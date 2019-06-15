#include "arquivos.h"


arquivos::arquivos()
{

}

bool arquivos::salvarLista(QString &arquivo, ordenador &lista)
{
    QFile arq(arquivo);

    if(!arq.open(QIODevice::WriteOnly))
        return false;

    QTextStream out(&arq);

    for(int i = 0; i < lista.size(); i++){
        out << lista[i].getNome() << ","
            << lista[i].getGenero() << ","
            << lista[i].getNomeautor() << ","
            << lista[i].getNota() << ","
            << lista[i].getconcluido() << ","
            << lista[i].getReleitura() << "\n";
    }

       arq.close();
       return true;
}

bool arquivos::carregarLista(QString &arquivo, ordenador &lista)
{
    QFile arq(arquivo);

       if(!arq.open(QIODevice::ReadOnly)){
           return false;
       }

       QTextStream opa(&arq);

       QString line;

       while(!opa.atEnd()){
           line = opa.readLine();

           QStringList separados = line.split(",");

           if(separados.size() < 6){
               Book b(separados[0],separados[1],separados[2],separados[3].toFloat(),separados[4].toInt());
               lista.inserirlivro(b);
           }else{
               Book b(separados[0],separados[1],separados[2],separados[3].toFloat(),separados[4].toInt(),separados[5]);
               lista.inserirlivro(b);
           }

       }
       arq.close();
       return true;
}


