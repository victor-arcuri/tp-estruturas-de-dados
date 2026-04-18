#include "Acao.hpp"
#include "Metricas.hpp"

Acao::Acao(int w, int id) : w(w), proxima_posicao(0), id(id) { this->cotacoes = new double[w]; };

Acao::~Acao() { delete[] this->cotacoes; };

/**
 * Como o TAD Acao guarda as cotações em um vetor do tamanho fixo igual ao tamanho da janela definido no Sistema,
 * utiliza-se a lógica de buffer circular, em que uma vez que o vetor foi completamente preenchido, o elemento
 * mais antigo é substituído pelo novo elemento a ser adicionado. A variável proxima_posicao guarda qual o
 * próximo elemento a ser substituído. Os métodos a baixo utilizam o operador de módulo para calcular os índices
 * reais no vetor a partir da lógica circular.
 */
double Acao::ultima_cotacao() { return this->cotacoes[(this->proxima_posicao - 1 + this->w) % this->w]; };

void Acao::adicionar_cotacao(double cotacao) {
	this->cotacoes[this->proxima_posicao] = cotacao;
	this->proxima_posicao = (this->proxima_posicao + 1) % this->w;
};

double Acao::calcula_ret() {
	int index_final = (this->proxima_posicao - 1 + this->w) % this->w;
	double p_inicial = this->cotacoes[this->proxima_posicao];
	double p_final = this->cotacoes[index_final];
	this->ret = Metricas::calcular_RET(p_final, p_inicial);
	return this->ret;
};

double Acao::calcula_avgret() {
	this->avgret = Metricas::calcular_AVGRET(this->w, this->cotacoes, this->proxima_posicao);
	return this->avgret;
};

double Acao::calcula_stab() {
	this->stab = Metricas::calcular_STAB(this->w, this->cotacoes, this->proxima_posicao);
	return this->stab;
};

double Acao::calcula_cons() {
	this->cons = Metricas::calcular_CONS(this->w, this->cotacoes, this->proxima_posicao);
	return this->cons;
};

int Acao::get_id() { return this->id; }

double Acao::set_pontos(double pontuacao) {
	this->pontos = pontuacao;
	return this->pontos;
}

double Acao::get_ret() { return this->ret; }

double Acao::get_avgret() { return this->avgret; }

double Acao::get_stab() { return this->stab; }

double Acao::get_cons() { return this->cons; }

double Acao::get_pontos() { return this->pontos; }