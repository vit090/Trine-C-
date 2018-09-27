#pragma once
#include<string>
#include"libUnicornio.h"

using namespace std;

enum PersonagemAnim
{
	CAMINHANDO_BAIXO,
	CAMINHANDO_ESQ,
	CAMINHANDO_DIR,
	CAMINHANDO_CIMA
};

class Personagem
{
public:
	Personagem();
	~Personagem();
	virtual void especial() = 0;
	void setPosV(Vetor2D ponei);
	void setPos(int x, int y);
	Vetor2D getPosV();
	void setVel(float vel);
	void setSpriteSheet(string spritesheet);

	void moverDir();
	void moverEsq();
	void moverCima();
	void moverBaixo();
	
	void animar();
	void desenhar();

protected:
	Sprite sprite;
	float x, y;
	float vel;
};


