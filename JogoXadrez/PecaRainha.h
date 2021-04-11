#pragma once
#include "CoreXadrez.h"

class PecaRainha {

public:
	void jogarComRainha(char** tabuleiroBackEnd);

private:
	bool validarJogadaRainha(char** tabuleiroBackEnd);

	bool validarJogadaRainhaDiagonalDireita(char** tabuleiroBackEnd);
	bool validarJogadaRainhaDiagonalEsquerda(char** tabuleiroBackEnd);
	bool validarJogadaRainhaVertical(char** tabuleiroBackEnd);
	bool validarJogadaRainhaHorizontal(char** tabuleiroBackEnd);

	bool validarJogadaRainhaCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCorretaCapturaRainha();
};