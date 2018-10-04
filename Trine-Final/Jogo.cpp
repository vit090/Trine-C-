#include "Jogo.h"

Jogo::Jogo()
{
	select = 0;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	this->mapa_assets.open("..\\mapa_assets.txt", ios::in);
	if (!mapa_assets) {
		gDebug.erro("não abriu o arquivo", this);
	}
	CarregadorDeAssets * cda_carregador_assets = new CarregadorDeAssets;
	if (!cda_carregador_assets->CarregarAssets(mapa_assets)) {
		gDebug.erro("Falha no carregamento de recursos");
	}

	mapa.carregar("assets/tilemaps/mapa.json");

	classe[0] = new Guerreiro;
	classe[1] = new Mago;
	classe[2] = new Ladrao;
	classe[0]->setSpriteSheet("knight");
	classe[1]->setSpriteSheet("mage");
	classe[2]->setSpriteSheet("thief");

	Guerreiro* g = (Guerreiro*)classe[0];
	g->setAudio("grito");

	bola->setSpriteSheet("bola");

	classe[0]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	classe[0]->setVel(1);
	classe[1]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	classe[1]->setVel(1);
	classe[2]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	classe[2]->setVel(1);
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		mapa.desenhar();
	
		//--------------------------------------------//
		//Seleção de personagem
		if (gTeclado.pressionou[TECLA_1])
		{
			posicao = classe[select]->getPosV();
			select = 0;
			classe[select]->setPosV(posicao);
		}

		else if (gTeclado.pressionou[TECLA_2])
		{
			posicao = classe[select]->getPosV();
			select = 1;
			classe[select]->setPosV(posicao);
		}
	
		else if (gTeclado.pressionou[TECLA_3])
		{
			posicao = classe[select]->getPosV();
			select = 2;
			classe[select]->setPosV(posicao);
		}

		//--------------------------------------------//
		//Movimentação
		if (gTeclado.segurando[TECLA_DIR]) {
			classe[select]->moverDir();
			classe[select]->animar();
		}
		else if (gTeclado.segurando[TECLA_ESQ]) {
			classe[select]->moverEsq();
			classe[select]->animar();
		}
		else if (gTeclado.segurando[TECLA_CIMA]) {
			classe[select]->moverCima();
			classe[select]->animar();
		}
		else if (gTeclado.segurando[TECLA_BAIXO]) {
			classe[select]->moverBaixo();
			classe[select]->animar();
		}

		//--------------------------------------------//
		//Especiais
		Ladrao* l = (Ladrao*)classe[2];

		//Especial do guerreiro
		if (select == 0 && gTeclado.pressionou[TECLA_ESPACO]) {
			classe[0]->especial();
		}

		//Especial do ladrão
		if (select == 2 && gTeclado.pressionou[TECLA_ESPACO]) {
			classe[2]->especial();
		}

		//Especial do mago
		if (select == 1 && gTeclado.pressionou[TECLA_ESPACO]) {
			bola->setDirecao(classe[1]->getDirecao());
			bola->desenhar();
			bola->atualizar();
		}

		if (select == 1 && gTeclado.segurando[TECLA_ESPACO]) {
			bola->desenhar();
			bola->atualizar();
		}
		else {
			bola->setX(classe[select]->getX());
			bola->setY(classe[select]->getY());
		}

		//--------------------------------------------//
		//Desenhar sprites
		if (select != 2) {
			classe[select]->desenhar();
		}
		else {
			if (l->check() == false) {
				classe[2]->desenhar();
			}
		}

		//--------------------------------------------//
		//Gerenciador da música
		if (gTeclado.pressionou[TECLA_T]) {
			gMusica.tocar("uruk", true);
		}
		if (gMusica.estaTocando()==true && gTeclado.pressionou[TECLA_P]) {
			gMusica.pausar();
		}
		else if (gMusica.estaTocando()==false && gTeclado.pressionou[TECLA_P]) {
			gMusica.continuar();
		}

		//--------------------------------------------//
		uniTerminarFrame();
	}
}