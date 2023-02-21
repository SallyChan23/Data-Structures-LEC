#include <stdio.h>
#include <stdlib.h>
// single linked list
struct tnode{
    int value;
    struct node *next; // agar ke selanjutnya (seperti gerbong kereta, jadi ke gerbong selanjutnya di kereta)
};
struct tnode *head = 0; // 0 dengan null adalah sama
struct tnode *node = (struct tnode*) malloc (sizeof(struct tnode));
// node -> value = x;
// node -> next = head;
// head = node;

// PUSH (insert)
//1. Push head (depan)
// 2. push tail (di belakang)
// 3. push middle (selipin di tengah)
int main(){
    
    return 0;
}
