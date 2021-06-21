#include "PecaBase.h"
#include "PecaPiao.h"
#include "PecaBispo.h"
#include "PecaTorre.h"
#include "PecaCavalo.h"
#include "PecaRainha.h"
#include "PecaRei.h"

int		PecaBase::globalLinhaPecaSelecionada = 0,
		PecaBase::globalColunaPecaSelecionada = 0;

char	PecaBase::globalPecaSelecionada = VAZIO;

int		PecaBase::globalLinhaPonteiro = 0,
		PecaBase::globalColunaPonteiro = 0;

char	PecaBase::globalPecaBackupDoPonteiro = VAZIO;

int		PecaBase::globalPlacarPretas = 0,
		PecaBase::globalPlacarBrancas = 0;

char	PecaBase::globalAvisos[1000] = { VAZIO };

char	PecaBase::ultimaPecaEliminada = VAZIO;

static PecaBase* _instance;

PecaBase* PecaBase::getInstance(char** tabuleiroBackEnd)
{
	if (_instance == nullptr) {

		_instance = new PecaBase(tabuleiroBackEnd);
	}

	return _instance;
}

PecaBase::PecaBase(char** tabuleiroBackEnd) {

	globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
}

PecaBase::~PecaBase() {
	PecaBase::zerarInformacoes();
	_instance = nullptr;
}

