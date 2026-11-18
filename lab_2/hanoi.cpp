#include <iostream>

void hanoi(int n, int from, int to, int aux)
{
    if(n == 1)
    {
        std::cout << "Disk 1 move from " << from << " to " << to << std::endl;
        return;
    }
    
    hanoi(n-1, from, aux, to);
    std::cout << "Disk " << n << " move from " << from << " to " << to << std::endl;
    hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    std::cin >> n;
    hanoi(n, 1, 2, 3);
}