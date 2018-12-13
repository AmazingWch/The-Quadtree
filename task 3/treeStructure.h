#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int add;
int re;
int num;
int p;

// tree data structure

struct qnode
{
    int flag;
    int level;
    double xy[2];
    struct qnode *child[4];
};
typedef struct qnode Node;
