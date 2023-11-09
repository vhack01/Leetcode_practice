#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<vector<string>>> timemap;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {

        vector<string> iv;
        iv.push_back(to_string(timestamp));
        iv.push_back(value);

        timemap[key].push_back(iv);
    }

    void display()
    {
        for (auto it : timemap)
        {
            cout << it.first << "===" << endl;
            for (auto p : it.second)
            {
                for (auto str : p)
                    cout << str << " : ";
                cout << endl;
            }
        }
        cout << endl;
    }

    string get(string key, int timestamp)
    {

        int size = timemap[key].size();
        int s = 0, e = size - 1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if ((stoi(timemap[key][mid][0]) == timestamp))
                return timemap[key][mid][1];
            else if ((stoi(timemap[key][mid][0]) < timestamp))
                s = mid + 1;
            else
                e = mid - 1;
        }

        if (e == -1)
        {
            return "";
        }
        else if (s == size)
            return timemap[key][size - 1][1];
        else
        {
            return timemap[key][e][1];
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main()
{
    system("cls");
    TimeMap *tm = new TimeMap();

    tm->set("foo", "bar", 1);
    tm->set("foo", "bar2", 4);
    tm->set("foo", "bar3", 5);
    tm->display();
    cout << "get: " << tm->get("foo", 2) << endl;

    // cout << "\n\n";

    // cout << "get: " << tm->get("foo", 1) << endl;
    // cout << "get: " << tm->get("foo", 4) << endl;
    // cout << "get: " << tm->get("foo", 5) << endl;
}
