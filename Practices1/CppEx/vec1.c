// Online C++ compiler to run C++ online.
// Write C++ code in this online editor and run it.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 3;
    vector<int>test(n);
    for(int i = 0; i < n; i++)
    {
        cout << "Num " << i + 1 << ": ";
        cin >> test[i];
    }

    cout << test[1] << endl;
    test.push_back(10);
    for(int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    test.insert(test.begin(), 1);
    cout << endl;
    for(int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    test.erase(test.begin() + 1);
    cout << endl;
    for(int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }

    return 0;
}