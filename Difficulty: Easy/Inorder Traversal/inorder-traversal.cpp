/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/


class Solution {
  public:
    void in(Node* root , vector<int>&ans){
        if(root==NULL)
        return;
        //LEFT
        in(root->left , ans);
         //NODE
        ans.push_back(root->data);
        //RIGHT
        in(root->right , ans);
       
    }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        in(root , ans);
        return ans;
    }
};