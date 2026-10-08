#include <iostream>
#include <vector>
template <typename T, typename Compare>
void mySort(std::vector<T>& a, int left, int right, Compare comp)
{
    
    if (left >= right)
        return;
    
    T pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (comp(a[i], pivot))
        {
            i++;
        }
        while (comp(pivot,a[j]))
        {
            j--;
        }

        if (i <= j)
        {
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            
            i++;
            j--;
        }

        
    }
    mySort(a, left, j, comp);
    mySort(a, i, right, comp);


}