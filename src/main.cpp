#include <iostream>
#include <string>
#include "Sistema.hpp"

int main(){
	Sistema sistema;
	char comando;
	while (cin >> comando){
		if (comando == 'M'){
		}
		else if (comando == 'A'){
			int id;
			cin >> id;
			sistema.adicionar_acao(id);
		}
		else if (comando == 'U'){
			int id;
			cin >> id;
			sistema.adicionar_cliente(id);
		}
		else if (comando == 'P'){
			int id;
			double valor;
			cin >> id >> valor;
			sistema.nova_cotacao(id, valor);
		}
		else if (comando == 'B'){
			int id_cliente;
			int id_acao;
			cin >> id_cliente >> id_acao;
			sistema.comprar_acao(id_cliente, id_acao);
		}
		else if (comando == 'V'){
			int id_cliente;
			int id_acao;
			cin >> id_cliente >> id_acao;
			sistema.vender_acao(id_cliente, id_acao);
		}
		else if (comando == 'Q'){
		}
	}
	return 0;
}
