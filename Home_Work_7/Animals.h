// класс животных
// вводит сущность животных которых нужно хранить на складе
// поля:
//	-порода
//	-индикатор голода в % (0% - сытые животные; 90-100% - голодная смерть) (расчитывается средний по породе т.к. кормление проходит
//  цетрализованно на общем кормостоле)
//	-расход корма во время кормления в кг. (пример: расход коровы 35 кг для удовлетворения 100% голода; (35 / 2) для удовлетворения 50% голода)
//	-звуки издоваемые животными при индикаторе голода == 0 (Гуд), > 0 (Рррр)
//	-количество животных определенной породы  

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
	// порода
	std::string breed_;
	// звуки
	std::string sounds_; 
	// голод
	unsigned short hunger_;
	// расход при кормлении
	unsigned short appetite_;
	// колличество
	unsigned ammount_;
};

std::string Warning(Animals& that);
