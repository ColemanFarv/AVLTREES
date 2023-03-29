/******************************************************************************
FILENAME:     lab4_2_avl.c 
COURSE:       MREN 178
LAB:          4
STUDENTS:    [STUDENT NAMES AND IDS HERE] 
DATE:         

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE] 
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////    
/* MREN 178 - Code is missing from the implmentation of this AVL Tree. Copy 
 * completed functions for lab4_1_avl.c.   
 * Fill in the missing code for deleteAVLNode. 
 */
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "bintree.h"
#include "lab4_2_avl.h"


void printTree(Node* root)
// Print representation of tree. We make an assumption, because tree nodes
// actually have pointer to data, not actual data.  So assume that it is a
// pointer to an integer.
{
	printf("{");		// Tree starts with an opening curly bracket
	// then value of root node
	printf("(%d,%d)", root->key);
						// need to cast void pointer actual data type
	printf(",");		// children come next

	// left child. If NULL it will just print two empty braces,
	// otherwise it prints whole left tree.
	if (root->leftChild) {
		printTree(root->leftChild);
	} else
		printf("{}");
	// separate left child from right child
	printf(",");
	// right child. If NULL it will just print two empty braces,
	// otherwise it prints whole right tree.
	if (root->rightChild) {
		printTree(root->rightChild);
	} else
		printf("{}");
	printf("}");	// Tree ends with closing curly bracket
}//printTree()

//=============================================================================
// ALTERNATE IMPLEMENTATION OF PRINTTREE - FOR YOUR REVIEW.
//    YOU MAY IGNORE THIS.

void printTree2(Node* root)
// Print representation of tree. We make an assumption, because tree nodes
// actually have pointer to data, not actual data.  So assume that it is a
// pointer to an integer.
{
	if (root == NULL)	{
		// printing an empty tree
		printf("{}");
	} else	{
		// printing non-empty tree
		printf("{");		// Tree starts with an opening curly bracket
		// then value of root node
		printf("(%ld,%d)", (long) root->key, *(int*) root->value);
							// need to cast void pointer actual data type
		printf(",");		// children come next

		// left child.
		printTree(root->leftChild);
		// separate left child from right child
		printf(",");
		// right child.
		printTree(root->rightChild);
		printf("}");	// Tree ends with closing curly bracket
		}
}//printTree2()
//=============================================================================

int maxint(int a, int b)	{ return (a>=b) ? a : b; }


void insertAVL (Key k, void *v, Tree *t)
// Add new data item to tree.  Use two data components - key and actual data -
// to create new node and insert node in appropriate place.
{
	// Check for mistakes, including verification of tree type
	if ((t == NULL) || (t->tt != AVL))	return;
	//printf("Insert %d into AVL\n", k);
	// Check if tree empty - if so, insert first node
	if (t->root == NULL) {
		Node *n = initNode(k, v);
		n->height = 0;
		t->root = n;
	} else	{
		t->root = insertNodeAVL(k, v, t->root);
		}
	return;
}//insert()

Node* rotateRight(Node* root){
// Rotate to right.  Returns new root pointer.

    printf("Rotate Right\n");//print the rotation
//---Your code goes here
    if (root != NULL)   {//if the root exists, continue
        Node* left = root->leftChild;//create a left pointer and set it to the roots leftChild
        Node* leftRight = left->rightChild;//create a leftRight pointer and set it to lefts rightChild

        //rotate right
        left->rightChild = root;//set lefts rightChild equal to the root
        root->leftChild = leftRight;//set roots left Child equal to the leftRight node

        //update the height of each node (left, leftRight, and height) if they are not NULL
        if(left != NULL) {
            left->height = calcHeight(left);
        }
        if (leftRight != NULL) {
            leftRight->height = calcHeight(leftRight);
        }
        if (root != NULL) {
            root->height = calcHeight(root);
        }

        return left;//returns the left node as new root pointer
    }

}//rotateRight()



Node* rotateLeft(Node* root)
// Rotate to left.  Returns new root pointer.
{
    printf("Rotate Left\n");//print the rotation
//---Your code goes here
    if (root != NULL)   {//if the root exists, continue

        Node* right = root->rightChild;//create a right pointer and set it to the roots rightChild
        Node* rightLeft = right->leftChild;//create a rightLeft pointer and set it to the rights leftChild

        //perform left rotation
        right->leftChild = root;//set the rights leftChild equal to the root
        root->rightChild = rightLeft;//set the roots right child equal to the pointer rightLeft

        //update height of the right, root, and rightLeft nodes if they are not NULL
        if(right != NULL) {
            right->height = calcHeight(right);
        }
        if (rightLeft != NULL) {
            rightLeft->height = calcHeight(rightLeft);
        }
        if (root != NULL) {
            root->height = calcHeight(root);
        }

        return right;//return the right node as new root pointer
    }

}//rotateLeft()


int getBalanceFactor(Node *root)
// Get balance factor - difference between left height and right height
{
    int    hr = -1, hl = -1;     // Default values
//---Your code goes here
//---<SNIP>---
    if (root == NULL)//if root is NULL print that there is an error and return -1
    {
        printf("Error, root dosen't exist");
        return -1;
    }
    return calcHeight(root->leftChild) - calcHeight(root->rightChild);//call the calcHeight function for left and right of the root, then subtract left from right height

//---</SNIP>---

}//getBalanceFactor()



