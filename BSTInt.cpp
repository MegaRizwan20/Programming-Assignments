
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
    if (item < curr->data) 
    {
      if (curr->left == NULL)
      {
        curr->left = newNode;
        newNode->parent = curr;
        break;
      }
      else
      {
        curr = curr->left;
      }
    }
    else 
    {
      if (curr->right == NULL)
      {
        curr->right = newNode;
        newNode->parent = curr;
        break;
      }
      else
      {
        curr = curr->right;
      }
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
int BSTInt::height() const
{
  // TODO
  if (BSTInt::empty()) {
    return 0;
  }
  else if (root->left == NULL && root-> right == NULL){
    return 0;
  }
  else {
    int heightleft = root->left->height + 1;
    int heightright = root->right->height + 1;
    if (heightleft>heightright){
      return heightleft;
    }
    else {
      return heightright;
    }
    
  }
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  // TODO
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
  // TODO
  /*if (n->left != NULL) {
    deleteAll(n->left);
  }
  else if (n->right != NULL) {
    deleteAll(n->right);
  }
  else {
    delete n;
  }*/
  if (n) {
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }
}

