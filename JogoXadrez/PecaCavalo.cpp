#include "PecaCavalo.h"

extern int		globalLinhaPecaSelecionada,
				globalColunaPecaSelecionada;
extern char		globalPecaSelecionada;

extern int		globalLinhaPonteiro,
				globalColunaPonteiro;
extern char		globalPecaBackupDoPonteiro;

extern int		globalPlacarPretas,
				globalPlacarBrancas;
extern char		globalAvisos[1000];



void soltaPecaAposValidacoesCavalo(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}


void PecaCavalo::jogarComCavalo(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaCavalo(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (globalPecaBackupDoPonteiro != VAZIO && validarJogadaCorretaCapturaCavalo()) {

		if (validarJogadaCavaloCaptura(tabuleiroBackEnd)) {

			if (globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO)
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

bool PecaCavalo::validarJogadaCavalo(char** tabuleiroBackEnd) {

	if (!validarJogadaCavaloEsquerdaAcima(tabuleiroBackEnd))
	{
		if (!validarJogadaCavaloEsquerdaAbaixo(tabuleiroBackEnd))
		{
			if (!validarJogadaCavaloDireitaAcima(tabuleiroBackEnd))
			{
				if (validarJogadaCavaloDireitaAbaixo(tabuleiroBackEnd))
					return true;
			}
			else
				return true;
		}
		else
			return true;
	}
	else
		return true;


	return false;
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAcima(char** tabuleiroBackEnd) {
	int linha = globalLinhaPonteiro + 2,
		coluna = globalColunaPonteiro + 1;

	if (linha < LINHAS && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
			return true;
		}

	}
	else
	{
		linha = globalLinhaPonteiro + 1;
		coluna = globalColunaPonteiro + 2;

		if (linha < LINHAS && coluna < COLUNAS)
		{
			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
				return true;
			}
		}
	}

	return false;
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAbaixo(char** tabuleiroBackEnd) {
	int linha = globalLinhaPonteiro - 1,
		coluna = globalColunaPonteiro + 2;

	if (linha >= 0 && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
			return true;
		}
	}
	else
	{
		linha = globalLinhaPonteiro - 2;
		coluna = globalColunaPonteiro + 1;

		if (linha >= 0 && coluna < COLUNAS)
		{
			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
				return true;
			}
		}
	}

	return false;
}

bool PecaCavalo::validarJogadaCavaloDireitaAcima(char** tabuleiroBackEnd) {
	int linha = globalLinhaPonteiro + 2,
		coluna = globalColunaPonteiro - 1;

	if (linha < LINHAS && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
			return true;
		}

	}
	else
	{
		linha = globalLinhaPonteiro + 1;
		coluna = globalColunaPonteiro - 2;

		if (linha < LINHAS && coluna >= 0)
		{
			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
				return true;
			}
		}
	}

	return false;
}

bool PecaCavalo::validarJogadaCavaloDireitaAbaixo(char** tabuleiroBackEnd) {
	int linha = globalLinhaPonteiro - 1,
		coluna = globalColunaPonteiro - 2;

	if (linha >= 0 && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
			return true;
		}
	}
	else
	{
		linha = globalLinhaPonteiro - 2;
		coluna = globalColunaPonteiro - 1;

		if (linha >= 0 && coluna >= 0)
		{
			if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
			{
				soltaPecaAposValidacoesCavalo(tabuleiroBackEnd);
				return true;
			}
		}
	}
	return false;
}

bool PecaCavalo::validarJogadaCavaloCaptura(char** tabuleiroBackEnd) {
	
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAcimaCaptura(char** tabuleiroBackEnd) {
	return validarJogadaCavaloEsquerdaAcima(tabuleiroBackEnd);
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAbaixoCaptura(char** tabuleiroBackEnd) {
	return validarJogadaCavaloEsquerdaAbaixo(tabuleiroBackEnd);
}

bool PecaCavalo::validarJogadaCavaloDireitaAcimaCaptura(char** tabuleiroBackEnd) {
	return validarJogadaCavaloDireitaAcima(tabuleiroBackEnd);
}

bool PecaCavalo::validarJogadaCavaloDireitaAbaixoCaptura(char** tabuleiroBackEnd) {
	return validarJogadaCavaloDireitaAbaixo(tabuleiroBackEnd);
}

bool PecaCavalo::validarJogadaCorretaCapturaCavalo() {

	//JOGADA DA TORRE
	if (((globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
		&& globalPecaSelecionada == PECA_BRANCA_CAVALO) ||

		//JOGADA DO BISPO PRETO
		((globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_CAVALO)) {

		return true;
	}

	return false;
}