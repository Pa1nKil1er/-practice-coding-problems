//实现一个函数，将给定的单链表逆转。
//List为链表指针类型
List Reverse( List L )
{
    //List L1=(List*)malloc(sizeof(List));//逆转链表要建立一个新的存放
    List L1=NULL;
    List p=L;
    while(p){//链表L不为空
        List next=p->Next;
        p->Next=L1;
        L1=p;
        p=next;
    }
    return L1;
}