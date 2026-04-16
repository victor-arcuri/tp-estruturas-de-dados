#include "Metricas.hpp"
#include <cmath>
namespace Metricas {
	double calcular_RET(double cotacao_final, double cotacao_inicial){
		return (cotacao_final/cotacao_inicial) - 1;	
	}
	double calcular_retorno_elementar(double cotacao_atual, double cotacao_anterior){
		return (cotacao_atual/cotacao_anterior) - 1;
	}
	double calcular_AVGRET(int w, double* cotacoes, int inicio){
		double somatorio = 0;
		for (int i = 1; i < w; i++){
			int index_atual = (inicio + i) % w;
			int index_anterior = (inicio + i -1) % w;
			somatorio += calcular_retorno_elementar(cotacoes[index_atual], cotacoes[index_anterior]);
		}
		return (1.0/(w-1.0)) * somatorio;

	}
	double calcular_STAB(int w, double* cotacoes, int inicio){
		double somatorio = 0;
		double avgret = calcular_AVGRET(w, cotacoes, inicio);
		for (int i = 1; i < w; i++){
			int index_atual = (inicio + i) % w;
			int index_anterior = (inicio + i -1) % w;
			somatorio += pow((calcular_retorno_elementar(cotacoes[index_atual], cotacoes[index_anterior]) - avgret),2);
		}
		double vol = sqrt((1.0/(w-1.0)) * somatorio);
		return 1.0 / (1.0 + vol);
	}
	double calcular_CONS(int w, double* cotacoes, int inicio){
		double somatorio = 0;		
		for (int i = 1; i < w; i++){
			int index_atual = (inicio + i) % w;
			int index_anterior = (inicio + i -1) % w;
			if (calcular_retorno_elementar(cotacoes[index_atual], cotacoes[index_anterior]) > 0){
				somatorio += 1;
			}
		}
		return (1.0/(w-1.0)) * somatorio;
	}
	
}
