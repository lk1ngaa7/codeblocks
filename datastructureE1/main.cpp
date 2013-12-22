#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct node          //������
   {
	char data[10];               //����������Ϊ�ַ���
	struct node *next;        //����ָ����
   }ListNode;
typedef ListNode * LinkList;         // �Զ���LinkList����������
LinkList CreatListR1();              //��������β���뷨������ͷ���ĵ�����
LinkList CreatListR2();              // ���� ��ͷ�巨������ͷ�ڵ�ĵ�����
ListNode *LocateNode(LinkList head, char *key);//��������ֵ���ҽ��
void  InsertNodeBydata(LinkList head); //  ���� �� ����������ַ������ݲ���ڵ㵽������һλ

void InsertNodeByNum(LinkList head);  // ������ ��������Ľڵ��λ�ò������ݵ�������һλ

void DeleteList();                   //������ɾ��ָ��ֵ�Ľ��
void printlist();                    //��������ӡ�����е�����ֵ
void DeleteAll();                    //������ɾ�����н�㣬�ͷ��ڴ�
// ----------------------------------------���� �� ����������ַ������� ������ڵ㵽������һλ
void  InsertNodeBydata(LinkList  head){
           char data[10];
           ListNode *N = (ListNode*)malloc(sizeof(ListNode));
           ListNode *p,*temp , *check;
           fflush(stdin);   //  ��ջ�����
           printf("please input a string to find the position :\n");
           gets(data);
           p = LocateNode(head,data);
           if(p == NULL){
                printf("Can't find!!!");
           }
           printf("Please input Node_data:");
          scanf("%s", data);           //����������ַ���
           check = LocateNode(head,data);
           if(check != NULL){
                printf("input error\n");
           }
           strcpy(N->data,data);
           temp = p->next;
           p->next = N;
           N->next = temp;
}
// ----------------------------------------------------  ������ ��������Ľڵ��λ�ò������ݵ�������һλ
void InsertNodeByNum(LinkList  head){
           char data[10];
           ListNode *N = (ListNode*)malloc(sizeof(ListNode));
           ListNode *p = head, *temp , *check;
           int num = 0;
           fflush(stdin);   //  ��ջ�����
           while(num<=0){
                printf("Please input the position you want to insert :::  (eg:  3)\n");
                scanf("%d", &num);
                if(num<=0)
                   printf("input error!!!!\n");
                   fflush(stdin);   //  ��ջ�����
           }
          while(num--){
              p = p->next;
              if(p == NULL){
                  printf("position is not valid");
              }
          }
           printf("Please input Node_data:");
          scanf("%s", data);           //����������ַ���
          check = LocateNode(head,data);
           if(check != NULL){
                printf("input error\n");
           }
          strcpy(N->data,data);
           temp = p->next;
           p->next = N;
           N->next = temp;

}
//----------------------------���� ��ͷ�巨������ͷ�ڵ�ĵ�����--------------------------------------
LinkList CreatListR2(void){
    char ch[10];
    LinkList head=(LinkList)malloc(sizeof(ListNode)); //����ͷ���
    ListNode *s,*r,*pp,*temp;
    r=head;
    r->next=NULL;
    printf("Input # to end  \n");  //���롰#�������������
    printf("Please input Node_data:");
    scanf("%s",ch);           //����������ַ���
    while(strcmp(ch,"#")!=0) {
         pp=LocateNode(head,ch);      //��ֵ���ҽ�㣬���ؽ��ָ��
	 if(pp==NULL) {  //û���ظ����ַ��������뵽������

	    		s=(ListNode *)malloc(sizeof(ListNode));
	            strcpy(s->data,ch);
	            temp  = r->next;
		       r->next = s;
		       s->next = temp;
		       /*
		           r->next=s;
                   r=s;
		          r->next=NULL;
		          //  �¶�����temp ָ�������� r �� next ��ֵ
		       */
         }else{
               printf("input error!!!\n");
         }
	    		printf("Input # to end  ");
	    printf("Please input Node_data:");
		    scanf("%s",ch);
    }
    return head;        //����ͷָ��


}
//==========��ֵ���ҽ�㣬�ҵ��򷵻ظý���λ�ã����򷵻�NULL==========
ListNode *LocateNode(LinkList head, char *key)
{
    ListNode *p=head->next; //�ӿ�ʼ���Ƚ�
    while(p&&strcmp(p->data,key)!=0)  //ֱ��pΪNULL��p->	dataΪkeyֹ
		p=p->next;        //ɨ����һ�����
    return p;    //��p=NULL�����ʧ�ܣ�����pָ���ҵ���ֵΪkey�Ľ��
}

//==========��β���뷨������ͷ���ĵ�����===========
 LinkList CreatListR1(void)
 {
    char ch[10];
    LinkList head=(LinkList)malloc(sizeof(ListNode)); //����ͷ���
    ListNode *s,*r,*pp;
    r=head;
    r->next=NULL;
    printf("Input # to end  ");  //���롰#�������������
    printf("Please input Node_data:");
    scanf("%s",ch);           //����������ַ���
    while(strcmp(ch,"#")!=0) {
         pp=LocateNode(head,ch);      //��ֵ���ҽ�㣬���ؽ��ָ��
	 if(pp==NULL) {            //û���ظ����ַ��������뵽������
	    		s=(ListNode *)malloc(sizeof(ListNode));
	    strcpy(s->data,ch);
		    r->next=s;
            r=s;
		    r->next=NULL;
         }
	    		printf("Input # to end  ");
	    printf("Please input Node_data:");
		    scanf("%s",ch);
    }
    return head;        //����ͷָ��
}
//==========ɾ����ͷ���ĵ������е�ָ�����=======
void DeleteList(LinkList head,char *key)
{
    ListNode *p,*r,*q=head;
    p=LocateNode(head,key);    //��keyֵ���ҽ���
    if(p==NULL ) {            //��û���ҵ���㣬�˳�
	printf("position error");
		exit(0);
    }
    while(q->next!=p)        //pΪҪɾ���Ľ�㣬qΪp��ǰ���
		q=q->next;
    r=q->next;
    q->next=r->next;
    free(r);                //�ͷŽ��
}
//===========��ӡ����=======
void printlist(LinkList head)
{
    ListNode *p=head->next;       //�ӿ�ʼ����ӡ
    while(p){
	printf("%s,   ",p->data);
		p=p->next;
    }
    printf("\n");
}
//==========ɾ�����н�㣬�ͷſռ�===========
void DeleteAll(LinkList head)
{
    ListNode *p=head,*r;
    while(p->next){
	r=p->next;
		free(p);
	p=r;
     }
     free(p);
}

//==========������==============
int main()
{
  char ch[10],num[10];
  LinkList head;
   head=CreatListR2();          //��β���뷨��������������ͷָ��
   printlist(head);             //�������������ֵ
   InsertNodeBydata(head);
   InsertNodeByNum(head);
    printlist(head);             //�������������ֵ
  printf(" Delete node (y/n):");  //���롰y����n��ȥѡ���Ƿ�ɾ�����
  scanf("%s",num);
  if(strcmp(num,"y")==0 || strcmp(num,"Y")==0){
    printf("Please input Delete_data:");
    		scanf("%s",ch);	        //����Ҫɾ�����ַ���
    DeleteList(head,ch);
    		printlist(head);
  }
  DeleteAll(head);
  return 1;         //ɾ�����н�㣬�ͷ��ڴ�
}
