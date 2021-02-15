#include "Diretorio.hpp"

#define PROFUNDIDADE_INICIAL 1
#define TAMANHO_INICIAL 2

using namespace std;

Diretorio::Diretorio(size_t maxbits, size_t capacidade_balde):
	_conjunto_baldes {new shared_ptr<Balde>[TAMANHO_INICIAL]},
	_capacidade_balde {capacidade_balde},
	_maxbits {maxbits},
	_profundidade {PROFUNDIDADE_INICIAL},
	_tamanho {TAMANHO_INICIAL},
	_num_baldes {1},
	_num_elementos {0}
{
	shared_ptr<Balde> p(new Balde(this->_capacidade_balde));

	for (size_t i = 0; i < this->_tamanho; ++i)
		this->_conjunto_baldes[i] = p;
}

size_t Diretorio::tamanho() const
{
	return this->_tamanho;
}

size_t Diretorio::maxbits() const
{
	return this->_maxbits;
}

size_t Diretorio::profundidade() const
{
	return this->_profundidade;
}

size_t Diretorio::capacidade_balde() const
{
	return this->_capacidade_balde;
}

size_t Diretorio::numero_de_baldes() const
{
	return this->_num_baldes;
}

size_t Diretorio::numero_de_elementos() const
{
	return this->_num_elementos;
}

double Diretorio::fator_de_carga() const
{
	return (double) this->_num_elementos / (this->_num_baldes * this->_capacidade_balde);
}

size_t Diretorio::chave_to_index(const chave_type& chave) const
{
	return std::stoi(
		chave.substr(0, this->_profundidade),
		nullptr,
		2
	);
}

void Diretorio::duplica_diretorio()
{
	unique_ptr<shared_ptr<Balde>[]> temp(new shared_ptr<Balde>[this->_tamanho * 2]);

	for (size_t i = 0; i < this->_tamanho; ++i)
	{
		temp[i * 2] = this->_conjunto_baldes[i];
		temp[i * 2 + 1] = this->_conjunto_baldes[i];
	}
	
	this->_tamanho *= 2;
	++this->_profundidade;
	this->_conjunto_baldes = std::move(temp);
}

void Diretorio::divide_balde(Balde& balde_antigo, size_t indx)
{
	balde_antigo.aumenta_profundidade();

	Balde *novo = new Balde(balde_antigo.profundidade(), this->capacidade_balde());

	++this->_num_baldes;
	this->_conjunto_baldes[indx].reset(novo);
	this->redistribui_chaves(*novo, balde_antigo, indx);
}

void Diretorio::redistribui_chaves(Balde& balde_novo, Balde& balde_antigo, size_t indx_novo)
{
	for (size_t i = 0; i < balde_antigo.tamanho(); ++i)
	{
		size_t indx = this->chave_to_index(balde_antigo[i]);

		if (indx == indx_novo)
			balde_novo.insere(balde_antigo[i]);
	}

	for (size_t i = 0; i < balde_novo.tamanho(); ++i)
		balde_antigo.remove_chave(balde_novo[i]);
}

bool Diretorio::insere(chave_type chave)
{
	size_t indx = this->chave_to_index(chave);
	Balde& balde = *(this->_conjunto_baldes[indx]);

	if (balde.is_cheio())
	{
		if (this->_profundidade == this->_maxbits)
			return false;
		if (balde.profundidade() == this->_profundidade)
			this->duplica_diretorio();
		this->divide_balde(balde, indx);
		return this->insere(chave);
	}
	balde.insere(std::move(chave));
	++this->_num_elementos;
	return true;
}

bool Diretorio::buscar(const chave_type& chave) const
{
	size_t indx = this->chave_to_index(chave);
	return this->_conjunto_baldes[indx]->buscar(chave);
}

ostream& Diretorio::print(ostream& out) const
{

	for (size_t i = 0; i < this->_tamanho; ++i)
	{
		Balde& b = *(this->_conjunto_baldes[i]);

		out << "==============================\n";
		out << "Balde " << i << ":";
		out << "Profundidade: " << b.profundidade() << '\n';
		out << "Numero de elementos: " << b.tamanho() << '\n';
		out << "==============================\n";
		out << "Elementos no balde:\n";

		for (size_t j = 0; j < b.tamanho(); ++j)
			out << b[j] << '\n';
		out << "****************************\n";
	}
	return out;
}
