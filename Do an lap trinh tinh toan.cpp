#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
	char masosach[10];
	char tensach[50];
	char tentacgia[50];
	int namxuatban;
	bool trangthaisach;
	char nhaxuatban[100];
};
typedef struct Book BOOK;
struct BookNode{
   	struct Book data;
   	struct BookNode*pNext;
};
typedef struct BookNode *BOOKNODE;
struct List{
	BOOKNODE pHead,pTail;
};
typedef struct List LIST;
void Init(LIST *l)
{
	l->pHead=NULL;
	l->pTail=NULL;
}
BOOKNODE CreateBook(BOOK p)
{
	BOOKNODE temp=(BOOKNODE)malloc(sizeof(struct BookNode));
	temp->data=p;
	temp->pNext=NULL;
	return temp;
}
void InsertFirst(LIST*l,Book p)
{
	BOOKNODE temp=CreateBook(p);
	if(l->pHead==NULL)
	{
		l->pHead=l->pTail=temp;
	}
	else
	{
		temp->pNext=l->pHead;
		l->pHead=temp;
	}
}
BOOK tao1cuonsach()
{
	BOOK p;
		printf("\nMoi ban nhap sach:");
	    printf("\nNhap ma so sach:");
	    fflush(stdin);
	    gets(p.masosach);
	    printf("Nhap ten sach:");
	    fflush(stdin);
	    gets(p.tensach);
	    printf("Nhap nam xuat ban:");
	    fflush(stdin);
	    scanf("%d",&p.namxuatban);
	    printf("Nhap ten tac gia:");
	    fflush(stdin);
	    gets(p.tentacgia);
	    printf("Nhap nha xuat ban:");
	    fflush(stdin);
	    gets(p.nhaxuatban);
	    p.trangthaisach=true;
	    return p;
}
void InsertLast(LIST*l,Book p)
{
		
	BOOKNODE temp=CreateBook(p);		
	if(l->pHead==NULL)
	{
		l->pHead=l->pTail=temp;
	}
	else
	{
		l->pTail->pNext=temp;
		l->pTail=temp;
	}
}
void InsertAfter(LIST*l,BOOKNODE p,BOOKNODE k)//them sach k dang sau sach p
{
	if(p==l->pHead){
	InsertFirst(l,p->data);
    return;
	}
	if(p==l->pTail){
		InsertLast(l,p->data);
		return;
	}
	BOOKNODE temp;
    for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
    {
    	if(q==p)
    	{
    		k->pNext=q->pNext;
    		q->pNext=k;
		}
	}
}
void deleteFirst(LIST*l) 
{
	BOOKNODE temp=l->pHead;
	l->pHead=l->pHead->pNext;
	free(temp);
}
void deleteLast(LIST*l)
{
	BOOKNODE temp=NULL;
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		if(q==l->pTail)
		{
			temp->pNext=NULL;
			l->pTail=temp;
		}
		temp=q;
	}
}

void xoatheomasosach(LIST*l,char masosach[])
{
	if(strcmp(masosach,l->pHead->data.masosach)==0){
	deleteFirst(l);
	}
	if(strcmp(masosach,l->pTail->data.masosach)==0){
	deleteLast(l);
	}
	BOOKNODE temp=NULL;
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		
		if(strcmp(q->data.masosach,masosach)==0)
		{
			temp->pNext=q->pNext;
			return;
		}
		temp=q;
	}

}
void xoa1cuonsachtheosau1cuon(LIST*l,char masosach[])
{
	BOOKNODE temp=NULL;
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		
		if(strcmp(q->data.masosach,masosach)==0)
		{
			q->pNext=(q->pNext)->pNext;
			return;
		}
	}
}
void xoatheotensach(LIST*l,char tensach[])
{
	if(strcmp(tensach,l->pHead->data.tensach)==0){
	deleteFirst(l);
	}
	if(strcmp(tensach,l->pTail->data.tensach)==0){
	deleteLast(l);
	}
	BOOKNODE temp=NULL;
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		if(strcmp(q->data.tensach,tensach)==0)
		{
			temp->pNext=q->pNext;
			return;
		}
		temp=q;
	}
}
void xoatheotentacgia(LIST*l,char tentacgia[])
{
	if(strcmp(tentacgia,l->pHead->data.tentacgia)==0){
	deleteFirst(l);
	}
	if(strcmp(tentacgia,l->pTail->data.tentacgia)==0){
	deleteLast(l);
	}
	BOOKNODE temp=NULL;
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		if(strcmp(q->data.tentacgia,tentacgia)==0)
		{
			temp->pNext=q->pNext;
			return;
		}
		temp=q;
	}
}

