// it is based on recusrion - on divide and conqure technique.

#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void printVec(std::vector<int> const &a);

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << " ";
    cout << endl;
}

void mergeSortedArrays(vector<int> *l, vector<int> *r, vector<int> *a)
{
    int size_l = l->size();
    int size_r = r->size();
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size_l && j < size_r)
    {
        if (l->at(i) < r->at(j))
        {
            a->at(k) = (l->at(i));
            i++;
            k++;
        }
        else
        {
            a->at(k) = (r->at(j));
            j++;
            k++;
        }
    }

    while (i < size_l)
    {
        a->at(k) = (l->at(i));
        i++;
        k++;
    }

    while (j < size_r)
    {
        a->at(k) = (r->at(j));
        j++;
        k++;
    }
}

void mergeSort(vector<int> *arr)
{
    if (arr->size() == 1)
    {
        return;
    }
    //2. Divide the array into two halves x and y
    int mid = (arr->size() - 1) / 2;
    vector<int> x, y;
    for (int i = 0; i <= mid; i++)
    {
        x.push_back(arr->at(i));
    }
    for (int i = mid + 1; i <= arr->size() - 1; i++)
    {
        y.push_back(arr->at(i));
    }

    //3. Apply merge sort on each half .ie. sort each array x and y
    mergeSort(&x);
    mergeSort(&y);

    //4. merge two sorted array togther
    mergeSortedArrays(&x, &y, arr);
}

int main(int argc, char const *argv[])
{
    // vector<int> l_arr{1, 2, 4, 6, 12};
    // vector<int> r_arr{10, 20, 30, 40, 50, 60};
    // vector<int> m_arr(l_arr.size() + r_arr.size());

    // mergeSortedArrays(&l_arr, &r_arr, &m_arr);
    vector<int> arr{6, 3, 2, 9, 1, 5, 10, 16, 14, 12, 4};
    mergeSort(&arr);

    printVec(arr);

    return 0;
}
