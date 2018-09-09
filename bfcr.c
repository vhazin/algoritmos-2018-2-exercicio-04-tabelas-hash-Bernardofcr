//
//  bfcr.c
//  Hazin pos prova
//
//  Created by Bernardo Russo on 06/09/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct chave{
    int id;
    int mod;
    struct chave *proximo;
}chaveIn;

typedef struct fila{
    int total;
    struct chave *primeiro;
    struct chave *ultimo;
}filaIn;


void addlista(struct fila *lista, int add, int mol){
    struct chave *novo;
    novo=malloc(sizeof(struct chave));
    novo->id=add;
    novo->mod=add%mol;
    novo->proximo=NULL;
    if (lista->primeiro==NULL){
        lista->primeiro=novo;
        lista->ultimo=novo;
        return;
    }
    lista->ultimo->proximo=novo;
    lista->ultimo=novo;
    return;
}

void dellista (struct fila *lista, int del){
    struct chave *ant=NULL,*aux;
    aux=lista->primeiro;
    while (aux==NULL){
        if (aux->id==del){
            if (ant==NULL)
                lista->primeiro=aux->proximo;
            lista->total=(lista->total)-1;
            
            return;
        }
        ant=aux;
        aux=aux->proximo;
    }
    return;
}

int main(void) {
    int n,i=0,j,k,add,count,l=0;
    struct chave *print;
    scanf("%d",&n);
    struct fila *lista[n];
    int m[n],c[n];
    while (i<n){
        lista[i]=malloc(sizeof(struct fila));
        scanf("%d %d",&m[i],&c[i]);
        lista[i]->total=c[i];
        for(j=0; j<c[i]; j++){
            scanf("%d ",&add);
            addlista(lista[i],add,m[i]);
        }
        i++;
    }
    while (l<n){
        for(k=0; k<m[l]; k++){
            print=lista[l]->primeiro;
            printf("%d -> ",k);
            count=0;
            while(count<=m[l]){
                if (print->mod==k){
                    printf("%d -> ",print->id);
                    //dellista(lista[l],print->id);
                }
                print=print->proximo;
                count++;
            }
            printf("\\\n");
        }
        l++;
    }
    return 0;
}
