// One Recursive solution for all the Three Problems - 
// 1. Print all Power sets.
// 1. Print all Sub sets.
// 1. Print all Sub sequences.

// T.C. -> O(2^n)

#include<iostream>
#include<vector>
using namespace std;


void printAllSets(string ip, string op){

    if(ip.length() == 0){
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op2 += ip[0];

    ip.erase(ip.begin() + 0);

    printAllSets(ip, op1);
    printAllSets(ip, op2);

}


int main(){

    string ip;
    cin >> ip;

    printAllSets(ip, "");

    return 0;
}