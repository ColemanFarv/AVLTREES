/******************************************************************************
FILENAME:     lab4_3_bst.c 
COURSE:       MREN 178
LAB:          4
STUDENTS:    [STUDENT NAMES AND IDS HERE] 
DATE:         

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE] 
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////    
/* MREN 178 - Code is missing from the implmentation of this BST Tree.  
 * Fill in the missing code to insert a node into the BST by passing a pTree 
 * paramter.
 */
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "lab4_3_bst.h"

int insertnodeBST(Key k, void *v, pNode root)
// Function inserts new node into tree, with key k and value pointed to
// by v. Parameter root points to root node of tree.  Note that this code
// rejects an attempt to insert a duplicate key.
{
	int result = BST_FAIL;

	//printf ("Insert %d into BST\n", k);
	
	// already exists in tree ==> can't insert
	if (root->key == k)
		result = BST_FAIL;
	else if (k < root->key) {
		// key value less than key value in root node - try to insert into left
		// subtree, if it exists.
		if (root->leftChild != NULL)
			// there is a left subtree - insert it
			result = insertnodeBST(k, v, root->leftChild);
		else {
			// new Node becomes the left subtree
			Node *n = initNode(k, v);
			root->leftChild = n;
			result = BST_OK;
		}
	} else if (k > root->key) {			// test actually redundant
		// key is greater than this nodes key value, so value goes into right
		// subtree, if it exists
		if (root->rightChild != NULL)
			// there is a right subtree - insert new node
			result = insertnodeBST(k, v,root->rightChild);
		else {
			// no right subtree - new node becomes right subtree
			Node *n = initNode(k, v);
			root->rightChild = n;
			result = BST_OK;
			}
		}
	return result;	
}

//insert()

// Your code goes here - addition so that insert to a BST can be done by passing
// a pTree parameter, not a pNode parameter. (See AVL code for a suggestion.)
//---<SNIP>---

void insertBST (Key k, void *v, Tree *t)
// Add new data item to tree.  Use two data components - key and actual data -
// to create new node and insert node in appropriate place.
{
    // Check for mistakes, including verification of tree type
    // Check if tree empty - if so, insert first node
    if (t->root == NULL) {
        Node *n = initNode(k, v);
        n->height = 0;
        t->root = n;
    }

     else	{

        insertnodeBST(k , v, t->root);  //insert the  node recursivly using insertnode bst function
    }
    return;
}//insert()

//---</SNIP>---

//finished