/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        queue<Node *>q;
        q.push(root);
        
        while(!q.empty()){
            ans.push_back(q.front()->data);
            int n=q.size();
            while(n--){
                Node *temp=q.front();
                q.pop();
                if(temp->right)
                q.push(temp->right);
                if(temp->left)
                q.push(temp->left);
            }
        }
        return ans;
    }
};