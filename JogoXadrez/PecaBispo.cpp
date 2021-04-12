#include "PecaBispo.h"
#include "Peca.h"

void PecaBispo::jogarComBispo(char** tabuleiroBackEnd) {

	if (Peca::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaBispo(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if(Peca::globalPecaBackupDoPonteiro != VAZIO && Peca::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaBispoCaptura(tabuleiroBackEnd)) {

			if (Peca::globalPecaBackupDoPonteiro == PECA_PRETA_BISPO)
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

bool PecaBispo::validarJogadaBispo(char** tabuleiroBackEnd) {

	if (!validarJogadaBispoDireita(tabuleiroBackEnd))
	{
		return validarJogadaBispoEsquerda(tabuleiroBackEnd);
	}else{

		return true;
	}

	return false;
}

bool PecaBispo::validarJogadaBispoDireita(char** tabuleiroBackEnd) {
	int retorno;

	//VALIDACAO DIAGONAL DIREITA ACIMA
	for (int linha = (Peca::globalLinhaPonteiro - 1), coluna = (Peca::globalColunaPonteiro + 1); linha >= 0 && coluna < COLUNAS; linha--, coluna++) {
		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL DIREITA A BAIXO
	for (int linha = (Peca::globalLinhaPonteiro + 1), coluna = (Peca::globalColunaPonteiro + 1); linha < LINHAS && coluna < COLUNAS; linha++, coluna++) {
		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	return false;
}

bool PecaBispo::validarJogadaBispoEsquerda(char** tabuleiroBackEnd) {
	int retorno;
	//VALIDACAO DIAGONAL ESQUERDA ACIMA
	for (int linha = (Peca::globalLinhaPonteiro - 1), coluna = (Peca::globalColunaPonteiro - 1); linha >= 0 && coluna >= 0; linha--, coluna--) {
		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);
		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL ESQUERDA A BAIXO
	for (int linha = (Peca::globalLinhaPonteiro + 1), coluna = (Peca::globalColunaPonteiro - 1); linha < LINHAS && coluna >= 0; linha++, coluna--) {
		retorno = Peca::validacoesDeCapturaPecaExtras(tabuleiroBackEnd, linha, coluna);
		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	return false;
}

bool PecaBispo::validarJogadaBispoCaptura(char** tabuleiroBackEnd) {

	return validarJogadaBispo(tabuleiroBackEnd);
}