#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDesktopServices>
#include <QUrl>
#include <QInputDialog>
#include <QWidget>

#include "arquivos.h"
#include "book.h"
#include "ordenador.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ordenador a, n;
private slots:
    void on_pushButton_skoob_clicked();

    void on_pushButton_git_clicked();

    void on_pushButton_lelivros_clicked();

    void on_pushButton_cadastrar_clicked();

    void on_botao_ordenarnota_clicked();

    void on_botao_ordenarnome_clicked();

    void on_btn_atualizar_clicked();

    void CarregarLidos();
    void salvarLidos();
    void salvarLivrosparaler();
    void CarregarparaLer();

private:
    Ui::MainWindow *ui;
    void inserirlivroTab(Book b, int row);

};

#endif // MAINWINDOW_H
