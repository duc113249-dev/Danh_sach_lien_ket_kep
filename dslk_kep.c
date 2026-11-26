#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *next, *prev;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}DList;
/////////////////////////////////////
void initList(DList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(DList L)
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(DList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->next = NULL;
    	pp->prev = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
        	L->pHead->prev=pp;
    		pp->next = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ten sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(DList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor);
        	pp = pp->next;
    	}
}
/////////////////////////////////////////
void insert_Tail(DList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->next = NULL;
    	pp->prev = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		L->pTail->next = pp;
    		pp->prev=L->pTail;
    		L->pTail = pp;
    		}
    	L->spt++;
}
/////////////////
void insert_After(DList *L, Node *q, Data x){
	Node *pp;
	if(NULL==q) return;
	else{
		pp = (Node*)malloc(sizeof(Node));
		pp->infor = x;
		pp->next = q->next;
		q->next->prev = pp;
		q->next = pp;
		pp->prev = q;
		if(q==L->pTail)L->pTail = pp;
		L->spt++;
	}
}
////////////////////////
void del_Head(DList *L){
	Node *pp;
	if(emptyList(*L))return;
	else{
		pp = L->pHead;
		L->pHead = pp->next;
		if(L->pHead==NULL)L->pHead->prev = NULL;
		free(pp);
		L->spt--;
		if(L->pHead==NULL)L->pTail= NULL;
	}
}
//////////////////////
void del_After(DList *L, Node *q){
	Node *pp;
	if(NULL==q)return;
	else{
		pp=q->next;
		q->next=pp->next;
		if(pp->next!= NULL) pp->next->prev=q;
		free(pp);
		L->spt--;
		if(NULL == L->pTail || pp == L->pTail)
		L->pTail=q;
	}
}
///////////////////////
void del_K(DList *L, char K[30]){
	Node *pp=L->pHead, *q;
	while(pp!=NULL && !strstr(pp->infor.hoten, K)){
		q=pp;
		pp=pp->next;
	}
	if(NULL==pp)return;
	else
	if(pp==L->pHead)del_Head(L);
	else del_After(L, q);
}
//////////////////
void LIFO(DList *L){
	Data x;
	initList(L);
	do{
		nhap(&x);
		if(x.masv!=0) insert_Head(L, x);
	}while(x.masv!=0);
}
//////////////
void FIFO(DList *L){
	Data x;
	initList(L);
	do{
		nhap(&x);
		if(x.masv!=0) insert_Tail(L, x);
	}while(x.masv!=0);
}
///////////
int main(){
    DList L;
	int kt = 0;
	Data x;
	initList(&L); //tao ra 1 ds rong
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Xoa nut o dau danh sach");
	    printf("\n5: Xoa nut o sau mot nut trong danh sach");
	    printf("\n6: Xoa nut theo ten");
	    printf("\n7: Tao danh sach kieu LIFO");
	    printf("\n8: Tao danh sach kieu FIFO");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thong tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
	            nhap(&x);
            	break;
            case 3:
	            printf("Nhap so thong tin sv can them\n");
	            if(x.masv > 0) 
                	insert_After(&L, L.pTail, x);
            	break;
            case 4: 
                if(emptyList(L)){
                	printf("Danh sach rong");
				}else{
					del_Head(&L);
					printf("Xoa nut dau\n");
				}
                break;
            case 5: 
                if(emptyList(L)){
                	printf("Danh sach rong");
				}else{
					del_After(&L, L.pTail);
					printf("Xoa nut dau\n");
				}
                break;
            case 6:
                if (emptyList(L)) {
                printf("Danh sach rong\n");
                } else {
                char K[30];
                printf("Nhap ten can xoa: ");
                scanf("%s", K);
                del_K(&L, K);
                printf("Da xoa\n");
                }
                break;
            case 7:
                LIFO(&L);
                printf("Da tao danh sach theo kieu LIFO\n");
                break;
            case 8:
                FIFO(&L);
                printf("Da tao danh sach theo kieu FIFO\n");
                break;
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}
