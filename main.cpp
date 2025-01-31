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
// Cria uma conta
    ServicoConta servicoConta(db);
    CODIGO codigoConta("CONTA1");
    SENHA senhaConta(68503);

    if (servicoConta.criarConta(codigoConta, senhaConta)) {
        std::cout << "Conta criada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar conta." << std::endl;
    }

    // Cria uma viagem associada à conta
    ServicoViagem servicoViagem(db);
    CODIGO codigoViagem("VIAG01");
    NOME nomeViagem("Viagem para o Nordeste");
    AVALIACAO avaliacaoViagem(5);

    if (servicoViagem.criarViagem(codigoViagem, nomeViagem, avaliacaoViagem, codigoConta)) {
        std::cout << "Viagem criada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar viagem." << std::endl;
    }

    // Cria um destino associado à viagem
    ServicoDestino servicoDestino(db);
    CODIGO codigoDestino("DEST01");
    NOME nomeDestino("Praia de Porto de Galinhas");
    DATA dataInicio("01-01-24");
    DATA dataFim("10-01-24");
    AVALIACAO avaliacaoDestino(5);

    if (servicoDestino.criarDestino(codigoDestino, nomeDestino, dataInicio, dataFim, avaliacaoDestino, codigoViagem)) {
        std::cout << "Destino criado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar destino." << std::endl;
    }

    // Cria uma atividade associada ao destino
    ServicoAtividade servicoAtividade(db);
    CODIGO codigoAtividade("ATIV01");
    NOME nomeAtividade("Passeio de buggy");
    DATA dataAtividade("05-01-24");
    HORARIO horarioAtividade("10:00");
    DURACAO duracaoAtividade(120);
    DINHEIRO precoAtividade(150.0);
    AVALIACAO avaliacaoAtividade(5);

    if (servicoAtividade.criarAtividade(codigoAtividade, nomeAtividade, dataAtividade, horarioAtividade, duracaoAtividade, precoAtividade, avaliacaoAtividade, codigoDestino)) {
        std::cout << "Atividade criada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar atividade." << std::endl;
    }

    // Cria uma hospedagem associada ao destino
    ServicoHospedagem servicoHospedagem(db);
    CODIGO codigoHospedagem("HOSP01");
    NOME nomeHospedagem("Resort Porto de Galinhas");
    AVALIACAO avaliacaoHospedagem(5);
    DINHEIRO diariaHospedagem(500.0);

    if (servicoHospedagem.criarHospedagem(codigoHospedagem, nomeHospedagem, avaliacaoHospedagem, diariaHospedagem, codigoDestino)) {
        std::cout << "Hospedagem criada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao criar hospedagem." << std::endl;
    }

    // Testa as funções de atualização
    std::cout << "\nTestando funções de atualização...\n";

    // Atualiza a viagem
    NOME novoNomeViagem("Viagem Nordeste Atualizada");
    AVALIACAO novaAvaliacaoViagem(4);

    if (servicoViagem.atualizarViagem(codigoViagem, novoNomeViagem, novaAvaliacaoViagem)) {
        std::cout << "Viagem atualizada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao atualizar viagem." << std::endl;
    }

    // Atualiza o destino
    NOME novoNomeDestino("Porto Galinhas Atualizada");
    DATA novaDataInicio("02-01-24");
    DATA novaDataFim("11-01-24");
    AVALIACAO novaAvaliacaoDestino(4);

    if (servicoDestino.atualizarDestino(codigoDestino, novoNomeDestino, novaDataInicio, novaDataFim, novaAvaliacaoDestino)) {
        std::cout << "Destino atualizado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao atualizar destino." << std::endl;
    }

    // Atualiza a atividade
    NOME novoNomeAtividade("Passeio buggy Atualizado");
    DATA novaDataAtividade("06-01-24");
    HORARIO novoHorarioAtividade("11:00");
    DURACAO novaDuracaoAtividade(150);
    DINHEIRO novoPrecoAtividade(200.0);
    AVALIACAO novaAvaliacaoAtividade(4);

    if (servicoAtividade.atualizarAtividade(codigoAtividade, novoNomeAtividade, novaDataAtividade, novoHorarioAtividade, novaDuracaoAtividade, novoPrecoAtividade, novaAvaliacaoAtividade)) {
        std::cout << "Atividade atualizada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao atualizar atividade." << std::endl;
    }

    // Atualiza a hospedagem
    NOME novoNomeHospedagem("Resort Galinhas Atualizado");
    AVALIACAO novaAvaliacaoHospedagem(4);
    DINHEIRO novaDiariaHospedagem(600.0);

    if (servicoHospedagem.atualizarHospedagem(codigoHospedagem, novoNomeHospedagem, novaAvaliacaoHospedagem, novaDiariaHospedagem)) {
        std::cout << "Hospedagem atualizada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao atualizar hospedagem." << std::endl;
    }

    // Deleta a conta (deve deletar tudo devido ao ON DELETE CASCADE)
    std::cout << "\nDeletando a conta...\n";
    if (servicoConta.deletarConta(codigoConta)) {
        std::cout << "Conta deletada com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao deletar conta." << std::endl;
    }

    return 0;
}