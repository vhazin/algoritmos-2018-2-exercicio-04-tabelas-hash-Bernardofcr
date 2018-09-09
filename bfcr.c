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
    struct chave *proximo;
}chaveIn;

typedef struct fila{
    int total;
    struct chave *primeiro;
    struct chave *ultimo;
}filaIn;


void addlista(filaIn *lista, int add){
    chaveIn *novo;
    novo=(chaveIn*)malloc(sizeof(chaveIn));
    novo->id=add;
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
            free(aux);
            return;
        }
        ant=aux;
        aux=aux->proximo;
    }
    return;
}

int main(void) {
    int n,i=0,j,k,add,count,l=0,mol;
    scanf("%d",&n);
    filaIn *lista[n];
    chaveIn *print[n];
    int m[n],c[n];
    while (i<n){
        lista[i]=malloc(sizeof(filaIn));
        print[i]=malloc(sizeof(chaveIn));
        scanf("%d %d",&m[i],&c[i]);
        lista[i]->total=c[i];
        j=c[i];
        while(j--){
            scanf("%d",&add);
            addlista(lista[i],add);
        }
        i++;
    }
    while (l<n){
        if (l!=0)
            printf("\n");
        k=0;
        while (k<m[l]){
            print[l]=lista[l]->primeiro;
            printf("%d -> ",k);
            count=c[l];
            while(count--){
                mol=(print[l]->id)%m[l];
                if (mol==k){
                    printf("%d -> ",print[l]->id);
                    dellista(lista[l],print[l]->id);
                }
                print[l]=print[l]->proximo;
            }
            printf("\\\n");
            k++;
        }
        l++;
    }
    return 0;
}
