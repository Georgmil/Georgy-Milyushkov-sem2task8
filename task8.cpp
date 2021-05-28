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

    if((root->value)%2 ==0){
        if(root->ves==0){
            printf("Net, est nulevoj ves u chetnoj vershini\n");
            *proverka=0;
            return;
        }
        else
            *proverka=1;
    }
    preorder(root->left,proverka);
    preorder(root->right,proverka);

}
void individ(treenode *root, int proverka){
    printf("\n\n");
    preorder(root,&proverka);
    if(proverka==1){
        printf("Da, vse chetnie vershini s nenulevim vesom");
}

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

int minimal_r(treenode *root){
    treenode *tmp=root;
    while((tmp->left)!=NULL){
        tmp=tmp->left;
    }
    return (tmp->value);
}

treenode *deletenode(treenode *root, int value){

    if(root==NULL)
        return NULL;

    if(root->value<value)
        root->right=deletenode(root->right,value);

    else if(root->value>value)
        root->left=deletenode(root->left,value);

    else{
        if(root->left==NULL && root->right==NULL){
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
            int rmin=minimal_r(root->right);
            root->value=rmin;
            root->right=deletenode(root->right,rmin);
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

void samo(treenode **root,int z){
    srand(z);
     int znachenie=printik_z();
            int vesik=printik_v();
            while(znachenie!=0){
            *root=insertnode(*root,znachenie,vesik);
                znachenie=printik_z();
                if(znachenie==0)
                    return;
                vesik=printik_v();}


}


