#ifndef INCLUDE_DLL_1

#define INCLUDE_DLL_1

//----------stack.cpp-----------------------------

typedef struct sdate {

         int tail;

         int leng;//この値はindexではなくデータの個数とする

         int* body;

} d_stack;

 

typedef struct s2date {

         int tail;

         int leng;//この値はindexではなくデータの個数とする

         int* body;

         int* index;

} d2_stack;

 

int s_push(d_stack* x,int input);

int s_pop(d_stack* x,int* result);

void is( d_stack* x, int* b, int l);

 

int s2_push(d2_stack* x,int input,int inputind);

int s2_pop(d2_stack* x,int* result,int* resultind);

void is2(d2_stack* x, int* b,int* i, int l);

//----------queue.cpp-----------------------------

typedef struct qdate {

         int head;

         int tail;

         int leng;

         int* body;

}d_queue;

 

typedef struct q2date {

         int head;

         int tail;

         int leng;

         int* body;

         int* index;

} d2_queue;

 

int q_put(d_queue* x,int input);

int q_get(d_queue* x,int* result);

void iq( d_queue* x, int* b, int l);

 

int q2_put(d2_queue* x,int input,int inputind);

int q2_get(d2_queue* x,int* result,int* resultind);

 void iq2( d2_queue* x, int* b,int* i, int l);

//----------priority_queue.cpp-------------------

typedef struct p_date {

         int size;

         int tail;

         int* body;

}d_prqueue;

 

typedef struct p2_date {

         int size;

         int tail;

         int* body;

         int* index;

} d2_prqueue;

 

int chmin(int a, int b);

int chmax(int a, int b);

void swap(int* x, int* y);

 

void make_heap(d_prqueue* x, int broad);

void remake_heap(d_prqueue* x, int broad);

int put_check(d_prqueue* x);

int get_check(d_prqueue* x);

int p_put(d_prqueue* x, int y);

int p_get(d_prqueue* x, int* y);

void ip(d_prqueue* x, int* b, int s);

 

void make2_heap(d2_prqueue* x, int broad);

void remake2_heap(d2_prqueue* x, int broad);

int put2_check(d2_prqueue* x);

int get2_check(d2_prqueue* x);

int p2_put(d2_prqueue* x, int y,int i);

int p2_get(d2_prqueue* x, int* y,int* i);

void ip2(d2_prqueue* x, int* b,int* i, int s);

#endif
