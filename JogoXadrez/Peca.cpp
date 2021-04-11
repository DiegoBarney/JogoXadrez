#include "Peca.h"

int		Peca::globalLinhaPecaSelecionada1,
		Peca::globalColunaPecaSelecionada1;

char	Peca::globalPecaSelecionada1;

int		Peca::globalLinhaPonteiro1,
		Peca::globalColunaPonteiro1;

char	Peca::globalPecaBackupDoPonteiro1;

int		Peca::globalPlacarPretas1,
		Peca::globalPlacarBrancas1;

char	Peca::globalAvisos1[1000];


bool Peca::validarJogadaCorretaCapturaPeca() {

	//JOGADA BRANCA
	if (((globalPecaBackupDoPonteiro1 == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro1 == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro1 == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro1 == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro1 == PECA_PRETA_REI || globalPecaBackupDoPonteiro1 == PECA_PRETA_PIAO)
		&& globalPecaSelecionada1 == PECA_BRANCA_TORRE || globalPecaSelecionada1 == PECA_BRANCA_CAVALO || globalPecaSelecionada1 == PECA_BRANCA_BISPO ||
		globalPecaSelecionada1 == PECA_BRANCA_RAINHA || globalPecaSelecionada1 == PECA_BRANCA_REI || globalPecaSelecionada1 == PECA_BRANCA_PIAO) ||

		//JOGADA PRETO
		((globalPecaBackupDoPonteiro1 == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro1 == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro1 == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro1 == PECA_BRANCA_RAINHA ||globalPecaBackupDoPonteiro1 == PECA_BRANCA_REI || globalPecaBackupDoPonteiro1 == PECA_BRANCA_PIAO)
			&& globalPecaSelecionada1 == PECA_PRETA_TORRE || globalPecaSelecionada1 == PECA_PRETA_CAVALO || globalPecaSelecionada1 == PECA_PRETA_BISPO ||
			globalPecaSelecionada1 == PECA_PRETA_RAINHA || globalPecaSelecionada1 == PECA_PRETA_REI || globalPecaSelecionada1 == PECA_PRETA_PIAO)) {

		return true;
	}

	return false;
}

 void Peca::soltaPecaAposValidacoesExtras(char** tabuleiroBackEnd) {
	 //RETIRO A PECA DO LOCAL ANTERIOR 
	 tabuleiroBackEnd[globalLinhaPecaSelecionada1][globalColunaPecaSelecionada1] = VAZIO;

	 //SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	 tabuleiroBackEnd[globalLinhaPonteiro1][globalColunaPonteiro1] = globalPecaSelecionada1;

	 //VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	 globalPecaBackupDoPonteiro1 = globalPecaSelecionada1;

	 globalPecaSelecionada1 = VAZIO;
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
