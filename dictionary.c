#define HASHSIZE 101
#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct dict{
    struct dict *next;
    char *name;
    char *mean;
};

struct dict *hashtable[HASHSIZE];

unsigned hash(char *s){
    unsigned hashval;
    for(hashval=0;*s != '\0';s++)
        hashval = *s +31*hashval;
    return hashval%HASHSIZE;
}

struct dict *lookup(char *s){
    struct dict *np;
    for(np=hashtable[hash(s)];np != NULL;np=np->next){
        if(strcmp(s,np->name) == 0)
            return np;
        return NULL;
    }
}

void insert(char *name,char *defn){
    struct dict *ptr;
    unsigned hashval;
    if(lookup(name) == NULL){
        ptr=(struct dict *)malloc(sizeof(struct dict));
        hashval=hash(name);
        strcpy(ptr->name,name);
        ptr->next = hashtable[hashval];
        hashtable[hashval] = ptr;
    }
}

int main(){
    //insert("a","b");
    //struct dict *ptr=lookup("a");
   // printf("%s",ptr->name);
    return 0;
}
