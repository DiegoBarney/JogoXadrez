#pragma once

#include "CoreXadrez.h"
#include "Tabuleiro.h"

class PecaBase {     

public:     
	static int		globalLinhaPecaSelecionada,
					globalColunaPecaSelecionada;

	static char		globalPecaSelecionada;

	static int		globalLinhaPonteiro,
					globalColunaPonteiro;

	static char		globalPecaBackupDoPonteiro;

	static int		globalPlacarPretas,
					globalPlacarBrancas;

	static char		globalAvisos[1000];

	static char		ultimaPecaEliminada;


	static PecaBase* getInstance(char** tabuleiroBackEnd);
	~PecaBase();
	void moveParaDireita(char** tabuleiroBackEnd);
	void moveParaEsquerda(char** tabuleiroBackEnd);
	void moveParaCima(char** tabuleiroBackEnd);
	void moveParaBaixo(char** tabuleiroBackEnd);
	void pegaPeca(char** tabuleiroBackEnd);
	void soltaPeca(char** tabuleiroBackEnd);
	void cancelaJogada(char** tabuleiroBackEnd);
	static bool validarJogadaCorretaCapturaPecaExtras();
	static void soltaPecaAposValidacoesExtras(char** tabuleiroBackEnd);
	static int	validacoesDeCapturaPecaExtras(char** tabuleiroBackEnd, int linha, int coluna);
	static void zerarInformacoes();

private:
	PecaBase(char** tabuleiroBackEnd);
	void verificaSePiaoEvoluiu(char** tabuleiroBackEnd);
};