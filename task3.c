#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int add=0;
int re=0;
int num=0;
int p=0;

// tree data structure

struct qnode
{
    int flag;
    int level;
    double xy[2];
    struct qnode *child[4];
};
typedef struct qnode Node;

// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void removeChildren( Node *parent );
void writeTree( Node *head );
void growtree( Node *node );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
double value( double x, double y, double time );
double nodeValue( Node *node, double time );
void letsgo(Node *node);
void check(Node *node);

// main

int main( int argc, char **argv )
{

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

// make a node at given location (x,y) and level

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

// split a leaf nodes into 4 children

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

double value( double x, double y, double time )
{

    return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

double nodeValue( Node *node, double time )
{

    int level = node->level;
    double x = node->xy[0];
    double y = node->xy[1];

    double h = pow(2.0,-level);

    return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function


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


void letsgo(Node *node)
{

    int i;
    double when=0.0;
    node->flag=0;

    if ( node->child[0] == NULL )
    {
        when = nodeValue(node, 0.0);
        if (when > 0.5)
        {
            node->flag=1;
        }
        else if (when < -0.5)
        {
            node->flag=-1;
        }
    }
//printf("%f",date);
    else
    {
        for ( i=0; i<4; ++i )
        {
            letsgo(node->child[i]);
        }

    }
    return;
}

void check(Node *node)
{
    int i;

    if (node->child[0]==NULL)
    {
        if (node->flag==1)
        {
            makeChildren(node);
            num+=1;
            add=num*4;
        }
    }
    else
    {
        if (node->child[0]->flag==-1&&node->child[1]->flag==-1&&node->child[2]->flag==-1&&node->child[3]->flag==-1)
        {
            removeChildren(node);
            p+=1;
            re=p*4;
            return;


        }
        for (i=0; i<4; ++i)
        {
            check(node->child[i]);
        }
    }
    return;
}




// write out the tree to file 'quad.out'

void writeTree( Node *head )
{

    FILE *fp = fopen("quad.out","w");

    writeNode(fp,head);

    fclose(fp);

    return;
}

// recursively visit the leaf nodes

void growtree( Node *node )
{

    int i;

    if( node->child[0] == NULL )
        makeChildren(node);
    else
    {
        for ( i=0; i<4; ++i )
        {
            growtree( node->child[i] );
        }
    }
    return;
}



// recursively visit the leaf nodes

void writeNode( FILE *fp, Node *node )
{

    int i;

    if( node->child[0] == NULL )
        printOut( fp, node );
    else
    {
        for ( i=0; i<4; ++i )
        {
            writeNode( fp, node->child[i] );
        }
    }
    return;
}

// write out the (x,y) corners of the node

void printOut( FILE *fp, Node *node )
{
    double x = node->xy[0];
    double y = node->xy[1];
    int level = node->level;
    double h = pow(2.0,-level);

    fprintf(fp, " %g %g\n",x,y);
    fprintf(fp, " %g %g\n",x+h,y);
    fprintf(fp, " %g %g\n",x+h,y+h);
    fprintf(fp, " %g %g\n",x,y+h);
    fprintf(fp, " %g %g\n\n",x,y);

    return;
}
