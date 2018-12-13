#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"

void makeChildren( Node *parent )
{

    double x = parent->xy[0];
    double y = parent->xy[1];

    int level = parent->level;

    double hChild = pow(2.0,-(level+1));

    parent->child[0] = makeNode( x,y, level+1 );
    parent->child[1] = makeNode( x+hChild,y, level+1 );
    parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
    parent->child[3] = makeNode( x,y+hChild, level+1 );

    return;
}

