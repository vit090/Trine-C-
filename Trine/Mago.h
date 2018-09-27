#pragma once
#include "Personagem.h"
class Mago :
	public Personagem
{
public:
	Mago();
	~Mago();
	void especial() override;
};

