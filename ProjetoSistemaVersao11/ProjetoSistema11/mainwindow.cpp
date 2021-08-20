#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listaCliente = new wictor::LDEC<wictor::Cliente>;
    listaProduto = new wictor::LDEC<wictor::Produto>;
    listaPedido = new wictor::LDEC<wictor::Pedido>;

    persistenciaPedido.lerArquivo(listaPedido);
    persistenciaProduto.lerArquivo(listaProduto);
    persistenciaCliente.lerArquivo(listaCliente);

    //alterar o caminho para o diretorio onde a imagem esta localizada !!!!!!!!
    QPixmap logo("C:/Users/T-Gamer/Desktop/ProjetoSistemaVersao11/ProjetoSistema11/Image/LudmilaSoftware.png");
    QPixmap Cliente("C:/Users/T-Gamer/Desktop/ProjetoSistemaVersao11/ProjetoSistema11/Image/clientes.png");
    QPixmap Produto("C:/Users/T-Gamer/Desktop/ProjetoSistemaVersao11/ProjetoSistema11/Image/produtos.png");
    QPixmap Pedido("C:/Users/T-Gamer/Desktop/ProjetoSistemaVersao11/ProjetoSistema11/Image/pedidos.png");
    ui->label_39->setPixmap(logo);
    ui->label_40->setPixmap(logo);
    ui->label_41->setPixmap(logo);

    ui->label_clientes->setPixmap(Cliente);
    ui->label_produtos->setPixmap(Produto);
    ui->label_pedidos->setPixmap(Pedido);


    ui->textEdit_saidaCliente->setReadOnly(1);
    ui->textEdit_saidaProduto->setReadOnly(1);
    ui->textEdit_saidaPedido->setReadOnly(1);
    ui->textEdit_saidaPedidoListar->setReadOnly(1);

    ui->maconha->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(3);
    ui->stackedWidget_3->setCurrentIndex(2);

    ui->lineEdit_pedidoData->setDisabled(1);
}

MainWindow::~MainWindow()
{
    persistenciaPedido.salvarArquivo(listaPedido);
    persistenciaProduto.salvarArquivo(listaProduto);
    persistenciaCliente.salvarArquivo(listaCliente);

    delete ui;
}

//====================================== CLIENTE ===================================

