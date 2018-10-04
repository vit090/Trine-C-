#include "Guerreiro.h"



Guerreiro::Guerreiro()
{
}


Guerreiro::~Guerreiro()
{
}

void Guerreiro::especial()
{
	som.tocar();
}

void Guerreiro::setAudio(string nome)
{
	som.setAudio(nome);
}
