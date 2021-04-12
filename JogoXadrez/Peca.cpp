#include "Peca.h"

int		Peca::globalLinhaPecaSelecionada = 0,
		Peca::globalColunaPecaSelecionada = 0;

char	Peca::globalPecaSelecionada = VAZIO;

int		Peca::globalLinhaPonteiro = 0,
		Peca::globalColunaPonteiro = 0;

char	Peca::globalPecaBackupDoPonteiro = VAZIO;

int		Peca::globalPlacarPretas = 0,
		Peca::globalPlacarBrancas = 0;

char	Peca::globalAvisos[1000] = {' '};

bool Peca::validarJogadaCorretaCapturaPecaExtras() {

	//JOGADA BRANCA
	if (((globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
		&& globalPecaSelecionada == PECA_BRANCA_TORRE || globalPecaSelecionada == PECA_BRANCA_CAVALO || globalPecaSelecionada == PECA_BRANCA_BISPO ||
		globalPecaSelecionada == PECA_BRANCA_RAINHA || globalPecaSelecionada == PECA_BRANCA_REI || globalPecaSelecionada == PECA_BRANCA_PIAO) ||

		//JOGADA PRETA
		((globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA ||globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada == PECA_PRETA_TORRE || globalPecaSelecionada == PECA_PRETA_CAVALO || globalPecaSelecionada == PECA_PRETA_BISPO ||
			globalPecaSelecionada == PECA_PRETA_RAINHA || globalPecaSelecionada == PECA_PRETA_REI || globalPecaSelecionada == PECA_PRETA_PIAO)) {

		return true;
	}

	return false;
}

 void Peca::soltaPecaAposValidacoesExtras(char** tabuleiroBackEnd) {
	 //RETIRO A PECA DO LOCAL ANTERIOR 
	 tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	 //SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	 tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	 //VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	 globalPecaBackupDoPonteiro = globalPecaSelecionada;

	 globalPecaSelecionada = VAZIO;
}

 int Peca::validacoesDeCapturaPecaExtras(char** tabuleiroBackEnd, int linha, int coluna) {

	 if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

		 if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		 {
			 Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
			 return VALIDACAO_CAPTURADA;
		 }
		 else
		 {
			 return VALIDACAO_ENCERRAR;
		 }
	 }

	 return VALIDACAO_CONTINUAR;
 }
