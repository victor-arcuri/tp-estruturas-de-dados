#include "Acao.hpp"
#include "Metricas.hpp"

Acao::Acao(int w): w(w), proxima_posicao(0){
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

double Acao::ret(){
	int index_final = (this->proxima_posicao - 1 + this->w) % this->w;
	double p_inicial = this->cotacoes[this->proxima_posicao];
	double p_final = this->cotacoes[index_final];
	return Metricas::calcular_RET(p_final, p_inicial);
};

double Acao::avgret(){
	return Metricas::calcular_AVGRET(this->w, this->cotacoes, this->proxima_posicao);
};

double Acao::stab(){
	return Metricas::calcular_STAB(this->w, this->cotacoes, this->proxima_posicao);
};

double Acao::cons(){
	return Metricas::calcular_CONS(this->w, this->cotacoes, this->proxima_posicao);
};
