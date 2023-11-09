#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>

using namespace std;
class RandomizedSet
{
    unordered_set<int> set;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (set.find(val) != set.end())
            return false;

        set.insert(val);
        return true;
    }

    bool remove(int val)
    {
        auto it = set.find(val);
        if (it != set.end())
        {
            set.erase(it);
            return true;
        }
        else
            return false;
    }

    int getRandom()
    {
        unordered_set<int>::iterator it = set.begin();
        advance(it, (rand() % ((set.size() - 1) - 0 + 1) + 0));
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{
    system("cls");
    RandomizedSet *r = new RandomizedSet();
    cout << "insert: " << r->insert(1) << endl;
    cout << "insert: " << r->insert(3) << endl;
    cout << "insert: " << r->insert(4) << endl;
    cout << "random: " << r->getRandom() << endl;

    cout << "remove: " << r->remove(1) << endl;

    cout << "random: " << r->getRandom() << endl;
    cout << "remove: " << r->remove(3) << endl;
    cout << "random: " << r->getRandom() << endl;
    cout << "random: " << r->getRandom() << endl;
    cout << "random: " << r->getRandom() << endl;
}