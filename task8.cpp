#include "task8.hpp"


treenode *createnode(int value,int ves){
    tree* result=(tree*)malloc(sizeof(treenode));
    if(result!=NULL){
        result->left=NULL;
        result->right=NULL;
        result->value=value;
        result->ves=ves;

    }
    return result;
}



void preorder(treenode *root,int *proverka){
    if(root==NULL)
        return;

    if((root->value)%2==0){
        if(root->ves==0){
            *proverka=0;
            return;
        }
    }
    preorder(root->left,proverka);
    preorder(root->right,proverka);

}
void individ(int *proverka){
    printf("\n\n");
    if(*proverka==0){
        printf("indinvidualnoe zadanie: NET\n");
        *proverka=1;
    }
    else
        printf("Indinvualnoe zadanie: DA\n");

}


void printusha(tree *root, int probel){
    if(root==NULL)
        return;

    probel=probel+ Count;
    printusha(root->right,probel);

    printf("\n");
    for(int i=Count;i<probel;i++)
        printf(" ");
    printf("%d",root->value);
    printf("(%d)\n",root->ves);


    printusha(root->left,probel);

}

void printuem(treenode *root){
    printusha(root,0);
}


treenode *insertnode(treenode *root, int value, int ves){
    if(root==NULL)
        return createnode(value,ves);

    if(root->value<value)
        root->right=insertnode(root->right,value,ves);

    else if(root->value>value)
        root->left=insertnode(root->left,value,ves);


    return root;

}

treenode *minimal_r(treenode *root){
    treenode *tmp=root;
    while((tmp->left)!=NULL){
        tmp=tmp->left;
    }
    return (tmp);
}



treenode *deletenode(treenode *root, int value){

    if(root==NULL)
        return NULL;

    if(root->value<value)
        root->right=deletenode(root->right,value);

    else if(root->value>value)
        root->left=deletenode(root->left,value);

    else{
        if((root->left==NULL) && (root->right==NULL)){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            treenode *tmp=root->right;
            free(root);
            return tmp;
        }
        else if(root->right==NULL){
            treenode *tmp=root->left;
            free(root);
            return tmp;
        }
        else{
            //int rmin=minimal_r(root->right);
            root->value=minimal_r(root->right)->value;
            root->ves=minimal_r(root->right)->ves;
            root->right=deletenode(root->right,minimal_r(root->right)->value);
        }

    }
    return root;


}




int printik_z(){
    int znachenie;
    printf("Kakoe znachenie dobavit (znachenie 0 oznachaet ostanovit dobavlenie)?\n:");
    scanf("%d",&znachenie);
    return znachenie;
}

int printik_v(){
    int vesik;
    printf("Kakoj ves?\n:");
    scanf("%d",&vesik);
    return vesik;
}

void samo(treenode **root,int z,int *proverka){
    srand(z);
     int znachenie=printik_z();
            int vesik=printik_v();
            if(vesik==0 &&znachenie%2==0)
                *proverka=0;
            while(znachenie!=0){
            *root=insertnode(*root,znachenie,vesik);
                znachenie=printik_z();
                if(znachenie==0)
                    return;
                vesik=printik_v();
                if(vesik==0 &&znachenie%2==0)
                *proverka=0;}


}

void deltree(treenode *root){
    if (root == NULL)
        return;

    deltree(root->left);
    deltree(root->right);
    free(root);
}