void nhapsach(LIST*l)
{
        while(1)
        {
		BOOK p=tao1cuonsach();
	    InsertLast(l,p);
	   printf("Nhan 0 de thoat chuc nang nhap sach. Nhan 1 de tiep tuc nhap:");
	   int pr;
	   scanf("%d",&pr);
	   if(pr==0)
	   break;
	 }
}
void xoa1cuonkhoidanhsach(LIST *l)
{
	printf("\n----MENU-----\n");
	printf("\n1.Xoa theo ma so:");
	printf("\n2.Xoa theo ten sach:");
	printf("\n3.Xoa theo ten tac gia:");
	printf("\n4.Xoa cuon dau danh sach:");
	printf("\n5.Xoa cuon cuoi danh sach:");
	printf("\n6.Xoa 1 cuon theo sau 1 cuon co ma so nao do:");
	int n;
	printf("\nNhap chuc nang:");
	scanf("%d",&n);
	if(n==4)
	deleteFirst(l);
	if(n==5)
	deleteLast(l);
	if(n==1)
	{
		char masosach[100];
		printf("\nNhap ma so can xoa:");
		fflush(stdin);
		gets(masosach);
		xoatheomasosach(l,masosach);
	}
	if(n==2)
	{
		char tensach[100];
		fflush(stdin);
		printf("\nNhap ten sach can xoa:");
		gets(tensach);
		xoatheotensach(l,tensach);
	}
	if(n==3)
	{
		char tacgia[100];
		int dem=0;
		printf("\nNhap ten tac gia can xoa:");
		fflush(stdin);
		gets(tacgia);
		for(BOOKNODE p=l->pHead;p!=NULL;p=p->pNext)
		{
			if(strcmp(p->data.tentacgia,tacgia)==0)
			dem++;
		}
		while(dem--)
		xoatheotentacgia(l,tacgia);
	}
	if(n==6)
	{
	   	char masosach[100];
	   	printf("Nhap ma so sach can xoa:");
	   	fflush(stdin);
		gets(masosach);
		xoa1cuonsachtheosau1cuon(l,masosach);
	}	
}
//Muon sach
void muonsach(LIST*l)
{
	char masosach[100];
	printf("Nhap ma so sach can muon:");
	fflush(stdin);
	gets(masosach);
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		if(strcmp(q->data.masosach,masosach)==0)
		{
			q->data.trangthaisach=false;
		}
	}
}
void trasach(LIST*l)
{
	char masosach[100];
	printf("Nhap ma so sach can tra:");
	fflush(stdin);
	gets(masosach);
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		if(strcmp(q->data.masosach,masosach)==0)
		{
			q->data.trangthaisach=true;
		}
	}
}

