#include "Sistema.hpp"

Sistema::Sistema(int w): janela_w(w){};
Sistema::~Sistema(){
	for (int i = 0; i < this->acoes.get_tamanho(); i++){
		delete this->acoes.obter(i);
	}
	for (int i = 0; i < this->clientes.get_tamanho(); i++){
		delete this->clientes.obter(i);
	}

}

Cliente* Sistema::retomar_cliente(int id){
	for (int i = 0; i < this->clientes.get_tamanho(); i++){
		if (this->clientes.obter(i)->get_id() == id){
			return this->clientes.obter(i);
		}
	}
	return nullptr;
}
Acao* Sistema::retomar_acao(int id){
	for (int i = 0; i < this->acoes.get_tamanho(); i++){
		if (this->acoes.obter(i)->get_id() == id){
			return this->acoes.obter(i);
		}
	}
	return nullptr;
}
void Sistema::adicionar_acao(int id){
	Acao* nova_acao = new Acao(this->janela_w, id);
	this->acoes.adicionar(nova_acao);
}
void Sistema::adicionar_cliente(int id){
	Cliente* novo_cliente = new Cliente(id);
	this->clientes.adicionar(novo_cliente);
}
void Sistema::nova_cotacao(int id, double preco){
	Acao* acao = this->retomar_acao(id);
	acao->adicionar_cotacao(preco);
}
void Sistema::comprar_acao(int id_cliente, int id_acao){
	Cliente* cliente = this->retomar_cliente(id_cliente);
	Acao* acao = this->retomar_acao(id_acao);
	cliente->comprar_acao(acao);
}
void Sistema::vender_acao(int id_cliente, int id_acao){
	Cliente* cliente = this->retomar_cliente(id_cliente);
	Acao* acao = this->retomar_acao(id_acao);
	cliente->vender_acao(acao);
}

void Sistema::set_w(int w){
	this->janela_w = w;
}
