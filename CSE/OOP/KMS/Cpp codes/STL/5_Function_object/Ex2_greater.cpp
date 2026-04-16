#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> // required header

int main()
{

    std::vector<int> numbers = {5, 2, 8, 1, 9, 4};

    // sort in descending order using functor
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // print vector
    std::cout << "Sorted in descending order: ";

    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    // use function object directly
    std::greater<int> is_greater;

    if (is_greater(10, 5))
    {
        std::cout << "10 is greater than 5" << std::endl;
    }

    return 0;
}

/*
Key Notes
---------
greater<int>() sorts container in descending order.
Default sort uses less<int>().
Functors can be used like functions.
*/