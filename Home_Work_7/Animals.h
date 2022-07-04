// ����� ��������
// ������ �������� �������� ������� ����� ������� �� ������
// ����:
//	-������
//	-��������� ������ � % (0% - ����� ��������; 90-100% - �������� ������) (������������� ������� �� ������ �.�. ��������� ��������
//  �������������� �� ����� ����������)
//	-������ ����� �� ����� ��������� � ��. (������: ������ ������ 35 �� ��� �������������� 100% ������; (35 / 2) ��� �������������� 50% ������)
//	-����� ���������� ��������� ��� ���������� ������ == 0 (���), > 0 (����)
//	-���������� �������� ������������ ������  

#pragma once
#include <string>
#include <iostream>
#include "Feed.h"

class Animals : public Feed
{
public:
	Animals() {};

	Animals(std::string breed, unsigned ammount);
	
	Animals(const Animals& that);
	
	const Animals& operator=(const Animals& that);

	const Animals& operator+=(const Animals& that);

	const std::string& GetBreed() const
	{
		return breed_;
	}

	const unsigned short GetHunger()const
	{
		return hunger_;
	}

	const unsigned GetAmmount() const
	{
		return ammount_;
	}

	const std::string& GetSound() const
	{
		return sounds_;
	}

	const unsigned GetAppetite() const
	{
		return appetite_;
	}

	const unsigned Harvest();

	void Feeding(Feed& feed);


private:
	// ������
	std::string breed_;
	// �����
	std::string sounds_; 
	// �����
	unsigned short hunger_;
	// ������ ��� ���������
	unsigned short appetite_;
	// �����������
	unsigned ammount_;
};

std::string Warning(Animals& that);
