#include "PecaPiao.h"

extern int		globalLinhaPecaSelecionada,
				globalColunaPecaSelecionada;
extern char		globalPecaSelecionada;

extern int		globalLinhaPonteiro,
				globalColunaPonteiro;
extern char		globalPecaBackupDoPonteiro;

extern int	globalPlacarPretas,
			globalPlacarBrancas;
extern char	globalAvisos[1000];


void soltaPecaAposValidacoes(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

void PecaPiao::jogarComPiao(char** tabuleiroBackEnd) {
	if (globalPecaSelecionada == PECA_BRANCA_PIAO || globalPecaSelecionada == PECA_PRETA_PIAO)
	{
		if (globalPecaBackupDoPonteiro == VAZIO)
		{
			validarJogadaPiao(tabuleiroBackEnd);
		}
		else {
			validarJogadaPiaoCaptura(tabuleiroBackEnd);
		}

	}
}

void PecaPiao::validarJogadaPiao(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		if (globalPecaSelecionada == PECA_BRANCA_PIAO)
		{
			validarJogadaPiaoPecaBranca(tabuleiroBackEnd);
		}

		if (globalPecaSelecionada == PECA_PRETA_PIAO)
		{
			validarJogadaPiaoPecaPreta(tabuleiroBackEnd);
		}
	}
	else {
		memcpy(globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA) + 1);
	}
}

void PecaPiao::validarJogadaPiaoPecaBranca(char** tabuleiroBackEnd) {

	if ((globalLinhaPecaSelecionada - 1) == globalLinhaPonteiro && globalColunaPecaSelecionada == globalColunaPonteiro) {
		soltaPecaAposValidacoes(tabuleiroBackEnd);
		return;
	}
}

void PecaPiao::validarJogadaPiaoPecaPreta(char** tabuleiroBackEnd) {

	if ((globalLinhaPecaSelecionada + 1) == globalLinhaPonteiro && globalColunaPecaSelecionada == globalColunaPonteiro) {
		soltaPecaAposValidacoes(tabuleiroBackEnd);
		return;
	}
}

void PecaPiao::validarJogadaPiaoCaptura(char** tabuleiroBackEnd) {

	if (globalPecaSelecionada == PECA_PRETA_PIAO)
	{
		validarJogadaPiaoPecaPretaCaptura(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_PIAO) {

		validarJogadaPiaoPecaBrancaCaptura(tabuleiroBackEnd);
	}
}

void PecaPiao::validarJogadaPiaoPecaBrancaCaptura(char** tabuleiroBackEnd) {

	//JOGADA DE CAPTURA ESQUERDA
	if ((globalLinhaPecaSelecionada - 1) == globalLinhaPonteiro && (globalColunaPecaSelecionada - 1) == globalColunaPonteiro ||
		(globalLinhaPecaSelecionada - 1) == globalLinhaPonteiro && (globalColunaPecaSelecionada + 1) == globalColunaPonteiro) {

		if (globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO) {

			//ELIMINO PECA INIMIGA
			tabuleiroBackEnd[globalLinhaPecaSelecionada - 1][globalColunaPecaSelecionada - 1] = VAZIO;

			globalPlacarBrancas++;

			soltaPecaAposValidacoes(tabuleiroBackEnd);

			return;
		}
	}

	memcpy(globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
}

void PecaPiao::validarJogadaPiaoPecaPretaCaptura(char** tabuleiroBackEnd) {

	if ((globalLinhaPecaSelecionada + 1) == globalLinhaPonteiro && (globalColunaPecaSelecionada + 1) == globalColunaPonteiro ||
		(globalLinhaPecaSelecionada + 1) == globalLinhaPonteiro && (globalColunaPecaSelecionada - 1) == globalColunaPonteiro) {

		if (globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO) {

			//ELIMINO PECA INIMIGA
			tabuleiroBackEnd[globalLinhaPecaSelecionada + 1][globalColunaPecaSelecionada + 1] = VAZIO;

			globalPlacarPretas++;

			soltaPecaAposValidacoes(tabuleiroBackEnd);

			return;
		}
	}

	memcpy(globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
}