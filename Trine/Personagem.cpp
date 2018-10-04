#include "Personagem.h"
#include<iostream>


Personagem::Personagem()
{
	vel = 0.2;
	x = 0;
	y = 0;
	direcao = 2;
}

Personagem::~Personagem()
{
}


void Personagem::setPosV(Vetor2D ponei)
{
	x = ponei.x;
	y = ponei.y;
}

void Personagem::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vetor2D Personagem::getPosV()
{
	Vetor2D pimba(this->x, this->y);
	return pimba;
}

int Personagem::getX()
{
	return x;
}

int Personagem::getY()
{
	return y;
}

void Personagem::setVel(float vel)
{
	this->vel = vel;
}

void Personagem::moverDir()
{
	direcao = 2;
	x += vel;
	sprite.setAnimacao(CAMINHANDO_DIR);
}

void Personagem::moverEsq()
{
	direcao = 4;
	x -= vel;
	sprite.setAnimacao(CAMINHANDO_ESQ);
}

void Personagem::moverCima()
{
	direcao = 1;
	y -= vel;
	sprite.setAnimacao(CAMINHANDO_CIMA);
}

void Personagem::moverBaixo()
{
	direcao = 3;
	y += vel;
	sprite.setAnimacao(CAMINHANDO_BAIXO);
}

void Personagem::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Personagem::setDirecao(int dir)
{
	this->direcao = dir;
}

int Personagem::getDirecao()
{
	return direcao;
}

void Personagem::animar()
{
	sprite.avancarAnimacao();
}

void Personagem::desenhar()
{
	sprite.desenhar(x, y);
}