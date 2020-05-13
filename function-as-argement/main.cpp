#include <stdio.h>
#include <stdlib.h>

struct aa {
    int foo;
};

void *used1(void *arg){
    int *rt = (int *)malloc(sizeof(int *));
    *rt = *(int *)arg - 1;
    *(int *)arg = *rt;
    return rt;
}

void *to_use1(void *(*a)(void *), void *arg) {
    return a(arg);
}

int foo() {
    float i = 1.00123120211;
    return i;
}

typedef void *used2(void *);

void *to_use2(used2 *a, void *arg) {
    return a(arg);
}

int main(){
    int rt = 100;
    void *resp = to_use1(used1, &rt);
    printf("%d\n", *(int *)resp);
    printf("%d\n", rt);
    free(resp);

    void *resp2 = to_use2(used1, &rt);
    printf("%d\n", *(int *)resp2);
    printf("%d\n", rt);
    free(resp2);

//    void _;
//    void *a;
//    int *b;
//    float *c;
//    double *d;
//    int e;
//    float f;
//    double g;
//
//    a = b;
//    a = c;
//    a = d;
//    d = a;
//    d = b;
//    d = c;
//
//    e = f;
//    e = g;
//    g = e;
//    g = f;

    struct aa aaa;
    printf("%x %d %c %x\n",aaa,aaa,aaa,&aaa);
    struct aa bbb;
    printf("%x %d %c %x\n",bbb,bbb,bbb,&bbb);
    struct aa ccc;
    printf("%x %d %c %x\n",ccc,ccc,ccc,&ccc);
    struct aa ddd;
    printf("%x %d %c %x\n",ddd,ddd,ddd,&ddd);

    printf("%d\n", foo());
}