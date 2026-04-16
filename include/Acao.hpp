#ifndef ACAO_HPP
#define ACAO_HPP

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
		
		double ultima_cotacao();
		void adicionar_cotacao(double cotacao);
		double calcula_ret();
		double calcula_avgret();
		double calcula_stab();
		double calcula_cons();
		int get_id();
		double set_pontos(double pontuacao);
		double get_ret();
		double get_avgret();
		double get_stab();
		double get_cons();
		double get_pontos();
		
		
};

#endif
