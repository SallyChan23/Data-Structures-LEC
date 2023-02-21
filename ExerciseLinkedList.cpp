#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
    char nama[50];
    int umur;
    struct data *next;
}*head = NULL, *tail = NULL;

// untuk reserve, inisialisasi, connect
struct data* newNode(char nama[], int umur){
    // reserve
    struct data *node = (struct data*) malloc(sizeof(struct data));
    // inisialisasi
    strcpy(node -> nama, nama);
    node -> umur = umur;
    node -> next = NULL;
    return node;
}

void printData(){
    struct data *curr = head;
    while(curr){ // curr != NULL
    printf("%s %d\n", curr -> nama, curr -> umur);
    curr = curr -> next;
    }

} 

// connect
void pushHead(char nama[], int umur){
    struct data *node = newNode(nama, umur);

    if(head == NULL)
        head = tail = node;
    else{
        node -> next = head;
        head = node;
    }
}



// 1. reserve
// 2. inisialisasi
// 3. connect

int main(){
    printf("Hello World");
    pushHead("Andi", 25);
    pushHead("Budi", 18);
    pushHead("Charlie", 15);
    pushHead("Eko", 15);
    printData();
    return 0;
}