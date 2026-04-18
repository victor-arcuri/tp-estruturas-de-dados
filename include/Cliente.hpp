#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Acao.hpp"
#include "VetorDinamico.hpp"

/**
 * Classe Cliente
 * ---------------------------------------------------
 * Tipo de Dado Abstrato responsável por gerenciar os clientes da aplicação,
 * guardando sua carteira de ações e definindo operações de compra e venda.
 */
class Cliente {
  private:
	int id;
	VetorDinamico<Acao *> carteira;

  public:
	Cliente(int id);

	/**
	 * Função comprar_acao
	 * ---------------------------------------------------
	 * Adiciona uma ação à carteira do cliente.
	 *
	 * acao: ponteiro para a ação a ser comprada.
	 */
	void comprar_acao(Acao *acao);

	/**
	 * Função vender_acao
	 * ---------------------------------------------------
	 * Remove uma ação da carteira do cliente.
	 *
	 * acao: ponteiro para a ação a ser vendida.
	 */
	void vender_acao(Acao *acao);

	/**
	 * Função get_id
	 * ---------------------------------------------------
	 * Retorna o id do cliente.
	 *
	 * retorno: retorna um inteiro representando o id do cliente.
	 */
	int get_id();

	/**
	 * Função get_acoes
	 * ---------------------------------------------------
	 * Retorna a carteira de ações do cliente.
	 *
	 * retorno: retorna um ponteiro para a carteira de ações do cliente.
	 */
	VetorDinamico<Acao *> *get_acoes();
};

#endif
