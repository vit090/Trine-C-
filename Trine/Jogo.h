#pragma once
#include "libUnicornio.h"
#include<fstream>
#include"Mago.h"
#include"Guerreiro.h"
#include"Ladrao.h"
#include"CarregadordeAssets.h"


class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

protected:
	Personagem* classe[3];
	fstream mapa_assets;
	int select;
	TileMap mapa;
	Vetor2D posicao;
};

