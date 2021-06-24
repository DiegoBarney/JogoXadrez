#include "PecaPeao.h"
#include "PecaBase.h"

void PecaPeao::jogarComPeao(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaBackupDoPonteiro == VAZIO)
	{
		if (validarJogadaPeao(tabuleiroBackEnd))
		{
			return;
		}
		else {
			memcpy(PecaBase::globalAvisos, AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA, strlen(AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA) + 1);
		}
	}
	else if (PecaBase::globalPecaBackupDoPonteiro != VAZIO && PecaBase::validarJogadaCapturaPeca()) {

		if (validarJogadaPeaoCaptura(tabuleiroBackEnd)) {

			if (PecaBase::globalPecaBackupDoPonteiro == PECA_PRETA_PEAO)
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

bool PecaPeao::validarJogadaPeao(char** tabuleiroBackEnd) {

	if (!validarJogadaPeaoPecaBranca(tabuleiroBackEnd)) {

		if (validarJogadaPeaoPecaPreta(tabuleiroBackEnd))
			return true;
	}
	else
	{
		return true;
	}

	return false;		
}

bool PecaPeao::validarJogadaPeaoPecaBranca(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaSelecionada == PECA_BRANCA_PEAO)
	{
		if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}
	return false;
}

bool PecaPeao::validarJogadaPeaoPecaPreta(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaSelecionada == PECA_PRETA_PEAO) 
	{
		if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && PecaBase::globalColunaPecaSelecionada == PecaBase::globalColunaPonteiro)
		{
			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);
			return true;
		}
	}
	return false;
}

bool PecaPeao::validarJogadaPeaoCaptura(char** tabuleiroBackEnd) {

	if (!validarJogadaPeaoPecaPretaCaptura(tabuleiroBackEnd))
	{
		if (validarJogadaPeaoPecaBrancaCaptura(tabuleiroBackEnd))
			return true;
	}
	else {
		return true;
	}

	return false;
}

bool PecaPeao::validarJogadaPeaoPecaBrancaCaptura(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaSelecionada == PECA_BRANCA_PEAO)
	{
		//JOGADA DE CAPTURA ESQUERDA
		if ((PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro ||
			(PecaBase::globalLinhaPecaSelecionada - 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro) {

			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);

			return true;
		}
	}
	return false;
}

bool PecaPeao::validarJogadaPeaoPecaPretaCaptura(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaSelecionada == PECA_PRETA_PEAO) 
	{

		if ((PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada + 1) == PecaBase::globalColunaPonteiro ||
			(PecaBase::globalLinhaPecaSelecionada + 1) == PecaBase::globalLinhaPonteiro && (PecaBase::globalColunaPecaSelecionada - 1) == PecaBase::globalColunaPonteiro) {

			PecaBase::soltaPecaAposValidacoes(tabuleiroBackEnd);

			return true;
		}
	}
	return false;
}