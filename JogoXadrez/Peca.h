#pragma once
#include "CoreXadrez.h"

class Peca{

public:
	static int		globalLinhaPecaSelecionada1,
					globalColunaPecaSelecionada1;
	static char		globalPecaSelecionada1;

	static int		globalLinhaPonteiro1,
					globalColunaPonteiro1;
	static char		globalPecaBackupDoPonteiro1;

	static int		globalPlacarPretas1,
					globalPlacarBrancas1;

	static char		globalAvisos1[1000];

	static bool validarJogadaCorretaCapturaPeca();
	static void soltaPecaAposValidacoesExtras(char** tabuleiroBackEnd);
	static int	validacoesDeCapturaPecaExtras(char** tabuleiroBackEnd, int linha, int coluna);

private:
	Peca();
};
