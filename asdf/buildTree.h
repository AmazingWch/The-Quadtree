#include "stdio.h"
#include "stdlib.h"
#include "math.h"

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
void growtree( Node *node );
void destorytree( Node *node );
