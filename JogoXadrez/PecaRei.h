#pragma once
#include "CoreXadrez.h"

class PecaRei {

public:
	void jogarComRei(char** tabuleiroBackEnd);

private:
	bool validarJogadaRei(char** tabuleiroBackEnd);
	bool validarJogadaReiDiagonais(char** tabuleiroBackEnd);
	bool validarJogadaReiLinhaReta(char** tabuleiroBackEnd);
	bool validarJogadaReiCaptura(char** tabuleiroBackEnd);
};