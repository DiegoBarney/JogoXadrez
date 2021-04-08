#pragma once
#include "CoreXadrez.h"

class TecladoJogo {

public:
	static TecladoJogo* getInstance();
	~TecladoJogo();
	int capturaTeclado();

private:
	TecladoJogo();
	void registraTeclasDoJogo();
};
