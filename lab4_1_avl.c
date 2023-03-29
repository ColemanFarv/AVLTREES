/******************************************************************************

FILENAME:     lab4_1_avl.c
COURSE:       MREN 178
LAB:          4
STUDENTS:    Hannah Vibien and Coleman Farvolden
DATE:2023-03-26

 Calibration: compass.setCalibration(-1748, 1728, -508, 2760, -2396, 658);

ATTRIBUTIONS: [https://www.educative.io/answers/how-to-balance-an-avl-tree]

 Source is used in all documents
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/* MREN 178 - Code is missing from the implmentation of this AVL Tree.
 * Fill in the missing code.
 */
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "bintree.h"
#include "lab4_1_avl.h"


void printTree(Node* root)
// Print representation of tree. We make an assumption, because tree nodes
// actually have pointer to data, not actual data.  So assume that it is a
// pointer to an integer.
{
    printf("{"); // Tree starts with an opening curly bracket
// then value of root node
    printf("(%d,%d)", root->key, *(int*) root->value);
// need to cast void pointer actual data type
    printf(","); // children come next

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
    printf("}"); // Tree ends with closing curly bracket
}//printTree()

//=============================================================================
// ALTERNATE IMPLEMENTATION OF PRINTTREE - FOR YOUR REVIEW.
//    YOU MAY IGNORE THIS.

void printTree2(Node* root)
// Print representation of tree. We make an assumption, because tree nodes
// actually have pointer to data, not actual data.  So assume that it is a
// pointer to an integer.
{
    if (root == NULL) {
// printing an empty tree
        printf("{}");
    } else {
// printing non-empty tree
        printf("{"); // Tree starts with an opening curly bracket
// then value of root node
        printf("(%ld,%d)", (long) root->key, *(int*) root->value);
// need to cast void pointer actual data type
        printf(","); // children come next

// left child.
        printTree(root->leftChild);
// separate left child from right child
        printf(",");
// right child.
        printTree(root->rightChild);
        printf("}"); // Tree ends with closing curly bracket
    }
}//printTree2()
//=============================================================================

int maxint(int a, int b) { return (a>b) ? a : b; }

void insertAVL (Key k, long* num, void *v, Tree *t)
// Add new data item to tree.  Use two data components - key and actual data -
// to create new node and insert node in appropriate place.
{
// Check for mistakes, including verification of tree type
    if ((t == NULL) || (t->tt != AVL)) return;
//printf("Insert %d into AVL\n", k);
// Check if tree empty - if so, insert first node
    if (t->root == NULL) {
        Node *n = initNode(k, num, v);
        n->height = 0;
        t->root = n;
    } else {
        t->root = insertNodeAVL(k, num, v, t->root);
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


Node* insertNodeAVL(Key k,long* num, void *v, Node *root)
// Build new node and insert into (non-empty) tree. Check if insertion has
// created imbalance and rebalance if necessary.
{
    if (root==NULL) {
        Node *n = initNode(k, num, v);
        n->height = 0;
        return n;
    }
    if (k < root->key) {
        root->leftChild = insertNodeAVL(k, num, v, root->leftChild);
        root->height = calcHeight(root);
    } else if (k > root->key) {
        root->rightChild = insertNodeAVL(k, num, v, root->rightChild);
        root->height = calcHeight(root);
    }
// Note - ignored equal case - should not occur.
    return rebalance(root);
}//insertNode()


void inOrderT(Node* root)
// In order traversal of tree displaying contents
{
    if (root) {
        inOrderT(root->leftChild);
        printf("%d (h=%d, bf=%d, x=%d, y=%d, z=%d) -> ", root->key, root->height,getBalanceFactor(root),root->x,root->y,root->z);
        inOrderT(root->rightChild);
    }
}//inOrderT()

//finished