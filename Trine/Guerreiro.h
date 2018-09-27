#pragma once
#include "Personagem.h"
class Guerreiro :
	public Personagem
{
public:
	Guerreiro();
	~Guerreiro();
	void especial() override;
};

