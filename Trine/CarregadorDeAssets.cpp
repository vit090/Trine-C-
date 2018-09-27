#include "CarregadorDeAssets.h"



CarregadorDeAssets::CarregadorDeAssets()
{
}


CarregadorDeAssets::~CarregadorDeAssets()
{
}

bool CarregadorDeAssets::CarregarAssets(fstream & arq_recursos)
{
	string tipo_asset;
	string nome_asset;
	string caminho_asset;
	string num_anim_asset;
	string num_max_frames_asset;
	string volume_musica;
	string::size_type sz;
	if (arq_recursos) {
		char c_num_assets = arq_recursos.get();
		this->i_num_assets = c_num_assets - '0';
		while (!arq_recursos.eof()) {
			arq_recursos >> tipo_asset >> nome_asset;
			if (!arq_recursos.fail()) {
				gDebug.depurar("erro_leitura", arq_recursos.fail());
				gDebug.depurar("tipo_asset", tipo_asset);
				gDebug.depurar("nome_asset", nome_asset);
				if (tipo_asset == "sprite_sheet") {
					arq_recursos>> caminho_asset >> num_anim_asset >> num_max_frames_asset;
					gDebug.depurar("caminho_asset", caminho_asset);
					gDebug.depurar("numAnim", num_anim_asset);
					gDebug.depurar("numMaxFrames", num_max_frames_asset);
					gRecursos.carregarSpriteSheet(nome_asset, caminho_asset, stoi(num_anim_asset, &sz), stoi(num_max_frames_asset, &sz), QUALIDADE_ESCALA_BAIXA);
				}
				if (tipo_asset == "audio") {
					arq_recursos >> caminho_asset;
					gDebug.depurar("caminho_asset", caminho_asset);
					gRecursos.carregarAudio(nome_asset, caminho_asset);
				}
				if (tipo_asset == "textura") {
					arq_recursos >> caminho_asset;
					gDebug.depurar("caminho_asset", caminho_asset);
					gRecursos.carregarTextura(nome_asset, caminho_asset, QUALIDADE_ESCALA_BAIXA);

				}
				if (tipo_asset == "musica") {
					arq_recursos >> caminho_asset >> volume_musica;
					gDebug.depurar("caminho_asset", caminho_asset);
					gDebug.depurar("volume_musica", volume_musica);
					gRecursos.carregarMusica(nome_asset, caminho_asset, stoi(volume_musica, &sz));
				}
				if (!gRecursos.carregouSpriteSheet(nome_asset)) {
					gDebug.erro("Não carregou recurso");
					return false;
				}
			}
		}
		return true;
	}
}
