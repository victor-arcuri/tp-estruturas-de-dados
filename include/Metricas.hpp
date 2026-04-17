#ifndef METRICAS_HPP
#define METRICAS_HPP
namespace Metricas {
	double calcular_RET(double cotacao_final, double cotacao_inicial);
	double calcular_retorno_elementar(double cotacao_atual, double cotacao_anterior);
	double calcular_AVGRET(int w, double* cotacoes, int inicio);
	double calcular_STAB(int w, double* cotacoes, int inicio);
	double calcular_CONS(int w, double* cotacoes, int inicio);

	enum Metrica {
		RET,
		AVGRET,
		STAB,
		CONS,
		PONTOS
	};

	struct MetricaPesada {
		Metrica metrica;
		double peso;
	};
};
#endif
