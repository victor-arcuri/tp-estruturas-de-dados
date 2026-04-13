#include "Metricas.hpp"
namespace Metricas {
	double calcular_RET(double cotacao_final, double cotacao_inicial){
		return (cotacao_final/cotacao_inicial) - 1;	
	};
	double calcular_retorno_elementar(double cotacao_atual, double cotacao_anterior){
		return (cotacao_atual/cotacao_anterior) - 1;
	};
	double calcular_AVGRET(double w, double* cotacoes){
		double somatorio = 0;
		for (int i = 1; i < w; i++){
			somatorio += calcular_retorno_elementar(cotacoes[i], cotacoes[i-1]);
		}
		return (1/(w-1)) * somatorio;

	};
	double calcular_STAB(double w, double* cotacoes){};
	double calcular_CONS(double w, double* cotacoes){};
};
