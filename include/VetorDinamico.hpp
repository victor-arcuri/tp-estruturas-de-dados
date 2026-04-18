#ifndef VETORDINAMICO_HPP
#define VETORDINAMICO_HPP

#include <stdexcept>

/**
 * Classe VetorDinamico
 * ---------------------------------------------------
 * Tipo de Dado Abstrato responsável por armazenar elementos genéricos
 * em um vetor, alocando automaticamente mais espaço conforme necessário
 */

template <typename T> class VetorDinamico {
  private:
	int capacidade;
	int tamanho;
	T *array;

	/**
	 * Função redimensionar
	 * ---------------------------------------------------
	 * Dobra a capacidade de armazenamento do VetorDinamico, alocando
	 * mais memória e copiando os elementos para o novo espaço.
	 */
	void redimensionar() {
		this->capacidade *= 2;
		T *nova_array = new T[this->capacidade];
		for (int i = 0; i < tamanho; i++) {
			nova_array[i] = this->array[i];
		}
		delete[] this->array;
		this->array = nova_array;
	}

  public:
	VetorDinamico(int capacidade_inicial = 2)
		: capacidade(capacidade_inicial), tamanho(0), array(new T[capacidade_inicial]) {}
	~VetorDinamico() { delete[] this->array; }

	/**
	 * Função adicionar
	 * ---------------------------------------------------
	 * Adiciona mais um elemento ao VetorDinamico.
	 *
	 * item: elemento a ser adicionado.
	 */
	void adicionar(T item) {
		if (this->tamanho == this->capacidade) {
			this->redimensionar();
		}
		this->array[tamanho] = item;
		this->tamanho++;
	}

	/**
	 * Função obter
	 * ---------------------------------------------------
	 * Retorna o item no índice especificado.
	 *
	 * pos: o índice do elemento.
	 *
	 * retorno: item na posição desejada, caso seja válida.
	 * Retorna erro se a posićão for inválida.
	 */
	T obter(int pos) {
		if (pos < 0) {
			pos = this->tamanho + pos;
		}
		if (pos >= this->tamanho || pos < 0) {
			throw std::out_of_range("Erro: índice excede limite do vetor!");
		}
		return this->array[pos];
	}

	/**
	 * Função primeiro
	 * ---------------------------------------------------
	 * Retorna o primeiro item do VetorDinamico.
	 *
	 * retorno: item na primeira posição do VetorDinamico.
	 * Retorna erro se o VetorDinamico for vazio.
	 */
	T primeiro() {
		if (this->tamanho == 0) {
			throw std::out_of_range("Erro: vetor vazio!");
		}
		return this->array[0];
	}

	/**
	 * Função ultimo
	 * ---------------------------------------------------
	 * Retorna o último item do VetorDinamico.
	 *
	 * retorno: item na última posição do VetorDinamico.
	 * Retorna erro se o VetorDinamico for vazio.
	 */

	T ultimo() {
		if (this->tamanho == 0) {
			throw std::out_of_range("Erro: vetor vazio!");
		}
		return this->array[this->tamanho - 1];
	}

	/**
	 * Função get_tamanho
	 * ---------------------------------------------------
	 * Retorna o número de elementos do VetorDinamico.
	 *
	 * retorno: número inteiro representanto a quantidade de elementos
	 * no VetorDinamico.
	 */
	int get_tamanho() { return this->tamanho; }

	/**
	 * Função remover_trocando
	 * ---------------------------------------------------
	 * Remove o elemento da posição desejada.
	 * O método troca o elemento na última posição do VetorDinamico com a ser removido,
	 * e reduz o tamanho em 1, deixando elemento original da última posição como lixo de memória
	 * e sua cópia salva na posição do elemento a ser removido.
	 *
	 * pos: número inteiro representando índice do elemento a ser removido.
	 *
	 * retorno: void.
	 * Retorna erro caso o índice seja inválido.
	 */
	void remover_trocando(int pos) {
		if (pos < 0 || pos >= this->tamanho) {
			throw std::out_of_range("Erro: índice inválido para remoção!");
		}
		this->array[pos] = this->array[tamanho - 1];
		this->tamanho--;
	}

	/**
	 * Função encontrar_item
	 * ---------------------------------------------------
	 * Retorna a posição do elemento desejado no VetorDinamico.
	 *
	 * item: elemento a ser buscado no VetorDinamico.
	 *
	 * retorno: retorna um número inteiro representando a posição do elemento no VetorDinamico.
	 * Caso o item não esteja no VetorDinamico, retorna -1.
	 */

	int encontrar_item(const T &item) {
		for (int i = 0; i < this->tamanho; i++) {
			if (this->array[i] == item)
				return i;
		}
		return -1;
	}

	/**
	 * Função alterar
	 * ---------------------------------------------------
	 * Alterna o item na posição especificada para o item especificado.
	 *
	 * pos: inteiro representando a posição a ser alterada.
	 * item: elemento a ser definido na posição.
	 *
	 * retorno: void.
	 * Retorna erro caso o índice seja inválido.
	 */
	void alterar(int pos, const T &item) {
		if (pos < 0 || pos >= tamanho) {
			throw std::out_of_range("Índice inválido no alterar");
		}
		this->array[pos] = item;
	}
};

#endif
