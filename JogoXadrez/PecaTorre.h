#pragma once
#include "CoreXadrez.h"

class PecaTorre {

public:
	void jogarComTorre(char** tabuleiroBackEnd);

private:
	bool validarJogadaTorre(char** tabuleiroBackEnd);
	bool validarJogadaTorreVertical(char** tabuleiroBackEnd);
	bool validarJogadaBispoHorizontal(char** tabuleiroBackEnd);

	bool validarJogadaTorreCaptura(char** tabuleiroBackEnd);
	bool validarJogadaTorreCapturaVertical(char** tabuleiroBackEnd);
	bool validarJogadaTorreCapturaHorizontal(char** tabuleiroBackEnd);
	bool validarJogadaCorretaCaptura();
};
