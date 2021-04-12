#include "PecaBase.h"
#include "PecaPiao.h"
#include "PecaBispo.h"
#include "PecaTorre.h"
#include "PecaCavalo.h"
#include "PecaRainha.h"
#include "Peca.h"


static PecaBase* instance_;

PecaBase* PecaBase::getInstance(char** tabuleiroBackEnd)
{
	if (instance_ == nullptr) {

		instance_ = new PecaBase(tabuleiroBackEnd);
	}

	return instance_;
}

PecaBase::PecaBase(char** tabuleiroBackEnd) {

	Peca::globalPecaBackupDoPonteiro = tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro];
	tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
}

PecaBase::~PecaBase() {
	Peca::globalLinhaPecaSelecionada = 0;
	Peca::globalColunaPecaSelecionada = 0;
	Peca::globalPecaSelecionada = ' ';
	Peca::globalLinhaPonteiro = 0;
	Peca::globalColunaPonteiro = 0;
	Peca::globalPecaBackupDoPonteiro = ' ';
	instance_ = nullptr;
}

void PecaBase::moveParaDireita(char** tabuleiroBackEnd){

	if (Peca::globalColunaPonteiro >= 0 && Peca::globalColunaPonteiro < (LINHAS -1) )
	{
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = Peca::globalPecaBackupDoPonteiro;
		Peca::globalColunaPonteiro++;
		Peca::globalPecaBackupDoPonteiro = tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro];
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaEsquerda(char** tabuleiroBackEnd) {

	if (Peca::globalColunaPonteiro > 0 && Peca::globalColunaPonteiro <= (LINHAS - 1) )
	{
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = Peca::globalPecaBackupDoPonteiro;
		Peca::globalColunaPonteiro--;
		Peca::globalPecaBackupDoPonteiro = tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro];
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaCima(char** tabuleiroBackEnd) {

	if (Peca::globalLinhaPonteiro > 0 && Peca::globalLinhaPonteiro <= (LINHAS - 1) )
	{
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = Peca::globalPecaBackupDoPonteiro;
		Peca::globalLinhaPonteiro--;
		Peca::globalPecaBackupDoPonteiro = tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro];
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaBaixo(char** tabuleiroBackEnd) {

	if (Peca::globalLinhaPonteiro >= 0 && Peca::globalLinhaPonteiro < (LINHAS - 1) )
	{
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = Peca::globalPecaBackupDoPonteiro;
		Peca::globalLinhaPonteiro++;
		Peca::globalPecaBackupDoPonteiro = tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro];
		tabuleiroBackEnd[Peca::globalLinhaPonteiro][Peca::globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::pegaPeca(char** tabuleiroBackEnd) {

	if (Peca::globalPecaBackupDoPonteiro != VAZIO && Peca::globalPecaSelecionada == VAZIO)
	{
		//CAPTURO PECA
		Peca::globalPecaSelecionada = Peca::globalPecaBackupDoPonteiro;

		//ADICIONO O NO LOCAL 
		Peca::globalPecaBackupDoPonteiro = PECA_SELECIONADA;

		//GUARDO A LOCALIZACAO DA PECA ANTERIOR
		Peca::globalLinhaPecaSelecionada = Peca::globalLinhaPonteiro;
		Peca::globalColunaPecaSelecionada = Peca::globalColunaPonteiro;
	}
}

void PecaBase::soltaPeca(char** tabuleiroBackEnd) {

	if (Peca::globalPecaSelecionada == PECA_PRETA_PIAO || Peca::globalPecaSelecionada == PECA_BRANCA_PIAO)
	{
		PecaPiao piao;
		piao.jogarComPiao(tabuleiroBackEnd);
	}

	if (Peca::globalPecaSelecionada == PECA_BRANCA_BISPO || Peca::globalPecaSelecionada == PECA_PRETA_BISPO)
	{
		PecaBispo bispo;
		bispo.jogarComBispo(tabuleiroBackEnd);
	}

	if (Peca::globalPecaSelecionada == PECA_BRANCA_CAVALO || Peca::globalPecaSelecionada == PECA_PRETA_CAVALO)
	{
		PecaCavalo cavalo;
		cavalo.jogarComCavalo(tabuleiroBackEnd);

	}

	if (Peca::globalPecaSelecionada == PECA_BRANCA_TORRE || Peca::globalPecaSelecionada == PECA_PRETA_TORRE)
	{
		PecaTorre torre;
		torre.jogarComTorre(tabuleiroBackEnd);
	}

	if (Peca::globalPecaSelecionada == PECA_BRANCA_RAINHA || Peca::globalPecaSelecionada == PECA_PRETA_RAINHA)
	{
		PecaRainha rainha;
		rainha.jogarComRainha(tabuleiroBackEnd);
	}

	if (Peca::globalPecaSelecionada == PECA_BRANCA_REI || Peca::globalPecaSelecionada == PECA_PRETA_REI)
	{
		//JOGA COM REI
	}

	verificaSePiaoEvoluiu(tabuleiroBackEnd);
}

void PecaBase::cancelaJogada(char** tabuleiroBackEnd) {

	if (Peca::globalPecaSelecionada != VAZIO) {
		tabuleiroBackEnd[Peca::globalLinhaPecaSelecionada][Peca::globalColunaPecaSelecionada] = Peca::globalPecaSelecionada;

		if (Peca::globalPecaBackupDoPonteiro == PECA_SELECIONADA)
		{
			Peca::globalPecaBackupDoPonteiro = Peca::globalPecaSelecionada;
		}

		Peca::globalPecaSelecionada = VAZIO;
	}
}

void PecaBase::verificaSePiaoEvoluiu(char** tabuleiroBackEnd) {

	/*for (int coluna = 0; coluna < COLUNAS; coluna++)
	{
		if (tabuleiroBackEnd[0][coluna] == PECA_BRANCA)
		{
			tabuleiroBackEnd[0][coluna] = PECA_BRANCA_DAMA;
			globalPecaBackupDoPonteiro = PECA_BRANCA_DAMA;
		}

		if (tabuleiroBackEnd[7][coluna] == PECA_PRETA)
		{
			tabuleiroBackEnd[7][coluna] = PECA_PRETA_DAMA;
			globalPecaBackupDoPonteiro = PECA_PRETA_DAMA;
		}
	}*/
}


