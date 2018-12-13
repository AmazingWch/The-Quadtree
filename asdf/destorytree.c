#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"

void destorytree( Node *node )
{

    int i;

    if( node->child[0] == NULL )
    {
        free(node);
        node = NULL;
    }
    else
    {
        for ( i=0; i<4; ++i )
        {
            destorytree( node->child[i] );
            node->child[i] == NULL;
        }
        free(node);
        node = NULL;
    }
    return;
}
