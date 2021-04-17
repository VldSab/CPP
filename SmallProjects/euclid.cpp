#include <iostream>
using namespace std;

int main() {

    int x = 0, y = 0, nod = 0, tmp = 0;

    cin >> x >> y;

    while (true)
    {
        if (x < y)
        {
            tmp = x;
            x = y;
            y = tmp;
        }

        if (x % y == 0)
        {
            cout << y;
            break;
        } else {
            x %= y;
        }
    }

    return 0;
}
