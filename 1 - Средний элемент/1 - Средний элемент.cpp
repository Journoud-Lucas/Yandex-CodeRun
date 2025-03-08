/*
Author: JOURNOUD Lucas
Date: 2025-03-07
Website: Yandex - CodeRun
Problems: 1 - Средний элемент
Category: Backend
*/

#include <iostream>
#include <algorithm>

int main()
{
    int arrayNumber[3];
    for (int i = 0; i < 3; i++)
    {
            std::cin >> arrayNumber[i];
    }
    std::sort(&arrayNumber[0], &arrayNumber[3]);
    std::cout << arrayNumber[1] << std::endl;
    return 0;
}