// Dynamic array

#include <bits/stdc++.h>

using namespace std;

class DynamicArray
{
    int *data;
    int n;
    int capacity; // total size of the array

public:
    DynamicArray()
    {
        data = new int[5];
        n = 0;
        capacity = 5;
    }
    DynamicArray(int c)
    {
        data = new int[c];
        n = 0;
        capacity = c;
    }
    
    // this is copy constructor
    DynamicArray(DynamicArray const &d)
    {
        this->n = d.n;
        this->capacity = d.capacity;
        // this->data = d.data; this is shallow copy
        // deep copy

        this->data = new int[d.capacity];
        for (int i = 0; i < d.n; i++)
        {
            this->data[i] = d.data[i];
        }
    }

    void operator=(DynamicArray const &d)
    {
        this->n = d.n;
        this->capacity = d.capacity;
        // this->data = d.data; this is shallow copy
        // deep copy

        this->data = new int[d.capacity];
        for (int i = 0; i < d.n; i++)
        {
            this->data[i] = d.data[i];
        }
    }

    void add(int element)
    {
        if (n == capacity)
        {
            // increase the capacity
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = 2 * capacity;
        }
        data[n] = element;
        n++;
    }

    int get(int i) const
    {
        if (i >= 0 && i < n)
        {
            return data[i];
        }
        return -1;
    }

    void add(int element, int i)
    {
        if (i < n)
        {
            data[i] = element;
        }
        else if (i == n)
        {
            // if element is added at last
            add(element);
        }
        else
        {
            return;
        }
    }

    void print() const
    {
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int getCapacity() const
    {
        return capacity;
    }
};

int main(int argc, char const *argv[])
{
    DynamicArray d1;

    for (int i = 1; i < 7; i++)
    {
        d1.add(i * 10);
    }
    DynamicArray d2(d1);
    DynamicArray d3;

    d3 = d1;

    d1.add(100, 0);
    d1.print();
    d2.print();
    d3.print();

    cout << d1.getCapacity() << endl;
    cout << d1.get(3) << endl;

    vector<int> v2(5, -2);
    v2.push_back(5);

    cout << "capacity " << v2.capacity() << endl;

    return 0;
}