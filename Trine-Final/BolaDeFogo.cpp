#include "BolaDeFogo.h"



BolaDeFogo::BolaDeFogo()
{
	x = 400;
	y = 300;
	vel = 4;
}


BolaDeFogo::~BolaDeFogo()
{
}

void BolaDeFogo::setX(int x)
{
	this->x = x;
}

void BolaDeFogo::setY(int y)
{
	this->y = y;
}

int BolaDeFogo::getX()
{
	return  x;
}

int BolaDeFogo::getY()
{
	return y;
}

int BolaDeFogo::getVel()
{
	return vel;
}

void BolaDeFogo::setVel(int vel)
{
	this->vel = vel;
}

void BolaDeFogo::desenhar()
{
	if (direcao == 1) {
		y -= vel;
	}
	else if (direcao == 3) {
		y += vel;
	}
	else if (direcao == 4) {
		x -= vel;
	}
	else if(direcao == 2) {
		x += vel;
	}

}

void BolaDeFogo::animar()
{
	spr.avancarAnimacao();
}

void BolaDeFogo::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
}

void BolaDeFogo::atualizar()
{
	spr.desenhar(x, y);
}

void BolaDeFogo::setDirecao(int dir)
{
	this->direcao = dir;
}

