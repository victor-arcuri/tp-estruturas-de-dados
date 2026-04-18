#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Acao.hpp"
#include "Cliente.hpp"
#include "Metricas.hpp"
#include "VetorDinamico.hpp"

/**
 * Classe Sistema
 * ---------------------------------------------------
 * Tipo de Dado Abstrato responsável por gerenciar as requisoções de usuários,
 * guardar as ações e suas ordenações por métrica e gerenciar a lógica de consulta.
 */
class Sistema {
  private:
	int janela_w;
	VetorDinamico<Cliente *> clientes;
	VetorDinamico<Acao *> acoes;
	VetorDinamico<Acao *> ordenacao_ret;
	VetorDinamico<Acao *> ordenacao_avgret;
	VetorDinamico<Acao *> ordenacao_stab;
	VetorDinamico<Acao *> ordenacao_cons;
	bool ret;
	bool avgret;
	bool stab;
	bool cons;

	/**
	 * Função retomar_cliente
	 * ---------------------------------------------------
	 * Retorna um Cliente a partir de seu id.
	 *
	 * id: inteiro que representa o índice do cliente no VetorDinamico de Clientes.
	 *
	 * retorno: ponteiro para o Cliente de id especificado.
	 */
	Cliente *retomar_cliente(int id);

	/**
	 * Função retomar_acao
	 * ---------------------------------------------------
	 * Retorna uma Ação a partir de seu id.
	 *
	 * id: inteiro que representa o índice da ação no VetorDinamico de Ações.
	 *
	 * retorno: ponteiro para a Ação de id especificado.
	 */
	Acao *retomar_acao(int id);

	/**
	 * Função OrdenaMetrica
	 * ---------------------------------------------------
	 * Ordena as Ações a partir de uma métrica específica.
	 *
	 * metrica: enum referente a métrica para servir de base para a ordenação das Ações.
	 */
	void OrdenaMetrica(Metricas::Metrica metrica);

	/**
	 * Função OrdenarMetricasAtivas
	 * ---------------------------------------------------
	 * Ordena as Ações a partir de todas as métrica ativas definidas no início do programa.
	 */
	void OrdenarMetricasAtivas();

  public:
	Sistema();
	~Sistema();

	/**
	 * Função set_w
	 * ---------------------------------------------------
	 * Define o tamanho da janela de cotações de todas as Ações.
	 *
	 * w: inteiro que representa o tamanho da janela de cotações.
	 */
	void set_w(int w);

	/**
	 * Função adicionar_acao
	 * ---------------------------------------------------
	 * Adiciona uma Ação ao VetorDinamico acoes, tornando-a disponível para compra por Clientes.
	 *
	 * id: inteiro que representa o id da ação.
	 */
	void adicionar_acao(int id);

	/**
	 * Função adicionar_cliente
	 * ---------------------------------------------------
	 * Adiciona um Cliente ao VetorDinamico clientes, tornando-o um usuário ativo do sistema.
	 *
	 * id: inteiro que representa o id do Cliente.
	 */
	void adicionar_cliente(int id);

	/**
	 * Função nova_cotacao
	 * ---------------------------------------------------
	 * Registra uma nova cotação para uma Ação especifica.
	 *
	 * id: inteiro que representa o id da Ação.
	 * preco: double que representa o valor da nova cotação.
	 */
	void nova_cotacao(int id, double preco);

	/**
	 * Função comprar_acao
	 * ---------------------------------------------------
	 * Solicita a compra de uma determinada Ação para um determinado Cliente.
	 *
	 * id_cliente: inteiro que representa o id do Cliente.
	 * id_acao: inteiro que representa o id da Ação.
	 */
	void comprar_acao(int id_cliente, int id_acao);

	/**
	 * Função comprar_acao
	 * ---------------------------------------------------
	 * Solicita a venda de uma determinada Ação da carteira de um determinado Cliente.
	 *
	 * id_cliente: inteiro que representa o id do Cliente.
	 * id_acao: inteiro que representa o id da Ação.
	 */
	void vender_acao(int id_cliente, int id_acao);

	/**
	 * Função set_ret
	 * ---------------------------------------------------
	 * Define se a métrica RET será ativa para a instância do programa ou não.
	 *
	 * state: bool que representa estado ativo (true) ou inativo (false) da métrica.
	 */
	void set_ret(bool state);

	/**
	 * Função set_avgret
	 * ---------------------------------------------------
	 * Define se a métrica AVGRET será ativa para a instância do programa ou não.
	 *
	 * state: bool que representa estado ativo (true) ou inativo (false) da métrica.
	 */
	void set_avgret(bool state);

	/**
	 * Função set_avgret
	 * ---------------------------------------------------
	 * Define se a métrica STAB será ativa para a instância do programa ou não.
	 *
	 * state: bool que representa estado ativo (true) ou inativo (false) da métrica.
	 */
	void set_stab(bool state);

	/**
	 * Função set_avgret
	 * ---------------------------------------------------
	 * Define se a métrica CONS será ativa para a instância do programa ou não.
	 *
	 * state: bool que representa estado ativo (true) ou inativo (false) da métrica.
	 */
	void set_cons(bool state);

	/**
	 * Função consulta
	 * ---------------------------------------------------
	 * Realiza uma consulta das melhores e piores Ações na carteira de um Cliente a partir
	 * de determinadas Métricas.
	 *
	 * id_consulta: inteiro que representa o id da consulta a ser realizada.
	 * id_cliente: inteiro que representa o id do Cliente.
	 * n: inteiro que representa o número de melhores e piores Ações a serem retomadas pela consulta.
	 * m: inteiro que representa o número de métricas utilizadas na consulta.
	 * metricas_pesadas: vetor de structs com as métricas utilizadas e seus respectivos pesos na consulta.
	 */
	void consulta(int id_consulta, int id_cliente, int n, int m, Metricas::MetricaPesada *metricas_pesadas);
};

#endif
