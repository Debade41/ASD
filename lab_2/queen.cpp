#include <iostream>
#include <vector>
#include <string>

bool isSafe(const std::vector<int>& board, int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) 
            return false;
    }
    return true;
}

void solveNQueens(std::vector<std::vector<std::string>>& solutions, std::vector<int>& board, int row, int n) 
{
    if (row == n) 
    {
        std::vector<std::string> solution(n, std::string(n, '.'));
        for (int i = 0; i < n; i++) 
            {solution[i][board[i]] = 'Q';}
        solutions.push_back(solution);
        return;
    }
    
    for (int col = 0; col < n; col++) 
    {
        if (isSafe(board, row, col)) 
        {
            board[row] = col; 
            solveNQueens(solutions, board, row + 1, n); 
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) 
{
    std::vector<std::vector<std::string>> solutions;
    std::vector<int> board(n, -1); 
    solveNQueens(solutions, board, 0, n);
    return solutions;
}

void printSolutions(const std::vector<std::vector<std::string>>& solutions) 
{
    for (const auto& solution : solutions) 
    {
        std::cout << "Решение:" << std::endl;
        for (const std::string& row : solution) 
            std::cout << row << std::endl;
        std::cout << std::endl;
    }
}

int main() 
{
    int n;
    std::cout << "Введите размер доски N: ";
    std::cin >> n;

    std::vector<std::vector<std::string>> solutions = solveNQueens(n);
    
    if (solutions.empty()) 
        std::cout << "Решений не найдено для N = " << n << std::endl;
    else 
    {
        std::cout << "Найдено решений: " << solutions.size() << std::endl;
        printSolutions(solutions);
    }
}