#include <stdio.h>
#include <stdlib.h>
#include "task8.hpp"


#define Count 10




int main(){
    int proverka=1;
    treenode *root=NULL;

    int n=1;
    int z=1;
    while(n){
        printf("\n\n");
        printf("Chtobi sozdat randomno neskolkoko(vi reshaete skolkol) verhin nazmite 1:\n");
        printf("Chtobi smomu sozdat derevo ili dobavit samomu vershinu nazhmite 2:\n");
        printf("Chtobi udalit vershinu nazhmite 3:\n");
        printf("Chtobi udalit VSE derervo i nachat zanogo nazmite 10:\n");
        scanf("%d",&n);
        switch(n){
        case 1:
            int skolko;
            printf("Skolko randomno vershin budem sozdovat: ");
            scanf("%d",&skolko);
            srand(z);
            for(int i=0;i<skolko;i++)
                root=insertnode(root,rand(),rand()%3-1);
            printuem(root);
            individ(root,proverka);
            z++;
            break;
        case 2:
            samo(&root,z);
            printf("\n\n Resultat:");
            printuem(root);
            individ(root,proverka);
            z++;
            break;
        case 3:
            int del;
            printf("Kakuju vershinu buded udaljat:\n");
            scanf("%d",&del);
            deletenode(root,del);
            printf("Udalenie vipoloneno\n");
            printuem(root);
            individ(root,proverka);
            z++;
            break;

        case 10:
            root=NULL;
            printf("Udalenie vsego dereva viploneno\n");
            free(root);
            z++;
            break;

        }
    }



    return 0;
}
