// Sort a given Array using Recursion.
// Smaller the Input - (Induction - Base - Hypothesis)

#include<iostream>
#include<vector>
using namespace std;


// Insert Function 
void Insert(vector<int> &v, int temp){

    // Base Condition
    if(v.size() == 0 || v[v.size() - 1] <= temp){
        v.push_back(temp);
        return;
    }

    int lastElement = v[v.size() - 1];

    v.pop_back();

    // Hypothesis
    Insert(v, temp);

    // Induction
    v.push_back(lastElement);

}


// Sort Function
void Sort(vector<int> &v){

    // Base Condition
    if(v.size() == 1) return;

    int temp = v[v.size() - 1];

    v.pop_back();

    // Hypothesis
    Sort(v);

    // Induction
    Insert(v, temp);

}


int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }    

    Sort(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }    

    return 0;
}