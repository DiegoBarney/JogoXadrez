#include "PecaCavalo.h"
#include "Peca.h"

void PecaCavalo::jogarComCavalo(char** tabuleiroBackEnd) {

	if (Peca::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaCavalo(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (Peca::globalPecaBackupDoPonteiro != VAZIO && Peca::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaCavaloCaptura(tabuleiroBackEnd)) {

			if (Peca::globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO)
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

bool PecaCavalo::validarJogadaCavalo(char** tabuleiroBackEnd) {

	if (!validarJogadaCavaloEsquerda(tabuleiroBackEnd))
	{
		if (validarJogadaCavaloDireita(tabuleiroBackEnd))
		{
			return true;
		}
	}
	else {
		return true;
	}


	return false;
}

bool PecaCavalo::validarJogadaCavaloEsquerda(char** tabuleiroBackEnd) {

	if (!validarJogadaCavaloEsquerdaAcima(tabuleiroBackEnd))
	{
		if (validarJogadaCavaloEsquerdaAbaixo(tabuleiroBackEnd))
			return true;
	}
	else {
		return true;
	}

	return false;
}

bool PecaCavalo::validarJogadaCavaloDireita(char** tabuleiroBackEnd) {

	if (!validarJogadaCavaloDireitaAcima(tabuleiroBackEnd))
	{
		if (validarJogadaCavaloDireitaAbaixo(tabuleiroBackEnd))
			return true;
	}
	else {
		return true;
	}

	return false;
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAcima(char** tabuleiroBackEnd) {
	int linha = Peca::globalLinhaPonteiro + 2,
		coluna = Peca::globalColunaPonteiro + 1;

	if (linha < LINHAS && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}

	}

	linha = Peca::globalLinhaPonteiro + 1;
	coluna = Peca::globalColunaPonteiro + 2;

	if (linha < LINHAS && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}
	}
	

	return false;
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAbaixo(char** tabuleiroBackEnd) {
	int linha = Peca::globalLinhaPonteiro - 1,
		coluna = Peca::globalColunaPonteiro + 2;

	if (linha >= 0 && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}
	}

	linha = Peca::globalLinhaPonteiro - 2;
	coluna = Peca::globalColunaPonteiro + 1;

	if (linha >= 0 && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}
	}


	return false;
}

bool PecaCavalo::validarJogadaCavaloDireitaAcima(char** tabuleiroBackEnd) {
	int linha = Peca::globalLinhaPonteiro + 2,
		coluna = Peca::globalColunaPonteiro - 1;

	if (linha < LINHAS && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}

	}

	linha = Peca::globalLinhaPonteiro + 1;
	coluna = Peca::globalColunaPonteiro - 2;

	if (linha < LINHAS && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}
	}
	

	return false;
}

bool PecaCavalo::validarJogadaCavaloDireitaAbaixo(char** tabuleiroBackEnd) {
	int linha = Peca::globalLinhaPonteiro - 1,
		coluna = Peca::globalColunaPonteiro - 2;

	if (linha >= 0 && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}
	}

	linha = Peca::globalLinhaPonteiro - 2;
	coluna = Peca::globalColunaPonteiro - 1;

	if (linha >= 0 && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			return true;
		}
	}
	
	return false;
}

bool PecaCavalo::validarJogadaCavaloCaptura(char** tabuleiroBackEnd) {
	return validarJogadaCavalo(tabuleiroBackEnd);
}
