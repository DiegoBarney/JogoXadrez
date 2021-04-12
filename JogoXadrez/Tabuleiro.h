#pragma once

#include "CoreXadrez.h"
#include "PecaBase.h"

struct dados_jogador
{
	char nome[50];
	char pecaJogador;
	bool vencedor = false;
};

//Variavel global adicionais do jogo -----------------------//
															//		
extern char		globalPecaDeveJogarAgora;					//
															//
extern dados_jogador	globalPlayer1,						//
						globalPlayer2;						//
//----------------------------------------------------------//

class Tabuleiro {

public:
	char** organizaTabuleiroBackEndIncial();
	void tabuleiroUserIterface(char** tabuleiroBackEnd);
	void movimentacaoNoTabuleiroBackEnd(char** tabuleiroBackEnd, int eventoDeTecla);

};
