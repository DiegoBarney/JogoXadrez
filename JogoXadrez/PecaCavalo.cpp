#include "PecaCavalo.h"
#include "PecaBase.h"

void PecaCavalo::jogarComCavalo(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaCavalo(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCapturaPeca()) {

		if (validarJogadaCavaloCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO)
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
	int linha = PecaBase::globalLinhaPonteiro + 2,
		coluna = PecaBase::globalColunaPonteiro + 1;

	if (linha < LINHAS && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}

	}

	linha = PecaBase::globalLinhaPonteiro + 1;
	coluna = PecaBase::globalColunaPonteiro + 2;

	if (linha < LINHAS && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}
	

	return false;
}

bool PecaCavalo::validarJogadaCavaloEsquerdaAbaixo(char** tabuleiroBackEnd) {
	int linha = PecaBase::globalLinhaPonteiro - 1,
		coluna = PecaBase::globalColunaPonteiro + 2;

	if (linha >= 0 && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}

	linha = PecaBase::globalLinhaPonteiro - 2;
	coluna = PecaBase::globalColunaPonteiro + 1;

	if (linha >= 0 && coluna < COLUNAS)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}


	return false;
}

bool PecaCavalo::validarJogadaCavaloDireitaAcima(char** tabuleiroBackEnd) {
	int linha = PecaBase::globalLinhaPonteiro + 2,
		coluna = PecaBase::globalColunaPonteiro - 1;

	if (linha < LINHAS && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}

	}

	linha = PecaBase::globalLinhaPonteiro + 1;
	coluna = PecaBase::globalColunaPonteiro - 2;

	if (linha < LINHAS && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}
	

	return false;
}

bool PecaCavalo::validarJogadaCavaloDireitaAbaixo(char** tabuleiroBackEnd) {
	int linha = PecaBase::globalLinhaPonteiro - 1,
		coluna = PecaBase::globalColunaPonteiro - 2;

	if (linha >= 0 && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}

	linha = PecaBase::globalLinhaPonteiro - 2;
	coluna = PecaBase::globalColunaPonteiro - 1;

	if (linha >= 0 && coluna >= 0)
	{
		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}
	
	return false;
}

bool PecaCavalo::validarJogadaCavaloCaptura(char** tabuleiroBackEnd) {
	return validarJogadaCavalo(tabuleiroBackEnd);
}
