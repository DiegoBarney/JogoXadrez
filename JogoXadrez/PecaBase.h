#pragma once
#include "CoreXadrez.h"
#include "Tabuleiro.h"

class PecaBase {     

public:     
				
	static PecaBase* getInstance(char** tabuleiroBackEnd);
	~PecaBase();
	void moveParaDireita(char** tabuleiroBackEnd);
	void moveParaEsquerda(char** tabuleiroBackEnd);
	void moveParaCima(char** tabuleiroBackEnd);
	void moveParaBaixo(char** tabuleiroBackEnd);
	void pegaPeca(char** tabuleiroBackEnd);
	void soltaPeca(char** tabuleiroBackEnd);
	void cancelaJogada(char** tabuleiroBackEnd);


private:
	PecaBase(char** tabuleiroBackEnd);
	void verificaSePiaoEvoluiu(char** tabuleiroBackEnd);
};