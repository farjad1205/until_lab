#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

using namespace std;

int deuce(int x)
{
    return x * 2;
}

bool check100(int x)
{
    if (x >= 100)
        return true;
    else
        return false;
}
int until(int x, function<int(int)> change, function<bool(int)> check)
{
    if (check(x))
        return x;

    return until(change(x), change, check);
}

int main()
{
    assert(until(5, deuce, check100));
    assert(until(2, deuce, check100));
    assert(until(3, deuce, check100));
    cout << "dope";
    return 0;
}