#include"lib_1.h"
int s_push(d_stack* x,int input) {

         if ((x->tail + 1) > (x->leng - 1)) {

                  return 0;

         }

         x->body[x->tail + 1] = input;

         x->tail++;

         return 1;

}

int s_pop(d_stack* x,int* result) {

         if (x->tail < 0) {

                  return 0;

         }

         *result = x->body[x->tail];

         x->tail--;

         return 1;

}

void is( d_stack* x, int* b, int l) {

         x->leng = l;

         x->tail = -1;

         x->body = b;

}

//-------------------------------------------------

int s2_push(d2_stack* x,int input,int inputind) {

         if ((x->tail + 1) > (x->leng - 1)) {

                  return 0;

         }

         x->body[x->tail + 1] = input;

         x->index[x->tail + 1] = inputind;

         x->tail++;

         return 1;

}

int s2_pop(d2_stack* x,int* result,int* resultind) {

         if (x->tail < 0) {

                  return 0;

         }

         *result = x->body[x->tail];

         *resultind = x->index[x->tail];

         x->tail--;

         return 1;

}

void is2( d2_stack* x, int* b, int* i, int l) {

         x->leng = l;

         x->tail = -1;

         x->body = b;

         x->index = i;

}
