//����� ��������� ��������� �����
//	-��������� �����
//	-���������� �������� ��������� ������
//	-���� ������� ���������
//	-��������� ��������
//	-���������� ������ ������
//	-���������� ������ ������� ���������
//	
//

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Feed.h"
#include "Animals.h"
#include "FinishedWarhouse.h"

//class FinishedWarhouse;//��������� (�� ����� ����� ��������� �������� �� ������ ��������)

class Farm : public Animals //������������ (���������� ����� �� ������)
{
public:
	Farm();
	const void ShowFarm() const; // �������� ��������� ��� �� �����
	void Harvest(FinishedWarhouse& that);// ������� ������ �� ����� (����������� ����� ������ ����������� ������ �� 15%)
	void Feeding();//��������� ��������
	void FillFeed();//��������� ����� (��������� ����� �� ������������ �����������)
	void AddAnimals();// �������� ��������

private:
	std::vector<Animals> animals_; // ����� ��������
	std::vector<Feed> feedWarhouse_; //����� �����
	std::string warning_;
};