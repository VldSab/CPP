#include <iostream>
using namespace std;

int main()
{

    char key = ' ', operation = ' ';
    int next = 1, a = 0, b = 0;

    while (next)
    {
        if (next == 0)
            break;
        cout << "So, write 'a' and 'b', ok?\n" << endl;
        cout << "a = " << endl;
        cin >> a;
        cout << "\nb = " << endl;
        cin >> b;
        cout << "\nWhat should I do? Write '+', '-', '*' or '/'\n" << endl;
        cin >> operation;
        switch (operation)
        {
        case '+':
            cout << "Result" << a + b << "\n" << endl;
            break;

        case '-':
            cout << "Result " << a - b << "\n" << endl;
            break;

        case '*': 
            cout << "Result " << a * b << "\n" << endl;
                break;

        case '/': 
            cout << "Result " << a / b << "\n" << endl;
                break;

        default:
            cout << "Its illegal\n" << endl;
            break;
        }
        cout << "Go further? Yes - 1, No - 0\n" << endl;
        cin >> next;
    }
    
    return 0;
}