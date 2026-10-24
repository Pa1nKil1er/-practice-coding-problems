List MakeEmpty()
{
    //ElementType p=(ElementType)malloc(MAXSIZE*sizeof(ElementType)); 
    
    //List T=(List)malloc(sizeof(List));
    List T=(List)malloc(sizeof(struct LNode));
    
    //T->Data=p;
    T->Last=-1;
    return T;
}
Position Find( List L, ElementType X )
{
    Position i=0;
    while(i<=L->Last){
        if(L->Data[i]==X) return i;
        i++;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P )
{

    if(L->Last==MAXSIZE-1){
    printf("FULL");
    return false;
    }
    //if(P<0 || P>L->Last){
    if(P<0 || P>L->Last+1){
        printf("ILLEGAL POSITION");
        return false;
    }

    for(int i=L->Last+1;i>=P+1;i--){
        L->Data[i]=L->Data[i-1];
    }
    L->Data[P]=X;
    L->Last++;
    return true;
}
bool Delete( List L, Position P )
{
    if(P<0 || P>L->Last){
        printf("POSITION %d EMPTY",P);
        return false;
    }
    for(int i=P;i<=L->Last-1;i++){
        L->Data[i]=L->Data[i+1];
    }
    L->Last--;
    return true;
}
