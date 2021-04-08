#include "Tabuleiro.h"

char** Tabuleiro::organizaTabuleiroBackEndIncial() {
	char** matriz = NULL;

	matriz = (char**)malloc(LINHAS * sizeof(char*));

	for (int i = 0; i < LINHAS; ++i)
		matriz[i] = (char*)malloc(COLUNAS * sizeof(char));


	for (int linha = 0; linha < LINHAS; linha++)
	{
		for (int coluna = 0; coluna < COLUNAS; coluna++)
		{
			if (linha == 0) {
				switch (coluna){

					case 0: matriz[linha][coluna] = PECA_PRETA_TORRE;
						break;
					case 1: matriz[linha][coluna] = PECA_PRETA_CAVALO;
						break;
					case 2: matriz[linha][coluna] = PECA_PRETA_BISPO;
						break;
					case 3: matriz[linha][coluna] = PECA_PRETA_RAINHA;
						break;
					case 4: matriz[linha][coluna] = PECA_PRETA_REI;
						break;
					case 5: matriz[linha][coluna] = PECA_PRETA_BISPO;
						break;
					case 6: matriz[linha][coluna] = PECA_PRETA_CAVALO;
						break;
					case 7: matriz[linha][coluna] = PECA_PRETA_TORRE;
						break;

				default:
					break;
				}
					
			}
			else if (linha == 1) {
					matriz[linha][coluna] = PECA_PRETA_PIAO;
			}
			else if (linha == 6) {
				matriz[linha][coluna] = PECA_BRANCA_PIAO;
			}
			else if (linha == 7) {

				switch (coluna) {
				case 0: matriz[linha][coluna] = PECA_BRANCA_TORRE;
					break;
				case 1: matriz[linha][coluna] = PECA_BRANCA_CAVALO;
					break;
				case 2: matriz[linha][coluna] = PECA_BRANCA_BISPO;
					break;
				case 3: matriz[linha][coluna] = PECA_BRANCA_RAINHA;
					break;
				case 4: matriz[linha][coluna] = PECA_BRANCA_REI;
					break;
				case 5: matriz[linha][coluna] = PECA_BRANCA_BISPO;
					break;
				case 6: matriz[linha][coluna] = PECA_BRANCA_CAVALO;
					break;
				case 7: matriz[linha][coluna] = PECA_BRANCA_TORRE;
					break;

				default:
					break;
				}
			}
			else {
				matriz[linha][coluna] = VAZIO;
			}
		}
	}
	return matriz;
}

void Tabuleiro::tabuleiroUserIterface(char** tabuleiroBackEnd) {
	int descontoLinhasInterfaceMatriz = 0;

	system("cls");

	printf("\x1b[37mF1 - \x1b[32mPEGA A PECA  ||  \x1b[37mF2 - \x1b[32mSOLTA A PECA || \x1b[37mF3 - \x1b[32mCANCELA JOGADA || \x1b[37mF9 - \x1b[32mSAIR DO JOGO || \x1b[37mDirecionais - \x1b[32mMovimenta \n");

	printf("\x1b[31m________________________________________________________________________________\n");
	for (int linhasInterface = 1; linhasInterface <= TAM_LINHAS_INTERFACE; linhasInterface++) {
		printf("\n");

		if (linhasInterface % 2 == 0)
		{
			printf("\x1b[31m________________________________________________________________________________\n");
		}
		else {

			descontoLinhasInterfaceMatriz++;

			for (int colunasInterface = 0; colunasInterface < TAM_COLUNAS_INTERFACE; colunasInterface++)
			{
				if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_BRANCA_TORRE) {
					printf("\x1b[37m   TO.B  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_BRANCA_CAVALO) {
					printf("\x1b[37m   CA.B  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_BRANCA_BISPO) {
					printf("\x1b[37m   BI.B  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_BRANCA_RAINHA) {
					printf("\x1b[37m   RA.B  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_BRANCA_REI) {
					printf("\x1b[37m   RE.B  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_BRANCA_PIAO) {
					printf("\x1b[37m   PI.B  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_PRETA_TORRE) {
					printf("\x1b[31m   TO.P  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_PRETA_CAVALO) {
					printf("\x1b[31m   CA.P  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_PRETA_BISPO) {
					printf("\x1b[31m   BI.P  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_PRETA_RAINHA) {
					printf("\x1b[31m   RA.P  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_PRETA_REI) {
					printf("\x1b[31m   RE.P  ");

				}
				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PECA_PRETA_PIAO) {
					printf("\x1b[31m   PI.P  ");

				}

				else if (tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface] == PONTEIRO_DIRECIONAL) {
					printf("\x1b[32m    %c    ", tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface]);

				}
				else {
					printf("\x1b[37m    %c    ", tabuleiroBackEnd[linhasInterface - descontoLinhasInterfaceMatriz][colunasInterface]);
				}

				if (colunasInterface < 8) {
					printf("\x1b[31m|");
				}
			}
		}
	}
	printf("\n\x1b[31m________________________________________________________________________________\n");
	printf("\x1b[32mPlacar \x1b[34m%s: %d", globalPlayer2.nome, globalPlacarPretas);
	printf("\n\x1b[32mPlacar \x1b[37m%s: %d\n", globalPlayer1.nome, globalPlacarBrancas);
	printf("\x1b[32mAVISOS:\x1b[31m %s", globalAvisos);

}

void Tabuleiro::movimentacaoNoTabuleiroBackEnd(char** tabuleiroBackEnd, int eventoDeTecla) {

	PecaBase* pecaBase = PecaBase::getInstance(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_ACAO_CAPTURAR)
		pecaBase->pegaPeca(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_ACAO_SOLTAR)
		pecaBase->soltaPeca(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_ACAO_CANCELAR_JOGADA)
		pecaBase->cancelaJogada(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_DIRECIONAL_RIGHT)
		pecaBase->moveParaDireita(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_DIRECIONAL_LEFT)
		pecaBase->moveParaEsquerda(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_DIRECIONAL_UP)
		pecaBase->moveParaCima(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_DIRECIONAL_DOWN)
		pecaBase->moveParaBaixo(tabuleiroBackEnd);

	if (eventoDeTecla == TECLA_GAMEPLAY_ACAO_SAIR_DO_JOGO)
		pecaBase->~PecaBase();

		
}