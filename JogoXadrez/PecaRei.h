#pragma once
#include "CoreXadrez.h"

class PecaRei {

public:
	void jogarComRei(char** tabuleiroBackEnd);

private:
	bool validarJogadaRei(char** tabuleiroBackEnd);

	bool validarJogadaReiDireita(char** tabuleiroBackEnd);
	bool validarJogadaReiEsquerda(char** tabuleiroBackEnd);
	bool validarJogadaReiAcima(char** tabuleiroBackEnd);
	bool validarJogadaReiAbaixo(char** tabuleiroBackEnd);

	bool validarJogadaReiCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCorretaCapturaRei();
};