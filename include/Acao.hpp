#ifndef ACAO_HPP
#define ACAO_HPP

class Acao {
	private:
		float* cotacoes;
		int w;
	public:
		Acao(int w);
		~Acao();
		
		float ultima_cotacao();
		float adicionar_cotacao();
		float ret();
		float avgret();
		float stab();
		float cons();
		
		
};

#endif
