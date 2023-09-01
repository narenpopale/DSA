// Find Pairs having sum equals to k in DLL. 
// DLL is sorted and contains distinct elements.

// TC - O(N)
// SC - O(1)

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    Node* left = head;
    Node* right = head;

    while(right -> next != NULL) right = right -> next;

    while (left != right && left -> prev != right) {
        int sum = left -> data + right -> data;
        if(sum == k) {
            ans.push_back({left -> data, right -> data});
            left = left -> next;
            right = right -> prev;            
        }
        else if(sum < k) {
            left = left -> next;
        }
        else {
            right = right -> prev;            
        }
    }

    return ans;
}
