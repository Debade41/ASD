#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

const int moves[8][2] = 
{
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValid(int x, int y, int N) 
    {return (x >= 0 && x < N && y >= 0 && y < N);}

int cntMoves(int x, int y, const std::vector<std::vector<int>>& board, int N) 
{
    int cnt = 0;

    for (int i = 0; i < 8; i++) 
    {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if (isValid(nx, ny, N) && board[nx][ny] == -1) 
            cnt++;
    }
    return cnt;
}

bool knightTour(int x, int y, int moveNum, std::vector<std::vector<int>>& board, int N) 
{
    board[x][y] = moveNum; 
    
    if (moveNum == N * N) 
        return true;
    
    std::vector<std::pair<int, int>> nextMoves;
    
    for (int i = 0; i < 8; i++) 
    {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if (isValid(nx, ny, N) && board[nx][ny] == -1) 
        {
            int priority = cntMoves(nx, ny, board, N);
            nextMoves.push_back({priority, i});
        }
    }
    
    std::sort(nextMoves.begin(), nextMoves.end());
    
    for (auto& move : nextMoves) 
    {
        int i = move.second;
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if (knightTour(nx, ny, moveNum + 1, board, N)) 
            return true;
    }
    
    board[x][y] = -1;
    return false;
}

int main() 
{
    int N, startX, startY;
    std::cout << "Введите размер доски N: ";
    std::cin >> N;
    std::cout << "Введите начальную позицию (x y): ";
    std::cin >> startX >> startY;
    
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));
    
    if (!isValid(startX, startY, N)) 
    {
        std::cout << "Неверная начальная позиция!" << std::endl;
        return 1;
    }
    
    if (knightTour(startX, startY, 1, board, N))
    {
        std::cout << "Маршрут коня:" << std::endl;
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) {std::cout << std::setw(3) << board[i][j] << " ";}
            std::cout << std::endl;
        }
    } 
    else 
        std::cout << "Решение не найдено!" << std::endl;    
}