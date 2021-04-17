#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool  IsPalindrom (string word){
    int end = word.size()-1;
    for (int i = 0; i < word.size()/2; ++i)
    {
        if (word[i] == word[end-i])
        {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter (vector<string> words, int minLength){
    vector<string> new_vector(0);
    for (int i = 0; i < words.size(); ++i)
    {
        if (IsPalindrom(words[i]) && words[i].size() >= minLength)
        {
            new_vector.push_back(words[i]);
        } else {
            continue;
        }
    }
    return new_vector;
}

int main() {


    vector<string> palindroms = PalindromFilter({"abacaba", "aba", "helloolleh", "net"}, 5);
    for (auto s : palindroms)
    {
        cout << s << endl;
    }
    return 0;
}
