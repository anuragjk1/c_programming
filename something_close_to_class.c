#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1


typedef struct n{
    struct n* self;
    int a;
    int b;
    int c;
    int (*add)(struct n*);
    int (*sub)(struct n*);
    void (*print)(struct n*);
} num;

int add (num *st){
    st->c = st->a + st->b; 
    return(st->c);
}
int sub(num *st){
    st->c = st->a - st->b; 
    return(st->c);
}
void print(num* st){
    printf("%d\n",st->c);
}

num* init_num(){
    num* var = calloc(1,sizeof(num));
    
    var->add = add;
    var->sub = sub;
    var->print = print;
    
    return var;
}

int main(){
    int x;
    
    num *var=init_num();
    
    var->a = 13;
    var->b = 53;
    
    x = var->add(var);
    var->print(var);
    printf("%d\n", x);
}
