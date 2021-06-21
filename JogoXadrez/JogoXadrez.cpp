#include "CoreXadrez.h"
#include "JogoXadrez.h"
#include "Tabuleiro.h"
#include "PecaBase.h"
#include "TecladoJogo.h"

extern dados_jogador	globalPlayer1 = { " ", ' ', false },						
						globalPlayer2 = { " ", ' ', false };						

void JogoXadrez::intro() {
	system("cls");
	printf("\x1b[37m ############ Bem vindo ao jogo \x1b[31m XadrezBreuva\x1b[37m !!! ############\n\n");
	printf("Pressione a tecla numero 1 para Comecar a jogar\n");
	printf("Pressione a tecla numero 2 para acessar o tutorial do jogo\n");
	printf("Pressione a tecla numero 3 para Sair\n");
}

void JogoXadrez::imprimeTutorial()
{
	system("cls");
	printf("##### Tutorial XadrezBreuva ######");

	printf("\n\x1b[33mControles do Jogo:");

	printf("\n\n\x1b[31mMovimentacao no tabuleiro:\n");
	printf("\x1b[37mDirecional para cima.\n");
	printf("Direcional para baixo.\n");
	printf("Direcional para esquerda.\n");
	printf("Direcional para direita.\n");

	printf("\n\n\x1b[31mMovimentacao das pecas no tabuleiro:\n");
	printf("\x1b[37mPasso 1: Selecionar peca pressionando F1.\n");
	printf("Passo 2: Usar os direcionais para escolher uma casa onde a peca vai ficar.\n");
	printf("Passo 3: Soltar a peca pressionando F2.\n");
	printf("Passo 4: Repetir o processo para todas as jogadas.\n");

	printf("\n\n\x1b[31mSignificados de siglas do jogo:\n");
	printf("\x1b[37mPI = Piao.\n");
	printf("TO = Torre.\n");
	printf("CA = Cavalo.\n");
	printf("BI = Bispo.\n");
	printf("RA = Rainha.\n");
	printf("RE = Rei.\n");
	printf("*  = Ponteiro do Jogo, serve para você se localizar no jogo, o mesmo movimenta ao apertar os direcionais.\n");
	printf("X  = Posicao da Peca que está selecionada no momento.\n\n");
}

void JogoXadrez::capturaDadosJogador() {
	system("cls");
	size_t tam;
	printf("\x1b[37mDigite o nome do jogador que vai jogar com a peca BRANCA:");
	fgets(globalPlayer1.nome, 40, stdin);
	globalPlayer1.pecaJogador = 'B';

	tam = strlen(globalPlayer1.nome);
	globalPlayer1.nome[tam-1] = '\0';

	printf("\n\x1b[34mDigite o nome do jogador que vai jogar com a peca PRETA:");
	fgets(globalPlayer2.nome, 40, stdin);
	globalPlayer2.pecaJogador = 'P';
	tam = strlen(globalPlayer2.nome);
	globalPlayer2.nome[tam-1] = '\0';
}

bool JogoXadrez::ehGanhador() {
	
	if (PecaBase::ultimaPecaEliminada == PECA_BRANCA_REI) {

		system("cls");
		printf("\x1b[37m ############ Parabens \x1b[31m %s, voce venceu o Jogo\x1b[37m !!! ############\n\n", globalPlayer2.nome);
		return true;
	}

	if (PecaBase::ultimaPecaEliminada == PECA_PRETA_REI) {

		system("cls");
		printf("\x1b[37m ############ Parabens \x1b[31m %s, voce venceu o Jogo\x1b[37m !!! ############\n\n", globalPlayer1.nome);
		return true;
	}

	return false;
}

char imprimeSelecaoDePeca() {
	return PECA_RAINHA;
}

void reorganizaDadosDasPecasAposSairDoJogo(char** tabuleiroBackEnd)
{
	PecaBase* pecaBase;
	pecaBase = PecaBase::getInstance(tabuleiroBackEnd);
	pecaBase->~PecaBase();
}

void verificaEvolucaoDaPecaPiao(char** tabuleiroBackEnd)
{
	char pecaSelecionadaParaEvolucao = VAZIO;
	PecaBase* pecaBase;
	pecaBase = PecaBase::getInstance(tabuleiroBackEnd);
	
	if (pecaBase->verificaSePiaoEstaProntoEvoluir(tabuleiroBackEnd))
	{
		pecaSelecionadaParaEvolucao = imprimeSelecaoDePeca();
		pecaBase->evoluiPiao(tabuleiroBackEnd, pecaSelecionadaParaEvolucao);
	}
}

int main() {
	char** tabuleiroBackEnd; 
	int TeclasCapturadasDoUsuario = 0;
	JogoXadrez jogo;
	Tabuleiro tabuleiro;
	TecladoJogo* TecladoJogo = TecladoJogo::getInstance();

	while (TeclasCapturadasDoUsuario != TECLA_MENU_OPCAO_SAIR) {

		jogo.intro();

		TeclasCapturadasDoUsuario = TecladoJogo->capturaTeclado();

		switch (TeclasCapturadasDoUsuario) {

			case TECLA_MENU_OPCAO_JOGAR:

				jogo.capturaDadosJogador();
				tabuleiroBackEnd = tabuleiro.organizaTabuleiroBackEndIncial();
			
				tabuleiro.movimentacaoNoTabuleiroBackEnd(tabuleiroBackEnd, TABULEIRO_PONTEIRO_INICIAL);

				while (TeclasCapturadasDoUsuario != TECLA_GAMEPLAY_ACAO_SAIR_DO_JOGO && jogo.ehGanhador() == false) {

					tabuleiro.tabuleiroUserIterface(tabuleiroBackEnd);
					TeclasCapturadasDoUsuario = TecladoJogo->capturaTeclado();
					tabuleiro.movimentacaoNoTabuleiroBackEnd(tabuleiroBackEnd, TeclasCapturadasDoUsuario);
					verificaEvolucaoDaPecaPiao(tabuleiroBackEnd);
				}

				reorganizaDadosDasPecasAposSairDoJogo(tabuleiroBackEnd);

			break;

			case TECLA_MENU_OPCAO_TUTORIAL:
				jogo.imprimeTutorial();
			break;

			default:
				break;
		}

		system("pause");
	}
}

