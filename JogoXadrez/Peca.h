#pragma once
#include "CoreXadrez.h"

class Peca{

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

	static bool validarJogadaCorretaCapturaPecaExtras();
	static void soltaPecaAposValidacoesExtras(char** tabuleiroBackEnd);
	static int	validacoesDeCapturaPecaExtras(char** tabuleiroBackEnd, int linha, int coluna);

private:
	Peca();
};
