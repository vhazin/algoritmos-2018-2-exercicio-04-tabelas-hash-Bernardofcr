//
//  main.c
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
};

int checar (int chave,int m){
    int count;
    int saida;
    saida=chave%m;
    return saida;
}

void addlista(struct fila *lista, int add,int m){
    struct chave *novo=(chaveIn*)malloc(sizeof(struct chave));
    novo->id=add;
    novo->mod=checar(add,m);
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

int main(void) {
    int n,m,c,i=0,j=0,add,count=0;
    struct fila *lista, *saida;
    struct chave *print;
    lista=malloc(sizeof(struct fila));
    saida=malloc(sizeof(struct fila));
    scanf("%d",&n);
    while (i<=n){
        scanf("%d %d",&m,&c);
        while(j<=c){
            scanf("%d",add);
            addlista(lista,add,m);
            j++;
        }
        print=lista->primeiro;
        for(j=0;j<c;j++){
            printf("%d -> ",j);
            count=c;
            while (count--){
                if (print->mod==j)
                    printf("%d ",print->id);
                else
                    printf("//");
            }
            print=print->proximo;
        }
        i++;
    }
    
}
