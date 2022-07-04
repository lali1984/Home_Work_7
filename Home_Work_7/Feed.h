// класс хронит вид и количество корма в кг
//
#pragma once
#include <string>
#include <iostream>


class Feed
{
public:
	Feed(){}
	Feed(std::string typeFeed, unsigned availability);
	Feed(const Feed& that);
	Feed& operator=(const Feed& that);
	const std::string GetFeed() const;
	const unsigned GetAvailFeed() const;
	void FillFeed(std::string type, unsigned num);
	const unsigned GetFeedPer(unsigned appetite);
	void SetAvail(double that);

private:
	std::string typeFeed_;
	double availability_ = 1000;
};

