#include <iostream>
#include <string>
#include <sstream>

#include "Sistema.hpp"
#include "Metricas.hpp"

using namespace std;
using namespace Metricas;

int main(){
	Sistema sistema;
	char comando;
	while (cin >> comando){
		switch (comando){
			case 'M': {
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
						} else if (metrica_atual == "STAB"){
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
					} else if (metrica_atual == "STAB"){
						sistema.set_stab(true);
					} else if (metrica_atual == "CONS"){
						sistema.set_cons(true);
					}
				}
				break;
			}
			case 'A': {
				int id;
				cin >> id;
				sistema.adicionar_acao(id);
				break;
			}
			case 'U': {
				int id;
				cin >> id;
				sistema.adicionar_cliente(id);
				break;
			}
			case 'P': {
				int id;
				double valor;
				cin >> id >> valor;
				sistema.nova_cotacao(id, valor);
				break;
			}
			case 'B': {
				int id_cliente;
				int id_acao;
				cin >> id_cliente >> id_acao;
				sistema.comprar_acao(id_cliente, id_acao);
				break;
			}
			case 'V': {
				int id_cliente;
				int id_acao;
				cin >> id_cliente >> id_acao;
				sistema.vender_acao(id_cliente, id_acao);
				break;
			}
			case 'Q': {
				int id_consulta, id_cliente, n, m;
				cin >> id_consulta >> id_cliente >> n >> m;
				MetricaPesada metricas_pesadas[m];
				for (int i = 0; i < m; i++){
					string metrica_nome;
					double metrica_peso;
					cin >> metrica_nome >> metrica_peso;
					Metrica metrica;
					if(metrica_nome == "RET"){
						metrica = RET;
					}
					else if (metrica_nome=="AVGRET"){
						metrica = AVGRET;
					}
					else if (metrica_nome=="STAB"){
						metrica = STAB;
					}
					else if (metrica_nome=="CONS"){
						metrica = CONS;
					}
					metricas_pesadas[i] = { metrica, metrica_peso }; 
				}
				sistema.consulta(id_consulta, id_cliente, n, m, metricas_pesadas);
				break;
			}
		}
	}
	return 0;
}
