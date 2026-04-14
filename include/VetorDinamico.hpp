#ifndef VETORDINAMICO_HPP
#define VETORDINAMICO_HPP

#include <stdexception>

template <typename T>
class VetorDinamico{
	private:
		int capacidade;
		int tamanho;
		T* array;
		
		void redimensionar(){
			this->capacidade *= 2
			T* nova_array = new T[this->capacidade];
			for (int i = 0; i < tamanho; i++){
				nova_array[i] = this->array[i];
			}
			delete[] this->array;
			this->array = nova_array;
		}
	public:
		VetorDinamico(int capacidade_inicial=2): capacidade(capacidade_inicial), tamanho(0), array(new T[capacidade_inicial]){}
		~VetorDinamico(){
			delete[] this->array;
		}
		void adicionar(T item){
			if (this->tamanho == this->capacidade){
				this->redimensionar();
			}
			this->array[tamanho] = item;
			this->tamanho++;
		}
		T obter(int pos){
			if (pos < 0){
				pos = this->tamanho + pos;
			}
			if (pos >= this->tamanho || pos < 0){
				throw std::out_of_range("Erro: índice excede limite do vetor!");
			}
			return this->array[pos];
		}
		T primeiro(){
			if (this->tamanho == 0){
				throw std::out_of_range("Erro: vetor vazio!");
			}
			return this->array[0];
		}
		T ultimo(){
			if (this->tamanho == 0){
				throw std::out_of_range("Erro: vetor vazio!");
			}
			return this->array[this->tamanho-1];
		}
		int get_tamanho(){
			return this->tamanho;
		}
		void remover_trocando(int pos){
			if (pos<0 || pos >= this->tamanho){
				throw std::out_of_range("Erro: índice inválido para remoção!");
			}
			this->array[pos] = this->array[tamanho-1];
			this->tamanho--;
		}

}

#endif
