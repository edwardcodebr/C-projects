#include <iostream>
#include <string>
#include <vector>
int main()
{
    int vector;
    std::vector<std::vector<int>> matriz =
    {
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };
    for (const auto& row : matriz)
    {
        for (const auto& lin : row)
        {
            std::cout << lin << "";
        }
        std::cout << std::endl;
    }

    std::cout << "\n";

    int soma = 0;
    int soma2 = 2;
    for (int i = 0 ; i < matriz.size() ; i++)
    {
        for (int j = 0 ; j < matriz[i].size() ; j++)
        {
            soma += matriz[i][j];
        }
    }
    vector = soma * soma2;
    std::cout << soma << "\n";
    std::cout << soma2 << "\n";
    std::cout << vector << "\n";
    return 0;
}