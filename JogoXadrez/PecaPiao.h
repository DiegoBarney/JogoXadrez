#pragma once
#include "CoreXadrez.h"

class PecaPiao {

public:
	void jogarComPiao(char** tabuleiroBackEnd);

private:
	bool validarJogadaPiao(char** tabuleiroBackEnd);
	bool validarJogadaPiaoCaptura(char** tabuleiroBackEnd);
	bool validarJogadaPiaoPecaBranca(char** tabuleiroBackEnd);
	bool validarJogadaPiaoPecaPreta(char** tabuleiroBackEnd);
	bool validarJogadaPiaoPecaBrancaCaptura(char** tabuleiroBackEnd);
	bool validarJogadaPiaoPecaPretaCaptura(char** tabuleiroBackEnd);
};