
#include "FinishedWarhouse.h"


FinishedWarhouse::FinishedWarhouse(){}

FinishedWarhouse::FinishedWarhouse(std::vector<Product> warhouse) : warhouse_(warhouse) {}

FinishedWarhouse::FinishedWarhouse(const FinishedWarhouse& that)
{
	for (int i = 0; i < warhouse_.size(); ++i) {
		warhouse_[i] = that.warhouse_[i];
	}
}

const std::string& FinishedWarhouse::GetProduct(Product& that) const
{
	return that.type_;
}

const unsigned FinishedWarhouse::GetAmmount(Product& that) const
{
	return that.ammount_;
}

const std::vector<Product> FinishedWarhouse::GetWarehouse() const
{
	return warhouse_;
}

const void FinishedWarhouse::AddProduct(std::string type, unsigned num)
{
	if (warhouse_.size() != 0) {
		int i;
		for (i = 0; i < warhouse_.size(); ++i) {
			if (warhouse_[i].type_ == type) {
			warhouse_[i].ammount_ += num;
			break;
			}
		}
		if (i == warhouse_.size())
			warhouse_.push_back(Product(type, num));
	}
	else
		warhouse_.push_back(Product(type, num));
}

const void CalculateWarehouse(FinishedWarhouse& that)
{
	std::cout << "Receit of finished products to the warehouse\n";
	std::cout << "=================================================\n";
	for (auto& v : that.GetWarehouse()) {
		std::cout << "| " << v.type_ << ": " << v.ammount_ << "\t";
	}
	std::cout << "|\n";
	std::cout << "=================================================\n";
}
