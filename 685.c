#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int * parent; int * Dparent;
int find(int x) {
    if(parent[x] != x)
       { parent[x] = find(parent[x]); }
    return parent[x];
}

bool unionOp(int x, int y)
{   
    int pX = find(x);
    int pY = find(y);
    if(pX == pY){
        return false;
    }
    parent[pX] = pY;  
    return true;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    parent = (int *) malloc((edgesSize + 1)* sizeof(int));
    Dparent = (int *) malloc((edgesSize + 1)* sizeof(int));
    for(int i = 0; i <= edgesSize; i++)
    {
        parent[i] = i; //here it is -1
        Dparent[i] = -1;
    }

    int conflict = -1;
    int cycle = -1;
    *returnSize = 2;

    //int * result = (int *) malloc(2 * sizeof(int));
    int *edge1 = NULL, *edge2 = NULL;
    for(int i = 0; i < edgesSize; i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];

        if(Dparent[to] != -1)
            {conflict = i; 
            edge1 =(int*)malloc(2* sizeof(int));
            edge1[0] = Dparent[to];
            edge1[1] = to;
            edge2 =(int*)malloc(2* sizeof(int));
            edge2[0] = from;
            edge2[1] = to;
            }
        else {
            Dparent[to] = from;
            if(!unionOp(from, to))
            {
                cycle = i;
            }
        }           
    }

    if(conflict == -1){
        return edges[cycle];
        }
    if(cycle != -1)
        {
            return edge1;
        }
    
    return edge2;
}