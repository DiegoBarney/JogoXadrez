#include "PecaPiao.h"
#include "Peca.h"

void PecaPiao::jogarComPiao(char** tabuleiroBackEnd) {
	if (Peca::globalPecaSelecionada == PECA_BRANCA_PIAO || Peca::globalPecaSelecionada == PECA_PRETA_PIAO)
	{
		if (Peca::globalPecaBackupDoPonteiro == VAZIO)
		{
			validarJogadaPiao(tabuleiroBackEnd);
		}
		else {
			validarJogadaPiaoCaptura(tabuleiroBackEnd);
		}

	}
}

void PecaPiao::validarJogadaPiao(char** tabuleiroBackEnd) {

	if (Peca::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (Peca::globalPecaSelecionada == PECA_BRANCA_PIAO)
			validarJogadaPiaoPecaBranca(tabuleiroBackEnd);

		if (Peca::globalPecaSelecionada == PECA_PRETA_PIAO)
			validarJogadaPiaoPecaPreta(tabuleiroBackEnd);
	}
	else {
		memcpy(Peca::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA) + 1);
	}
}

void PecaPiao::validarJogadaPiaoPecaBranca(char** tabuleiroBackEnd) {

	if ((Peca::globalLinhaPecaSelecionada - 1) == Peca::globalLinhaPonteiro && Peca::globalColunaPecaSelecionada == Peca::globalColunaPonteiro)
		Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
}

void PecaPiao::validarJogadaPiaoPecaPreta(char** tabuleiroBackEnd) {

	if ((Peca::globalLinhaPecaSelecionada + 1) == Peca::globalLinhaPonteiro && Peca::globalColunaPecaSelecionada == Peca::globalColunaPonteiro)
		Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
}

void PecaPiao::validarJogadaPiaoCaptura(char** tabuleiroBackEnd) {

	if (Peca::validarJogadaCorretaCapturaPecaExtras()) {

		if (Peca::globalPecaSelecionada == PECA_PRETA_PIAO)
			validarJogadaPiaoPecaPretaCaptura(tabuleiroBackEnd);

		if (Peca::globalPecaSelecionada == PECA_BRANCA_PIAO) 
			validarJogadaPiaoPecaBrancaCaptura(tabuleiroBackEnd);
	}
}

void PecaPiao::validarJogadaPiaoPecaBrancaCaptura(char** tabuleiroBackEnd) {

	//JOGADA DE CAPTURA ESQUERDA
	if ((Peca::globalLinhaPecaSelecionada - 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada - 1) == Peca::globalColunaPonteiro ||
		(Peca::globalLinhaPecaSelecionada - 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada + 1) == Peca::globalColunaPonteiro) {

			//ELIMINO PECA INIMIGA
			tabuleiroBackEnd[Peca::globalLinhaPecaSelecionada - 1][Peca::globalColunaPecaSelecionada - 1] = VAZIO;

			Peca::globalPlacarBrancas++;

			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);

			return;
	}

	memcpy(Peca::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
}

void PecaPiao::validarJogadaPiaoPecaPretaCaptura(char** tabuleiroBackEnd) {

	if ((Peca::globalLinhaPecaSelecionada + 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada + 1) == Peca::globalColunaPonteiro ||
		(Peca::globalLinhaPecaSelecionada + 1) == Peca::globalLinhaPonteiro && (Peca::globalColunaPecaSelecionada - 1) == Peca::globalColunaPonteiro) {

			//ELIMINO PECA INIMIGA
			tabuleiroBackEnd[Peca::globalLinhaPecaSelecionada + 1][Peca::globalColunaPecaSelecionada + 1] = VAZIO;

			Peca::globalPlacarPretas++;

			Peca::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);

			return;
	}

	memcpy(Peca::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
}