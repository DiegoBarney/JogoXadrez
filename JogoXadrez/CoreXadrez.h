#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LINHAS 8
#define COLUNAS 8

#define TAM_LINHAS_INTERFACE 15
#define TAM_COLUNAS_INTERFACE 8

#define TECLA_MENU_OPCAO_JOGAR 1
#define TECLA_MENU_OPCAO_TUTORIAL 2
#define TECLA_MENU_OPCAO_SAIR 3

#define TECLA_GAMEPLAY_DIRECIONAL_UP 88
#define TECLA_GAMEPLAY_DIRECIONAL_DOWN 22
#define TECLA_GAMEPLAY_DIRECIONAL_RIGHT 66
#define TECLA_GAMEPLAY_DIRECIONAL_LEFT 44
#define TECLA_GAMEPLAY_ACAO_CAPTURAR 55
#define TECLA_GAMEPLAY_ACAO_SOLTAR 33
#define TECLA_GAMEPLAY_ACAO_CANCELAR_JOGADA 11
#define TECLA_GAMEPLAY_ACAO_SAIR_DO_JOGO 118
#define TECLA_INVALIDA 999

#define TABULEIRO_PONTEIRO_INICIAL 0
#define AVISOS_MOVIMENTO_INVALIDO_POSICAO_OCUPADA " MOVIMENTO DE PECA INVALIDO, ESTA POSICAO JA ESTA OCUPADA."
#define AVISOS_MOVIMENTO_INVALIDO_POSICAO_ERRADA  " MOVIMENTO DE PECA INVALIDO, ESTA PECA NAO PODE FAZER ESTE MOVIMENTO."
#define AVISOS_MOVIMENTAR_PECA_BRANCA " MOVIMENTO DE PECA INVALIDO, VOCE DEVE MOVIMENTAR AS PECAS BRANCAS."
#define AVISOS_MOVIMENTAR_PECA_PRETA " MOVIMENTO DE PECA INVALIDO, VOCE DEVE MOVIMENTAR AS PECAS PRETAS."
#define AVISOS_MOVIMENTAR_SEM_PECA " MOVIMENTO DE PECA INVALIDO, VOCE ESTA TENTANDO CAPTURAR UMA CASA SEM PECA."
#define AVISOS_MOVIMENTAR_CAPTURA_INCORRETA1 " MOVIMENTO DE PECA INVALIDO, VOCE ESTA TENTANDO CAPTURAR MAIS DE UMA PECA POR VEZ."
#define AVISOS_SEM_AVISOS " "


//PECAS BRANCAS XADREZ
#define PECA_BRANCA_TORRE 'Q'
#define PECA_BRANCA_CAVALO 'W'
#define PECA_BRANCA_BISPO 'E'
#define PECA_BRANCA_RAINHA 'R'
#define PECA_BRANCA_REI 'T'
#define PECA_BRANCA_PEAO 'Y'

//PECAS PRETAS XADREZ
#define PECA_PRETA_TORRE 'A'
#define PECA_PRETA_CAVALO 'S'
#define PECA_PRETA_BISPO 'D'
#define PECA_PRETA_RAINHA 'F'
#define PECA_PRETA_REI 'G'
#define PECA_PRETA_PEAO 'H'


//PECAS EVOLUCAO XADREZ
#define PECA_TORRE 'M'
#define PECA_CAVALO 'N'
#define PECA_BISPO 'B'
#define PECA_RAINHA 'V'

#define VAZIO ' '
#define PONTEIRO_DIRECIONAL '*'
#define PECA_SELECIONADA 'X'

#define VALIDACAO_CAPTURADA 0
#define VALIDACAO_ENCERRAR 1
#define VALIDACAO_CONTINUAR 2