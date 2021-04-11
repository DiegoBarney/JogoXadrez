#include"PecaRei.h"

extern int		globalLinhaPecaSelecionada,
				globalColunaPecaSelecionada;
extern char		globalPecaSelecionada;

extern int		globalLinhaPonteiro,
				globalColunaPonteiro;
extern char		globalPecaBackupDoPonteiro;

extern int		globalPlacarPretas,
				globalPlacarBrancas;
extern char		globalAvisos[1000];

void soltaPecaAposValidacoesRei(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

void PecaRei::jogarComRei(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaRei(tabuleiroBackEnd))
		{
			return;
		}
		else {
			//avisos
		}
	}
	else if (globalPecaBackupDoPonteiro != VAZIO && validarJogadaCorretaCapturaRei()) {

		if (validarJogadaReiCaptura(tabuleiroBackEnd)) {

			if (globalPecaBackupDoPonteiro == PECA_PRETA_TORRE)
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

bool PecaRei::validarJogadaCorretaCapturaRei() {

	//JOGADA DA REI BRANCO
	if (((globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
		&& globalPecaSelecionada == PECA_BRANCA_REI) ||

		//JOGADA DO REI PRETO
		((globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_REI)) {

		return true;
	}

	return false;
}