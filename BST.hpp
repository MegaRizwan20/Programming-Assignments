/*
 * Authors: Rizwan Khan, Zhuoran Gu
 * UCSD Email: rikhan@ucsd.edu, zhg050@ucsd.edu
 * PID: A12236946, A53213113
 * CSE Login: cs100sgv, zhg050
 */

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
      This is inlined because it is trivial.
   */
  BST() : root(nullptr), isize(0) {}


  /** Default destructor.
      Delete every node in this BST.
  */
  ~BST();

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return a pair where the first element is an iterator 
   *  pointing to either the newly inserted element or the element 
   *  that was already in the BST, and the second element is true if the 
   *  element was newly inserted or false if it was already in the BST.
   * 
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** Return the height of the BST.
      height of a tree starts with root at height 0
	  height of an empty tree is -1
   */ 
  int height() const;


  /** Return true if the BST is empty, else false.
   */
  bool empty() const;

  /** Return an iterator pointing to the first (smallest) item in the BST.
   */ 
  iterator begin() const;

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Find the first element of the BST
   * Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);

  int height_helper(BSTNode<Data>* r) const;

 };


// ********** Function definitions ****************


/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BST<Data>::~BST() {
  deleteAll(root);
}


/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return a pair where the first element is an iterator pointing to either 
 *  the newly inserted element or the element that was already in the BST, 
 *  and the second element is true if the element was newly inserted or 
 *  false if it was already in the BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  
 */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {

  /* Checking if the root node exists */
  if (!root)
  {
    /* If it doesn't then we create new node and increment the size
     * and this new node becomes our root node */
    root = new BSTNode<Data>(item);
    ++isize;
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(root), true);
  }

  /* We make a current node set to the root node to traverse the tree */
  BSTNode<Data>* curr = root;

  /* We create a new node because we are inserting in a new node */
  BSTNode<Data>* newNode = new BSTNode<Data>(item);
  /* While we are trying to insert into the tree, do the condition
   * checks */
  while (true)
  {
    /* If what we are trying to insert is less than the current node
     * then we will be moving to the left */
    if (item < curr->data)
    {
      // If there is nothing to the left then we make a new node to the left 
      if (curr->left == NULL)
      {
        curr->left = newNode;
        newNode->parent = curr;
        ++isize;
        break;
      }
      // Else we point to the left of the current node
      else
      {
        curr = curr->left;
      }
    }
    /* Else if the item we are trying to insert is greater than the current
     * node then we will be doing operations to the right */
    else if (curr->data < item)
    {
      // If there is nothing to the right then we make a new node to the right
      if (curr->right == NULL)
      {
        curr->right = newNode;
        newNode->parent = curr;
        ++isize;
        break;
      }
      // Else we point to the right of the current node
      else
      {
        curr = curr->right;
      }
    }
    // Else the item is equal to the current node's data so we return false
    else
    {
      delete newNode;
      return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(0), false);
    }
  }
  return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(newNode), true);

}


/** Find a Data item in the BST.
 *  Return an iterator pointing to the item, or pointing past
 *  the last node in the BST if not found.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{

  // Create a new current node equal to the root
  BSTNode<Data>* curr = root;
  // While we are in the current, we do the following checks
  while (curr)
  {
    // If the data of the current node is less than the item, we go right
    if (curr->data < item)
    {
      curr = curr->right;
    }
    // Else if the item is less than current node data, we go left
    else if (item < curr->data)
    {
      curr = curr->left;
    }
    // Else we return the current node
    else
    {
      return BSTIterator<Data>(curr);
    }
  }
  // Otherwise we return null pointer
  return BSTIterator<Data>(nullptr);

}

  
/** Return the number of items currently in the BST.
 */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/** Helper method to get the height of the tree
 */
template <typename Data>
int BST<Data>::height_helper(BSTNode<Data>* r) const
{
  // Check the existence of nodes on the tree
  if (!r || (r->left==NULL && r->right==NULL))
  {
    return 0;
  }
  // Initialize the heights of the nodes to find the longest branch
  int leftheight = height_helper(r->left);
  int rightheight = height_helper(r->right);
  
  // Return the height of the whole tree
  return leftheight>rightheight ? leftheight+1:rightheight+1;
}

/** Return the height of the BST.
 */
template <typename Data> 
int BST<Data>::height() const
{
  // Returns the height of the tree
  return height_helper(root);
}


/** Return true if the BST is empty, else false.
 */ 
template <typename Data>
bool BST<Data>::empty() const
{

  // If root does not exist then there is no tree, so return true
  if (!root)
  {
    return true;
  }
  // Else return false
  else
  {
    return false;
  }
}

/** Return an iterator pointing to the first (smallest) item in the BST.
 */ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/** Return an iterator pointing past the last item in the BST.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/** Find the first element of the BST
 * Helper function for the begin method above.
 */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  // Made a new BSTnode called curr
  BSTNode<Data>* curr;
  // If the root does not exist return NULL
  if (!root) 
  {
    return NULL;
  }
  // Else do the following checks
  else
  {
    // If there is something to the left, we go left and set curr to left node
    if (root->left != NULL)
    {
      curr = root->left;
    }
    // Else we set the curr to the root
    else
    {
      curr = root;
    }
    // While the left is not null, we go to the left
    while (curr->left != NULL)
    {
      curr = curr->left;
    }
    // We return where ever curr ends up. This gets the smallest value in tree
    return curr;
  }
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
  // Check if there is a BSTNode in the tree
  if (n)
  {
    // Recursively deletes from the left
    deleteAll(n->left);
    // Recursively deletes from the right
    deleteAll(n->right);
    // Finally deletes the node
    delete n;
  }
}



#endif //BST_HPP
