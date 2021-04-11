#include "PecaTorre.h"
#include"Peca.h"

extern int		globalLinhaPecaSelecionada,
				globalColunaPecaSelecionada;
extern char		globalPecaSelecionada;

extern int		globalLinhaPonteiro,
				globalColunaPonteiro;
extern char		globalPecaBackupDoPonteiro;

extern int		globalPlacarPretas,
				globalPlacarBrancas;
extern char		globalAvisos[1000];


void soltaPecaAposValidacoesTorre(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

int validacoesDeCapturaPecaTorre(char** tabuleiroBackEnd, int linha, int coluna) {

	if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesTorre(tabuleiroBackEnd);
			return VALIDACAO_CAPTURADA;
		}
		else
		{
			return VALIDACAO_ENCERRAR;
		}
	}

	return VALIDACAO_CONTINUAR;
}

void PecaTorre::jogarComTorre(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaTorre(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if(globalPecaBackupDoPonteiro != VAZIO && validarJogadaCorretaCaptura()) {

		if (validarJogadaTorreCaptura(tabuleiroBackEnd)) {

			if (globalPecaBackupDoPonteiro == PECA_PRETA_TORRE)
				globalPlacarPretas++;
			else
				globalPlacarBrancas++;

			return;
		}
		else {
			//avisos
		}
	}
	else {
		//avisos
	}

}

bool PecaTorre::validarJogadaTorre(char** tabuleiroBackEnd) {

	if (!validarJogadaTorreVertical(tabuleiroBackEnd))
	{
		return validarJogadaBispoHorizontal(tabuleiroBackEnd);
	}
	else{
		return true;
	}

	return false;
}

bool PecaTorre::validarJogadaTorreVertical(char** tabuleiroBackEnd) {
	int retorno;

	//VERIFICA PECA LARGADA A BAIXO
	for (int linha = (globalLinhaPonteiro - 1), coluna = globalColunaPonteiro; linha >= 0; linha--) {

		retorno = validacoesDeCapturaPecaTorre(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;

	}

	//VERIFICA PECA LARGADA ACIMA
	for (int linha = (globalLinhaPonteiro + 1), coluna = globalColunaPonteiro; linha < LINHAS; linha++) {
		retorno = validacoesDeCapturaPecaTorre(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	return false;
}

bool PecaTorre::validarJogadaBispoHorizontal(char** tabuleiroBackEnd) {
	int retorno;

	//VERIFICA PECA LARGADA A DIREITA
	for (int linha = globalLinhaPonteiro, coluna = (globalColunaPonteiro - 1); coluna >= 0; coluna--) {
		retorno = validacoesDeCapturaPecaTorre(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VERIFICA PECA LARGADA A ESQUERDA
	for (int linha = globalLinhaPonteiro, coluna = (globalColunaPonteiro + 1); coluna < LINHAS; coluna++) {

		retorno = validacoesDeCapturaPecaTorre(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	return false;
}

bool PecaTorre::validarJogadaTorreCaptura(char** tabuleiroBackEnd) {

	return validarJogadaTorre(tabuleiroBackEnd);
}

bool PecaTorre::validarJogadaCorretaCaptura() {

	//JOGADA DA TORRE BRANCA
	if (((globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
		&& globalPecaSelecionada == PECA_BRANCA_TORRE) ||

		//JOGADA DO BISPO PRETO
		((globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_TORRE)) {

		return true;
	}

	return false;
}

