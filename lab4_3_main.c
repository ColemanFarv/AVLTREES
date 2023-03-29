#include <stdio.h>
#include <time.h>
#include "bintree.h"
#include "lab4_3_avl.h"
#include "lab4_3_bst.h"

void panic(char *msg, char *fname)
// Function to display error message on stderr and exit program.
// First parameter is error message; second is optional, and if present,
// is supplemental information.
{
	fprintf (stderr, "ERROR: %s %s\n",
			msg==NULL ? "Unknown!" : msg,
			fname==NULL ? "" : fname);
	fprintf (stderr, "       Program terminating\n");
	exit (-1);
}// panic()

int main(int argc, char *argv[])
{
    float bstTime;
    float AVLTime;
	int		v1 = 1;
	char	*fname;			// name of input file
	FILE	*finn;			// used to input data file
	int		i, j, readcount;
	int		lastkeys[10], lastkeyindex;
	Tree	*t_avl;			// pointer to AVL tree descriptor
	Tree	*t_bst;			// pointer to BST tree descriptor
	int		gabby = 1;		// flag whether we should generate lots of output
	int		defaultdata;
	int		count;			// count number of insertions
	pNode	foundnode;
	clock_t	start, end, deltaBST, deltaAVL;

	fprintf (stderr, "Compare BST and AVL Trees.\n");
	// set up descriptor to be used for AVL tree
	t_avl = initTree(AVL);

	if (t_avl == NULL)	{
		panic ("Failed to initialize AVL tree descriptor.", NULL);
	}
	// set up descriptor to be used for BST tree
	t_bst = initTree(BST);
	if (t_bst == NULL)	{
		panic ("Failed to initialize BST tree descriptor.", NULL);
	}
	if (argc == 2)	{
		// Looks like user has specified an input file on command line. Assume
		// there is lots of data and output should be small.
		fname = argv [1];
		gabby = 0;
		defaultdata = 0;
	} else	{
		// use default input file
		fname = "data_a.txt";
		defaultdata = 0;
	}
	fprintf (stderr, " -- Using input file: %s\n", fname);
	finn = fopen (fname, "r");
	if (finn == NULL)	{
		// something wrong - could not open file
		panic ( "Cannot open file:", fname);
	}
	// Insert each data value from file, and after inserting, output some
	// information about what the tree looks like. For the first part of
	// the lab, you just want to use the default input file.
	lastkeyindex = 0;
	for (count=0;;count++)	{
		// Read value from file
		readcount = fscanf (finn, "%d", &i);
		// Failure to read or negative number means end of list
		if ((readcount < 1) || (i < 0))	break;
		// Insert value into AVL tree (Note we're using a fake data value
		insertAVL(i, NULL, t_avl);


		if (gabby)	{
			printf("Inorder AVL: ");
			inOrderT(t_avl->root);
			printf("\n-------\n");


		} else	{
			// This is the terse output when a large file is being read
			printf ("%7d: %11d\n", count, i);
		}

		// Your code to populate BST goes here
		//---<SNIP>---

        insertBST(i, NULL, t_bst); //inserts value into binary tree
        if (gabby)	{

            //prints out the binary search tree in order
            printf("Inorder BSt: ");
            inOrderT(t_bst->root);
            printf("\n-------\n");

        } else	{
            // This is the terse output when a large file is being read
            printf ("%7d: %11d\n", count, i);
        }
		//---</SNIP>---

		// keep track of last key inserted
		lastkeys [lastkeyindex] = i;
		if (++lastkeyindex > 9)	lastkeyindex = 0;
	}
	// Close file
	fclose (finn);


    //priny the AVL and BST tree

    printf("Print AVL tree: \n");

    printTree(t_avl->root);

    printf("\n");

    printf("Print BST tree: \n");

    printTree(t_bst->root);


    // Note we have last key inserted. We are going to use this to test
	// lookup performance using finds
	if (!defaultdata)	{
		// Your code to test BST goes here
		//---<SNIP>---
        start = clock();
        for (i=0; i<1000000; i++) {
            for (j=0; j<10; j++) {
                foundnode = find (lastkeys[j], t_bst->root);
                if (foundnode == NULL)	{
                    fprintf (stderr, "ERROR: AVL Could not find %d iteration %d\n",
                             lastkeys[j], i);
                    return -1;
                }//endif
            }//endfor
        }//endfor
        end = clock();
        printf("\nBST Elapsed time: %.2f seconds (%d ticks)\n",
               (end - start) / (double)(CLOCKS_PER_SEC), (end-start));

         bstTime =  (end - start) / (double)(CLOCKS_PER_SEC); //finds the time of the bst search

		//---</SNIP>---

		start = clock();
		for (i=0; i<1000000; i++) {
			for (j=0; j<10; j++) {
				foundnode = find (lastkeys[j], t_avl->root);
				if (foundnode == NULL)	{
					fprintf (stderr, "ERROR: AVL Could not find %d iteration %d\n",
							lastkeys[j], i);
					return -1;
				}//endif
			}//endfor
		}//endfor
		end = clock();
		printf("\nAVL Elapsed time: %.2f seconds (%d ticks)\n",
				(end - start) / (double)(CLOCKS_PER_SEC), (end-start));

        AVLTime =  (end - start) / (double)(CLOCKS_PER_SEC); //finds time of AVL search
	}//endif check timing

    printf("\nDiffernce in search time between AVL and bST data trees is %.2f seconds", bstTime-AVLTime); //Prints the time difference between AVL and bst search

	return 0;
}//main()

//finished fin