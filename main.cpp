#include "database.h"
#include "servico.h"
#include <iostream>

int main() {
    Database db("banco.db");

    // Abre a conexão com o banco de dados
    if (!db.open()) {
        std::cerr << "Erro ao abrir o banco de dados." << std::endl;
        return 1;
    }

    // Verifica se as tabelas já existem
    if (!db.tabelaExiste("Conta")) {
        std::cout << "Criando tabelas..." << std::endl;
        if (!db.executeScript("create_tables.sql")) {
            std::cerr << "Erro ao criar tabelas. Verifique o script SQL." << std::endl;
            return 1;
        }
    } else {
        std::cout << "Tabelas já existem. Prosseguindo..." << std::endl;
    }

    // Teste do ServicoConta
    ServicoConta servicoConta(db);
    CODIGO codigoConta("ABC123");
    SENHA senhaConta(58396);

    if (servicoConta.criarConta(codigoConta, senhaConta)) {
        std::cout << "Conta criada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar conta." << std::endl;
    }

    if (servicoConta.autenticarConta(codigoConta, senhaConta)) {
        std::cout << "Autenticação bem-sucedida!" << std::endl;
    } else {
        std::cout << "Falha na autenticação." << std::endl;
    }

    // Teste do ServicoViagem
    ServicoViagem servicoViagem(db);
    CODIGO codigoViagem(codigoConta.GetCodigo());
    NOME nomeViagem("Viagem para o Nordeste");
    AVALIACAO avaliacaoViagem(5);

    if (servicoViagem.criarViagem(codigoViagem, nomeViagem, avaliacaoViagem, codigoConta)) {
        std::cout << "Viagem criada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar viagem." << std::endl;
    }

    if (servicoViagem.listarViagens(codigoConta)) {
        std::cout << "Listagem de viagens concluída." << std::endl;
    } else {
        std::cout << "Erro ao listar viagens." << std::endl;
    }

    return 0;
}