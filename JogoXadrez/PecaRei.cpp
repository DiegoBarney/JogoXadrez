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

			if (Peca::globalPecaBackupDoPonteiro == PECA_PRETA_TORRE)
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
	return false;
}

bool PecaRei::validarJogadaReiDireita(char** tabuleiroBackEnd) {
	return false;
}

bool PecaRei::validarJogadaReiEsquerda(char** tabuleiroBackEnd) {
	return false;
}

bool PecaRei::validarJogadaReiAcima(char** tabuleiroBackEnd) {
	return false;
}

bool PecaRei::validarJogadaReiAbaixo(char** tabuleiroBackEnd) {
	return false;
}

bool PecaRei::validarJogadaReiCaptura(char** tabuleiroBackEnd) {
	return validarJogadaRei(tabuleiroBackEnd);
}