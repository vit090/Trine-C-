#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"libUnicornio.h"

using namespace std;

class CarregadorDeAssets
{
private:
	int i_num_assets;
public:
	CarregadorDeAssets();
	~CarregadorDeAssets();
	bool CarregarAssets(fstream & arq_recursos);
};

