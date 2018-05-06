/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
     int globalMax;
     int univalCount;
public:
    Solution()
    {
        globalMax = 0;
        univalCount = 0;
    }
    bool countUnivalTrees(TreeNode* root)
    {
        bool leftUnival, rightUnival;
        if(root == NULL)
            return true;
        leftUnival  = countUnivalTrees(root->left);
        rightUnival = countUnivalTrees(root->right);
        if( leftUnival == true &&  rightUnival == true)
        {
            if((root->left == NULL || root->left->val == root->val) &&
              (root->right == NULL || root->right->val == root->val) )
            {
                univalCount++;
                return true;
            }
            
        }
        
        return false;
    }
    void printUnivalCount()
    {
        cout<<univalCount<<endl;
    }
    int longestUnivaluePath(TreeNode* root)
    {
        longestUnivaluePathHelper(root);
        countUnivalTrees(root);
        printUnivalCount();
        return globalMax;
    }
    int longestUnivaluePathHelper(TreeNode* root) {
        
        int leftcount = 0, rightcount = 0;
        int currentCount = 0, returnVal;
        if(root == NULL)
            return 0;
        //count++;
        if(root->left != NULL)
        {
            leftcount = longestUnivaluePathHelper(root->left);
            
            if(root->left->val != root->val)
            {
               leftcount  = 0;
            }
            else 
            {
                
                leftcount++;
            }
        }
       
        if(root->right != NULL )
        {
            rightcount = longestUnivaluePathHelper(root->right);
            
            if(root->right->val != root->val)
            {
               rightcount  = 0;
            }
            else 
            {
                rightcount++;
            }
        }
        
        if( (rightcount+leftcount)  > globalMax)
        {
            
            globalMax = rightcount+leftcount;
          //cout<<"rval"<<root->val<<"lcount"<<leftcount<<"rcount"<<rightcount<<"gmax"<<globalMax<<endl;
            
        }
        
                
        returnVal =  (leftcount>rightcount)? (leftcount): (rightcount);
       // cout<<"cval"<<root->val<<"returnVal"<<returnVal<<endl;
        return returnVal;
    }
};
