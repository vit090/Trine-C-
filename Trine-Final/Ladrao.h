#pragma once
#include "Personagem.h"
class Ladrao :
	public Personagem
{
public:
	Ladrao();
	~Ladrao();
	void especial() override;
	bool check();
protected:
	bool invisivel = false;
};

