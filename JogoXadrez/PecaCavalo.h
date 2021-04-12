#pragma once
#include "CoreXadrez.h"

class PecaCavalo {

public:
	void jogarComCavalo(char** tabuleiroBackEnd);

private:
	bool validarJogadaCavalo(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerda(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireita(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerdaAcima(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerdaAbaixo(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireitaAcima(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireitaAbaixo(char** tabuleiroBackEnd);
	bool validarJogadaCavaloCaptura(char** tabuleiroBackEnd);
};
