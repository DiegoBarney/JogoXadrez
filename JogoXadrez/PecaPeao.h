#pragma once
#include "CoreXadrez.h"

class PecaPeao {

public:
	void jogarComPeao(char** tabuleiroBackEnd);

private:
	bool validarJogadaPeao(char** tabuleiroBackEnd);
	bool validarJogadaPeaoCaptura(char** tabuleiroBackEnd);
	bool validarJogadaPeaoPecaBranca(char** tabuleiroBackEnd);
	bool validarJogadaPeaoPecaPreta(char** tabuleiroBackEnd);
	bool validarJogadaPeaoPecaBrancaCaptura(char** tabuleiroBackEnd);
	bool validarJogadaPeaoPecaPretaCaptura(char** tabuleiroBackEnd);
};