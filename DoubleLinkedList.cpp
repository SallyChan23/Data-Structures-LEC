#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	char nama[50];
	int umur;
	
	struct data *next, *prev;
} *head = NULL, *tail = NULL;

struct data* newNode(char nama[], int umur){
	// 1) Reserve
	struct data *node = (struct data*)malloc(sizeof(data));
	// 2) Inisialisasi
	strcpy(node->nama, nama);
	node->umur = umur;
	node->next = NULL;
	node->prev = NULL;
	
	return node;	
}

// 3) Connect
void pushHead(char nama[], int umur){
	struct data *node = newNode(nama, umur);
	if(!head){ // if(head == NULL)
		head = tail = node;
	}
	else{
		node -> next = head;
		head -> prev = node;
		head = node;
	}
}

void pushTail(char nama[], int umur){
	struct data *node = newNode(nama, umur);
	if(!head){
		head = tail = node;
	}
	else{
		tail -> next = node;
		node -> prev = tail;
		tail = node;
	}
}

void pushMid(char nama[], int umur){
	// priority queue by umur
	if(!head || umur > head->umur){
		pushHead(nama, umur);
	}
	else if(umur <= tail->umur){
		pushTail(nama, umur);
	}
	else{
		struct data *curr = head;
		while(curr->next->umur >= umur){
			curr = curr->next;
		}
		struct data *node = newNode(nama, umur);
		node->prev = curr;
		node->next = curr->next;
		curr->next->prev = node;
		curr->next = node;	
	}
}

void popHead(){
	if(head){ 
		struct data *curr = head;	//data curr sebagai head
		if(head == tail){ //kalau head = tail yg artinya nodenya cuman ada satu, langsung dihapus aja trus di null in	
			head = tail = NULL;
		}
		else{	//kalau node nya lebih dari satu
			head = head -> next;
			head -> prev = NULL;
		}
		free(curr); //hapus curr;
	}
	else{ // Optional
		printf("Tidak ada data\n");
	}
	
}

void popTail(){
	if(head){ 
		struct data *curr = tail;	//data curr sebagai head
		if(head == tail){ //kalau head = tail yg artinya nodenya cuman ada satu, langsung dihapus aja trus di null in	
			head = tail = NULL;
		}
		else{	//kalau node nya lebih dari satu
			tail = tail -> prev;
			tail -> next = NULL;
		}
		free(curr); //hapus curr;
	}
	else{ // Optional
		printf("Tidak ada data\n");
	}
	
}

void printData(){
	struct data *curr = head;
	
	while(curr){	//curr != NULL
		printf("%s %d\n", curr->nama, curr->umur);
		curr = curr -> next;
	}
}

int main(){
	
	pushMid("Andi", 25);
	pushMid("Budi", 18);
	pushMid("Charlie", 15);
	pushMid("Eko", 22);
	pushMid("Doni", 30);
	pushMid("Fifi", 11);
	
	printData();
	
	printf("\nPop Head : \n");
	
	popHead();
	printData();
	
	printf("\nPop Head : \n");
	popHead();
	printData();
	
	printf("\nPop Head : \n");
	popHead();
	printData();
	
	printf("\nPop Head : \n");
	popHead();
	printData();
	
	return 0;
}