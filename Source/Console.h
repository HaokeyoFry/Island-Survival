#pragma once
#include "stdafx.h"

class Console {
public:
	//��ʾ������Ϣ
	inline static void showDescription(std::string text)
	{
		showText(text);
		newline();
	}

	//���һ��ѡ��
	inline static void pushOption(std::string text)
	{
		options.push_back(text);
	}

	//��ʾ����ѡ��
	static void showOptions();

	//��ʾ���غϽ�������ѡ��
	static void showResult(std::string text);

	//�ȴ����ѡ��
	static int waitForChoose();

private:
	template <typename T>
	inline static void showText(T text) {
		std::cout << text;
	}

	inline static void newline() {
		std::cout << std::endl;
	}
	static std::vector<std::string> options;
};