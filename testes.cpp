#include <iostream>
#include <cassert>

#include "Diretorio.hpp"
#include "ig_assert.hpp"
#include "printbits.hpp"

#define CHAVE_PADRAO "0000"
#define CHAVE_1 "0001"
#define CHAVE_2 "0010"

int main()
{
	std::cout << "testeConstrutorBalde\n\n";
	{
		size_t capacidade = 5;
		Balde b(capacidade);

		ig_assert(b.tamanho() == 0);
		ig_assert(b.profundidade() == 0);
		ig_assert(b.capacidade() == capacidade);
	}

	std::cout << "testeInsereUmElementoNoBalde\n\n";
	{
		size_t capacidade = 1;
		Balde b(capacidade);

		b.insere(CHAVE_PADRAO);

		ig_assert(b.insere(CHAVE_PADRAO) == false);
		ig_assert(b[0] == CHAVE_PADRAO);
		ig_assert(b.tamanho() == 1);
		ig_assert(b.profundidade() == 0);
		ig_assert(b.capacidade() == capacidade);
	}

	std::cout << "testeInsereDoisElementosNoBalde\n\n";
	{
		size_t capacidade = 2;
		Balde b(capacidade);

		b.insere(CHAVE_PADRAO);
		b.insere(CHAVE_PADRAO);

		ig_assert(b.insere(CHAVE_PADRAO) == false);
		ig_assert(b.tamanho() == 2);
		ig_assert(b.profundidade() == 0);
		ig_assert(b.capacidade() == capacidade);
	}

	std::cout << "testeContrutorDiretorio\n\n";
	{
		size_t capacidade_balde = 5;
		size_t maxbits = 8;

		Diretorio d(maxbits, capacidade_balde);

		ig_assert(d.capacidade_balde() == capacidade_balde);
		ig_assert(d.maxbits() == maxbits);
	}

	std::cout << "testeInsere1ElementoNoDiretorio\n\n";
	{
		size_t capacidade_balde = 4;
		size_t maxbits = 8;

		Diretorio d(maxbits, capacidade_balde);

		ig_assert(d.buscar(CHAVE_PADRAO) == false);

		d.insere(CHAVE_PADRAO);
		
		ig_assert(d.buscar(CHAVE_PADRAO) == true);
		ig_assert(d.buscar(CHAVE_1) == false);
		ig_assert(d.buscar(CHAVE_2) == false);
	}
	return 0;
}
