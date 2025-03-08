/*
Author: JOURNOUD Lucas
Date: 2025-03-07
Website: Yandex - CodeRun
Problems: 155 - Уникальные элементы
Category: Backend
*/

#include <iostream>
#include <set>

int main()
{
	int N;
	std::cin >> N;
	std::set<int> uniqueNumber;
	std::set<int> toDelete;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if (toDelete.find(temp) == toDelete.end())
		{
			std::pair result = uniqueNumber.insert(temp);
			if (!result.second)
			{
				uniqueNumber.erase(result.first);
				toDelete.insert(temp);
			}
		}
	}
	std::cout << uniqueNumber.size();
}