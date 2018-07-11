#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct avlnode avlnode;
struct avlnode
{
    int key;
    int data;
    int height;
    struct avlnode* left;
    struct avlnode* right;
};

avlnode* insertRight(avlnode *root, avlnode* node, int *newheight)
{
    if(root->right == NULL)
    {
        root->right = node;
        if((root->left ==  NULL) ||
               (root->left->height < (node->height+1)))
        {
                root->height = node->height+1;
        }

        *newheight = root->height;
        return root;
    }
    else
    {
        root->right  = insertRight(root->right, node, newheight);
        root->height = *newheight +1;
        return root;
    }
}

avlnode* insertLeft(avlnode *root, avlnode* node, int *newheight)
{
    if(root->left == NULL)
    {
        root->left = node;
        if((root->right ==  NULL) ||
               (root->right->height < (node->height+1)))
        {
                root->height = node->height+1;
        }

        *newheight = root->height;
        return root;
    }
    else
    {
        root->left  = insertLeft(root->left, node, newheight);
        root->height = *newheight +1;
        return root;
    }
}

//  10      10
//9       9   1
//7      7 
//      6 
avlnode* checkandrebalance(avlnode *root)
{
    int leftHeight = 0, rightHeight = 0;
    if(root->left != NULL)
       leftHeight = root->left->height;
    if(root->right != NULL)
       rightHeight = root->right->height;

    //left rebalance
    if((leftHeight-rightHeight) >= 2)
    {
        int newHeight;
        avlnode *leftnode = root->left;
        // make left as root
        root->height = (rightHeight>0)? rightHeight:1;
        root->left = NULL;
        // make root as right of left  node
        root = insertRight(leftnode, root, &newHeight);
        return checkandrebalance(root);
        
    }
    else if((rightHeight-leftHeight) >= 2)
    {
        int newHeight;
        avlnode *rightnode = root->right;
        // make left as root
        root->height = (leftHeight>0)?leftHeight:1;
        root->right = NULL;
        // make root as right of left  node
        root = insertLeft(rightnode, root, &newHeight);
        return checkandrebalance(root);

    }
    else
        return root;
   
    //right rebalance
}

avlnode* insertHelper(avlnode* root, int data, int key, int *height)
{
    if(root == NULL)
    {
        root = (avlnode*)malloc(sizeof(avlnode));
        root->key  = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
    }
    else
    {
        int lheight, rheight;
        if(key <= root->key)
        {
            root->left = insertHelper(root->left, data, key, &lheight);

            if((root->right ==  NULL) ||
               (root->right->height < lheight))
            {
                root->height = lheight+1;
            }
        }
        else
        {
            root->right = insertHelper(root->right, data, key, &rheight);

            if((root->left ==  NULL) ||
               (root->left->height < rheight))
            {
                root->height = rheight+1;;
            }
        }
    }
   
    root = checkandrebalance(root);
    *height = root->height;
    return root;
}

avlnode* insertAVL(avlnode* root, int key, int data)
{
    int dummyHeight;
    return insertHelper(root, data, key, &dummyHeight);

}
void traverseAVL(avlnode *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        cout<<"key:"<<root->key<<"data:"<<root->data<<"height"<<root->height<<endl;
        traverseAVL(root->left);
        traverseAVL(root->right);
    }
}
int main()
{
    avlnode *root = NULL;
    for(int i = 10; i >=0; i--)
    {
        root = insertAVL(root, i, i*10);
    }
    for(int i = 11; i <= 31; i++)
    {
        root = insertAVL(root, i, i*10);
    }

    traverseAVL(root);
    return 0;

}
