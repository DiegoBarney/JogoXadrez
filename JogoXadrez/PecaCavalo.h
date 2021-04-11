#pragma once
#include "CoreXadrez.h"

class PecaCavalo {

public:
	void jogarComCavalo(char** tabuleiroBackEnd);

private:
	bool validarJogadaCavalo(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerdaAcima(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerdaAbaixo(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireitaAcima(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireitaAbaixo(char** tabuleiroBackEnd);

	bool validarJogadaCavaloCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerdaAcimaCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCavaloEsquerdaAbaixoCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireitaAcimaCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCavaloDireitaAbaixoCaptura(char** tabuleiroBackEnd);
	bool validarJogadaCorretaCapturaCavalo();
};
