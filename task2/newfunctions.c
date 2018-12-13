#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"


void removeChildren( Node *parent )
{
    int i;
    for ( i=0; i<4; ++i )
    {
        free(parent->child[i]);
        parent->child[i] = NULL;
    }
    return;

}
