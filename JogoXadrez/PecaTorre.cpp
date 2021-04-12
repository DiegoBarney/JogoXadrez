#include "PecaTorre.h"
#include"Peca.h"

void PecaTorre::jogarComTorre(char** tabuleiroBackEnd) {

	if (Peca::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaTorre(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if(Peca::globalPecaBackupDoPonteiro != VAZIO && Peca::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaTorreCaptura(tabuleiroBackEnd)) {

			if (Peca::globalPecaBackupDoPonteiro == PECA_PRETA_TORRE)
				Peca::globalPlacarPretas++;
			else
				Peca::globalPlacarBrancas++;

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
	for (int linha = (Peca::globalLinhaPonteiro - 1), coluna = Peca::globalColunaPonteiro; linha >= 0; linha--) {

		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;

	}

	//VERIFICA PECA LARGADA ACIMA
	for (int linha = (Peca::globalLinhaPonteiro + 1), coluna = Peca::globalColunaPonteiro; linha < LINHAS; linha++) {
		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

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
	for (int linha = Peca::globalLinhaPonteiro, coluna = (Peca::globalColunaPonteiro - 1); coluna >= 0; coluna--) {
		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VERIFICA PECA LARGADA A ESQUERDA
	for (int linha = Peca::globalLinhaPonteiro, coluna = (Peca::globalColunaPonteiro + 1); coluna < LINHAS; coluna++) {

		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

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
