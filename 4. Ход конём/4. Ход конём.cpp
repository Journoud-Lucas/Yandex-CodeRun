#include <iostream>
#include <vector>
#include <array>

int main()
{
	int N, M;
	std::cin >> N;
	std::cin >> M;

	std::vector<std::vector<int>> array(N, std::vector<int>(M, 0));

	array[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j - 2 >= 0 && i - 1 >= 0)
			{
				array[i][j] += array[i - 1][j - 2];
			}

			if (i - 2 >= 0 && j - 1 >= 0)
			{
				array[i][j] += array[i - 2][j - 1];
			}
		}
	}

	std::cout << array[N - 1][M - 1];

    return 0;
}