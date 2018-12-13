#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"

int add;
int re;
int num;
int p;

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

    int maxlevel = 6;

    if (node->child[0]==NULL)
    {
        if (node->flag==1&&node->level<maxlevel)
        {
            makeChildren(node);
            //num+=4;
            //add=num*4;
            add+=4;
        }
    }
    else
    {
        if (node->child[0]->flag==-1&&node->child[1]->flag==-1&&node->child[2]->flag==-1&&node->child[3]->flag==-1)
        {
            removeChildren(node);
            //p+=;
            //re=p*4;
            re+=4;
            return;
        }
        for (i=0; i<4; ++i)
        {
            check(node->child[i]);
        }
    }
    return;
}

void adapt (Node *head)
{
    add=1;
    while (add!=0||re!=0)
    {
        add=0;
        re=0;
        letsgo(head);
        check(head);
        printf("add number is %i\n",add);
        printf("remove number is %i\n",re);
    }
    return;
}


