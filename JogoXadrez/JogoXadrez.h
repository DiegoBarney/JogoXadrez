#pragma once
#include "CoreXadrez.h"

class JogoXadrez {

public:
	void intro();
	void imprimeTutorial();
	bool ehGanhador();
	void capturaDadosJogador();
	void reorganizaDadosDasPecasAposSairDoJogo(char** tabuleiroBackEnd);
	void verificaEvolucaoDaPecaPiao(char** tabuleiroBackEnd);

private:
	char imprimeSelecaoDePecaParaEvolucao();
};