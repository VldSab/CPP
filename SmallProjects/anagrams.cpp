#include <iostream>
#include <map>
using namespace std;

void BuildCharCounters (const string& first_word, const string& second_word){
    map<char, int> dict_1, dict_2;
    for (const auto& s : first_word)
    {
        ++dict_1[s];
    }
    for (const auto& s : second_word)
    {
        ++dict_2[s];
    }
    if (dict_1 == dict_2)
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {

    int n = 0;
    string first_word, second_word;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> first_word >> second_word;
        BuildCharCounters (first_word, second_word);
    }


    return 0;
}