int calcHeight(Node* root)
// Calculate height of this node by adding 1 to maximum of left, right
// child height.
{
    int hrl = -1, hll = -1;        // Default values

//---Your code goes here
//---Code has to compute hrl - height of right subtree - and compute
//---hll - height of left subtree. In last line, 1 is added to the maximum
//---of hll and hrl and that value is returned.
//---<SNIP>---

    if (root == NULL) { //Returns -1 when reaches a null child
        return -1;
    }

    if (root->rightChild != NULL) { //checks if right child is not null
        hrl = calcHeight(root->rightChild); //finds height of right side of node recursivly
    }
    if (root->leftChild != NULL) { //checks if left child is not null
        hll = calcHeight(root->leftChild);//finds height of left side of node recursivly
    }
    return 1 + maxint(hll, hrl); //Determines whether right or left side is greater and makes that the height of the node
    //---</SNIP>---
}//calcHeight();

Node* rebalance(Node* root)
// Check balance factor to see if balancing required (bf > 1 or bf < -1).
// If balancing required, perform necessary rotations.
{
    int bf = getBalanceFactor(root); //find the balance factor of the node
    if (root == NULL) return NULL; //check if the root is null
//---Your code goes here
//---<SNIP>---

    if (bf > 1 || bf < -1) { //If the node is unbalance complete the code below

        // if the imbalance is on the right of the right node right right
        //if the imbalance is on the left of the right node right left rotation

        if (bf > 1) //if node is imbalanced on left side
        {
            // left-left imbalance
            if(getBalanceFactor(root->leftChild) >= 0)
            {
                root = rotateRight(root); //rotate right around the node
                return root; //return root
            }

                // left-right imbalance
            else if(getBalanceFactor(root->leftChild) == -1)
            {
                root->leftChild = rotateLeft(root->leftChild); //rotate left around roots leftchild
                root = rotateRight(root); //rotate right around root
                return root; //return root
            }
        }

        if (bf < -1) //If the node is unbalanced on the right side
        {
            // right-right imbalance
            if(getBalanceFactor(root->rightChild) <= -0)
            {
                root = rotateLeft(root); //rotate left around root
                return root; //return the root
            }

                // right-left imbalance
            else if(getBalanceFactor(root->rightChild) == 1)
            {
                root->rightChild = rotateRight(root->rightChild); //rotate right around the rooots rightchild
                root = rotateLeft(root); //rotate left around the root
                return root; //returns the root
            }
        }
    }

//---</SNIP>---
    return root;
}//rebalance()


Node* insertNodeAVL(Key k, void *v, Node *root)
// Build new node and insert into (non-empty) tree. Check if insertion has
// created imbalance and rebalance if necessary.
{
	if (root==NULL) {
		Node *n = initNode(k, v);
		n->height = 0;
		return n;
		}
	if (k < root->key) {
		root->leftChild = insertNodeAVL(k, v, root->leftChild);
		root->height = calcHeight(root);
	} else if (k > root->key) {
		root->rightChild = insertNodeAVL(k, v, root->rightChild);
		root->height = calcHeight(root);
		}
	// Note - ignored equal case - should not occur.
	return rebalance(root);
}//insertNode()

Node* deleteNodeAVL(Key k, Node *root, Node* rt) {
//---Your code goes here

    if (root==NULL) {//if root is NULL return NULL as nothing needs to be deleted
        return NULL;
    }

    if (k < root->key) {//if value to be deleted is smaller than the roots key
        root->leftChild = deleteNodeAVL(k, root->leftChild, rt);//roots left child is now equal to recursively calling the deleteNodeAvl function again with the roots left child
    }
    else if (k > root->key) {//if value to be deleted is larger than the roots jey
        root->rightChild = deleteNodeAVL(k, root->rightChild, rt);//roots right child is now equal to recursively calling the deleteNodeAvl function again with the roots right child
    }

    else {//when the value to delete is neither larger or smaller than the roots key (when it is the same)
        // Note - ignored equal case - should not occur.
        deleteNode(findParent(k, rt), find(k, rt));//call the deleteNode function to delete the node.
    }

    return rebalance(root);//return the new root node after deletion and rebalance the tree as needed

//_delete(
//---</SNIP>---
}

void inOrderT(Node* root)
// In order traversal of tree displaying contents
{
	if (root) {
		inOrderT(root->leftChild);
		printf("%d(h=%d,bf=%d) - ", root->key, root->height,getBalanceFactor(root));
		inOrderT(root->rightChild);
		}
}//inOrderT()

void deleteNode (Node *p, Node *n)
{
	Node *del = n;		// Save copy of pointer to node to delete.

	if (n->leftChild != NULL) {			// there is left child
		p = n;
		n = n->leftChild;
		// get to rightmost child of the left subtree
		while (n->rightChild) {
			p = n;
			n = n->rightChild;
			}
		
		// overwrite deleteNode (key,value) with (key,value) of rightmost child of left subtree
		del->key = n->key;
		del->value = n->value;
		deleteNode(p,n);
	}

    else if (n->rightChild) {
		p = n;
		n = n->rightChild;
		// get to leftmost child of the right subtree
		while(n->leftChild) {
			p = n;
			n = n->leftChild;
			}
		// overwrite deleteNode (key,value) with (key,value) of leftmost child of right subtree
		del->key = n->key;
		del->value = n->value;
		deleteNode(p,n);
	} else {
		if (p != NULL)	{
			// There is parent - are we deleting left or right subtree?
			if (p->leftChild == n)			p->leftChild = NULL;
			else if (p->rightChild == n)	p->rightChild = NULL;
			// We are ignoring possibility that neither subtree pointer
			// points to node. 
		}

	}	
}

//finished