#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <cliente.h>
#include <ldec.h>
#include <QMessageBox>
#include <produto.h>
#include <pedido.h>
#include <QDate>
#include <QInputDialog>
#include <pedidopersistencia.h>
#include <produtopersistencia.h>
#include <clientepersistencia.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_InserirCliente_clicked();

    void on_pushButton_cadastrarCliente_clicked();

    void on_pushButton_AlterarCliente_clicked();

    void on_pushButton_AlterarB_clicked();

    void on_pushButton_RemoverCliente_clicked();

    void on_pushButton_removerB_clicked();

    void on_pushButton_ConsultarCliente_clicked();

    void on_pushButton_Buscar_clicked();

    void on_pushButton_ListarCliente_clicked();

    void on_pushButton_BuscarLimpar_clicked();

    void on_pushButton_InserirProduto_clicked();

    void on_pushButton_cadastrarProduto_clicked();

    void on_pushButton_AlterarProduto_clicked();

    void on_pushButton_AlterarProduto_2_clicked();

    void on_pushButton_RemoverProduto_clicked();

    void on_pushButton_removerB_3_clicked();

    void on_pushButton_ConsultarProduto_clicked();

    void on_pushButton_BuscarProduto_clicked();

    void on_pushButton_ListarProduto_clicked();

    void on_pushButton_limparProduto_clicked();

    void on_pushButton_novoPedido_clicked();

    void on_pushButton_pedidoAdicionar_clicked();

    void on_pushButton_pedidoLimpar_clicked();

    void on_pushButton_pedidoRemoverProduto_clicked();

    void on_pushButton_pedidoGerar_clicked();

    void on_pushButton_ConsultarPedido_clicked();

    void on_pushButton_BuscarPedido_clicked();

    void on_pushButton_ListarPedido_clicked();

    void on_pushButton_RemoverPedido_clicked();

    void on_pushButton_removerPedidoB_clicked();

private:
    Ui::MainWindow *ui;
    wictor::LDEC<wictor::Cliente>* listaCliente;
    wictor::LDEC<wictor::Produto>* listaProduto;
    wictor::LDEC<wictor::Pedido>* listaPedido;
    wictor::LDEC<wictor::Produto>* listaPedidoProduto;
    QDate data;

    wictor::pedidoPersistencia persistenciaPedido;
    wictor::produtoPersistencia persistenciaProduto;
    wictor::clientePersistencia persistenciaCliente;

};
#endif // MAINWINDOW_H
