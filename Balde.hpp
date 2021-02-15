#ifndef BALDE_HPP
#define BALDE_HPP

#include <string>
#include <memory>

using chave_type = std::string;

class Balde
{
private:
	std::unique_ptr<chave_type[]> _elementos;
	size_t _tamanho;
	size_t _profundidade;
	const size_t _capacidade;

public:
	Balde(size_t capacidade);
	Balde(size_t profundidade, size_t capacidade);

	size_t profundidade() const;
	size_t capacidade() const;
	size_t tamanho() const;
	bool is_cheio() const;

	void aumenta_profundidade();
	void diminui_profundidade();
	void set_profundidade(size_t profundidade);

	bool buscar(const chave_type& chave) const;
	bool insere(const chave_type& val);
	void remove_chave(const chave_type& chave);
	void remove(size_t n);

	chave_type& operator[](size_t n);
};

#endif // BALDE_HPP
