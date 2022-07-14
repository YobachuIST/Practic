#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> weights{ 4, 1, 3 };
std::vector<int> values{ 4000, 2500, 2000 }; 

int countMax(int maxCapacity)
{
    std::vector<std::vector<int>> arr(weights.size() + 1, std::vector<int>(maxCapacity + 1));
    for (int i = 0; i <= weights.size(); i++)
    {
        for (int j = 0; j <= maxCapacity; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0;
            }
            else
            {
                if (weights[i - 1] > j)
                {
                    arr[i, j] = arr[i - 1, j];
                }
                else
                {
                    int prev = arr[i - 1][j];
                    int byFormula = values[i - 1] + arr[i - 1][j - weights[i - 1]];
                    arr[i][j] = std::max(prev, byFormula);
                }
            }
        }
    }
    return arr[weights.size()][maxCapacity];
}

int main()
{
    std::cout << countMax(4);
} 
