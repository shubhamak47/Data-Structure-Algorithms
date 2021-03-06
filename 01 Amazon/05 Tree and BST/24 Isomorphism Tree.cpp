Problemn Statement : https://www.geeksforgeeks.org/tree-isomorphism-problem/

/* Two trees are called isomorphic if one of them can be obtained from other by a series of flips, 
i.e. by swapping left and right children of a number of nodes. */

/********************** Time Comp :O(min( m,n)) ***********************/

bool isIsomorphic(Node *root1,Node *root2)
{
    if(root1 == NULL && root2 == NULL)
      return true;
    if(root1 == NULL || root2 == NULL)
      return false;
      
    if(root1->data != root2->data)
      return false;
      
    return 
    ( isIsomorphic(root1->left,root2->left) && 
      isIsomorphic(root1->right,root2->right) ||
      isIsomorphic(root1->left,root2->right) && 
      isIsomorphic(root1->right,root2->left)
    );  
}
