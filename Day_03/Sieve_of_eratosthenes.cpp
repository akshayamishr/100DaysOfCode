#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void fillNums(vector<bool> &sieve)
{
    int n = sieve.size() - 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            sieve[j] = 0;
        }
    }
}
int main()
{
    int n;
    do
    {
        cout << "Enter a number greater than 2 : ";
        cin >> n;
    } while (n <= 2);
    cout << "Following are the prime numbers strictly less than " << n << ":" << endl;
    vector<bool> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;
    fillNums(sieve);
    for (int i = 2; i < n; i++)
    {
        if (sieve[i])
            cout << i << " ";
    }
}