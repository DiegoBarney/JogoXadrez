#include "PecaRei.h"
#include "Peca.h"

void PecaRei::jogarComRei(char** tabuleiroBackEnd) {

	if (Peca::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaRei(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (Peca::globalPecaBackupDoPonteiro != VAZIO && Peca::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaReiCaptura(tabuleiroBackEnd)) {

			if (Peca::globalPecaBackupDoPonteiro == PECA_PRETA_REI)
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

bool PecaRei::validarJogadaRei(char** tabuleiroBackEnd) {

	if (!validarJogadaReiDiagonais(tabuleiroBackEnd))
	{
		if (validarJogadaReiLinhaReta(tabuleiroBackEnd))
		{
			return true;
		}
	}
	else {
		return true;
	}

	return false;
}

bool PecaRei::validarJogadaReiDiagonais(char** tabuleiroBackEnd) {



	if ((Peca::globalLinhaPecaSelecionada + 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada + 1) == Peca::globalColunaPonteiro ||
		(Peca::globalLinhaPecaSelecionada + 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada - 1) == Peca::globalColunaPonteiro)
	{
		Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	if ((Peca::globalLinhaPecaSelecionada - 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada - 1) == Peca::globalColunaPonteiro ||
		(Peca::globalLinhaPecaSelecionada - 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada + 1) == Peca::globalColunaPonteiro) {

		Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	return false;
}

bool PecaRei::validarJogadaReiLinhaReta(char** tabuleiroBackEnd) {

	if (((Peca::globalLinhaPecaSelecionada - 1) == Peca::globalLinhaPonteiro || (Peca::globalLinhaPecaSelecionada + 1) == Peca::globalLinhaPonteiro
		) && Peca::globalColunaPecaSelecionada == Peca::globalColunaPonteiro)
	{
		Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	if (((Peca::globalColunaPecaSelecionada - 1) == Peca::globalColunaPonteiro || (Peca::globalColunaPecaSelecionada + 1) == Peca::globalColunaPonteiro
		) && Peca::globalLinhaPecaSelecionada == Peca::globalLinhaPonteiro)
	{
		Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	return false;
}

bool PecaRei::validarJogadaReiCaptura(char** tabuleiroBackEnd) {
	return validarJogadaRei(tabuleiroBackEnd);
}