/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void pre(Node* root , vector<int>&ans){
        if(root==NULL)
        return;
        //NODE
        ans.push_back(root->data);
        //LEFT
        pre(root->left , ans);
        //RIGHT
        pre(root->right , ans);
    }
    vector<int> preOrder(Node* root) {
        
        vector<int>ans;
        pre(root , ans);
        return ans;
        
    }
};