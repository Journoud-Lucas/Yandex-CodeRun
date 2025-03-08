/*
Author: JOURNOUD Lucas
Date: 2025-03-08
Website: Yandex - CodeRun
Problems: 2. Самый дешевый путь
Category: Algorithms
*/

#include <iostream>
#include <vector>

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

    for (int i = 1; i < M; i++) // Fill other case
    {
        for (int j = 1; j < N; j++)
        {
            maze[i][j] += std::min(maze[i-1][j], maze[i][j-1]);
        }
    }
    
    std::cout << maze[M-1][N-1];

    return 0;
}