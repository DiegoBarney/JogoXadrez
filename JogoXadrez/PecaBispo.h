#pragma once
#include "CoreXadrez.h"

class PecaBispo {

public:
	void jogarComBispo(char** tabuleiroBackEnd);

private:
	bool validarJogadaBispo(char** tabuleiroBackEnd);
	bool validarJogadaBispoDireita(char** tabuleiroBackEnd);
	bool validarJogadaBispoEsquerda(char** tabuleiroBackEnd);
	bool validarJogadaBispoCaptura(char** tabuleiroBackEnd);
};
