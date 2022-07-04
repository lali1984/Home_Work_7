//класс реализует поведение фермы
//	-заселение фермы
//	-добалнение животных имеющейся пароды
//	-сбор готовой продукции
//	-кормление животных
//	-пополнение склада кормов
//	-пополнение склада готовой продукции
//	
//

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Feed.h"
#include "Animals.h"
#include "FinishedWarhouse.h"

//class FinishedWarhouse;//агрегация (на склад могут привозить продукты из других хозяйств)

class Farm : public Animals //наследование (выполнение работ на складе)
{
public:
	Farm();
	const void ShowFarm() const; // показать состояние дел на ферме
	void Harvest(FinishedWarhouse& that);// собрать урожай на ферме (стандартный забор урожая увеличивает голлод на 15%)
	void Feeding();//покармить животных
	void FillFeed();//пополнить склад (заполняет склад до максимальной вместимости)
	void AddAnimals();// добавить животных

private:
	std::vector<Animals> animals_; // склад животных
	std::vector<Feed> feedWarhouse_; //склад корма
	std::string warning_;
};