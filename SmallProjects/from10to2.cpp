#include <iostream>
#include <vector>
using namespace std;

int main() {

    int number_10 = 0;
    vector<int> number_2(0);

    cin >> number_10;
    while (true)
    {
        if (number_10 / 2 != 0)
        {
            number_2.push_back(number_10 % 2);
            number_10 /= 2;
        } else {
            number_2.push_back(1);
            break;
        }
    }

    for (int i = number_2.size()-1; i >= 0; --i)
    {
        cout << number_2[i];
    }

    return 0;
}
