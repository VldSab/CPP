#include <iostream>
#include <vector>
using namespace std;

void NEXT (int& month, const vector<int>& days_in_month, vector<vector<string>>& job_for_month){
    const int month_size = days_in_month[month];
    if (month < 11)
    {
        ++month;
    } else {
        month = 0;
    }
    int new_month_size = days_in_month[month];
    int previous_month_size = days_in_month[month-1];
    if (days_in_month[month] <  days_in_month[month-1])
    {
        for (int i = days_in_month[month]; i < days_in_month[month-1]; ++i)
        {
            job_for_month[days_in_month[month]-1].insert(end(job_for_month[days_in_month[month]-1]), begin(job_for_month[i]), end(job_for_month[i]));
            job_for_month[i].clear();
        }
    } else {
        job_for_month.resize(new_month_size);
    }
}

void ADD (const int& day_index, const string& job, vector<vector<string>>& job_for_month){
    job_for_month[day_index-1].push_back(job + ' ');
}

void DUMP (const int& day_index, const vector<vector<string>>& job_for_month){
    int job_count = job_for_month[day_index-1].size();
    cout << job_count << " " ;
    for (auto s :job_for_month[day_index-1])
    {
        cout << s;
    }
    cout << endl;
}


int main() {
    int n = 0, day_index = 0, month = 0;
    string key, new_job;
    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> job_for_month (31);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> key;
        if (key == "NEXT") {
            NEXT(month, days_in_month, job_for_month);
        }
        if (key == "ADD")
        {
            cin >> day_index;
            cin >> new_job;
            ADD(day_index, new_job, job_for_month);
        }
        if (key == "DUMP")
        {
            cin >> day_index;
            DUMP(day_index, job_for_month);
        }

    }

    return 0;
}

