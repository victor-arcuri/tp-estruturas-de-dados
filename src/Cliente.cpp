#include "Cliente.hpp"

Cliente::Cliente(int id) : id(id), carteira(10) {}
void Cliente::comprar_acao(Acao *acao) { this->carteira.adicionar(acao); }
void Cliente::vender_acao(Acao *acao) {
	for (int i = 0; i < this->carteira.get_tamanho(); i++) {
		if (this->carteira.obter(i) == acao) {
			this->carteira.remover_trocando(i);
			return;
		}
	}
}
int Cliente::get_id() { return this->id; }

VetorDinamico<Acao *> *Cliente::get_acoes() { return &(this->carteira); }