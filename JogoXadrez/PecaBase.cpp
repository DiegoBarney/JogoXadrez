#include "PecaBase.h"
#include "PecaPiao.h"
#include "PecaBispo.h"

extern int	globalPlacarPretas,		
			globalPlacarBrancas;	
extern char	globalAvisos[1000];

extern int		globalLinhaPecaSelecionada = 0,
				globalColunaPecaSelecionada = 0;
extern char		globalPecaSelecionada = VAZIO;

extern int		globalLinhaPonteiro = 0,
				globalColunaPonteiro = 0;
extern char		globalPecaBackupDoPonteiro = VAZIO;


static PecaBase* instance_;

PecaBase* PecaBase::getInstance(char** tabuleiroBackEnd)
{
	if (instance_ == nullptr) {

		instance_ = new PecaBase(tabuleiroBackEnd);
	}

	return instance_;
}

PecaBase::PecaBase(char** tabuleiroBackEnd) {

	globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
}

PecaBase::~PecaBase() {
	globalLinhaPecaSelecionada = 0;
	globalColunaPecaSelecionada = 0;									
	globalPecaSelecionada = ' ';
	globalLinhaPonteiro = 0;							
	globalColunaPonteiro = 0;							
	globalPecaBackupDoPonteiro = ' ';	
	instance_ = nullptr;
}

void PecaBase::moveParaDireita(char** tabuleiroBackEnd){

	if (globalColunaPonteiro >= 0 && globalColunaPonteiro < (LINHAS -1) )
	{
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaBackupDoPonteiro;
		globalColunaPonteiro++;
		globalPecaBackupDoPonteiro = tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro];
		tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = PONTEIRO_DIRECIONAL;
	}
}

void PecaBase::moveParaEsquerda(char** tabuleiroBackEnd) {

	if (globalColunaPonteiro > 0 && globalColunaPonteiro <= (LINHAS - 1) )
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
		validarJogadaBispoCaptura(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_TORRE || globalPecaSelecionada == PECA_PRETA_TORRE)
	{
		validarJogadaBispoCaptura(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_RAINHA || globalPecaSelecionada == PECA_PRETA_RAINHA)
	{
		validarJogadaBispoCaptura(tabuleiroBackEnd);
	}

	if (globalPecaSelecionada == PECA_BRANCA_REI || globalPecaSelecionada == PECA_PRETA_REI)
	{
		validarJogadaBispoCaptura(tabuleiroBackEnd);
	}

	verificaSePiaoEvoluiu(tabuleiroBackEnd);
}

void PecaBase::cancelaJogada(char** tabuleiroBackEnd) {

	if (globalPecaSelecionada != VAZIO) {
		tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = globalPecaSelecionada;

		if (globalPecaBackupDoPonteiro == PECA_SELECIONADA)
		{
			globalPecaBackupDoPonteiro = globalPecaSelecionada;
		}

		globalPecaSelecionada = VAZIO;
	}
}

void PecaBase::verificaSePiaoEvoluiu(char** tabuleiroBackEnd) {

	for (int coluna = 0; coluna < COLUNAS; coluna++)
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
	}
}

void PecaBase::soltaPecaAposValidacoes(char** tabuleiroBackEnd) {
	//RETIRO A PECA DO LOCAL ANTERIOR 
	tabuleiroBackEnd[globalLinhaPecaSelecionada][globalColunaPecaSelecionada] = VAZIO;

	//SOLTO A PECA NO NOVO LOCAL
	tabuleiroBackEnd[globalLinhaPonteiro][globalColunaPonteiro] = globalPecaSelecionada;

	//VOLTO O BACKUP DE PECA ONDE O PONTEIRO ESTA LOCALIZADO
	globalPecaBackupDoPonteiro = globalPecaSelecionada;

	globalPecaSelecionada = VAZIO;
}
