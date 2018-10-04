#pragma once
#include "Personagem.h"
#include"BolaDeFogo.h"
class Mago :
	public Personagem
{
public:
	Mago();
	~Mago();
	void especial() override;
};

