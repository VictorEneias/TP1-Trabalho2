#ifndef SERVICO_H
#define SERVICO_H

#include "database.h"
#include "dominio.h"

class ServicoConta {
private:
    Database& db;

public:
    ServicoConta(Database& database);
    bool criarConta(const CODIGO& codigo, const SENHA& senha);
    bool autenticarConta(const CODIGO& codigo, const SENHA& senha);
};  

class ServicoViagem {
private:
    Database& db;

public:
    ServicoViagem(Database& database);
    bool criarViagem(const CODIGO& codigo, const NOME& nome, const AVALIACAO& avaliacao, const CODIGO& codigoConta);
    bool listarViagens(const CODIGO& codigoConta);
};

class ServicoDestino {
private:
    Database& db;

public:
    ServicoDestino(Database& database);
    bool criarDestino(const CODIGO& codigo, const NOME& nome, const DATA& dataInicio, const DATA& dataFim, const AVALIACAO& avaliacao, const CODIGO& codigoViagem);
    bool listarDestinos(const CODIGO& codigoViagem);
};

class ServicoAtividade {
private:
    Database& db;

public:
    ServicoAtividade(Database& database);
    bool criarAtividade(const CODIGO& codigo, const NOME& nome, const DATA& data, const HORARIO& horario, const DURACAO& duracao, const DINHEIRO& preco, const AVALIACAO& avaliacao, const CODIGO& codigoDestino);
    bool listarAtividades(const CODIGO& codigoDestino);
};

class ServicoHospedagem {
private:
    Database& db;

public:
    ServicoHospedagem(Database& database);
    bool criarHospedagem(const CODIGO& codigo, const NOME& nome, const AVALIACAO& avaliacao, const DINHEIRO& diaria, const CODIGO& codigoDestino);
    bool listarHospedagens(const CODIGO& codigoDestino);
};

#endif // SERVICO_H