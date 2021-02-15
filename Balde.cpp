#include "Balde.hpp"

#include <stdexcept>

Balde::Balde(size_t capacidade):
	_elementos {new chave_type[capacidade]},
	_tamanho {0},
	_profundidade {0},
	_capacidade {capacidade}
{
}

Balde::Balde(size_t profundidade, size_t capacidade):
	_elementos {new chave_type[capacidade]},
	_tamanho {0},
	_profundidade {profundidade},
	_capacidade {capacidade}
{
}

size_t Balde::profundidade() const
{
	return this->_profundidade;
}

size_t Balde::capacidade() const
{
	return this->_capacidade;
}

size_t Balde::tamanho() const
{
	return this->_tamanho;
}

bool Balde::is_cheio() const
{
	return (this->_tamanho == this->_capacidade);
}

void Balde::remove_chave(const chave_type& chave)
{
	for (size_t i = 0; i < this->_tamanho; ++i)
	{
		if (this->_elementos[i] == chave)
		{
			this->remove(i);
			return;
		}
	}
}

void Balde::remove(size_t n)
{
	if (n >= this->_tamanho)
		throw std::out_of_range("Balde::remove()");

	--this->_tamanho;
	for (size_t i = n; i < this->_tamanho; ++i)
		this->_elementos[i] = this->_elementos[i + 1];
}

void Balde::aumenta_profundidade()
{
	++this->_profundidade;
}

void Balde::diminui_profundidade()
{
	if (this->_profundidade)
		--this->_profundidade;
}

void Balde::set_profundidade(size_t profundidade)
{
	this->_profundidade = profundidade;
}

bool Balde::insere(const chave_type& val)
{
	if (this->is_cheio())
		return false;
	this->_elementos[this->_tamanho++] = val;
	return true;
}

bool Balde::buscar(const chave_type& chave) const
{
	for (size_t i = 0; i < this->_tamanho; ++i)
		if (this->_elementos[i] == chave)
			return true;
	return false;
}

chave_type& Balde::operator[](size_t n)
{
	return this->_elementos[n];
}
