#include <iostream>
#include <vector>

class HashTable
{
private:
    static int EMPTY_NODE;
    static int LAZY_DELETED;
    static int FILLED_NODE;
    std::vector<int> Arr;
    std::vector<int> Flag;
    int tableSize = 0;
    virtual int ComputeHash(int key);
    virtual int ResolverFun(int index);

public:
    HashTable(int tSize);
    virtual bool Add(int value);
    virtual bool Find(int value);
    virtual bool Remove(int value);
    virtual void Print();
};


int HashTable::ComputeHash(int key)
{
    return key % tableSize;
}

int HashTable::ResolverFun(int index)
{
    return index;
}

bool HashTable::Add(int value)
{
    int hashValue = ComputeHash(value);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE || Flag[hashValue] == LAZY_DELETED)
        {
            Arr[hashValue] = value;
            Flag[hashValue] = FILLED_NODE;
            return true;
        }
        hashValue += ResolverFun(i);
        hashValue %= tableSize;
    }
    return false;
}

bool HashTable::Find(int value)
{
    int hashValue = ComputeHash(value);
    for (int i = 0; i < tableSize; i++)
    {
        if (Flag[hashValue] == EMPTY_NODE)
            return false;

        if (Flag[hashValue] == FILLED_NODE && Arr[hashValue] == value)
            return true;
        
        hashValue += ResolverFun(i);
        hashValue %= tableSize();
    }
    return false;
}