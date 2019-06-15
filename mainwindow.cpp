#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

int aux =0;
int aux1 =0;
int aux2=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    connect(ui->actionSalvarlidos,SIGNAL(triggered()), this, SLOT(salvarLidos()));
    connect(ui->actionSalvar_Livros_que_Estou_Lendo,SIGNAL(triggered()), this, SLOT(salvarLivrosparaler()));
    connect(ui->actionCarregar_Livros_Lidos,SIGNAL(triggered()), this, SLOT(CarregarLidos()));
    connect(ui->actionCarregar_Para_Ler,SIGNAL(triggered()), this, SLOT(CarregarparaLer()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_skoob_clicked()
{
    QUrl url = QUrl("https://www.skoob.com.br/");

    QDesktopServices::openUrl(url);
}

void MainWindow::on_pushButton_git_clicked()
{
    QUrl url = QUrl("https://github.com/ECarateu/BookShelf");

    QDesktopServices::openUrl(url);
}

void MainWindow::on_pushButton_lelivros_clicked()
{
    QUrl url = QUrl("http://lelivros.love/");

    QDesktopServices::openUrl(url);
}

void MainWindow::on_pushButton_cadastrar_clicked()
{
    int qrow = 0;
    bool stats = true;

    if(ui->lnnome->text().size() != 0 and ui->lnautor->text().size() != 0 and ui->lnnota->text().size() != 0 and ui->cbgenero->currentText() != "Selecione um Gênero" and ui->cbstatus->currentText() != "Selecione um status"){



        if(ui->cbep->currentText() == "SIM"){
            aux++;
            QString saida = QString::number(aux);

            ui->livrosep->setText(saida);

        }

        if(ui->lnrele->text().size()==0){
            QString nome = ui->lnnome->text();
            QString genero = ui->cbgenero->currentText();
            QString autor = ui->lnautor->text();
            float nota  = (ui->lnnota->text()).toFloat();

            if(ui->cbstatus->currentText() == "Livro em Andamento"){
                stats = false;
            }






            Book b(nome,genero,autor,nota,stats);

            if(stats == true){
                a.inserirlivro(b);
                qrow = ui->tbLidos->rowCount();
                ui->tbLidos->insertRow(qrow);
                inserirlivroTab(b,qrow);

            } else{
                n.inserirlivro(b);
                qrow = ui->tbanda->rowCount();
                ui->tbanda->insertRow(qrow);
                inserirlivroTab(b,qrow);
            }

        } else{
            QString nome = ui->lnnome->text();
            QString genero = ui->cbgenero->currentText();
            QString autor = ui->lnautor->text();
            float nota  = (ui->lnnota->text()).toFloat();
            if(ui->cbstatus->currentText() == "Livro em Andamento")
                stats = false;
            QString rel = ui->lnrele->text();

            Book b(nome,genero,autor,nota,stats,rel);
            if(stats == true){
                a.inserirlivro(b);
                qrow = ui->tbLidos->rowCount();
                ui->tbLidos->insertRow(qrow);
                inserirlivroTab(b,qrow);

            } else{
                n.inserirlivro(b);
                qrow = ui->tbanda->rowCount();
                ui->tbanda->insertRow(qrow);
                inserirlivroTab(b,qrow);
            }

            }
        }


    ui->lnnome->clear();
    ui->lnautor->clear();
    ui->lnrele->clear();
    ui->lnnota->clear();
    ui->cbgenero->setCurrentText("Selecione um Gênero");
    ui->cbstatus->setCurrentText("Selecione um status");
}
void MainWindow::inserirlivroTab(Book b, int row)
{
    if(b.getconcluido() == true){
            aux1++;
            QString saida1 = QString::number(aux1);
            ui->nlidos->setText(saida1);
        ui->tbLidos->setItem(row,0, new QTableWidgetItem(QString::number(b.getNota())));
        ui->tbLidos->setItem(row, 1, new QTableWidgetItem(b.getReleitura()));
        ui->tbLidos->setItem(row,2, new QTableWidgetItem(b.getNome()));
    } else{
        aux2++;
        QString saida2 = QString::number(aux2);
        ui->nanda->setText(saida2);
        ui->tbanda->setItem(row,0, new QTableWidgetItem(QString::number(b.getNota())));
        ui->tbanda->setItem(row, 1, new QTableWidgetItem(b.getReleitura()));
        ui->tbanda->setItem(row,2, new QTableWidgetItem(b.getNome()));
    }
    QString total = QString::number(aux2+aux1);
    ui->totallivros->setText(total);
}



void MainWindow::on_botao_ordenarnota_clicked()
{
    ui->tbLidos->clearContents();
    ui->tbanda->clearContents();

    a.ordenarListaNota();
    n.ordenarListaNota();
    for (int i=0; i<a.size(); i++)
    for(int i = 0; i < a.size(); i++){
        inserirlivroTab(a[i],i);
    }

    for(int i = 0; i < n.size(); i++){
        inserirlivroTab(n[i],i);
    }
}

void MainWindow::on_botao_ordenarnome_clicked()
{
    ui->tbLidos->clearContents();
    ui->tbanda->clearContents();

    a.ordenarListaNome();
    n.ordenarListaNome();
    for(int i = 0; i < a.size(); i++){
        inserirlivroTab(a[i],i);
    }

    for(int i = 0; i < n.size(); i++){
        inserirlivroTab(n[i],i);
    }
}

void MainWindow::on_btn_atualizar_clicked()
{
    if(a.size() == 0 or n.size() == 0){
       QMessageBox::warning(this, "BookShelf", "Ops! Acho que voce não preencheu as Tabelas");
    }else{
       QMessageBox::warning(this, "BookShelf", "Resultados em tela!");
}
}

    void MainWindow::salvarLidos()
    {
        QString arqname = QFileDialog::getSaveFileName(this, "Lista de Livros Lidos", "", "Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

        if(arquivos::salvarLista(arqname,a))
            QMessageBox::information(this,"Lista de Livros Lidos", " Salvos com Sucesso!");
        else
            QMessageBox::information(this,"Lista de Livros Lidos", "Não foi possível salvar!");
    }

    void MainWindow::CarregarLidos()
    {
        QString arqname = QFileDialog::getOpenFileName(this, "Lista de Livros Lidos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
        a.clear();

        if(arquivos::carregarLista(arqname,a)){

            ui->tbLidos->clearContents();
            for(int i = 0; i < a.size(); i++){
                if(i >= ui->tbLidos->rowCount())
                    ui->tbLidos->insertRow(i);
                inserirlivroTab(a[i],i);
            }
        }else{
            QMessageBox::information(this, "Carregar Lista de Livros Lidos", "Não foi possível carregar!");
        }
    }

    void MainWindow::salvarLivrosparaler()
    {
        QString arqname = QFileDialog::getSaveFileName(this, "Lista de Livros Para Ler", "", "Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

        if(arquivos::salvarLista(arqname,n))
            QMessageBox::information(this,"Salvar Livros para Ler", "Salvos com Sucesso!");
        else
            QMessageBox::information(this,"Salvar Livros para Ler", "Não foi possível salvar!");

    }
    void MainWindow::CarregarparaLer()
    {
        QString arqname = QFileDialog::getOpenFileName(this, "Lista de Livros Para Ler","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
        n.clear();

        if(arquivos::carregarLista(arqname,n)){

            ui->tbanda->clearContents();
            for(int i = 0; i < n.size(); i++){
                if(i >= ui->tbanda->rowCount()){
                    ui->tbanda->insertRow(i);
                    inserirlivroTab(n[i],i);
                }
            }
        }else{
            QMessageBox::information(this, "Carregar Lista de Livros Para Ler", "Não foi possível carregar!");
        }
    }


