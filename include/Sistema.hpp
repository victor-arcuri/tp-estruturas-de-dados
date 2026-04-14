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
		VetorDinamico<Acao*> ordenacao_ret;
		VetorDinamico<Acao*> ordenacao_avgret;
		VetorDinamico<Acao*> ordenacao_stab;
		VetorDinamico<Acao*> ordenacao_cons;
		bool ret;
		bool avgret;
		bool stab;
		bool cons;
		Cliente* retomar_cliente(int id);
		Acao* retomar_acao(int id);
	public:
		Sistema();
		~Sistema();
		void set_w(int w);
		void adicionar_acao(int id);
		void adicionar_cliente(int id);
		void nova_cotacao(int id, double preco);
		void comprar_acao(int id_cliente, int id_acao);
		void vender_acao(int id_cliente, int id_acao);
		void set_ret(bool state);	
		void set_avgret(bool state);	
		void set_stab(bool state);	
		void set_cons(bool state);	
};

#endif
