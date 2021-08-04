#include <iostream>
#include <chrono>

using namespace std;

int fib_iter(int n) {
    if (n < 1)
        return -1;
    else if (n <= 2)
        return 1;

    int prev_n1 = 1;
    int prev_n2 = 1;
    int temp;

    for (int i = 2; i < n; i++)
    {
        temp = prev_n1;
        prev_n1 = prev_n1 + prev_n2;
        prev_n2 = temp;
    }
    return prev_n1;
}

int fib_rec(int n){
    if (n < 1)
        return -1;
    else if (n <= 2)
        return 1;
    else
        return fib_rec(n - 1) + fib_rec(n - 2);
}

int main() {
    auto t1_1 = chrono::high_resolution_clock::now();
    cout << fib_iter(-4) << "\n";
    cout << fib_iter(5) << "\n";
    cout << fib_iter(20) << "\n";
    auto t1_2 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<std::chrono::nanoseconds>(t1_2 - t1_1).count();
    cout << "Iterative solution on C++ took: " << duration1 << " nanoseconds" << "\n\n";

    auto t2_1 = chrono::high_resolution_clock::now();
    cout << fib_rec(-4) << "\n";
    cout << fib_rec(5) << "\n";
    cout << fib_rec(20) << "\n";
    auto t2_2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<std::chrono::nanoseconds>(t2_2 - t2_1).count();
    cout << "Recursive solution on C++ took: " << duration2 << " nanoseconds" << "\n";

    return 0;
}
