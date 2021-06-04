#include"PecaRainha.h"
#include "PecaBase.h"

void PecaRainha::jogarComRainha(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaRainha(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaRainhaCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA)
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

bool PecaRainha::validarJogadaRainha(char** tabuleiroBackEnd) {

	if (!validarJogadaRainhaDiagonalDireita(tabuleiroBackEnd))
	{
		if (!validarJogadaRainhaDiagonalEsquerda(tabuleiroBackEnd))
		{
			if (!validarJogadaRainhaVertical(tabuleiroBackEnd)) {

				if (validarJogadaRainhaHorizontal(tabuleiroBackEnd))
					return true;
			}
			else {
				return true;
			}
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}

	return false;
}

bool PecaRainha::validarJogadaRainhaDiagonalDireita(char** tabuleiroBackEnd) {
	int retorno;

	//VALIDACAO DIAGONAL DIREITA ACIMA
	for (int linha = (PecaBase::globalLinhaPonteiro - 1), coluna = (PecaBase::globalColunaPonteiro + 1); linha >= 0 && coluna < COLUNAS; linha--, coluna++) {
		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL DIREITA A BAIXO
	for (int linha = (PecaBase::globalLinhaPonteiro + 1), coluna = (PecaBase::globalColunaPonteiro + 1); linha < LINHAS && coluna < COLUNAS; linha++, coluna++) {
		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	return false;
}

bool PecaRainha::validarJogadaRainhaDiagonalEsquerda(char** tabuleiroBackEnd) {
	int retorno;
	//VALIDACAO DIAGONAL ESQUERDA ACIMA
	for (int linha = (PecaBase::globalLinhaPonteiro - 1), coluna = (PecaBase::globalColunaPonteiro - 1); linha >= 0 && coluna >= 0; linha--, coluna--) {
		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);
		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL ESQUERDA A BAIXO
	for (int linha = (PecaBase::globalLinhaPonteiro + 1), coluna = (PecaBase::globalColunaPonteiro - 1); linha < LINHAS && coluna >= 0; linha++, coluna--) {
		retorno = PecaBase::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);
		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	return false;
}

bool PecaRainha::validarJogadaRainhaVertical(char** tabuleiroBackEnd) {
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

bool PecaRainha::validarJogadaRainhaHorizontal(char** tabuleiroBackEnd) {
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

bool PecaRainha::validarJogadaRainhaCaptura(char** tabuleiroBackEnd) {
	return validarJogadaRainha(tabuleiroBackEnd);
}