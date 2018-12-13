#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"

Node *makeNode( double x, double y, int level )
{

    int i;

    Node *node = (Node *)malloc(sizeof(Node));

    node->level = level;

    node->xy[0] = x;
    node->xy[1] = y;

    for( i=0; i<4; ++i )
        node->child[i] = NULL;

    return node;
}

void growtree( Node *node ) {

  int i;

  if( node->child[0] == NULL )
    makeChildren(node);
  else {
    for ( i=0; i<4; ++i ) {
     growtree( node->child[i] );
    }
  }
  return;
}

