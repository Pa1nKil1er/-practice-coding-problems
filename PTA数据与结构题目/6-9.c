void InorderTraversal( BinTree BT )//中序
{
    if(!BT) return;
    InorderTraversal(BT->Left);
    printf(" %c",BT->Data);
    InorderTraversal(BT->Right);
}
void PreorderTraversal( BinTree BT )//先序
{
    if(!BT) return;
    printf(" %c",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void PostorderTraversal( BinTree BT )//后序
{
    if(!BT) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c",BT->Data);
}
void LevelorderTraversal( BinTree BT )//
{
    //总是忘记判空
    BinTree queue[10010];
    int front=-1;
    int rear=-1;
    if(BT==NULL)
        {
            return;
        }
    queue[++rear]=BT;
    while(front!=rear)
        {
            BinTree B=queue[front+1];
            printf(" %c",queue[front+1]->Data);
            front++;
            if(B->Left){
            BinTree L=B->Left;
            queue[++rear]=L;
            }
            if(B->Right){
            BinTree R=B->Right;
            queue[++rear]=R;
            }
        }
    return;
}
