#include "vector.h"
#include <iostream>
#include <vector>

int main()
{
	Vector<int> v;
	std::vector<int>::iterator v2;
	Vector<int> v1;

	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(9);
	//v.push_back(6);
	//v.push_back(2);

	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(98);
	
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	
	//v1 = v;

	//v1.reverse();

	//std::cout << v2[0];

	//std::cin >> v2[0];

	//for (int i = 0; i < v2.size(); ++i)
	//std::cin >> v2[i];
	//v1 = v2;
	for (int i = 0; i < 7; ++i) 
		std::cout << v1[i] << "\n";

	//std::cout << v1.size() << "\n";
}