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
	Metricas::calcular_ret();
};

double Acao::avgret(){

};

double Acao::stab(){

};

double Acao::cons(){

};
