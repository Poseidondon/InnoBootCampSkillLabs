#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print_v(vector <int> array)
{
    for (int i = 0; i < array.capacity(); i++)
        if (i == array.capacity() - 1)
            cout << array[i] << "\n";
        else
            cout << array[i] << " ";
}


vector <int> bubble_sort(vector <int> array, bool reversed)
{
    int temp;
    int shift = 0;
    for (int i = 1; i < array.capacity(); i++)
    {
        while ((i - 1 - shift >= 0) && (array[i - 1 - shift] < array[i - shift]))
        {
            temp = array[i - 1 - shift];
            array[i - 1 - shift] = array[i - shift];
            array[i - shift] = temp;
            shift++;
        }
        shift = 0;
    }
    if (reversed)
        reverse(array.begin(), array.end());
    return array;
}


vector <int> bubble_sort(vector <int> array)
{
    return bubble_sort(std::move(array), false);
}


int main()
{
    vector <int> array = {5, 2, 3, 98, -1, 0};
    print_v(array);
    print_v(bubble_sort(array, true));
}
