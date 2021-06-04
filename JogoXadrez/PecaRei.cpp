#include "PecaRei.h"
#include "PecaBase.h"

void PecaRei::jogarComRei(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaRei(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCorretaCapturaPecaExtras()) {

		if (validarJogadaReiCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_REI)
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



	if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro ||
		(PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro)
	{
		PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro ||
		(PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro) {

		PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	return false;
}

bool PecaRei::validarJogadaReiLinhaReta(char** tabuleiroBackEnd) {

	if (((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro || (PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro
		) && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
	{
		PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	if (((PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro || (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro
		) && PecaBase::globalLinhaPecaSelecionada == PecaBase::globalLinhaPonteiro)
	{
		PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
		return true;
	}

	return false;
}

bool PecaRei::validarJogadaReiCaptura(char** tabuleiroBackEnd) {
	return validarJogadaRei(tabuleiroBackEnd);
}