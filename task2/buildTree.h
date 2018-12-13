#include "stdio.h"
#include "stdlib.h"
#include "math.h"


Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void removeChildren( Node *parent );
void writeTree( Node *head );
void growtree( Node *node );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
