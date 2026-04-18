#include "Sistema.hpp"
#include <iomanip>
#include <iostream>

using namespace Metricas;

Sistema::Sistema() : ret(false), avgret(false), stab(false), cons(false) {};
Sistema::~Sistema() {
	for (int i = 0; i < this->acoes.get_tamanho(); i++) {
		delete this->acoes.obter(i);
	}
	for (int i = 0; i < this->clientes.get_tamanho(); i++) {
		delete this->clientes.obter(i);
	}
}

Cliente *Sistema::retomar_cliente(int id) {
	for (int i = 0; i < this->clientes.get_tamanho(); i++) {
		if (this->clientes.obter(i)->get_id() == id) {
			return this->clientes.obter(i);
		}
	}
	return nullptr;
}
Acao *Sistema::retomar_acao(int id) {
	for (int i = 0; i < this->acoes.get_tamanho(); i++) {
		if (this->acoes.obter(i)->get_id() == id) {
			return this->acoes.obter(i);
		}
	}
	return nullptr;
}
void Sistema::adicionar_acao(int id) {
	Acao *nova_acao = new Acao(this->janela_w, id);
	this->acoes.adicionar(nova_acao);
	if (this->ret) {
		this->ordenacao_ret.adicionar(nova_acao);
	}
	if (this->avgret) {
		this->ordenacao_avgret.adicionar(nova_acao);
	}
	if (this->stab) {
		this->ordenacao_stab.adicionar(nova_acao);
	}
	if (this->cons) {
		this->ordenacao_cons.adicionar(nova_acao);
	}
}
void Sistema::adicionar_cliente(int id) {
	Cliente *novo_cliente = new Cliente(id);
	this->clientes.adicionar(novo_cliente);
}
void Sistema::nova_cotacao(int id, double preco) {
	Acao *acao = this->retomar_acao(id);
	acao->adicionar_cotacao(preco);
}
void Sistema::comprar_acao(int id_cliente, int id_acao) {
	Cliente *cliente = this->retomar_cliente(id_cliente);
	Acao *acao = this->retomar_acao(id_acao);
	cliente->comprar_acao(acao);
}
void Sistema::vender_acao(int id_cliente, int id_acao) {
	Cliente *cliente = this->retomar_cliente(id_cliente);
	Acao *acao = this->retomar_acao(id_acao);
	cliente->vender_acao(acao);
}

void Sistema::set_w(int w) { this->janela_w = w; }

void Sistema::set_ret(bool state) { this->ret = state; }
void Sistema::set_avgret(bool state) { this->avgret = state; }
void Sistema::set_stab(bool state) { this->stab = state; }
void Sistema::set_cons(bool state) { this->cons = state; }

/**
 * Esse método auxiliar é responsável por comparar duas Ações a partir de uma determinada métrica,
 * identificando qual é a maior, ou, em caso de empate, qual tem o menor id.
 */
Acao *ComparaAcoes(Acao *acao1, Acao *acao2, Metrica metrica) {
	switch (metrica) {
	case RET:
		if (acao1->get_ret() > acao2->get_ret())
			return acao1;
		if (acao1->get_ret() < acao2->get_ret())
			return acao2;
		break;
	case AVGRET:
		if (acao1->get_avgret() > acao2->get_avgret())
			return acao1;
		if (acao1->get_avgret() < acao2->get_avgret())
			return acao2;
		break;
	case STAB:
		if (acao1->get_stab() > acao2->get_stab())
			return acao1;
		if (acao1->get_stab() < acao2->get_stab())
			return acao2;
		break;
	case CONS:
		if (acao1->get_cons() > acao2->get_cons())
			return acao1;
		if (acao1->get_cons() < acao2->get_cons())
			return acao2;
		break;
	case PONTOS:
		if (acao1->get_pontos() > acao2->get_pontos())
			return acao1;
		if (acao1->get_pontos() < acao2->get_pontos())
			return acao2;
		break;
	}
	if (acao1->get_id() == acao2->get_id())
		return nullptr;
	if (acao1->get_id() < acao2->get_id())
		return acao1;
	return acao2;
}

/**
 * Esse método auxiliar é responsável por implementar a lógica de partição do algoritmo de ordenamento
 * QuickSort, utilizando uma métrica determinada para permitir a comparação de Ações.
 */
