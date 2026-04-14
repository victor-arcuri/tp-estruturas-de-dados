#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "VetorDinamico.hpp"
#include "Cliente.hpp"
#include "Acao.hpp"

class Sistema{
	private:
		int janela_w;
		VetorDinamico<Cliente*> clientes;
		VetorDinamico<Acao*> acoes;
		Cliente* retomar_cliente(int id);
		Acao* retomar_acao(int id);
	public:
		Sistema(int w);
		~Sistema();
		void adicionar_acao(int id);
		void adicionar_cliente(int id);
		void nova_cotacao(int id, double preco);
		void comprar_acao(int id_cliente, int id_acao);
		void vender_acao(int id_cliente, int id_acao);
};

#endif
