#ifndef ACAO_HPP
#define ACAO_HPP

class Acao {
	private:
		double* cotacoes;
		int w;
		int proxima_posicao;
		int id;
	public:
		Acao(int w, int id);
		~Acao();
		
		double ultima_cotacao();
		void adicionar_cotacao(double cotacao);
		double ret();
		double avgret();
		double stab();
		double cons();
		int get_id();
		
		
};

#endif