void Particionar(int Esq, int Dir, int *i, int *j, VetorDinamico<Acao *> &acoes, Metrica metrica) {
	Acao *x, *w;
	*i = Esq;
	*j = Dir;
	x = acoes.obter((*i + *j) / 2);
	do {
		while (ComparaAcoes(x, acoes.obter(*i), metrica) == x)
			(*i)++;
		while (ComparaAcoes(x, acoes.obter(*j), metrica) == acoes.obter(*j))
			(*j)--;
		if (*i <= *j) {
			w = acoes.obter(*i);
			acoes.alterar(*i, acoes.obter(*j));
			acoes.alterar(*j, w);
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}

/**
 * Esse método auxiliar é responsável por implementar a lógica recursiva do algoritmo de ordenamento
 * QuickSort, utilizando uma métrica determinada para permitir a comparação de Ações.
 */
void Ordenar(int Esq, int Dir, VetorDinamico<Acao *> &acoes, Metrica metrica) {
	int i, j;
	Particionar(Esq, Dir, &i, &j, acoes, metrica);
	if (Esq < j)
		Ordenar(Esq, j, acoes, metrica);
	if (i < Dir)
		Ordenar(i, Dir, acoes, metrica);
}

/**
 * Esse método auxiliar é responsável por iniciar o processo de ordenamento do algoritmo
 * QuickSort, utilizando uma métrica determinada para permitir a comparação de Ações.
 */
void OrdenarAcoes(VetorDinamico<Acao *> &acoes, int n, Metrica metrica) { Ordenar(0, n - 1, acoes, metrica); }

void Sistema::consulta(int id_consulta, int id_cliente, int n, int m, MetricaPesada *metricas_pesadas) {
	VetorDinamico<Acao *> *acoes_cliente = clientes.obter(id_cliente)->get_acoes();
	VetorDinamico<Acao *> acoes_com_peso(this->acoes.get_tamanho());
	for (int i = 0; i < acoes_cliente->get_tamanho(); i++) {
		Acao *acao = acoes_cliente->obter(i);
		double pontuacao = 0;
		for (int j = 0; j < m; j++) {
			MetricaPesada metrica_pesada = metricas_pesadas[j];
			VetorDinamico<Acao *> *vetor_metrica = nullptr;
			switch (metrica_pesada.metrica) {
			case RET:
				vetor_metrica = &(this->ordenacao_ret);
				break;
			case AVGRET:
				vetor_metrica = &(this->ordenacao_avgret);
				break;
			case STAB:
				vetor_metrica = &(this->ordenacao_stab);
				break;
			case CONS:
				vetor_metrica = &(this->ordenacao_cons);
				break;
			case PONTOS:
				break;
			}
			int pontos_pos = vetor_metrica->encontrar_item(acao) + 1;
			pontuacao += (pontos_pos * metrica_pesada.peso);
		}
		acao->set_pontos(pontuacao);
		acoes_com_peso.adicionar(acao);
	}
	OrdenarAcoes(acoes_com_peso, acoes_cliente->get_tamanho(), PONTOS);
	int limit;
	if (acoes_com_peso.get_tamanho() < n)
		limit = acoes_com_peso.get_tamanho();
	else
		limit = n;
	int pos = 0;
	int tamanho = acoes_com_peso.get_tamanho();
	for (int i = tamanho - 1; i >= tamanho - limit; i--) {
		std::cout << "R " << id_consulta << " " << "M " << pos << " " << acoes_com_peso.obter(i)->get_id() << " "
				  << std::fixed << std::setprecision(2) << acoes_com_peso.obter(i)->get_pontos() << "\n";
		pos++;
	}
	pos = 0;
	for (int i = 0; i < limit; i++) {
		std::cout << "R " << id_consulta << " " << "P " << pos << " " << acoes_com_peso.obter(i)->get_id() << " "
				  << std::fixed << std::setprecision(2) << acoes_com_peso.obter(i)->get_pontos() << "\n";
		pos++;
	}
}

void Sistema::OrdenaMetrica(Metrica metrica) {
	switch (metrica) {
	case RET:
		for (int i = 0; i < this->acoes.get_tamanho(); i++)
			this->acoes.obter(i)->calcula_ret();
		OrdenarAcoes(this->ordenacao_ret, this->ordenacao_ret.get_tamanho(), RET);
		break;
	case AVGRET:
		for (int i = 0; i < this->acoes.get_tamanho(); i++)
			this->acoes.obter(i)->calcula_avgret();
		OrdenarAcoes(this->ordenacao_avgret, this->ordenacao_avgret.get_tamanho(), AVGRET);
		break;
	case STAB:
		for (int i = 0; i < this->acoes.get_tamanho(); i++)
			this->acoes.obter(i)->calcula_stab();
		OrdenarAcoes(this->ordenacao_stab, this->ordenacao_stab.get_tamanho(), STAB);
		break;
	case CONS:
		for (int i = 0; i < this->acoes.get_tamanho(); i++)
			this->acoes.obter(i)->calcula_cons();
		OrdenarAcoes(this->ordenacao_cons, this->ordenacao_cons.get_tamanho(), CONS);
		break;
	case PONTOS:
		OrdenarAcoes(this->ordenacao_cons, this->ordenacao_cons.get_tamanho(), PONTOS);
	}
}

void Sistema::OrdenarMetricasAtivas() {
	if (this->ret)
		OrdenaMetrica(RET);
	if (this->avgret)
		OrdenaMetrica(AVGRET);
	if (this->stab)
		OrdenaMetrica(STAB);
	if (this->cons)
		OrdenaMetrica(CONS);
}