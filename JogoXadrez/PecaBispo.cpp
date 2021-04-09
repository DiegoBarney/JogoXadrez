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

	//SOLTO A PECA NO NOVO LOCAL
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

void PecaBispo::jogarComBispo(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		validarJogadaBispo(tabuleiroBackEnd);
	}
	else {
		validarJogadaBispoCaptura(tabuleiroBackEnd);
	}
}

bool PecaBispo::validarJogadaBispo(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO) {

		if (!validarJogadaBispoDireita(tabuleiroBackEnd))
		{
			return validarJogadaBispoEsquerda(tabuleiroBackEnd);
		}
	}
	return false;
}

bool PecaBispo::validarJogadaBispoDireita(char** tabuleiroBackEnd) {

	//VALIDACAO DIAGONAL DIREITA ACIMA
	for (int linha = (globalLinhaPonteiro-1), coluna = (globalColunaPonteiro+1); linha >= 0 && coluna < COLUNAS; linha--, coluna++) {

		if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesBispo(tabuleiroBackEnd);
				return true;
			}
			else
			{
				break;
			}
		}
	}

	//VALIDACAO DIAGONAL DIREITA ABAIXO
	for (int linha = (globalLinhaPonteiro + 1), coluna = (globalColunaPonteiro + 1); linha < LINHAS && coluna < COLUNAS; linha++, coluna++) {

		if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesBispo(tabuleiroBackEnd);
				return true;
			}
			else
			{
				break;
			}
		}
	}

	return false;
}

bool PecaBispo::validarJogadaBispoEsquerda(char** tabuleiroBackEnd) {

	//VALIDACAO DIAGONAL ESQUERDA ACIMA
	for (int linha = (globalLinhaPonteiro - 1), coluna = (globalColunaPonteiro - 1); linha >= 0 && coluna >= 0; linha--, coluna--) {

		if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{

				soltaPecaAposValidacoesBispo(tabuleiroBackEnd);
				return true;
			}
			else
			{
				break;
			}
		}
	}

	//VALIDACAO DIAGONAL ESQUERDA ABAIXO
	for (int linha = (globalLinhaPonteiro + 1), coluna = (globalColunaPonteiro - 1); linha < LINHAS && coluna >= 0; linha++, coluna--) {

		if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesBispo(tabuleiroBackEnd);
				return true;
			}
			else
			{
				break;
			}
		}
	}

	return false;
}

bool PecaBispo::validarJogadaBispoCaptura(char** tabuleiroBackEnd) {

	if (!validarJogadaBispoCapturaDireita(tabuleiroBackEnd))
	{
		return validarJogadaBispoCapturaEsquerda(tabuleiroBackEnd);
	}

	return false;
}

bool PecaBispo::validarJogadaBispoCapturaDireita(char** tabuleiroBackEnd) {
	int linhaPecaInimiga = 0,
		colunaPecaInimiga = 0;
	bool sairLoopEncadeado = false;

	//VALIDACAO DIAGONAL DIREITA ACIMA
	for (int linha = globalLinhaPonteiro, coluna = globalColunaPonteiro, sairLoopEncadeado = false; linha >= 0 && coluna < COLUNAS && sairLoopEncadeado == false; linha--, coluna++) {

		if (validarJogadaCorretaCaptura(tabuleiroBackEnd, linha, coluna)) {

			linhaPecaInimiga = linha;
			colunaPecaInimiga = coluna;

			linha--;
			coluna++;

			for (linha, coluna; linha >= 0 && coluna < COLUNAS && sairLoopEncadeado == false; linha--, coluna++) {

				if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

					if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
					{
						//ELIMINO PECA INIMIGA
						tabuleiroBackEnd[linhaPecaInimiga][colunaPecaInimiga] = VAZIO;


						if (globalPecaSelecionada == PECA_PRETA_BISPO)
							globalPlacarPretas++;
						else
							globalPlacarBrancas++;

						soltaPecaAposValidacoesBispo(tabuleiroBackEnd);

						return true;
					}
					else
					{
						sairLoopEncadeado = true;
					}
				}
			}
		}
	}

	//VALIDACAO DIAGONAL DIREITA A BAIXO
	for (int linha = globalLinhaPonteiro, coluna = globalColunaPonteiro, sairLoopEncadeado = false; linha < LINHAS && coluna < COLUNAS && sairLoopEncadeado == false; linha++, coluna++) {

		if (validarJogadaCorretaCaptura(tabuleiroBackEnd, linha, coluna)) {

			linhaPecaInimiga = linha;
			colunaPecaInimiga = coluna;

			linha++;
			coluna++;

			for (linha, coluna; linha < LINHAS && coluna < COLUNAS && sairLoopEncadeado == false; linha++, coluna++) {

				if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

					if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
					{
						//ELIMINO PECA INIMIGA
						tabuleiroBackEnd[linhaPecaInimiga][colunaPecaInimiga] = VAZIO;


						if (globalPecaSelecionada == PECA_PRETA_BISPO)
							globalPlacarPretas++;
						else
							globalPlacarBrancas++;

						soltaPecaAposValidacoesBispo(tabuleiroBackEnd);

						return true;
					}
					else
					{
						sairLoopEncadeado = true;
					}
				}
			}
		}
	}

	return false;
}

