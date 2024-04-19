#include <iostream>
using namespace std;
int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    };
    return res;
}
int main()
{
    for (int i = 1; i < 10; i++)
    {
        cout << catalan(i);
        cout << endl;
    }
    return 0;
}
// result is:
// 1
// 1
// 2
// 4
// 9
// 21
// 51
// 127
// 323
