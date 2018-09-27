#include "Ladrao.h"



Ladrao::Ladrao()
{

}


Ladrao::~Ladrao()
{
}

void Ladrao::especial()
{
	if (invisivel == false) {
		invisivel = true;
	}
	else {
		invisivel = false;
	}

}

bool Ladrao::check()
{
	if (invisivel == false){
		return false;
	}
	else {
		return true;
	}
}

