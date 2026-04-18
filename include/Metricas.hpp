#ifndef METRICAS_HPP
#define METRICAS_HPP

/**
 * namespace Metricas
 * ---------------------------------------------------
 * Namespace para agrupar métodos de cálculo de métricas e definir enums e structs
 * relevantes para retornos e parâmetros de funções.
 */
namespace Metricas {
/**
 * Função calcular_RET
 * ---------------------------------------------------
 * Calcula a métrica RET para uma determinada Ação.
 *
 * cotacao_final: double que representa o valor da última cotação salva na janela de cotações de uma Ação.
 * cotacao_inicial: double que representa o valor da primeira cotação salva na janela de cotações de uma Ação.
 *
 * retorno: double que representa o valor da métrica aplicada sobre a Ação.
 */
double calcular_RET(double cotacao_final, double cotacao_inicial);

/**
 * Função calcular_retorno_elementar
 * ---------------------------------------------------
 * Calcula o retorno elementar de uma determinada Ação para uso no cálculo de outras métricas.
 *
 * cotacao_atual: double que representa o valor da última cotação salva na janela de cotações de uma Ação.
 * cotacao_anterior: double que representa o valor da cotação salva imediatamente antes da cotacao_atual na janela de
 * cotações de uma Ação.
 *
 * retorno: double que representa o valor do retorno elementar aplicado sobre a Ação.
 */
double calcular_retorno_elementar(double cotacao_atual, double cotacao_anterior);

/**
 * Função calcular_AVGRET
 * ---------------------------------------------------
 * Calcula a métrica AVGRET para uma determinada Ação.
 *
 * w: inteiro que representa o tamanho da janela de cotações das ações
 * cotacoes: ponteiro para o primeiro elemento do vetor de cotações da Ação.
 * início: inteiro que representa o índice da cotação mais antiga na janela de cotações da Ação.
 *
 * retorno: double que representa o valor da métrica aplicada sobre a Ação.
 */
double calcular_AVGRET(int w, double *cotacoes, int inicio);

/**
 * Função calcular_STAB
 * ---------------------------------------------------
 * Calcula a métrica STAB para uma determinada Ação.
 *
 * w: inteiro que representa o tamanho da janela de cotações das ações
 * cotacoes: ponteiro para o primeiro elemento do vetor de cotações da Ação.
 * início: inteiro que representa o índice da cotação mais antiga na janela de cotações da Ação.
 *
 * retorno: double que representa o valor da métrica aplicada sobre a Ação.
 */
double calcular_STAB(int w, double *cotacoes, int inicio);

/**
 * Função calcular_CONS
 * ---------------------------------------------------
 * Calcula a métrica CONS para uma determinada Ação.
 *
 * w: inteiro que representa o tamanho da janela de cotações das ações
 * cotacoes: ponteiro para o primeiro elemento do vetor de cotações da Ação.
 * início: inteiro que representa o índice da cotação mais antiga na janela de cotações da Ação.
 *
 * retorno: double que representa o valor da métrica aplicada sobre a Ação.
 */
double calcular_CONS(int w, double *cotacoes, int inicio);

/**
 * enum Metrica
 * ---------------------------------------------------
 * Guarda os tipos de Métrica possíveis (RET, AVGRET, STAB, CONS) e o tipo
 * adicional PONTOS para cálculo da pontuação global.
 */
enum Metrica { RET, AVGRET, STAB, CONS, PONTOS };

/**
 * struct MetricaPesada
 * ---------------------------------------------------
 * Representa uma métrica solicitada na consulta e seu peso.
 */
struct MetricaPesada {
	Metrica metrica;
	double peso;
};
}; // namespace Metricas
#endif
