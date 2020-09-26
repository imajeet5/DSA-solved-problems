#include <bits/stdc++.h>

using namespace std;

class DynamicArray
{
private:
    int *arr;
    int currentPosition;
    int capacity;

    void increaseCapacity()
    {
        // increasing the capacity of arrray
        capacity = 2 * capacity;
        int *newarr = new int[capacity];
        for (int i = 0; i < currentPosition; i++)
        {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }

public:
    DynamicArray()
    {
        currentPosition = 0;
        capacity = 2;
        arr = new int[capacity];
    }

    int at(int i)
    {
        if (i < 0 || i >= currentPosition)
        {
            return -1;
        }
        return arr[i];
    }

    void push(int element)
    {
        if (currentPosition == capacity)
        {
            increaseCapacity();
        }
        arr[currentPosition] = element;
        currentPosition++;
    }

    void pop()
    {
        if (currentPosition == 0)
        {
            cout << "Array is empty " << endl;
            return;
        }
        currentPosition--;
    }

    // insert element at the ith position with shifting the elements
    void insertithindex(int index, int element)
    {
        if (index < 0 || index > currentPosition)
        {
            cout << "Index out of range " << endl;
            return;
        }

        if (index == currentPosition)
        {
            push(element);
            return;
        }

        if (currentPosition == capacity)
        {
            increaseCapacity();
        }
        for (int i = (currentPosition - 1); i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        currentPosition++;
    }

    void deleteithindex(int index)
    {

        if (index < 0 || index >= currentPosition)
        {
            cout << "Index out of range " << endl;
            return;
        }

        for (int i = index; i < (currentPosition - 1); i++)
        {
            arr[i] = arr[i + 1];
        }
        currentPosition--;
    }

    void left_rotate_usingArray(int n)
    {
        n = n % currentPosition;
        int temp[n];
        int j = 0;
        int k = 0;
        for (int i = 0; i < currentPosition; i++)
        {
            // storing first n element in temp array
            if (i < n)
            {
                temp[i] = arr[i];
            }
            else
            {
                // shifting rest of the elements
                arr[j] = arr[i];
                j++;
            }
        }

        while (j < currentPosition)
        {
            arr[j] = temp[k];
            j++;
            k++;
        }
    }

    int linearSearch(int element)
    {
        for (int i = 0; i < currentPosition; i++)
        {
            if (arr[i] == element)
            {
                return i;
            }
        }

        return -1;
    }

    // only work for sorted array
    int binarySearch(int element)
    {
        int s = 0, e = currentPosition - 1;
        int mid = 0;
        while (s <= e)
        {
            mid = (s + e) / 2; // s + (e - s)/2

            if (arr[mid] == element)
            {
                return mid;
            }
            else if (element < arr[mid])
            {
                // key will be on left side of mid
                e = mid - 1;
            }
            else
            {
                // key will be on right side of mid
                s = mid + 1;
            }
        }

        return -1;
    }

    void print()
    {
        for (int i = 0; i < currentPosition; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    int getCapacity()
    {
        return capacity;
    }
    int getSize()
    {
        return currentPosition;
    }
};

int main(int argc, char const *argv[])
{
    DynamicArray dr;

    dr.push(0);
    dr.push(1);
    dr.push(2);
    dr.push(3);
    dr.push(4);
    dr.push(5);
    dr.push(6);
    dr.push(7);
    dr.push(8);

    // dr.insertithindex(8, 99);
    // dr.insertithindex(0, 99);
    // dr.deleteithindex(5);
    // dr.left_rotate_usingArray(7);

    cout << "Element index is " << dr.binarySearch(5) << endl;

    dr.print();

    // cout << dr.at(3) << endl;
    cout << dr.getSize() << endl;

    return 0;
}