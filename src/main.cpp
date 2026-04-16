#include <iostream>
#include <string>
#include <sstream>
#include "Sistema.hpp"
#include "Metricas.hpp"

int main(){
	Sistema sistema;
	char comando;
	while (cin >> comando){
		if (comando == 'M'){
			int w;
			cin >> w;
			sistema.set_w(w);
			string resto_linha;
			getline(cin, resto_linha);
			string metrica_atual = "";
			for (char c : resto_linha){
				if (c!=' '){
					metrica_atual += c;
				} else if (!metrica_atual.empty()){
					if (metrica_atual == "RET"){
						sistema.set_ret(true);
					} else if (metrica_atual == "AVGRET"){
						sistema.set_avgret(true);
					} else if (metrica_atual == "STAB"{
						sistema.set_stab(true);
					} else if (metrica_atual == "CONS"){
						sistema.set_cons(true);
					}
					metrica_atual = "";
				}
			}
			if (!metrica_atual.empty()){
				if (metrica_atual == "RET"){
					sistema.set_ret(true);
				} else if (metrica_atual == "AVGRET"){
					sistema.set_avgret(true);
				} else if (metrica_atual == "STAB"{
					sistema.set_stab(true);
				} else if (metrica_atual == "CONS"){
					sistema.set_cons(true);
				}
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
			int id_consulta, id_cliente, n, m;
			cin >> id_consulta >> id_cliente >> n >> m;
			MetricaPesada metricas_pesadas[m];
			for (int i = 0; i < m; i++){
				string metrica_nome;
				double metrica_peso;
				cin >> metrica_nome >> metrica_peso;
				Metrica metrica;
				switch (metrica_nome){
					case "RET":
						metrica = RET;
						break;
					case "AVGRET":
						metrica = AVGRET;
						break;
					case "STAB":
						metrica = STAB;
						break;
					case "CONS":
						metrica = CONS;
						break;
				}
				metricas_pesadas[i] = { metrica, peso }; 
				
			}
		}
	}
	return 0;
}
