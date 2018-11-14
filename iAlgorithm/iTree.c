/*Tree*/
/*!log: [2018/11/4]write the algorithm of pr-order，in-order,post-order to travel through the tree */

#include <stdio.h>

struct kNote{
    int number;
    struct kNote *left;
    struct kNote *right;
};

void preOrder(struct kNote *root)
{
    if(NULL == root)
    {
        return;
    }
    else
    {
        printf("Current number:%d\n", root->number);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct kNote *root)
{
   if(NULL == root)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        printf("Current number:%d\n", root->number);
        inOrder(root->right);
    }
}

void postOrder(struct kNote *root)
{
   if(NULL == root)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("Current number:%d\n", root->number);
    }
}
