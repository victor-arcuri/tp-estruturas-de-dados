#include "Metricas.hpp"
#include <cmath>
namespace Metricas {
	double calcular_RET(double cotacao_final, double cotacao_inicial){
		return (cotacao_final/cotacao_inicial) - 1;	
	}
	double calcular_retorno_elementar(double cotacao_atual, double cotacao_anterior){
		return (cotacao_atual/cotacao_anterior) - 1;
	}
	double calcular_AVGRET(int w, double* cotacoes){
		double somatorio = 0;
		for (int i = 1; i < w; i++){
			somatorio += calcular_retorno_elementar(cotacoes[i], cotacoes[i-1]);
		}
		return (1.0/(w-1.0)) * somatorio;

	}
	double calcular_STAB(int w, double* cotacoes){
		double somatorio = 0;
		double avgret = calcular_AVGRET(w, cotacoes)
		for (int i = 1; i < w; i++){
			somatorio += pow((calcular_retorno_elementar(cotacoes[i], cotacoes[i-1]) - avgret),2);
		}
		double vol = sqrt((1.0/(w-1.0)) * somatorio);
		return 1.0 / (1.0 + vol);
	}
	double calcular_CONS(int w, double* cotacoes){
		double somatorio = 0;
			for (int i = 1; i < w; i++){
				if (calcular_retorno_elementar(cotacoes[i], cotacoes[i-1]) > 0){
					somatorio += 1;
				}
			}
		return (1.0/(w-1.0)) * somatorio;


	}
}
