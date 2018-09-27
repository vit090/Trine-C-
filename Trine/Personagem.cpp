#include "Personagem.h"
#include<iostream>


Personagem::Personagem()
{
	vel = 0.2;
	x = 0;
	y = 0;
}

Personagem::~Personagem()
{
}


void Personagem::setPosV(Vetor2D ponei)
{
	x = ponei.x;
	y = ponei.y;
}

void Personagem::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vetor2D Personagem::getPosV()
{
	Vetor2D pimba(this->x, this->y);
	return pimba;
}

void Personagem::setVel(float vel)
{
	this->vel = vel;
}

void Personagem::moverDir()
{
	x += vel;
	sprite.setAnimacao(CAMINHANDO_DIR);
}

void Personagem::moverEsq()
{
	x -= vel;
	sprite.setAnimacao(CAMINHANDO_ESQ);
}

void Personagem::moverCima()
{
	y -= vel;
	sprite.setAnimacao(CAMINHANDO_CIMA);
}

void Personagem::moverBaixo()
{
	y += vel;
	sprite.setAnimacao(CAMINHANDO_BAIXO);
}

void Personagem::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Personagem::animar()
{
	sprite.avancarAnimacao();
}

void Personagem::desenhar()
{
	sprite.desenhar(x, y);
}