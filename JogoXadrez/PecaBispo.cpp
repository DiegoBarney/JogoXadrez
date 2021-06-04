#include "PecaBispo.h"
#include "PecaBase.h"

void PecaBispo::jogarComBispo(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaBispo(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if(PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaBispoCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_BISPO)
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

bool PecaBispo::validarJogadaBispoEsquerda(char** tabuleiroBackEnd) {
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

bool PecaBispo::validarJogadaBispoCaptura(char** tabuleiroBackEnd) {

	return validarJogadaBispo(tabuleiroBackEnd);
}