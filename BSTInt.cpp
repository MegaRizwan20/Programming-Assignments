/*
 * Authors: Rizwan Khan, Zhuoran Gu
 * UCSD Email: rikhan@ucsd.edu, zhg050@ucsd.edu
 * PID: A12236946, A53213113
 * CSE Login: cs100sgv, zhg050
 */

#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  
 /* while (curr->left && curr->right) {
    if (item < curr->data) {
      curr = curr->left;
    }
    else if (curr->data < item) {
      curr = curr->right;
    }
    else {
      return false;
    }
  }*/

  // Ready to insert
  /*BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
  }*/

 BSTNodeInt* newNode = new BSTNodeInt(item);
  while (true)
  {
    /* If element is less than current data */
    if (item < curr->data) 
    {
      /* Checking if a left child exists */
      if (curr->left == NULL)
      {
        curr->left = newNode;
        newNode->parent = curr;
        break;
      }
      /* If it exists then we move the pointer to the left child */
      else
      {
        curr = curr->left;
      }
    }
    /* Else if element is greater than current data */
    else if (item > curr->data) 
    {
      /* Checking if right child exists */
      if (curr->right == NULL)
      {
        curr->right = newNode;
        newNode->parent = curr;
        break;
      }
      /* If it does exist we move the pointer to the right child */
      else
      {
        curr = curr->right;
      }
    }
    /* Else the element equals the data so we return false for the checkpoint*/
    else
    {
      delete newNode;
      return false;
    }
  }


  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */

int BSTInt::height_helper(BSTNodeInt* r) const{
  if (!r || (r->left==NULL && r->right == NULL)){
    return 0;
  }
  int leftheight = height_helper(r->left);
  int rightheight = height_helper(r->right);

  return leftheight>rightheight? leftheight+1:rightheight+1;
}

/** Finds the height of the tree. This means it is calculating
 *  how tall the tree is based on the longest branch on the tree.
 *  This is done by calling the height_helper function.
 *  This returns the height of the tree to the user as an integer.
 */	
int BSTInt::height() const
{
  // Return the height of the tree to the user
  return height_helper(root); 
}

/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  /* Checking if a root exists or not. If it does not exist then
   * return true, otherwise return false */
  if (!root) {
    return true;
  }
  else {
    return false;
  }
}

/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  /* Checking if a node exists and traversing through it to delete all
   * of the nodes in a proper order. This is done recursively */
  if (n) {
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }
}

