#include <vector>
#include <list>
#include <iostream>
using namespace std;
class MyHashSet
{
private:
    vector<list<int>> hashTable;
    int size;
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    MyHashSet()
    {
        size = 1000;
        hashTable.resize(size);
    }

    void add(int key)
    {
        int index = hashFunction(key);
        for (list<int>::iterator it = hashTable[index].begin(); it != hashTable[index].end(); ++it)
        {
            if (*it == key)
            {
                return;
            }
        }
        hashTable[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        hashTable[index].remove(key);
    }

    bool contains(int key)
    {
        int index = hashFunction(key);
        for (list<int>::iterator it = hashTable[index].begin(); it != hashTable[index].end(); ++it)
        {
            if (*it == key)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    MyHashSet *obj = new MyHashSet();
    obj->add(2000);
    obj->add(1000);
    for (int i = 0; i < 9; i++)
        obj->add(i);
    cout << obj->contains(1000) << endl;
    obj->remove(1000);
    cout << obj->contains(1000) << endl;
    return 0;
}