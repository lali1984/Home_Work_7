#include "Feed.h"

Feed::Feed(std::string typeFeed, unsigned availability) : 
	typeFeed_(typeFeed), availability_(availability) {}

Feed::Feed(const Feed& that)
{
	typeFeed_ = that.typeFeed_;
	availability_ = that.availability_;
}

void Feed::FillFeed(std::string type, unsigned num)
{
	if (typeFeed_ == type)
		availability_ += num;
	else
		std::cout << "Check data type feed!!";
}

Feed& Feed::operator=(const Feed& that)
{
	typeFeed_ = that.typeFeed_;
	availability_ = that.availability_;
	return *this;
}

const std::string Feed::GetFeed() const
{
	return typeFeed_;
}

const unsigned Feed::GetAvailFeed() const
{
	return availability_;
}

//принимает апетит животного для удовл 100% голода
//возвращает количество процентов которое может удовлетворить
const unsigned Feed::GetFeedPer(unsigned appetite)
{
	return (availability_) / ((double)appetite / 100);
}

void Feed::SetAvail(double that)
{
	availability_ = that;
}