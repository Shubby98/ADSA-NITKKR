#include <bits/stdc++.h>

using namespace std;

class Minheap
{

    vector<int> v;

    void heapify(int i)
    {
        int mini = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < v.size() && v[mini] > v[left])
        {
            mini = left;
        }
        if (right < v.size() && v[mini] > v[right])
        {
            mini = right;
        }
        if (mini != i)
        {
            swap(v[mini], v[i]);
            heapify(mini);
        }
    }

public:
    Minheap()
    {
        v.push_back(-1);
    }

    int size()
    {
        return v.size() - 1;
    }

    bool isEmpty()
    {
        return v.size() == 1;
    }

    void insert(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;

        while (index > 1 && v[index / 2] > v[index])
        {
            swap(v[index], v[index / 2]);
            index = index / 2;
        }

        return;
    }

    int min()
    {
        if (isEmpty())
        {
            return -1;
        }
        return v[1];
    }

    int removeMin()
    {
        int top = v[1];
        v[1] = v[v.size() - 1];
        v.pop_back();
        heapify(1);
        return top;
    }

    void print()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
};

class Maxheap
{

    vector<int> v;

    void heapify(int i)
    {
        int maxi = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < v.size() && v[maxi] < v[left])
        {
            maxi = left;
        }
        if (right < v.size() && v[maxi] < v[right])
        {
            maxi = right;
        }
        if (maxi != i)
        {
            swap(v[maxi], v[i]);
            heapify(maxi);
        }
    }

public:
    Maxheap()
    {
        v.push_back(-1);
    }

    int size()
    {
        return v.size() - 1;
    }

    bool isEmpty()
    {
        return v.size() == 1;
    }

    void insert(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;

        while (index > 1 && v[index / 2] < v[index])
        {
            swap(v[index], v[index / 2]);
            index = index / 2;
        }

        return;
    }

    int max()
    {
        if (isEmpty())
        {
            return -1;
        }
        return v[1];
    }

    int removeMax()
    {
        int top = v[1];
        v[1] = v[v.size() - 1];
        v.pop_back();
        heapify(1);
        return top;
    }

    void print()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
};

void get_kth_smaller(int k ,Minheap heap){

    for(int i = 0 ; i < k-1 ;i++){
        heap.removeMin();
    }

    cout<<"kth smaller Element ==> "<< heap.removeMin()<<endl;
    return;
}

void get_kth_larger(int k, Maxheap heap)
{

    for (int i = 0; i < k - 1; i++)
    {
        heap.removeMax();
    }

    cout <<"kth larger Element ==> " << heap.removeMax() << endl;
    return;
}

int main(){

    int n;
    cout << "Enter the total number of elements: ";
    cin >> n;

    Minheap miniheap;
    Maxheap maxaheap;

    cout << "Enter the element: " << endl;
    for (int i = 0; i < n; i++)
    {
        //int data;
        //cin >> data;
        miniheap.insert(i);
        maxaheap.insert(i);
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    get_kth_smaller(k , miniheap);
    get_kth_larger(k , maxaheap );

    return 0;
}