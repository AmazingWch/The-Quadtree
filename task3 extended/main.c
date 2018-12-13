#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"

int main( int argc, char **argv )
{

    Node *head;

    // make the head node
    head = makeNode( 0.0,0.0, 0 );

    // make a tree
    growtree(head);
    growtree(head);
    growtree(head);
    adapt(head);
    // print the tree for Gnuplot
    writeTree(head);

    return 0;
}
