#include "PecaTorre.h"
#include"PecaBase.h"

void PecaTorre::jogarComTorre(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaTorre(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if(PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaTorreCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_TORRE)
				PecaBase::globalPlacarPretas++;
			else
				PecaBase::globalPlacarBrancas++;

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
	for (int linha = (PecaBase::globalLinhaPonteiro - 1), coluna = PecaBase::globalColunaPonteiro; linha >= 0; linha--) {

		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;

	}

	//VERIFICA PECA LARGADA ACIMA
	for (int linha = (PecaBase::globalLinhaPonteiro + 1), coluna = PecaBase::globalColunaPonteiro; linha < LINHAS; linha++) {
		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

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
	for (int linha = PecaBase::globalLinhaPonteiro, coluna = (PecaBase::globalColunaPonteiro - 1); coluna >= 0; coluna--) {
		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VERIFICA PECA LARGADA A ESQUERDA
	for (int linha = PecaBase::globalLinhaPonteiro, coluna = (PecaBase::globalColunaPonteiro + 1); coluna < LINHAS; coluna++) {

		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

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
