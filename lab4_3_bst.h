/******************************************************************************
FILENAME:     lab4_3_bst.h 
COURSE:       MREN 178
LAB:          4
STUDENTS:    [STUDENT NAMES AND IDS HERE] 
DATE:         

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE] 
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////    
////////////////////////////////////////////////////////////////////////////////    
/* MREN 178 - 
 * Fill in the missing function prototype for the function you implemented in 
 * lab4_3_bst.c.
 */
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

#define	BST_FAIL	0		// return value when function fails
#define	BST_OK		1		// return value when function succeeds


// Prototypes for functions found in BST.C

int insertnodeBST(Key k, void *v, pNode root);

// Your function prototype goes here - addition so that insert to a BST can be done by passing
// a pTree parameter, not a pNode parameter. (See AVL code for a suggestion.)
// Create new node with key=k, value=v and insert it into tree
void insertBST (Key k, void *v, Tree *t);

//finished