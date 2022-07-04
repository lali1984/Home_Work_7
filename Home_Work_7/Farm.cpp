#include "Farm.h"

//���������� ������ ��������
std::vector<Animals> Animal()
{
	unsigned num;
	std::vector<Animals> farm;
	std::cout << "Enter the number of cows: ";
	std::cin >> num;
	farm.push_back(Animals("cow", num));
	std::cout << "Enter the number of chickens: ";
	std::cin >> num;
	farm.push_back(Animals("chicken", num));
	std::cout << "Enter the number of pigs: ";
	std::cin >> num;
	farm.push_back(Animals("pig", num));
	return farm;
}

// ��������� �������� ������ ������
std::vector<Feed> Feeds()
{
	std::vector<Feed> feed{ Feed("vegetables", 10000), Feed("corn", 10000), Feed("hay", 10000)};
	return feed;
}

Farm::Farm() :  animals_(Animal()), feedWarhouse_(Feeds()){}

// �������� ��������� ��� �� �����
const void Farm::ShowFarm() const
{
	int i = 0;
	for (auto v : animals_) {
		std::cout << "|" << std::setw(10) << v.GetBreed() << "|" << std::setw(10) << v.GetAmmount();
		std::cout << "|" << std::setw(12) << v.GetSound() << "|" << std::setw(10) << v.GetHunger() << "|" << std::setw(12) << feedWarhouse_[i].GetFeed();
		std::cout <<  ": " << std::setw(5) << feedWarhouse_[i].GetAvailFeed();
		std::cout << "|" << std::setw(12) << v.GetAppetite() << "|" << std::setw(17) << Warning(v) << "|\n";
		std::cout << "+------------------------------------------------------------------------------------------------+\n";
		++i;
	}
}

// ***���� ������:
//	- ����������� ����� ��������� �� 10 %
//	- ����� ��������� �� ����������(� ������� ���������):
//		- ������ -> ������ �� ���� 2 � �� 1 % ������
//		- ������� -> ���� �� ���� 6 �� �� 2 % ������
//		- ������ -> ���� �� ���� 1 �� �� 2 % ������
// 
void Farm::Harvest(FinishedWarhouse& that)
{
	for (auto& an : animals_) {
		if (an.GetBreed() == "cow") {
			that.AddProduct("milk", an.Harvest());
		}
		else if (an.GetBreed() == "pig") {
			that.AddProduct("meet", an.Harvest());
		}
		else if (an.GetBreed() == "chicken") {
			that.AddProduct("eggs", an.Harvest());
		}
	}
}

// ��������� ��������
// ���������� ���������� ����� �� ������
// ���������� ������ ��������
void Farm::Feeding()
{
	for (int i = 0; i < animals_.size(); ++i) {
		animals_[i].Feeding(feedWarhouse_[i]);
	}
}

void Farm::FillFeed() 
{
	for (auto& f : feedWarhouse_) {
		if (f.GetAvailFeed() < 10000)
			f.SetAvail(10000);
	}
}

void Farm::AddAnimals()
{
	unsigned numAn;
	for (auto& an : animals_) {
		std::cout << "Pleas enter number:" << an.GetBreed()<< "\t";
		std::cin >> numAn;
		Animals add(an.GetBreed(), numAn);
		an += add;
	}
}