#ifndef TASK8_H_INCLUDED
#define TASK8_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


#define Count 10


typedef struct tree{

        int value;
        int ves;
        struct tree *left;
        struct tree *right;
    } treenode;


treenode *createnode(int value,int ves);
void printusha(tree *root, int probel);
void printuem(treenode *root);
treenode *insertnode(treenode *root, int value, int ves);
treenode *minimal_r(treenode *root);
treenode *deletenode(treenode *root, int value);
void preorder(treenode *root,int *proverka);
int printik_z();
int printik_v();
void samo(treenode **root,int z,int *proverka);
void individ(int *proverka);
void deltree(treenode *root);






#endif // TASK8_H_INCLUDED
