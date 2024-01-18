/**
 * You are developing an online retail system. The system needs to support different types of products such as electronics, clothing, and books. Implement the Factory Method pattern to create product objects for each category. Define a common interface for all products with a method like displayInfo().
 */

#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    virtual void displayInfo() const = 0;
    virtual ~Product() = default;
};

class Electronics : public Product
{
public:
    void displayInfo() const override
    {
        std::cout << "Product: Electronics" << std::endl;
    }
};

class Books : public Product
{
public:
    void displayInfo() const override
    {
        std::cout << "Product: Books" << std::endl;
    }
};

class Clothing : public Product
{
public:
    void displayInfo() const override
    {
        std::cout << "Product: Clothing" << std::endl;
    }
};

class Factory
{
public:
    virtual Product *createProduct() = 0;
    virtual ~Factory() = default;
};

class ElectronicsFactory : public Factory
{
public:
    Product *createProduct() override
    {
        return new Electronics();
    }
};

class BooksFactory : public Factory
{
public:
    Product *createProduct() override
    {
        return new Books();
    }
};

class ClothingFactory : public Factory
{
public:
    Product *createProduct() override
    {
        return new Clothing();
    }
};

int main()
{
    // Using Electronics Factory
    Factory *electronicsFactory = new ElectronicsFactory();
    Product *electronicsProduct = electronicsFactory->createProduct();
    electronicsProduct->displayInfo();
    delete electronicsProduct;
    delete electronicsFactory;

    // Using Books Factory
    Factory *booksFactory = new BooksFactory();
    Product *booksProduct = booksFactory->createProduct();
    booksProduct->displayInfo();
    delete booksProduct;
    delete booksFactory;

    // Using Clothing Factory
    Factory *clothingFactory = new ClothingFactory();
    Product *clothingProduct = clothingFactory->createProduct();
    clothingProduct->displayInfo();
    delete clothingProduct;
    delete clothingFactory;

    return 0;
}
