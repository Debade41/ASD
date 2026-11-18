#include <iostream>
#include <vector>  

typedef struct 
{  
    int max_value;      
    int max_index;    
} MaxElement;  

MaxElement findMaxRecursive(int arr[], int n, int index) 
{  
    if (index == n - 1) 
    {  
        MaxElement result;  
        result.max_value = arr[index];  
        result.max_index = index;  
        return result;  
    }
    
    MaxElement current = findMaxRecursive(arr, n, index + 1);  
    
    if (arr[index] > current.max_value) 
    {  
        current.max_value = arr[index];  
        current.max_index = index;  
    }  

    return current;  
}  

int main() 
{  
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    if (n <= 0)
        std::cout << "Недопустимый размер массива" << std::endl;

    std::vector<int> arr(n);
    std::cout<< "Введите " << n << " элементов: ";

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    MaxElement result = findMaxRecursive(arr.data(), n, 0);  

    std::cout << "Максимальный элемент: " << result.max_value << std::endl;
    std::cout << "Его индекс: " << result.max_index << std::endl;
}