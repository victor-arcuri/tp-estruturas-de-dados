#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Acao.hpp"
#include "VetorDinamico.hpp"

class Cliente {
	private:
		int id;
		VetorDinamico<Acao*> carteira;
	
	public:
		Cliente(int id);
		void comprar_acao(Acao* acao);
		void vender_acao(Acao* acao);
		int get_id();
};

#endif
