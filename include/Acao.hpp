#ifndef ACAO_HPP
#define ACAO_HPP

/** 
 * Classe Cliente
 * ---------------------------------------------------
 * Tipo de Dado Abstrato responsável por gerenciar as ações do sistema, guardar suas métricas,
 * manipular cotações.
*/
class Acao {
	private:
		double* cotacoes;
		int w;
		int proxima_posicao;
		int id;
		double ret;
		double avgret;
		double stab;
		double cons;
		double pontos;
	public:
		Acao(int w, int id);
		~Acao();
		
		/** 
		 * Função ultima_cotacao
		 * ---------------------------------------------------
		 * Retorna o valor cotação mais recente na janela de cotações da Ação.
		 * 
		 * retorno: double que representa o valor da cotação mais recente.
		*/
		double ultima_cotacao();

		/** 
		 * Função adicionar_cotacao
		 * ---------------------------------------------------
		 * Adiciona uma cotação na janela de cotações da Ação.
		 * 
		 * cotacao: double que representa o valor da cotação.
		 * 
		*/
		void adicionar_cotacao(double cotacao);

		/** 
		 * Função calcula_ret
		 * ---------------------------------------------------
		 * Calcula, armazena e retorna o valor da métrica RET aplicada sobre a Ação.
		 * 
		 * retorno: double que representa o valor da métrica.
		*/
		double calcula_ret();

		/** 
		 * Função calcula_avgret
		 * ---------------------------------------------------
		 * Calcula, armazena e retorna o valor da métrica AVGRET aplicada sobre a Ação.
		 * 
		 * retorno: double que representa o valor da métrica.
		*/
		double calcula_avgret();

		/** 
		 * Função calcula_stab
		 * ---------------------------------------------------
		 * Calcula, armazena e retorna o valor da métrica STAB aplicada sobre a Ação.
		 * 
		 * retorno: double que representa o valor da métrica.
		*/
		double calcula_stab();

		/** 
		 * Função calcula_cons
		 * ---------------------------------------------------
		 * Calcula, armazena e retorna o valor da métrica CONS aplicada sobre a Ação.
		 * 
		 * retorno: double que representa o valor da métrica.
		*/
		double calcula_cons();

		/** 
		 * Função get_id
		 * ---------------------------------------------------
		 * Retorna o id da Ação.
		 * 
		 * retorno: número inteiro que representa o id da Ação.
		*/
		int get_id();

		/** 
		 * Função set_pontos
		 * ---------------------------------------------------
		 * Armazena temporariamente o valor da pontuação da Ação na última consulta,
		 * para fins de ordenação.
		 * 
		 * retorno: double que representa a pontuação estabelecida.
		*/
		double set_pontos(double pontuacao);

		/** 
		 * Função get_ret
		 * ---------------------------------------------------
		 * Retorna o valor armazenado da métrica RET da Ação.
		 * 
		 * retorno:  double que representa o valor da métrica.
		*/
		double get_ret();

		/** 
		 * Função get_avgret
		 * ---------------------------------------------------
		 * Retorna o valor armazenado da métrica AVGRET da Ação.
		 * 
		 * retorno:  double que representa o valor da métrica.
		*/
		double get_avgret();

		/** 
		 * Função get_stab
		 * ---------------------------------------------------
		 * Retorna o valor armazenado da métrica STAB da Ação.
		 * 
		 * retorno:  double que representa o valor da métrica.
		*/
		double get_stab();

		/** 
		 * Função get_cons
		 * ---------------------------------------------------
		 * Retorna o valor armazenado da métrica CONS da Ação.
		 * 
		 * retorno:  double que representa o valor da métrica.
		*/
		double get_cons();

		/** 
		 * Função get_cons
		 * ---------------------------------------------------
		 * Retorna o valor armazenado da pontuação da Ação na última consulta.
		 * 
		 * retorno:  double que representa o valor da pontuação.
		*/
		double get_pontos();
		
		
};

#endif
