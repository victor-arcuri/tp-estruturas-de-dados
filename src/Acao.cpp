#include "Acao.hpp"
#include "Metricas.hpp"

Acao::Acao(int w, int id): w(w), proxima_posicao(0), id(id){
	this->cotacoes = new double[w];
};

Acao::~Acao(){
	delete[] this->cotacoes;
};
		
double Acao::ultima_cotacao(){
	return this->cotacoes[(this->proxima_posicao - 1 + this->w) % this->w];
};

void Acao::adicionar_cotacao(double cotacao){
	this->cotacoes[this->proxima_posicao] = cotacao;	
	this->proxima_posicao = (this->proxima_posicao + 1 ) % this->w;
};

double Acao::calcula_ret(){
	int index_final = (this->proxima_posicao - 1 + this->w) % this->w;
	double p_inicial = this->cotacoes[this->proxima_posicao];
	double p_final = this->cotacoes[index_final];
	this->ret = Metricas::calcular_RET(p_final, p_inicial);
	return this->ret;
};	


double Acao::calcula_avgret(){
	this->avgret = Metricas::calcular_AVGRET(this->w, this->cotacoes, this->proxima_posicao);
	return this->avgret;
};

double Acao::stab(){
	this->stab = Metricas::calcular_STAB(this->w, this->cotacoes, this->proxima_posicao);
	return this->stab;
};

double Acao::cons(){
	this->cons = Metricas::calcular_CONS(this->w, this->cotacoes, this->proxima_posicao);
	return this->cons;
};

int Acao::get_id(){
	return this->id;
}