bool PecaBispo::validarJogadaBispoCapturaEsquerda(char** tabuleiroBackEnd) {
	int linhaPecaInimiga = 0,
		colunaPecaInimiga = 0;
	bool sairLoopEncadeado = false;

	//VALIDACAO DIAGONAL ESQUERDA ACIMA
	for (int linha = globalLinhaPonteiro, coluna = globalColunaPonteiro, sairLoopEncadeado = false; linha >= 0 && coluna >= 0 && sairLoopEncadeado == false; linha--, coluna--) {

		if (validarJogadaCorretaCaptura(tabuleiroBackEnd, linha, coluna)) {

			linhaPecaInimiga = linha;
			colunaPecaInimiga = coluna;

			linha--;
			coluna--;

			for (linha, coluna; linha >= 0 && coluna >= 0 && sairLoopEncadeado == false; linha--, coluna--) {

				if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

					if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
					{
						//ELIMINO PECA INIMIGA
						tabuleiroBackEnd[linhaPecaInimiga][colunaPecaInimiga] = VAZIO;

						if (globalPecaSelecionada == PECA_PRETA_BISPO)
							globalPlacarPretas++;
						else
							globalPlacarBrancas++;

						soltaPecaAposValidacoesBispo(tabuleiroBackEnd);
						return true;
					}
					else
					{
						sairLoopEncadeado = true;
					}
				}
			}
		}
	}

	//VALIDACAO DIAGONAL ESQUERDA A BAIXO
	for (int linha = globalLinhaPonteiro, coluna = globalColunaPonteiro, sairLoopEncadeado = false; linha < LINHAS && coluna >= 0 && sairLoopEncadeado == false; linha++, coluna--) {

		if (validarJogadaCorretaCaptura(tabuleiroBackEnd, linha, coluna)) {

			linhaPecaInimiga = linha;
			colunaPecaInimiga = coluna;

			linha++;
			coluna--;

			for (linha, coluna; linha < LINHAS && coluna >= 0 && sairLoopEncadeado == false; linha++, coluna--) {

				if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

					if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
					{
						//ELIMINO PECA INIMIGA
						tabuleiroBackEnd[linhaPecaInimiga][colunaPecaInimiga] = VAZIO;


						if (globalPecaSelecionada == PECA_PRETA_BISPO)
							globalPlacarPretas++;
						else
							globalPlacarBrancas++;

						soltaPecaAposValidacoesBispo(tabuleiroBackEnd);

						return true;
					}
					else
					{
						sairLoopEncadeado = true;
					}
				}
			}

		}
	}

	return false;
}

bool PecaBispo::validarJogadaCorretaCaptura(char** tabuleiroBackEnd, int linha, int coluna) {

			//JOGADA DO BISPO BRANCO
	if ( ( (tabuleiroBackEnd[linha][coluna] == PECA_PRETA_TORRE || tabuleiroBackEnd[linha][coluna] == PECA_PRETA_CAVALO || tabuleiroBackEnd[linha][coluna] == PECA_PRETA_BISPO ||
			tabuleiroBackEnd[linha][coluna] == PECA_PRETA_RAINHA || tabuleiroBackEnd[linha][coluna] == PECA_PRETA_REI || tabuleiroBackEnd[linha][coluna] == PECA_PRETA_PIAO)
			&& globalPecaSelecionada == PECA_BRANCA_BISPO ) ||

			//JOGADA DO BISPO PRETO
		( (	tabuleiroBackEnd[linha][coluna] == PECA_BRANCA_TORRE || tabuleiroBackEnd[linha][coluna] == PECA_BRANCA_CAVALO || tabuleiroBackEnd[linha][coluna] == PECA_BRANCA_BISPO ||
			tabuleiroBackEnd[linha][coluna] == PECA_BRANCA_RAINHA || tabuleiroBackEnd[linha][coluna] == PECA_BRANCA_REI || tabuleiroBackEnd[linha][coluna] == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_BISPO ) ) {

		return true;
	}

	return false;
}
