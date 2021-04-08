#pragma once
#include "CoreXadrez.h"

class PecaPiao {

public:
	void jogarComPiao(char** tabuleiroBackEnd);

private:
	void validarJogadaPiao(char** tabuleiroBackEnd);
	void validarJogadaPiaoCaptura(char** tabuleiroBackEnd);
	void validarJogadaPiaoPecaBranca(char** tabuleiroBackEnd);
	void validarJogadaPiaoPecaPreta(char** tabuleiroBackEnd);
	void validarJogadaPiaoPecaBrancaCaptura(char** tabuleiroBackEnd);
	void validarJogadaPiaoPecaPretaCaptura(char** tabuleiroBackEnd);
};