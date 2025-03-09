/*
Author: JOURNOUD Lucas
Date: 2025-03-08
Website: Yandex - CodeRun
Problems: 3. Вывести маршрут максимальной стоимости
Category: Algorithms
*/

#include <iostream>
#include <vector>

/*
Exemple 1:
5 5
9 9 9 9 9
3 0 0 0 0
9 9 9 9 9
6 6 6 6 8
9 9 9 9 9

Result:
74
D D R R R R D D

Help:
5 5
9 18 27 36 45
12 18 27 36 45
21 30 39 48 57
27 36 45 54 65
36 45 54 63 74

Exemple 2:
6 5
9 9 9 9 9
0 0 0 0 9
0 0 0 0 9
0 0 0 0 9
0 0 0 0 9
0 0 0 0 9

Result:
90
R R R R D D D D D
*/

int main()
{
    int N, M;
    std::cin >> N;
    std::cin >> M;
    std::vector<std::vector<int>> maze(N, std::vector<int>(M));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> maze[i][j];
            if (!i && j)
            {
                maze[0][j] += maze[0][j - 1]; //Fill first line
            }
        }
        if (i)
        {
            maze[i][0] += maze[i - 1][0]; //Fill first column
        }
    }

    for (int i = 1; i < N; i++) // Fill other case
    {
        for (int j = 1; j < M; j++)
        {
            maze[i][j] += std::max(maze[i - 1][j], maze[i][j - 1]);
        }
    }

    std::cout << maze[N - 1][M - 1] << std::endl;

    int i = N - 1;
    int j = M - 1;
    std::vector<char> letter;
    while(j || i)
    {
        if (!i)
        {
            j--;
            letter.push_back('R');
        }
        else if (!j)
        {
            i--;
            letter.push_back('D');
        }
        else if (maze[i-1][j] > maze[i][j-1])
        {
            i--;
            letter.push_back('D');
        }
        else
        {
            j--;
            letter.push_back('R');
        }
    }
    for (int i = letter.size() - 1; i >= 0; --i)
    {
        std::cout << letter[i] << ' ';
    }
}