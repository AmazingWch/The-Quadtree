#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"


int main( int argc, char **argv )
{
    add=0;
    re=0;
    num=0;
    p=0;
    Node *head;

    // make the head node
    head = makeNode( 0.0,0.0, 0 );

    // make a tree
    growtree(head);
    growtree(head);
    growtree(head);
    letsgo(head);
    check(head);
    printf("The number of add is %i\n",add);
    printf("The number of remove is %i",re);
    // print the tree for Gnuplot
    writeTree( head );

    return 0;
}
