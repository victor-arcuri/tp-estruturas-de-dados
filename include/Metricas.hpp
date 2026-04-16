#ifndef METRICAS_HPP
#define METRICAS_HPP
namespace Metricas {
	double calcular_RET(double cotacao_final, double cotacao_inicial);
	double calcular_retorno_elementar(double cotacao_atual, double cotacao_anterior);
	double calcular_AVGRET(double w, double* cotacoes);
	double calcular_STAB(double w, double* cotacoes);
	double calcular_CONS(double w, double* cotacoes);

	enum Metrica {
		RET,
		AVGRET,
		STAB,
		CONS
	};

	struct MetricaPesada {
		Metrica metrica;
		double peso;
	};
};
#endif
