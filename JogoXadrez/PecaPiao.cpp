#include "PecaPiao.h"
#include "PecaBase.h"

void PecaPiao::jogarComPiao(char** tabuleiroBackEnd) {
	if (PecaBase::globalPecaSelecionada == PECA_BRANCA_PIAO || PecaBase::globalPecaSelecionada == PECA_PRETA_PIAO)
	{
		if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
		{
			validarJogadaPiao(tabuleiroBackEnd);
		}
		else {
			validarJogadaPiaoCaptura(tabuleiroBackEnd);
		}

	}
}

void PecaPiao::validarJogadaPiao(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (PecaBase::globalPecaSelecionada == PECA_BRANCA_PIAO)
			validarJogadaPiaoPecaBranca(tabuleiroBackEnd);

		if (PecaBase::globalPecaSelecionada == PECA_PRETA_PIAO)
			validarJogadaPiaoPecaPreta(tabuleiroBackEnd);
	}
	else {
		memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA) + 1);
	}
}

void PecaPiao::validarJogadaPiaoPecaBranca(char** tabuleiroBackEnd) {

	if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
		PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
}

void PecaPiao::validarJogadaPiaoPecaPreta(char** tabuleiroBackEnd) {

	if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
		PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);
}

void PecaPiao::validarJogadaPiaoCaptura(char** tabuleiroBackEnd) {

	if (PecaBase::validarJogadaCorretaCapturaPecaExtras()) {

		if (PecaBase::globalPecaSelecionada == PECA_PRETA_PIAO)
			validarJogadaPiaoPecaPretaCaptura(tabuleiroBackEnd);

		if (PecaBase::globalPecaSelecionada == PECA_BRANCA_PIAO)
			validarJogadaPiaoPecaBrancaCaptura(tabuleiroBackEnd);
	}
}

void PecaPiao::validarJogadaPiaoPecaBrancaCaptura(char** tabuleiroBackEnd) {

	//JOGADA DE CAPTURA ESQUERDA
	if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro ||
		(PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro) {

			//ELIMINO PECA INIMIGA
			tabuleiroBackEnd[PecaBase::globalLinhaPecaSelecionada - 1][PecaBase::globalColunaPecaSelecionada - 1] = VAZIO;

			PecaBase::globalPlacarBrancas++;

			PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);

			return;
	}

	memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
}

void PecaPiao::validarJogadaPiaoPecaPretaCaptura(char** tabuleiroBackEnd) {

	if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro ||
		(PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro) {

			//ELIMINO PECA INIMIGA
			tabuleiroBackEnd[PecaBase::globalLinhaPecaSelecionada + 1][PecaBase::globalColunaPecaSelecionada + 1] = VAZIO;

			PecaBase::globalPlacarPretas++;

			PecaBase::soltaPecaAposValidacoesExtras(tabuleiroBackEnd);

			return;
	}

	memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
}