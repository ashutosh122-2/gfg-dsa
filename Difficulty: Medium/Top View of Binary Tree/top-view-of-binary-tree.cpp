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
    void find(Node *root , int pos , int &l , int &r){
        if(root==NULL)
        return ;
        
        l=min(pos , l);
        r=max(pos , r);
        
        find(root->left , pos-1 , l , r);
        find(root->right  , pos+1 , l , r);
    }
    
    
    vector<int> topView(Node *root) 
    {
        int l=0 , r=0 ;
        find(root , 0 , l , r);
        
        vector<int>ans(r-l+1);
        vector<bool>filled(r-l+1);
        
        queue<Node *>q;
        queue<int>index;
        
        q.push(root);
        index.push(-1 * l);
        
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            
            int pos=index.front();
            index.pop();
            
            if(!filled[pos]){
                filled[pos]=1;
                ans[pos]=temp->data;
            }
            
            //left
            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
            }
            //right
            if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};