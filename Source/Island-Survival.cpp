#include "stdafx.h"
#include "Console.h"

int main() {
	Console::showDescription("��ã�");
	Console::pushOption("ѡ��A");
	Console::pushOption("ѡ��B");
	Console::showOptions();
	switch (Console::waitForChoose()) {
		case 1: Console::showResult("��ѡ����ѡ��1"); break;
		case 2: Console::showResult("��ѡ����ѡ��2"); break;
	}

	return 0;
}