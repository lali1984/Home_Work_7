#pragma once
#include<iostream>
#include<string>
#include<vector>

struct Product
{
	Product(){}
	Product(std::string& type, unsigned ammount) : type_(type), ammount_(ammount) {}
	std::string type_;
	unsigned ammount_;
};

class FinishedWarhouse
{
public:
	FinishedWarhouse();
	FinishedWarhouse(std::vector<Product> warhouse);
	FinishedWarhouse(const FinishedWarhouse& that);
	const std::string& GetProduct(Product& that) const;
	const unsigned GetAmmount(Product& that) const;
	const std::vector<Product> GetWarehouse() const;
	const void AddProduct(std::string type, unsigned num);

private:
	std::vector<Product> warhouse_;
};

const void CalculateWarehouse(FinishedWarhouse& that);
