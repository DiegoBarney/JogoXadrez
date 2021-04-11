#include "PecaBispo.h"

extern int		globalLinhaPecaSelecionada,
				globalColunaPecaSelecionada;
extern char		globalPecaSelecionada;

extern int		globalLinhaPonteiro,
				globalColunaPonteiro;
extern char		globalPecaBackupDoPonteiro;

extern int		globalPlacarPretas,
				globalPlacarBrancas;
extern char		globalAvisos[1000];

void soltaPecaAposValidacoesBispo(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGO
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

int validacoesDeCapturaPeca(char** tabuleiroBackEnd, int linha, int coluna) {

	if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesBispo(tabuleiroBackEnd);
			return VALIDACAO_CAPTURADA;
		}
		else
		{
			return VALIDACAO_ENCERRAR;
		}
	}

	return VALIDACAO_CONTINUAR;
}

void PecaBispo::jogarComBispo(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaBispo(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if(globalPecaBackupDoPonteiro != VAZIO && validarJogadaCorretaCaptura()) {

		if (validarJogadaBispoCaptura(tabuleiroBackEnd)) {

			if (globalPecaBackupDoPonteiro == PECA_PRETA_BISPO)
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
	for (int linha = (globalLinhaPonteiro - 1), coluna = (globalColunaPonteiro + 1); linha >= 0 && coluna < COLUNAS; linha--, coluna++) {
		retorno = validacoesDeCapturaPeca(tabuleiroBackEnd, linha, coluna);

		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL DIREITA A BAIXO
	for (int linha = (globalLinhaPonteiro + 1), coluna = (globalColunaPonteiro + 1); linha < LINHAS && coluna < COLUNAS; linha++, coluna++) {
		retorno = validacoesDeCapturaPeca(tabuleiroBackEnd, linha, coluna);

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
	for (int linha = (globalLinhaPonteiro - 1), coluna = (globalColunaPonteiro - 1); linha >= 0 && coluna >= 0; linha--, coluna--) {
		retorno = validacoesDeCapturaPeca(tabuleiroBackEnd, linha, coluna);
		if (retorno == VALIDACAO_CAPTURADA)
			return true;
		if (retorno == VALIDACAO_ENCERRAR)
			break;
	}

	//VALIDACAO DIAGONAL ESQUERDA A BAIXO
	for (int linha = (globalLinhaPonteiro + 1), coluna = (globalColunaPonteiro - 1); linha < LINHAS && coluna >= 0; linha++, coluna--) {
		retorno = validacoesDeCapturaPeca(tabuleiroBackEnd, linha, coluna);
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

bool PecaBispo::validarJogadaCorretaCaptura() {

			//JOGADA DO BISPO BRANCO
	if ( ( (globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
			&& globalPecaSelecionada == PECA_BRANCA_BISPO ) ||

			//JOGADA DO BISPO PRETO
		( ( globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_BISPO ) ) {

		return true;
	}

	return false;
}
