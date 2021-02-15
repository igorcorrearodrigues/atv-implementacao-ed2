#include <iostream>
#include <cstdio>

#include "Diretorio.hpp"

#define N 10

using namespace std;

struct dados_teste_t
{
	size_t num_baldes;
	size_t num_elementos;
	double fator_de_carga;
};

chave_type gera_pseudochave(size_t nbits);
void print_dados_teste(const std::string& nome_do_teste, struct dados_teste_t& dados);

int main()
{
	size_t nbits;
	size_t capacidade_baldes;

	struct dados_teste_t dados_random;
	struct dados_teste_t dados_mesmo_padrao;

	srand(time(NULL));

	cout << "Digite o tamanho M e o número B de bits a ser usado nas pseudochaves: ";
	cin >> capacidade_baldes >> nbits;

	cout << "Inserindo " << N << " pseudochaves com" << N << " bits em um diretório com baldes com capacidade "
		<< capacidade_baldes << '\n';


	std::cout << "Inserindo " << N << " chaves aleatórias\n";
	{
		Diretorio dir(nbits, capacidade_baldes);

		for (size_t i = 0; i < N; ++i)
		{
			chave_type pseudochave = gera_pseudochave(nbits);

			std::cout << "Inserindo a chave: " << pseudochave << '\n';
			dir.insere(pseudochave);
		}
		cout << dir << '\n';

		dados_random.num_baldes = dir.numero_de_baldes();
		dados_random.fator_de_carga = dir.fator_de_carga();
		dados_random.num_elementos = dir.numero_de_elementos();
	}

	std::cout << "Inserindo " << N << " chaves com o mesmo padrão\n";
	{
		Diretorio dir(nbits, capacidade_baldes);
		const chave_type pseudochave = gera_pseudochave(nbits);
		cout << "Inserindo a chave: " << pseudochave << '\n';
		
		for (size_t i = 0; i < N; ++i)
			dir.insere(pseudochave);
		cout << dir << '\n';
		
		dados_mesmo_padrao.num_baldes = dir.numero_de_baldes();
		dados_mesmo_padrao.fator_de_carga = dir.fator_de_carga();
		dados_mesmo_padrao.num_elementos = dir.numero_de_elementos();
	}

	print_dados_teste("Insere chaves aleatorias", dados_random);
	print_dados_teste("Insere chaves com mesmo padrao", dados_mesmo_padrao);
	return 0;
}

chave_type gera_pseudochave(size_t nbits)
{
	chave_type bits = "";

	for (size_t i = 0; i < nbits; ++i)
		bits.push_back(random() % 2 + '0');
	return bits;
}

void print_dados_teste(const std::string& nome_do_teste, struct dados_teste_t& dados)
{
	std::cout << "Dados para o teste: `" << nome_do_teste << "'\n";

	std::cout << "Numero de elementos inseridos: " <<  dados.num_elementos << '\n';
	std::cout << "Numero de baldes: " <<  dados.num_baldes << '\n';
	std::cout << "Fator de carga: " <<  dados.fator_de_carga << '\n';
}
