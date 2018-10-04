#pragma once
#include "Personagem.h"
#include<string>
class Guerreiro :
	public Personagem
{
public:
	Guerreiro();
	~Guerreiro();
	void especial() override;
	void setAudio(string nome);
protected:
	Som som;

};

