#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <memory>
#include <ostream>

#include "Balde.hpp"

class Diretorio
{
private:
	std::unique_ptr<std::shared_ptr<Balde>[]> _conjunto_baldes;
	const size_t _capacidade_balde;
	const size_t _maxbits;
	size_t _profundidade;
	size_t _tamanho;
	size_t _num_baldes;
	size_t _num_elementos;

	size_t chave_to_index(const chave_type& chave) const;

	void duplica_diretorio();
	void divide_balde(Balde& balde_ant, size_t indx);
	void redistribui_chaves(Balde& novo, Balde& antigo, size_t indx_novo);

public:
	Diretorio(size_t maxbits, size_t capacidade_balde);

	size_t tamanho() const;
	size_t maxbits() const;
	size_t profundidade() const;
	size_t capacidade_balde() const;
	size_t numero_de_baldes() const;
	size_t numero_de_elementos() const;
	double fator_de_carga() const;

	bool insere(chave_type chave);
	bool buscar(const chave_type& chave) const;

	std::ostream& print(std::ostream& out) const;
};

inline std::ostream& operator<<(std::ostream& os, const Diretorio& d)
{
	return d.print(os);
}

#endif // DIRETORIO_HPP
