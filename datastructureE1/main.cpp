#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct node          //定义结点
   {
	char data[10];               //结点的数据域为字符串
	struct node *next;        //结点的指针域
   }ListNode;
typedef ListNode * LinkList;         // 自定义LinkList单链表类型
LinkList CreatListR1();              //函数，用尾插入法建立带头结点的单链表
LinkList CreatListR2();              // 函数 ，头插法建立带头节点的单链表
ListNode *LocateNode(LinkList head, char *key);//函数，按值查找结点
void  InsertNodeBydata(LinkList head); //  函数 ： 根据输入的字符串数据插入节点到他的下一位

void InsertNodeByNum(LinkList head);  // 函数： 根据输入的节点的位置插入数据到他的下一位

void DeleteList();                   //函数，删除指定值的结点
void printlist();                    //函数，打印链表中的所有值
void DeleteAll();                    //函数，删除所有结点，释放内存
// ----------------------------------------函数 ： 根据输入的字符串数据 ，插入节点到他的下一位
void  InsertNodeBydata(LinkList  head){
           char data[10];
           ListNode *N = (ListNode*)malloc(sizeof(ListNode));
           ListNode *p,*temp , *check;
           fflush(stdin);   //  清空缓存区
           printf("please input a string to find the position :\n");
           gets(data);
           p = LocateNode(head,data);
           if(p == NULL){
                printf("Can't find!!!");
           }
           printf("Please input Node_data:");
          scanf("%s", data);           //输入各结点的字符串
           check = LocateNode(head,data);
           if(check != NULL){
                printf("input error\n");
           }
           strcpy(N->data,data);
           temp = p->next;
           p->next = N;
           N->next = temp;
}
// ----------------------------------------------------  函数： 根据输入的节点的位置插入数据到他的下一位
void InsertNodeByNum(LinkList  head){
           char data[10];
           ListNode *N = (ListNode*)malloc(sizeof(ListNode));
           ListNode *p = head, *temp , *check;
           int num = 0;
           fflush(stdin);   //  清空缓存区
           while(num<=0){
                printf("Please input the position you want to insert :::  (eg:  3)\n");
                scanf("%d", &num);
                if(num<=0)
                   printf("input error!!!!\n");
                   fflush(stdin);   //  清空缓存区
           }
          while(num--){
              p = p->next;
              if(p == NULL){
                  printf("position is not valid");
              }
          }
           printf("Please input Node_data:");
          scanf("%s", data);           //输入各结点的字符串
          check = LocateNode(head,data);
           if(check != NULL){
                printf("input error\n");
           }
          strcpy(N->data,data);
           temp = p->next;
           p->next = N;
           N->next = temp;

}
//----------------------------函数 ，头插法建立带头节点的单链表--------------------------------------
LinkList CreatListR2(void){
    char ch[10];
    LinkList head=(LinkList)malloc(sizeof(ListNode)); //生成头结点
    ListNode *s,*r,*pp,*temp;
    r=head;
    r->next=NULL;
    printf("Input # to end  \n");  //输入“#”代表输入结束
    printf("Please input Node_data:");
    scanf("%s",ch);           //输入各结点的字符串
    while(strcmp(ch,"#")!=0) {
         pp=LocateNode(head,ch);      //按值查找结点，返回结点指针
	 if(pp==NULL) {  //没有重复的字符串，插入到链表中

	    		s=(ListNode *)malloc(sizeof(ListNode));
	            strcpy(s->data,ch);
	            temp  = r->next;
		       r->next = s;
		       s->next = temp;
		       /*
		           r->next=s;
                   r=s;
		          r->next=NULL;
		          //  新定义了temp 指针来保存 r 的 next 的值
		       */
         }else{
               printf("input error!!!\n");
         }
	    		printf("Input # to end  ");
	    printf("Please input Node_data:");
		    scanf("%s",ch);
    }
    return head;        //返回头指针


}
//==========按值查找结点，找到则返回该结点的位置，否则返回NULL==========
ListNode *LocateNode(LinkList head, char *key)
{
    ListNode *p=head->next; //从开始结点比较
    while(p&&strcmp(p->data,key)!=0)  //直到p为NULL或p->	data为key止
		p=p->next;        //扫描下一个结点
    return p;    //若p=NULL则查找失败，否则p指向找到的值为key的结点
}

//==========用尾插入法建立带头结点的单链表===========
 LinkList CreatListR1(void)
 {
    char ch[10];
    LinkList head=(LinkList)malloc(sizeof(ListNode)); //生成头结点
    ListNode *s,*r,*pp;
    r=head;
    r->next=NULL;
    printf("Input # to end  ");  //输入“#”代表输入结束
    printf("Please input Node_data:");
    scanf("%s",ch);           //输入各结点的字符串
    while(strcmp(ch,"#")!=0) {
         pp=LocateNode(head,ch);      //按值查找结点，返回结点指针
	 if(pp==NULL) {            //没有重复的字符串，插入到链表中
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
    return head;        //返回头指针
}
//==========删除带头结点的单链表中的指定结点=======
void DeleteList(LinkList head,char *key)
{
    ListNode *p,*r,*q=head;
    p=LocateNode(head,key);    //按key值查找结点的
    if(p==NULL ) {            //若没有找到结点，退出
	printf("position error");
		exit(0);
    }
    while(q->next!=p)        //p为要删除的结点，q为p的前结点
		q=q->next;
    r=q->next;
    q->next=r->next;
    free(r);                //释放结点
}
//===========打印链表=======
void printlist(LinkList head)
{
    ListNode *p=head->next;       //从开始结点打印
    while(p){
	printf("%s,   ",p->data);
		p=p->next;
    }
    printf("\n");
}
//==========删除所有结点，释放空间===========
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

//==========主函数==============
int main()
{
  char ch[10],num[10];
  LinkList head;
   head=CreatListR2();          //用尾插入法建立单链表，返回头指针
   printlist(head);             //遍历链表输出其值
   InsertNodeBydata(head);
   InsertNodeByNum(head);
    printlist(head);             //遍历链表输出其值
  printf(" Delete node (y/n):");  //输入“y”或“n”去选择是否删除结点
  scanf("%s",num);
  if(strcmp(num,"y")==0 || strcmp(num,"Y")==0){
    printf("Please input Delete_data:");
    		scanf("%s",ch);	        //输入要删除的字符串
    DeleteList(head,ch);
    		printlist(head);
  }
  DeleteAll(head);
  return 1;         //删除所有结点，释放内存
}
