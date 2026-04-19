#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>

using namespace std;

// Função para gerar um arquivo de teste completo
void gerar_cenario(string nome_arquivo, int num_acoes, int num_clientes, int num_eventos, double prob_P, double prob_Q) {
    ofstream out(nome_arquivo);
    if (!out.is_open()) {
        cerr << "Erro ao criar arquivo: " << nome_arquivo << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> acao_dist(0, num_acoes - 1);
    uniform_int_distribution<> cliente_dist(0, num_clientes - 1);
    uniform_real_distribution<> preco_dist(5.0, 100.0);
    uniform_real_distribution<> prob_dist(0.0, 1.0);
    uniform_int_distribution<> peso_dist(1, 5); // Pesos aleatórios de 1 a 5

    int janela_w = 10; // Janela W definida como 10
    out << "M " << janela_w << " RET AVGRET STAB CONS\n";

    // Cria as Ações
    for(int i = 0; i < num_acoes; i++) {
        out << "A " << i << "\n";
    }

    // Cria os Clientes
    for(int i = 0; i < num_clientes; i++) {
        out << "U " << i << "\n";
    }

    // Preenche a Janela W inicial de todas as ações para não dar erro nas métricas
    for(int j = 0; j < janela_w; j++) {
        for(int i = 0; i < num_acoes; i++) {
            out << "P " << i << " " << preco_dist(gen) << "\n";
        }
    }

    // Compras Iniciais (Popula as carteiras com ~20 ações por cliente)
    for(int c = 0; c < num_clientes; c++) {
        for(int a = 0; a < 20; a++) {
            out << "B " << c << " " << acao_dist(gen) << "\n";
        }
    }

    // Loop de Eventos Principais
    int id_consulta = 0;
    for(int i = 0; i < num_eventos; i++) {
        double sorteio = prob_dist(gen);
        
        if (sorteio < prob_P) {
            out << "P " << acao_dist(gen) << " " << preco_dist(gen) << "\n";
            
        } else if (sorteio < prob_P + prob_Q) {
            // Evento de Consulta (Q)
            // Sorteia n (tamanho do ranking) entre 5 e 15
            int n_ranking = 10;
            out << "Q " << id_consulta++ << " " << cliente_dist(gen) << " " 
                << n_ranking << " 2 RET " << peso_dist(gen) << " AVGRET " << peso_dist(gen) << "\n";
        }
    }
    
    out.close();
    cout << "[OK] Arquivo " << nome_arquivo << " gerado com sucesso!" << endl;
}

int main() {
    cout << "Gerando casos de teste para a Análise Experimental..." << endl;

    // Cenário 1: "Mercado Frio" (Poucas cotações, Muitas Consultas)
    // 1000 ações, 50 clientes, 20.000 eventos (5% de cotações, 95% de consultas)
    gerar_cenario("cenario1_mercado_frio.txt", 1000, 50, 20000, 0.05, 0.95);

    // Cenário 2: "Alta Volatilidade" (Muitas cotações, Poucas Consultas)
    // 1000 ações, 50 clientes, 20.000 eventos (95% de cotações, 5% de consultas)
    gerar_cenario("cenario2_alta_volatilidade.txt", 1000, 50, 20000, 0.95, 0.05);

    // Cenário 3: "Escalonamento" (50% cotações, 50% consultas, variando apenas o N de ações)
    gerar_cenario("cenario3_escalonamento_1000.txt", 1000, 50, 10000, 0.5, 0.5);
    gerar_cenario("cenario3_escalonamento_5000.txt", 5000, 50, 10000, 0.5, 0.5);
    gerar_cenario("cenario3_escalonamento_10000.txt", 10000, 50, 10000, 0.5, 0.5);

    return 0;
}