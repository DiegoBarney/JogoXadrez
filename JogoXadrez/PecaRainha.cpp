#include"PecaRainha.h"

extern int		globalLinhaPecaSelecionada,
				globalColunaPecaSelecionada;
extern char		globalPecaSelecionada;

extern int		globalLinhaPonteiro,
				globalColunaPonteiro;
extern char		globalPecaBackupDoPonteiro;

extern int		globalPlacarPretas,
				globalPlacarBrancas;
extern char		globalAvisos[1000];


void soltaPecaAposValidacoesRainha(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

int validacoesDeCapturaPecaRainha(char** tabuleiroBackEnd, int linha, int coluna) {

	if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesRainha(tabuleiroBackEnd);
			return VALIDACAO_CAPTURADA;
		}
		else
		{
			return VALIDACAO_ENCERRAR;
		}
	}

	return VALIDACAO_CONTINUAR;
}

void PecaRainha::jogarComRainha(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaRainha(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (globalPecaBackupDoPonteiro != VAZIO && validarJogadaCorretaCapturaRainha()) {

		if (validarJogadaRainhaCaptura(tabuleiroBackEnd)) {

			if (globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA)
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
	for (int linha = (globalLinhaPonteiro - 1), coluna = (globalColunaPonteiro + 1); linha >= 0 && coluna < COLUNAS; linha--, coluna++) {
		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL DIREITA A BAIXO
	for (int linha = (globalLinhaPonteiro + 1), coluna = (globalColunaPonteiro + 1); linha < LINHAS && coluna < COLUNAS; linha++, coluna++) {
		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);

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
	for (int linha = (globalLinhaPonteiro - 1), coluna = (globalColunaPonteiro - 1); linha >= 0 && coluna >= 0; linha--, coluna--) {
		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);
		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL ESQUERDA A BAIXO
	for (int linha = (globalLinhaPonteiro + 1), coluna = (globalColunaPonteiro - 1); linha < LINHAS && coluna >= 0; linha++, coluna--) {
		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);
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
	for (int linha = (globalLinhaPonteiro - 1), coluna = globalColunaPonteiro; linha >= 0; linha--) {

		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;

	}

	//VERIFICA PECA LARGADA ACIMA
	for (int linha = (globalLinhaPonteiro + 1), coluna = globalColunaPonteiro; linha < LINHAS; linha++) {
		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);

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
	for (int linha = globalLinhaPonteiro, coluna = (globalColunaPonteiro - 1); coluna >= 0; coluna--) {
		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VERIFICA PECA LARGADA A ESQUERDA
	for (int linha = globalLinhaPonteiro, coluna = (globalColunaPonteiro + 1); coluna < LINHAS; coluna++) {

		retorno = validacoesDeCapturaPecaRainha(tabuleiroBackEnd, linha, coluna);

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

bool PecaRainha::validarJogadaCorretaCapturaRainha() {
	//JOGADA DA RAINHA BRANCA
	if (((globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
		&& globalPecaSelecionada == PECA_BRANCA_RAINHA) ||

		//JOGADA DA RAINHA PRETA
		((globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_RAINHA)) {

		return true;
	}

	return false;
}