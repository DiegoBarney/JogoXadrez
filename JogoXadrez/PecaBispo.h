#pragma once
#include "CoreXadrez.h"

class PecaBispo {

public:
	void jogarComBispo(char** tabuleiroBackEnd);

private:
	void validarJogadaBispo(char** tabuleiroBackEnd);
	void validarJogadaBispoPecaBranca(char** tabuleiroBackEnd);
	void validarJogadaBispoPecaPreta(char** tabuleiroBackEnd);

	void validarJogadaBispoCaptura(char** tabuleiroBackEnd);
	void validarJogadaBispoPecaBrancaCaptura(char** tabuleiroBackEnd);
	void validarJogadaBispoPecaPretaCaptura(char** tabuleiroBackEnd);
};
