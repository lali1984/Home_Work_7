#include"Animals.h"

std::string Sound(std::string breed)
{
	if (breed == "cow")
		return "Myy!";
	else if (breed == "chicken")
		return "ko-ko-ko!";
	else if (breed == "pig")
		return "Xpy-xpy!";
	else if (breed == "hunger")
		return  "Ppp!!!";
	else
		return "check animals";
}

const unsigned short Appetite(std::string breed)
{
	if (breed == "cow")
		return 35;
	else if (breed == "chicken")
		return 10;
	else if (breed == "pig")
		return 20;
	else
		return 0;
}

Animals::Animals(std::string breed, unsigned ammount) : breed_(breed), sounds_(Sound(breed_)),hunger_(0),
appetite_(Appetite(breed_)), ammount_(ammount) {}

Animals::Animals(const Animals& that)
{
	breed_ = that.breed_;
	sounds_ = that.sounds_;
	hunger_ = that.hunger_;
	appetite_ = that.appetite_;
	ammount_ = that.ammount_;
}

const Animals& Animals::operator=(const Animals& that)
{
	breed_ = that.breed_;
	sounds_ = that.sounds_;
	hunger_ = that.hunger_;
	appetite_ = that.appetite_;
	ammount_ = that.ammount_;
	return *this;
}

const Animals& Animals::operator+=(const Animals& that)
{
	breed_ = that.breed_;
	ammount_ += that.ammount_;
	appetite_ = that.appetite_;
	hunger_ = (ammount_ * hunger_ + that.ammount_ * that.hunger_) / (ammount_ + that.ammount_);
	if (hunger_ != 0)
		sounds_ = "Ppp!!!";
	else
		sounds_ = Sound(breed_);
	return *this;
}

//	- выход продуктов по категориям(с каждого животного):
//		- корова -> молоко по цене 2 л за 1 % голода
//		- куприца -> яйцо по цене 6 шт за 2 % голода
//		- свинья -> мясо по цене 1 кг за 2 % голода
const unsigned Animals::Harvest()
{

	if (hunger_ < 100) {
		hunger_ += 10;
		if (breed_ == "cow") {
			sounds_ = Sound("hunger");
			return 20 * ammount_;
		}
		else if (breed_ == "chicken") {
			sounds_ = Sound("hunger");
			return 60 * ammount_;
		}
		else if (breed_ == "pig") {
			sounds_ = Sound("hunger");
			return 5 * ammount_;
		}
	}
}

//принимает породу в которой обнуляется голод и тип корма
// возвращает количество корма каторое списывается со склада
// расчет цены 1% голода
// cow = 0.35 
// chicken = 0.1
// pig = 0.2
//
void Animals::Feeding(Feed& feed)
{
	unsigned feedA = hunger_ * ((double)appetite_ / 100) * ammount_; //неообходимое кол корма
	if (feedA <= feed.GetAvailFeed() && hunger_ > 0) { // если корма в достатке
		feed.SetAvail(feed.GetAvailFeed() - feedA); // остаток корма
		hunger_ = 0;
		sounds_ = Sound(breed_);
	}
	else if (feedA > feed.GetAvailFeed() && hunger_ > 0) { // если корма не хватает
		hunger_ = ((feedA - feed.GetAvailFeed()) / ((double)appetite_ / 100) / ammount_);
		feed.SetAvail(0);//остаток корма
	}
}

std::string Warning(Animals& that) 
{	
	if (that.GetHunger() == 0)
		return "All GOOD!";
	else if (that.GetHunger() < 30)
		return "FEEDING ANIMALS";
	else if (that.GetHunger() >= 30 && that.GetHunger() < 90)
		return "That is CRITIKAL";
	else
		
		return "ANIMALS IS DIED";
}