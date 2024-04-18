#include <iostream>
#include <list>
#include <string>

using namespace std;

#pragma once
class Data{
public:
	struct Pizza {
		const char* name;
		const char* price;
		list<const char*> ingredients;
	};

private:
	list<Pizza> pizzas;

public:
	void addPizza(const char* name, const char* price, list<const char*> ingredients) {

		pizzas.push_back({name, price, ingredients});
		cout << "pizza added to data class" << endl;
	}

	void showData() {

		for (auto pizza : pizzas) {
			cout << "Name: " << pizza.name << " Price: " << pizza.price << endl;
			cout << "\nIngredientes:\n" << endl;

			for (auto ingredient : pizza.ingredients) {
				cout << "-" << ingredient << "\n" << endl;
			}
		}
	}
};