void PecaBase::moveParaDireita(char** tabuleiroBackEnd){

	if (globalColunaPonteiro >= 0 && globalColunaPonteiro < (COLUNAS -1) )
	{
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaBackupDoPonteiro;
		globalColunaPonteiro++;
		globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaEsquerda(char** tabuleiroBackEnd) {

	if (globalColunaPonteiro > 0 &&	globalColunaPonteiro <= (COLUNAS - 1) )
	{
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaBackupDoPonteiro;
		globalColunaPonteiro--;
		globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaCima(char** tabuleiroBackEnd) {

	if (globalLinhaPonteiro > 0 && globalLinhaPonteiro <= (LINHAS - 1) )
	{
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaBackupDoPonteiro;
		globalLinhaPonteiro--;
		globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaBaixo(char** tabuleiroBackEnd) {

	if (globalLinhaPonteiro >= 0 && globalLinhaPonteiro < (LINHAS - 1) )
	{
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaBackupDoPonteiro;
		globalLinhaPonteiro++;
		globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::pegaPeca(char** tabuleiroBackEnd) {

	if (globalPecaBackupDoPonteiro != VAZIO && globalPecaSelecionada == VAZIO)
	{
		//CAPTURO PECA
		globalPecaSelecionada = globalPecaBackupDoPonteiro;

		//ADICIONO O NO LOCAL 
		globalPecaBackupDoPonteiro = PECA_SELECIONADA;

		//GUARDO A LOCALIZACAO DA PECA ANTERIOR
		globalLinhaPecaSelecionada = globalLinhaPonteiro;
		globalColunaPecaSelecionada = globalColunaPonteiro;
	}
}

void PecaBase::soltaPeca(char** tabuleiroBackEnd) {

	if (globalPecaSelecionada == PECA_PRETA_PIAO || globalPecaSelecionada == PECA_BRANCA_PIAO)
	{
		PecaPiao piao;
		piao.jogarComPiao(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_BISPO || globalPecaSelecionada == PECA_PRETA_BISPO)
	{
		PecaBispo bispo;
		bispo.jogarComBispo(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_CAVALO || globalPecaSelecionada == PECA_PRETA_CAVALO)
	{
		PecaCavalo cavalo;
		cavalo.jogarComCavalo(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_TORRE || globalPecaSelecionada == PECA_PRETA_TORRE)
	{
		PecaTorre torre;
		torre.jogarComTorre(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_RAINHA || globalPecaSelecionada == PECA_PRETA_RAINHA)
	{
		PecaRainha rainha;
		rainha.jogarComRainha(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_REI || globalPecaSelecionada == PECA_PRETA_REI)
	{
		PecaRei rei;
		rei.jogarComRei(tabuleiroBackEnd);
	}

	verificaSePiaoEstaProntoEvoluir(tabuleiroBackEnd);
}

void PecaBase::cancelaJogada(char** tabuleiroBackEnd) {

	if (PecaBase::globalPecaSelecionada != VAZIO) {
		tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = globalPecaSelecionada;

		if (globalPecaBackupDoPonteiro == PECA_SELECIONADA)
		{
			globalPecaBackupDoPonteiro = globalPecaSelecionada;
		}

		globalPecaSelecionada = VAZIO;
	}
}

bool PecaBase::verificaSePiaoEstaProntoEvoluir(char** tabuleiroBackEnd) {

	for (int coluna = 0; coluna < (COLUNAS - 1); coluna++)
	{
		if (tabuleiroBackEnd[0][coluna] == PECA_BRANCA_PIAO)
		{
			return true;
		}
	}

	for (int coluna = 0; coluna < (COLUNAS - 1); coluna++)
	{
		if (tabuleiroBackEnd[7][coluna] == PECA_PRETA_PIAO)
		{
			return true;
		}
	}

	return false;
}

void PecaBase::evoluiPiao(char** tabuleiroBackEnd, char pecaNova) {

	for (int coluna = 0; coluna < (COLUNAS - 1); coluna++)
	{
		if (tabuleiroBackEnd[0][coluna] == PECA_BRANCA_PIAO)
		{
			if (pecaNova == PECA_TORRE)
				globalPecaBackupDoPonteiro = PECA_BRANCA_TORRE;
			if (pecaNova == PECA_BISPO)
				globalPecaBackupDoPonteiro = PECA_BRANCA_BISPO;
			if (pecaNova == PECA_CAVALO)
				globalPecaBackupDoPonteiro = PECA_BRANCA_CAVALO;
			if (pecaNova == PECA_RAINHA)
				globalPecaBackupDoPonteiro = PECA_BRANCA_RAINHA;

			return;
		}
		
	}

	for (int coluna = 0; coluna < (COLUNAS - 1); coluna++)
	{
		if (tabuleiroBackEnd[7][coluna] == PECA_PRETA_PIAO)
		{
			if (pecaNova == PECA_TORRE)
				globalPecaBackupDoPonteiro = PECA_PRETA_TORRE;
			if (pecaNova == PECA_BISPO)
				globalPecaBackupDoPonteiro = PECA_PRETA_BISPO;
			if (pecaNova == PECA_CAVALO)
				globalPecaBackupDoPonteiro = PECA_PRETA_CAVALO;
			if (pecaNova == PECA_RAINHA)
				globalPecaBackupDoPonteiro = PECA_PRETA_RAINHA;

			return;
		}
	}
}

void PecaBase::zerarInformacoes() {

	globalLinhaPecaSelecionada = 0,
		globalColunaPecaSelecionada = 0;

	globalPecaSelecionada = VAZIO;

	globalLinhaPonteiro = 0,
		globalColunaPonteiro = 0;

	globalPecaBackupDoPonteiro = VAZIO;

	globalPlacarPretas = 0,
		globalPlacarBrancas = 0;
	memcpy(globalAvisos, "", 999);

	ultimaPecaEliminada = VAZIO;
}

bool PecaBase::validarJogadaCapturaPeca() {

	//JOGADA BRANCA
	if (((globalPecaBackupDoPonteiro == PECA_PRETA_TORRE || globalPecaBackupDoPonteiro == PECA_PRETA_CAVALO || globalPecaBackupDoPonteiro == PECA_PRETA_BISPO ||
		globalPecaBackupDoPonteiro == PECA_PRETA_RAINHA || globalPecaBackupDoPonteiro == PECA_PRETA_REI || globalPecaBackupDoPonteiro == PECA_PRETA_PIAO)

		&& (globalPecaSelecionada == PECA_BRANCA_TORRE || globalPecaSelecionada == PECA_BRANCA_CAVALO || globalPecaSelecionada == PECA_BRANCA_BISPO ||
			globalPecaSelecionada == PECA_BRANCA_RAINHA || globalPecaSelecionada == PECA_BRANCA_REI || globalPecaSelecionada == PECA_BRANCA_PIAO)) ||

		//JOGADA PRETA
		((globalPecaBackupDoPonteiro == PECA_BRANCA_TORRE || globalPecaBackupDoPonteiro == PECA_BRANCA_CAVALO || globalPecaBackupDoPonteiro == PECA_BRANCA_BISPO ||
			globalPecaBackupDoPonteiro == PECA_BRANCA_RAINHA || globalPecaBackupDoPonteiro == PECA_BRANCA_REI || globalPecaBackupDoPonteiro == PECA_BRANCA_PIAO)

			&& (globalPecaSelecionada == PECA_PRETA_TORRE || globalPecaSelecionada == PECA_PRETA_CAVALO || globalPecaSelecionada == PECA_PRETA_BISPO ||
				globalPecaSelecionada == PECA_PRETA_RAINHA || globalPecaSelecionada == PECA_PRETA_REI || globalPecaSelecionada == PECA_PRETA_PIAO))) {

		return true;
	}

	return false;
}

void PecaBase::soltaPecaAposValidacoes(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL / ELIMINO PECA INIMIGA
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	ultimaPecaEliminada = globalPecaBackupDoPonteiro;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}

int PecaBase::validacoesDeCapturaPecaExtras(char** tabuleiroBackEnd, int linha, int coluna) {

	if (tabuleiroBackEnd[linha][coluna] != VAZIO) {

		if (tabuleiroBackEnd[linha][coluna] == PECA_SELECIONADA)
		{
			soltaPecaAposValidacoes(tabuleiroBackEnd);

			return VALIDACAO_CAPTURADA;
		}
		else
		{
			return VALIDACAO_ENCERRAR;
		}
	}

	return VALIDACAO_CONTINUAR;
}
