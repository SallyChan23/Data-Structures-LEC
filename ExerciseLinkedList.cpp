#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
    char nama[50];
    int umur;
    struct data *next;
}*head = NULL, *tail = NULL;

// 1. reserve
// 2. inisialisasi
// 3. connect


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

void pushTail(char nama[], int umur){
    struct data *node = newNode(nama, umur);
    if(head == NULL){
        head = tail = NULL;
    }else{
        tail -> next = node;
        tail = node;
    }
}

// delete (pop)
// pop head
// pop middle
// pop tail

void popHead(){
    if(head){
        struct data *curr = head;
        if (head == tail){
            head = tail = NULL;
        }else{
            head = head -> next;
        }
        free(curr);
    }else{
        printf("Tidak ditemukan\n");
    }
}

void popTail(){
    if(head){
        struct data *curr = head;
        if(head == tail){
            head = tail = NULL;
        }else{
            while(curr -> next != tail)
                curr = curr -> next;
            tail = curr;
            curr = curr -> next;
            tail -> next = NULL;
        }
        free(curr);
    }else  
        puts("Data not found");
}


int main(){
    pushHead("Andi", 25);
    pushHead("Budi", 18);
    pushHead("Charlie", 15);
    pushHead("Eko", 15);
    pushTail("Binu", 20);
    pushTail("Zara", 90);
    printData();

    puts("--------------");
    popHead();
    printData();

    puts("--------------");
    popHead();
    printData();

    puts("--------------");
    popTail();
    printData();

    puts("---------------");
    popTail();
    printData();
    return 0;
}