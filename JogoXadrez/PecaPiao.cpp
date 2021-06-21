#include "PecaPiao.h"
#include "PecaBase.h"

void PecaPiao::jogarComPiao(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaPiao(tabuleiroBackEnd))
		{
			return;
		}
		else {
			memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
		}
	}
	else if (PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCapturaPeca()) {

		if (validarJogadaPiaoCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)
				PecaBase::globalPlacarPretas++;
			else
				PecaBase::globalPlacarBrancas++;

			return;
		}
		else {
			memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
		}
	}
	else {
		memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
	}

}

bool PecaPiao::validarJogadaPiao(char** tabuleiroBackEnd) {

	if (!validarJogadaPiaoPecaBranca(tabuleiroBackEnd)) {

		if (validarJogadaPiaoPecaPreta(tabuleiroBackEnd))
			return true;
	}
	else
	{
		return true;
	}

	return false;		
}

bool PecaPiao::validarJogadaPiaoPecaBranca(char** tabuleiroBackEnd) {

	if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
	{
		PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
		return true;
	}
	return false;
}

bool PecaPiao::validarJogadaPiaoPecaPreta(char** tabuleiroBackEnd) {

	if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
	{
		PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
		return true;
	}

	return false;
}

bool PecaPiao::validarJogadaPiaoCaptura(char** tabuleiroBackEnd) {

	if (!validarJogadaPiaoPecaPretaCaptura(tabuleiroBackEnd))
	{
		if (validarJogadaPiaoPecaBrancaCaptura(tabuleiroBackEnd))
			return true;
	}
	else {
		return true;
	}

	return false;
}

bool PecaPiao::validarJogadaPiaoPecaBrancaCaptura(char** tabuleiroBackEnd) {

	//JOGADA DE CAPTURA ESQUERDA
	if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro ||
		(PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro) {

			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);

			return true;
	}

	memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
	return false;
}

bool PecaPiao::validarJogadaPiaoPecaPretaCaptura(char** tabuleiroBackEnd) {

	if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro ||
		(PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro) {

			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);

			return true;
	}
	return false;
}