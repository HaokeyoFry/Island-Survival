#include "stdafx.h"
#include "Game.h"
#include "Console.h"
#include <fstream>
#include <sstream>

vector<drama> Game::dramas;

bool Game::loadDramas()
{
	int i = 1;
	bool loadSuccess = false;
	std::stringstream ss;
	std::ifstream ifs;
	ifs.open("Data\\1.dat", std::ios::in | std::ios::binary); //���ļ�
	while (ifs) {
		int id;
		ifs.read((char*)&id, sizeof(int));
		if (id != i) { //У��ID�Ƿ���ȷ
			loadSuccess = false;
			break;
		}

		loadSuccess = true;
		drama dm;

		int length;

		//��ʼ��ȡ����
		ifs.read((char*)&length, sizeof(int));
		if (length == 0) {
			loadSuccess = false;
			break;
		}
		auto description = std::auto_ptr<char>(new char[length + 1]);
		ifs.read(description.get(), length);
		description.get()[length] = '\0';
		dm.description = description.get();

		//��ʼ��ȡѡ��
		ifs.read((char*)&length, sizeof(int));
		if (length == 0) {
			dm.isEnding = true;
		}
		else {
			auto options = std::auto_ptr<char>(new char[length + 1]);
			ifs.read(options.get(), length);
			options.get()[length] = '\0';
			//ѭ���и�ѡ��
			char* next_token = nullptr;
			char* option = strtok_s(options.get(), "|", &next_token);
			while (option != nullptr)
			{
				optionPackage opt;
				opt.text = option;
				dm.options.push_back(opt);
				option = strtok_s(nullptr, "|", &next_token);
			}
		}

		dramas.push_back(dm);

		ss.clear();
		ss.str("");
		ifs.close();

		i++;
		ss << "\\Data\\" << i << ".dat";
		ifs.open(ss.str(), std::ios::in | std::ios::binary); //���ļ���Ϊ��һ��ѭ����׼��
	}
	return loadSuccess;
}

void Game::mainLoop()
{
	if (dramas.size() == 0) return;
	int i = 0;

	drama& dmNow = dramas[i];

	Console::showDescription(dmNow.description);
	for each (optionPackage opt in dmNow.options)
	{
		Console::pushOption(opt.text);
	}
	Console::showOptions();
	Console::waitForChoose();
}