void MainWindow::on_pushButton_InserirCliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_cadastrarCliente_clicked()
{
    try {
        //recebe os dados.
        wictor::Cliente* objCliente;
        QString nome = ui->lineEdit_cadastroNome->text();
        QString endereco  = ui->lineEdit_cadastroEndereco->text();
        QString telefone = ui->lineEdit_cadastroTelefone->text();
        QString cpf  = ui->lineEdit_cadastroCpf->text();
        //verifica se a lista esta vazia
        if(listaCliente->empty())
            objCliente = new wictor::Cliente(0,nome,endereco,telefone,cpf);
        else{
            //Pega id do ultimo cliente inserido e da ++
            int id = listaCliente->operator[](listaCliente->getSize() - 1).getId();
            id++;
            objCliente = new wictor::Cliente(id,nome,endereco,telefone,cpf);
        }
        //coloca na lista
        listaCliente->pushBack(*objCliente);
        ui->lineEdit_cadastroNome->clear();
        ui->lineEdit_cadastroEndereco->clear();
        ui->lineEdit_cadastroTelefone->clear();
        ui->lineEdit_cadastroCpf->clear();
        QMessageBox::information(this,"Cliente Cadastrado:",objCliente->print());

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_AlterarCliente_clicked()
{
    //muda tela
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_AlterarB_clicked()
{
    try{
        wictor::Cliente* objCliente;
        QString idLer = ui->lineEdit_alterarId->text();
        QString nome = ui->lineEdit_alterarNome->text();
        QString endereco  = ui->lineEdit_alterarEndereco->text();
        QString telefone = ui->lineEdit_alterarTelefone->text();
        QString cpf  = ui->lineEdit_alterarCpf->text();
        int id = idLer.toInt();

        bool ok = false;
        for(int i = 0;i < listaCliente->getSize() && !ok;i++){
            if(listaCliente->operator[](i).getId() == id){
                listaCliente->erase(i);
                ok = true;
            }
        }
        if(ok){
            objCliente = new wictor::Cliente(id,nome,endereco,telefone,cpf);
            listaCliente->priorityInsert(*objCliente);
            ui->lineEdit_alterarId->clear();
            ui->lineEdit_alterarNome->clear();
            ui->lineEdit_alterarEndereco->clear();
            ui->lineEdit_alterarTelefone->clear();
            ui->lineEdit_alterarCpf->clear();
            QMessageBox::information(this,"Cliente Alterado:",objCliente->print());
        }
        else
            QMessageBox::information(this,"Erro:","Cliente Não Encontrado");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_RemoverCliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_removerB_clicked()
{
    try{
        QString idLer = ui->lineEdit_removerId->text();
        int id = idLer.toInt();
        bool ok = false;

        for(int i = 0;i < listaCliente->getSize() && !ok && idLer != "";i++){
            if(listaCliente->operator[](i).getId() == id){
                QMessageBox::information(this,"Cliente Removido:",listaCliente->operator[](i).print());
                listaCliente->erase(i);
                ok = true;
            }
        }

        if(!ok)
            QMessageBox::information(this,"Erro:","Cliente Não Encontrado");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_ConsultarCliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->textEdit_saidaCliente->clear();
}

void MainWindow::on_pushButton_Buscar_clicked()
{
    try{
        QString idLer = ui->lineEdit_buscarId->text();
        QString saida;
        int id = idLer.toInt();
        bool ok = false;
        for(int i = 0;i < listaCliente->getSize() && !ok && idLer != "";i++){
            if(listaCliente->operator[](i).getId() == id){
                ok = true;
                saida = listaCliente->operator[](i).print();
            }
        }
        if(!ok)
            QMessageBox::information(this,"ERRO","Id Não Econtrado");
        else
            ui->textEdit_saidaCliente->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_ListarCliente_clicked()
{
    try{
        if(listaCliente->empty())
            QMessageBox::information(this,"Erro:","Lista Vazia");
        QString saida;
        for(int i = 0;i < listaCliente->getSize();i++){
            saida += listaCliente->operator[](i).print();
            saida += "\n=======================\n";
        }
        ui->textEdit_saidaCliente->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_BuscarLimpar_clicked()
{
    ui->textEdit_saidaCliente->clear();
    ui->lineEdit_buscarId->clear();
}

//====================================== PRODUTO ===================================


void MainWindow::on_pushButton_InserirProduto_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_pushButton_cadastrarProduto_clicked(){
    try {
        //recebe os dados.
        wictor::Produto* objProduto;
        QString codigo = ui->lineEdit_cadastroCodigo->text();
        QString descricao  = ui->lineEdit_cadastroDescricao->text();
        QString estoqueString = ui->lineEdit_cadastroEstoque->text();
        QString precoString = ui->lineEdit_cadastroPreco->text();
        double estoque = estoqueString.toDouble();
        double preco = precoString.toDouble();
        bool ok = true;
        //verifica se o codigo ja foi inserido
        for (int i = 0; i < listaProduto->getSize() && ok;i++){
            if(listaProduto->operator[](i).getCodigo() == codigo)
                ok = false;
        }
        if(ok){
            objProduto = new wictor::Produto(codigo,descricao,estoque,preco);
            //coloca na lista
            listaProduto->pushBack(*objProduto);
            ui->lineEdit_cadastroCodigo->clear();
            ui->lineEdit_cadastroDescricao->clear();
            ui->lineEdit_cadastroEstoque->clear();
            ui->lineEdit_cadastroPreco->clear();
            QMessageBox::information(this,"Produto Cadastrado:",objProduto->print());
        }
        else
            QMessageBox::information(this,"Erro:","Codigo ja Cadastrado");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_AlterarProduto_clicked(){
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_AlterarProduto_2_clicked(){
    try {
        //recebe os dados.
        wictor::Produto* objProduto;
        QString codigo = ui->lineEdit_alterarCodigo->text();
        QString descricao  = ui->lineEdit_alterarDescricao->text();
        QString estoqueString = ui->lineEdit_alterarEstoque->text();
        QString precoString = ui->lineEdit_alterarPreco->text();
        double estoque = estoqueString.toDouble();
        double preco = precoString.toDouble();
        bool ok = true;
        //verifica se o codigo ja foi inserido
        for (int i = 0; i < listaProduto->getSize() && ok;i++) {
            if(listaProduto->operator[](i).getCodigo() == codigo){
                listaProduto->erase(i);
                ok = false;
            }
        }
        if(!ok) {
            objProduto = new wictor::Produto(codigo,descricao,estoque,preco);
            listaProduto->priorityInsert(*objProduto);
            ui->lineEdit_alterarCodigo->clear();
            ui->lineEdit_alterarDescricao->clear();
            ui->lineEdit_alterarEstoque->clear();
            ui->lineEdit_alterarPreco->clear();
            QMessageBox::information(this,"Produto Alterado:",objProduto->print());
        }
        else
            QMessageBox::information(this,"Erro:","Id não Encontrado");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_RemoverProduto_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->textEdit_saidaProduto->clear();
}

void MainWindow::on_pushButton_removerB_3_clicked()
{
    try{
        QString codigo = ui->lineEdit_removerCodigo->text();
        bool ok = false;

        for(int i = 0;i < listaProduto->getSize() && !ok;i++){
            if(listaProduto->operator[](i).getCodigo() == codigo){
                QMessageBox::information(this,"Produto Removido:",listaProduto->operator[](i).print());
                listaProduto->erase(i);
                ok = true;
            }
        }
        if(!ok)
            QMessageBox::information(this,"Erro:","Produto Não Encontrado");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_ConsultarProduto_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_BuscarProduto_clicked(){
    try{
        QString codigo = ui->lineEdit_buscarCodigo->text();
        QString saida;
        bool ok = false;
        for(int i = 0;i < listaProduto->getSize() && !ok;i++){
            if(listaProduto->operator[](i).getCodigo() == codigo){
                ok = true;
                saida = listaProduto->operator[](i).print();
            }
        }
        if(!ok)
            QMessageBox::information(this,"ERRO","Id Não Econtrado");
        else
            ui->textEdit_saidaProduto->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_ListarProduto_clicked()
{
    try{
        if(listaProduto->empty())
            QMessageBox::information(this,"Erro:","Lista Vazia");
        QString saida;
        for(int i = 0;i < listaProduto->getSize();i++){
            saida += listaProduto->operator[](i).print();
            saida += "\n=======================\n";
        }
        ui->textEdit_saidaProduto->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_limparProduto_clicked(){
    ui->textEdit_saidaProduto->clear();
    ui->lineEdit_buscarCodigo->clear();
}

//==================================== PEDIDO ===================================

void MainWindow::on_pushButton_novoPedido_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
    listaPedidoProduto = new wictor::LDEC<wictor::Produto>;
    data = QDate::currentDate();
    ui->lineEdit_pedidoData->setText(data.toString());
}



void MainWindow::on_pushButton_pedidoAdicionar_clicked()
{
    try {
        wictor::Produto objProduto;
        double total = 0;
        QString saida;
        int pos, pos2;
        bool ok = false, ok2 = false;
        QString produto = QInputDialog::getText(this , "Leitura","Codigo do Produto:");

        for(int i = 0;i < listaProduto->getSize() && !ok;i++){
            if(listaProduto->operator[](i).getCodigo() == produto){
                ok = true;
                pos = i;
            }
        }
        if(ok){ //se exite esse produto
            for(int i = 0;i < listaPedidoProduto->getSize() && !ok2;i++){
                if(listaPedidoProduto->operator[](i).getCodigo() == produto){
                    ok2 = true;
                    pos2 = i;
                }
            }

            int quantidade = QInputDialog::getInt(this , "Leitura","Quantidade:");
            int aux = 0; //auxilia para ver quantidade total
            if(ok2)
                aux = listaPedidoProduto->operator[](pos2).getQuantidade();
            if(listaProduto->operator[](pos).getQuantidade() < quantidade + aux || quantidade == 0)
                QMessageBox::information(this,"ERRO","Quantidade invalida");

            else{
                objProduto = listaProduto->operator[](pos);
                if(ok2){ //se exite no pedido
                    objProduto = listaPedidoProduto->operator[](pos2);
                    objProduto.setQuantidade(objProduto.getQuantidade() + quantidade);
                    listaPedidoProduto->erase(pos2);
                }
                else
                    objProduto.setQuantidade(quantidade);

                listaPedidoProduto->pushBack(objProduto);
                saida = "";
                for (int i = 0; i < listaPedidoProduto->getSize();i++){
                    objProduto = listaPedidoProduto->operator[](i);
                    saida += "Codigo: " + objProduto.getCodigo() + " | ";
                    saida += "Quantidade: " +QString::number(objProduto.getQuantidade()) + " | ";
                    saida += "Preço unitario: R$ " +QString::number(objProduto.getPreco());
                    total += objProduto.getPreco() * objProduto.getQuantidade();
                    saida += "\n";
                }
                saida += "\nPreço Total = R$ " + QString::number(total);
                ui->textEdit_saidaPedido->setText(saida);
            }
        }
        else
            QMessageBox::information(this,"ERRO","Produto não Econtrado");

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


void MainWindow::on_pushButton_pedidoRemoverProduto_clicked()
{
    try {
        wictor::Produto objProduto;
        bool ok = false;
        int pos;
        double total = 0;
        QString saida;
        QString produto = QInputDialog::getText(this , "Leitura","Codigo do Produto:");

        for(int i = 0;i < listaPedidoProduto->getSize() && !ok;i++){
            if(listaPedidoProduto->operator[](i).getCodigo() == produto){
                ok = true;
                pos = i;
            }
        }
        if(!ok)
            QMessageBox::information(this,"ERRO","Produto não Econtrado");
        else {
            objProduto = listaPedidoProduto->operator[](pos);
            int quantidade = QInputDialog::getInt(this , "Leitura","Quantidade:");
            if(quantidade > objProduto.getQuantidade())
                QMessageBox::information(this,"ERRO","Quantidade Invalida");
            else {
                listaPedidoProduto->erase(pos);
                if(quantidade < objProduto.getQuantidade()){
                    objProduto.setQuantidade(objProduto.getQuantidade() - quantidade);
                    listaPedidoProduto->pushBack(objProduto);
                }
                saida = "";
                for (int i = 0; i < listaPedidoProduto->getSize();i++){
                    objProduto = listaPedidoProduto->operator[](i);
                    saida += "Codigo: " + objProduto.getCodigo() + " | ";
                    saida += "Quantidade: " +QString::number(objProduto.getQuantidade()) + " | ";
                    saida += "Preço unitario: R$ " +QString::number(objProduto.getPreco());
                    total += objProduto.getPreco() * objProduto.getQuantidade();
                    saida += "\n";
                }
                if(total > 0)
                    saida += "\nPreço Total = R$ " + QString::number(total);
                ui->textEdit_saidaPedido->setText(saida);
            }
        }

    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_pedidoGerar_clicked()
{
    try {
        wictor::Pedido* objPedido;
        wictor::Produto objAux;
        bool ok = false, ok2 = false;
        int id;
        QString saida;
        QString codigo = ui->lineEdit_pedidoIdCliente->text();
        int idC = codigo.toInt();
        for(int i = 0;i < listaCliente->getSize() && !ok;i++){
            if(listaCliente->operator[](i).getId() == idC){
                ok = true;
            }
        }
        if(ok){
            if(listaPedido->empty()){
                id = 0;
                objPedido = new wictor::Pedido(id,idC,data.toString(),listaPedidoProduto);
            }
            else{
                //Pega id do ultimo Pedido inserido e da ++
                id = listaPedido->operator[](listaPedido->getSize() - 1).getIdCliente();
                id++;
                objPedido = new wictor::Pedido(id,idC,data.toString(),listaPedidoProduto);
            }
            listaPedido->pushBack(*objPedido);
            saida = "numero do pedido: " + QString::number(id) + "\n";
            saida += "Cliente: " + QString::number(idC) + "\n";
            saida += "Data: " + data.toString() + "\n";
            saida += "Total: R$ " + QString::number(objPedido->calcularValorTotalCompra(),'f',2) + "\n";
            QMessageBox::information(this,"Pedido gerado:",saida);
            data = QDate::currentDate();
            ui->textEdit_saidaPedido->clear();
            ui->lineEdit_pedidoIdCliente->clear();
            //remove do estoque quantia
            for(int i = 0;i < listaPedidoProduto->getSize();i++){
                ok2 = false;
                for (int j = 0 ; j < listaProduto->getSize() && !ok2; j++){
                    if(listaProduto->operator[](j).getCodigo() ==  listaPedidoProduto->operator[](i).getCodigo()){
                        objAux = listaProduto->operator[](j);
                        int quantidade1 = listaProduto->operator[](j).getQuantidade();
                        int quantidade2 = listaPedidoProduto->operator[](i).getQuantidade();
                        listaProduto->erase(j);
                        objAux.setQuantidade(quantidade1 - quantidade2);
                        listaProduto->pushBack(objAux);
                        ok2 = true;
                    }
                }
            }
            listaPedidoProduto = new wictor::LDEC<wictor::Produto>;
        }
        else
            QMessageBox::information(this,"ERRO","Cliente Invalido");
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


void MainWindow::on_pushButton_ConsultarPedido_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_pushButton_pedidoLimpar_clicked()
{
    ui->textEdit_saidaPedidoListar->clear();
    ui->lineEdit_buscarPedido->clear();
}

void MainWindow::on_pushButton_BuscarPedido_clicked()
{
    try{
        if(listaPedido->empty())
            QMessageBox::information(this,"ERRO","Lista Vazia");
        else{
            QString codigo = ui->lineEdit_buscarPedido->text();
            int id = codigo.toInt();
            QString saida;
            bool ok = false;
            wictor::Pedido objPedido;

            for(int i = 0;i < listaPedido->getSize() && !ok && codigo != "";i++){
                if(listaPedido->operator[](i).getIdPedido() == id){
                    listaPedidoProduto = listaPedido->operator[](i).getListaProdutos();
                    ok = true;
                    objPedido = listaPedido->operator[](i);
                    saida = "---------------- Pedido Numero: " + QString::number(objPedido.getIdPedido()) + "---------------- \n";
                    saida += "Cliente: " + QString::number(objPedido.getIdCliente()) + " \n";
                    saida += "Data: " + objPedido.getDataDaCompra() + " \n";
                    saida += "Produtos:\n";
                    for (int j = 0;j < listaPedidoProduto->getSize();j++){
                        saida += "   -Codigo: " + listaPedidoProduto->operator[](j).getCodigo();
                        saida += " | Quantidade: " + QString::number(listaPedidoProduto->operator[](j).getQuantidade());
                        double totalProduto = objPedido.calcularValorTotalPorProduto(j);
                        saida += " | Total Produto: R$ " + QString::number(totalProduto,'f',2) + "\n";
                    }

                    saida += "\nTotal Compra: R$ " + QString::number(objPedido.calcularValorTotalCompra(),'f',2) + "\n";
                    saida += "============================";
                }
            }
            if(!ok)
                QMessageBox::information(this,"ERRO","Id não Encontrado");
            else
                ui->textEdit_saidaPedidoListar->setText(saida);
        }
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_ListarPedido_clicked()
{
    try {
        if(listaPedido->empty())
            QMessageBox::information(this,"ERRO","Lista Vazia");
        wictor::Pedido objPedido;
        QString saida = "";
        for(int i = 0;i < listaPedido->getSize();i++){
            objPedido = listaPedido->operator[](i);
            saida += "numero do pedido: " + QString::number(objPedido.getIdPedido()) + " \n";
            saida += "Cliente: " + QString::number(objPedido.getIdCliente()) + " \n";
            saida += "Data: " + objPedido.getDataDaCompra() + " \n";
            saida += "Total: R$ " + QString::number(objPedido.calcularValorTotalCompra(),'f',2) + "\n";
            saida += "============================\n";
        }
        ui->textEdit_saidaPedidoListar->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_RemoverPedido_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->textEdit_saidaPedidoListar->clear();
}

void MainWindow::on_pushButton_removerPedidoB_clicked()
{
    try{
        wictor::Produto objAux;
        QString codigo = ui->lineEdit_removerPedido->text();
        int id = codigo.toInt();
        QString saida;
        bool ok = false, ok2 = false;
        wictor::Pedido objPedido;

        for(int i = 0;i < listaPedido->getSize() && !ok && codigo != "";i++){
            if(listaPedido->operator[](i).getIdPedido() == id){
                ok = true;
                listaPedidoProduto = listaPedido->operator[](i).getListaProdutos();
                objPedido = listaPedido->operator[](i);
                listaPedido->erase(i);
                saida = "numero do pedido: " + QString::number(objPedido.getIdPedido()) + " \n";
                saida += "Cliente: " + QString::number(objPedido.getIdCliente()) + " \n";
                saida += "Data: " + objPedido.getDataDaCompra() + " \n";
                saida += "Total: R$ " + QString::number(objPedido.calcularValorTotalCompra(),'f',2) + "\n";
                saida += "============================";
            }
        }
        if(!ok)
            QMessageBox::information(this,"ERRO","Id não Encontrado");
        else {
            QMessageBox::information(this,"Pedido removido:",saida);
            for(int i = 0;i < listaPedidoProduto->getSize();i++){
                ok2 = false;
                for (int j = 0 ; j < listaProduto->getSize() && !ok2; j++){
                    if(listaProduto->operator[](j).getCodigo() ==  listaPedidoProduto->operator[](i).getCodigo()){
                        objAux = listaProduto->operator[](j);
                        int quantidade1 = listaProduto->operator[](j).getQuantidade();
                        int quantidade2 = listaPedidoProduto->operator[](i).getQuantidade();
                        listaProduto->erase(j);
                        objAux.setQuantidade(quantidade1 + quantidade2);
                        listaProduto->pushBack(objAux);
                        ok2 = true;
                    }
                }
                if(!ok2){
                    objAux = listaPedidoProduto->operator[](i);
                    listaProduto->pushBack(objAux);
                }
            }
        }
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
