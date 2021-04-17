#include <iostream>
#include <set>
#include <map>
using namespace std;

void ADD (const string& word_1, const string& word_2, map<string, int>& sinonims, set<set<string>>& is_cin){
    if (is_cin.count({word_1, word_2}) == 0){
        sinonims[word_1]++;
        sinonims[word_2]++;
    }
    is_cin.insert({word_1,word_2});
}

void COUNT (const string& word, map<string, int>& sinonims){
    cout << sinonims[word] << endl;
}

void CHECK (const string& word_1, const string& word_2, const set<set<string>>& is_sin){
    if (is_sin.count({word_1, word_2}) > 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    map<string, int> sinonims;
    set<set<string>> is_cin;
    int n = 0;
    string key, word_1, word_2;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> key;
        if (key == "ADD"){
            cin >> word_1;
            cin >> word_2;
            ADD(word_1, word_2, sinonims, is_cin);
        } else {
            if (key == "COUNT"){
                cin >> word_1;
                COUNT(word_1, sinonims);
            } else {
                if (key == "CHECK"){
                    cin >> word_1;
                    cin >> word_2;
                    CHECK(word_1, word_2, is_cin);
                }
            }
        }
    }
    return 0;
}