void output(LIST*l)
{
	int i=1;
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		printf("\nSach %d:\n",i++);
		printf("\nTen sach la:%s",q->data.tensach);
		printf("\nMa so sach la:%s",q->data.masosach);
		printf("\nNam xuat ban cua sach la:%d",q->data.namxuatban);
		printf("\nTen tac gia la:%s",q->data.tentacgia);
		printf("\nNha xuat ban la:%s",q->data.nhaxuatban);
		if(q->data.trangthaisach==true)
		printf("\nTrang thai sach:chua muon");
		else
		printf("\nTrang thai sach:da cho muon");
	}
}
void in1cuonsach(LIST*l,BOOKNODE q)
{
	      printf("\nTen sach la:%s",q->data.tensach);
		  printf("\nMa so sach la:%s",q->data.masosach);
		  printf("\nNam xuat ban cua sach la:%d",q->data.namxuatban);
		  printf("\nNha xuat ban la:%s",q->data.nhaxuatban);
		  printf("\nTen tac gia la:%s",q->data.tentacgia);
		  if(q->data.trangthaisach==true)
		  printf("\nTrang thai sach:chua muon");
		  else
		  printf("\nTrang thai sach:da cho muon");
}
void timsach(LIST*l)
{
	printf("----MENU-----\n");
	printf("\n1.Tim sach theo ten tac gia:");
	printf("\n2.Tim sach theo ten sach:");
	printf("\n3.Tim sach theo ten nha xuat ban:");
	printf("\nNhap chuc nang:");
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("\nNhap ten tac gia can tim:");
		char tentacgia[100];
		fflush(stdin);
		gets(tentacgia);
		for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
		{
		   if(strcmp(q->data.tentacgia,tentacgia)==0)
    	    in1cuonsach(l,q);
		}
	}
	if(n==2)
	{
		printf("\nNhap ten sach can tim:");
		char tensach[100];
		fflush(stdin);
		gets(tensach);
		for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
		{
		   if(strcmp(q->data.tensach,tensach)==0)
    	    in1cuonsach(l,q);
		}
	}
	if(n==3)
	{
		printf("\nNhap ten nha xuat ban can tim:");
		char nhaxuatban[100];
		fflush(stdin);
		gets(nhaxuatban);
		for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
		{
		   if(strcmp(q->data.nhaxuatban,nhaxuatban)==0)
    	    in1cuonsach(l,q);
		}	
	}
	
}
// ham hoan vi 2 sach
void hoanvi(BOOK*x,BOOK *y)
{
	BOOK temp =*x;
	*x=*y;
	*y=temp; 
}
//ham xem sach
void xemsach(LIST*l)
{
	printf("\n1.Xem toan bo muc co trong danh sach:");
	printf("\n2.Xem toan bo cuon sach dang cho muon:");
	printf("\n3.Xem nhung cuon chua cho muon:");
	printf("\n4.Xem sach theo thu tu:");
	int n;
	printf("\nNhap lua chon:");
	scanf("%d",&n);
	if(n==1)
	output(l);
	else if(n==2)
	{
		int check=0;
		for(BOOKNODE p=l->pHead;p!=NULL;p=p->pNext)
		{
			if(p->data.trangthaisach==false)
			{
			in1cuonsach(l,p);
			check=1;
			}
		}
		if(check==0)
		printf("\nKhong co cuon nao dang cho muon");
	}
	else if(n==3)
	{
		int check=0;
		for(BOOKNODE p=l->pHead;p!=NULL;p=p->pNext)
		{
			if(p->data.trangthaisach==true)
			{
			in1cuonsach(l,p);
			check=1;
			}
		}
		if(check==0)
		printf("\nTat ca cac sach da duoc cho muon");
	}
	else if(n==4)
	{
		printf("\n1.Xem theo thu tu alphabet cua ten sach:");
		printf("\n2.Xem theo thu tu alphabet cua ten tac gia:");
		printf("\n3.Xem theo thu tu alphabet cua nha xuat ban:");
		printf("\n4.Xem sach theo cac nam xuat  ban moi nhat:");
		int k;
		printf("Nhap chuc nang:");
		scanf("%d",&k);
		if(k==1)
		{
		for(BOOKNODE i=l->pHead;i!=l->pTail;i=i->pNext)
		{
			for(BOOKNODE j=i->pNext;j!=NULL;j=j->pNext)
			{
				if(strcmp(i->data.tensach,j->data.tensach)>0)
				hoanvi(&i->data,&j->data);
			}
		}
	    }
	    if(k==2)
		{
		for(BOOKNODE i=l->pHead;i!=l->pTail;i=i->pNext)
		{
			for(BOOKNODE j=i->pNext;j!=NULL;j=j->pNext)
			{
				if(strcmp(i->data.tentacgia,j->data.tentacgia)>0)
				hoanvi(&i->data,&j->data);
			}
		}
	    }
	    if(k==3)
	    {
	    	for(BOOKNODE i=l->pHead;i!=l->pTail;i=i->pNext)
		{ 
			for(BOOKNODE j=i->pNext;j!=NULL;j=j->pNext)
			{
				if(strcmp(i->data.tentacgia,j->data.tentacgia)>0)
				hoanvi(&i->data,&j->data);
		     }
       	}
        }
        if(k==4)
        {
        	for(BOOKNODE i=l->pHead;i!=l->pTail;i=i->pNext)
		{ 
			for(BOOKNODE j=i->pNext;j!=NULL;j=j->pNext)
			{
				if(i->data.namxuatban<j->data.namxuatban)
				hoanvi(&i->data,&j->data);
		     }
       	}
		}
		output(l);   
}
}
void chinhsuasach(LIST*l)
{
	char mss[20];
	printf("\nNhap vao ma so sach cua sach can chinh sua:");
	fflush(stdin);
	gets(mss);
	for(BOOKNODE q=l->pHead;q!=NULL;q=q->pNext)
	{
		if(strcmp(q->data.masosach,mss)==0)
		{
			printf("\nNoi dung cu:\n");
			in1cuonsach(l,q);
			printf("\nChon noi dung can chinh sua:\n");
			printf("\n1.Ten sach");
		  	printf("\n2.Ma so sach");
		  	printf("\n3.Nam xuat ban cua sach");
		  	printf("\n4.nNha xuat ban");
		 	printf("\n5.Ten tac gia");
		 	printf("\n6.Trang thai sach");
			while(1)
			{
		 	int choose;
		 	printf("\nNhap lua chon:");
		 	scanf("%d",&choose);
		 	if(choose==1)
		 	{
		 	fflush(stdin);
		 	printf("\nNhap ten sach moi:");
		 	gets(q->data.tensach);
		    }
		 	if(choose==2)
		 	{
		 	fflush(stdin);
		 	printf("\nNhap ma so sach moi:");
		 	gets(q->data.masosach);
		 	}
		 	if(choose==3)
		 	{
		 	printf("\nNhap nam xuat ban moi:");
		 	scanf("%d",&q->data.namxuatban);
		 	}
		 	if(choose==4)
		 	{
		 	fflush(stdin);
		 	printf("\nNhap nha xuat ban moi:");
		 	gets(q->data.nhaxuatban);
		 	}
		 	if(choose==5)
		 	{
		 	fflush(stdin);
		 	printf("\nNhap ten sach moi:");
		 	gets(q->data.tentacgia);
		 	}
		 	if(choose==6)
		 	q->data.trangthaisach=!(q->data.trangthaisach);
		int ctn;
		printf("\nNhan 0 de dung chinh sua, nhan 1 de tiep tuc:");
		scanf("%d",&ctn);
		if(ctn==0)
		break;
		}
		}
	}
}
void luufile(FILE*output,LIST l)
{
		output=fopen("output.TXT","w");
		for(BOOKNODE q=l.pHead;q!=NULL;q=q->pNext)
		{
		  fprintf(output,"\nTen sach la:%s",q->data.tensach);
		  fprintf(output,"\nMa so sach la:%s",q->data.masosach);
		  fprintf(output,"\nNam xuat ban cua sach la:%d",q->data.namxuatban);
		  fprintf(output,"\nNha xuat ban la:%s",q->data.nhaxuatban);
		  fprintf(output,"\nTen tac gia la:%s",q->data.tentacgia);
		  if(q->data.trangthaisach==true)
		  fprintf(output,"\nTrang thai sach:chua muon");
		  else
		  fprintf(output,"\nTrang thai sach:da cho muon");
		  printf("\n");
		}
		  fclose(output);

}
void menu(LIST l)
{
    int choice;

    do {
        printf("------- MENU -------\n");
        printf("1. Khoi tao danh sach\n");
        printf("2. Them 1 cuon sach moi\n");
        printf("3. Xoa sach\n");
        printf("4. Tim kiem sach\n");
        printf("5. Xem danh sach sach\n");
        printf("6. Muon va tra sach\n");
        printf("7. Sua thong tin sach\n");
        printf("8. Luu file\n");
        printf("0. Thoat\n");
        printf("Vui long chon chuc nang (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	system("cls");
                nhapsach(&l);
                printf("\nNhap 0 de quay lai: ");
                int lp;
                scanf("%d",&lp);
                if(lp==0)
                system("cls");
                break;
            case 2:
            	system("cls");
            	int chon;
            	printf("\nLua chon chuc nang:");
            	
                printf("\n1.Them dau danh sach:");
                printf("\n2.Them sau 1 cuon sach nao do:");
				printf("\n3.Them cuoi danh sach:");
				printf("\nNhap lua chon:");
				scanf("%d",&chon);
				if(chon==1){
				BOOK p=tao1cuonsach();
				InsertFirst(&l,p);
				}
				if(chon==2){
				printf("\nNhap ma so cua sach de them 1 cuon vao sau no:");
				char ms[20];
				fflush(stdin);	
				gets(ms);
				printf("\nNhap noi dung sach can tao de them sau no:\n");
				BOOK temp=tao1cuonsach();
				BOOKNODE p=CreateBook(temp);
				for(BOOKNODE k=l.pHead;k!=NULL;k=k->pNext)
				{
					if(strcmp(ms,k->data.masosach)==0)
					InsertAfter(&l,k,p);
				}
				
				}
				if(chon==3){
				BOOK p=tao1cuonsach();	
				InsertLast(&l,p);
				}
				printf("\nNhap 0 de quay lai: ");
                int lp1;
                scanf("%d",&lp1);
                if(lp1==0)
                system("cls");
                break;
            case 3:
            	system("cls");
            	xoa1cuonkhoidanhsach(&l);
            	printf("\nNhap 0 de quay lai: ");
                int lp2;
                scanf("%d",&lp2);
                if(lp2==0)
                system("cls");
                break;
            case 4:
            	system("cls");
                timsach(&l);
                printf("\nNhap 0 de quay lai: ");
                int lp3;
                scanf("%d",&lp3);
                if(lp3==0)
                system("cls");
                break;
            case 5:
            	system("cls");
               	xemsach(&l);
               	printf("\nNhap 0 de quay lai: ");
                int lp4;
                scanf("%d",&lp4);
                if(lp4==0)
                system("cls");;
                break;
             case 6:
             	system("cls");
             	int c;
             	printf("\nChon chuc nang");
             	printf("\n1.Muon sach");
             	printf("\n2.Tra sach");
             	printf("\nNhap lua chon:");
             	scanf("%d",&c);
             	if(c==1)
            	muonsach(&l);
            	else
            	trasach(&l);
            	printf("\nNhap 0 de quay lai: ");
                int lp5;
                scanf("%d",&lp5);
                if(lp5==0)
                system("cls");
                break;
			case 7:
				system("cls");
               	chinhsuasach(&l);
               	printf("\nNhap 0 de quay lai: ");
                int lp6;
                scanf("%d",&lp6);
                if(lp6==0)
                system("cls");
                break;
			case 8:
				system("cls");
				FILE*output;
               	luufile(output,l);
               	printf("\nNhap 0 de quay lai: ");
                int lp7;
                scanf("%d",&lp7);
                if(lp7==0)
                system("cls");
                break;	   
            case 0:
                printf("Cam on da su dung chuong trinh quan li sach!\n");
                break;
            default:
                printf("Vui long chon lai chuc nang tu 1 den 8.\n");
                break;
        }
    } while (choice != 0);
}
int main(){
	LIST l;
	Init(&l);
	menu(l);

	return 0;
}
