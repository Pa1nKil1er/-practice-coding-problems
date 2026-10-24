//堆栈就是栈stack，一个数组实现->把数组两端当base
Stack CreateStack(int Maxsize)
{
    //这里的设置：top指向栈顶
    Stack a=(Stack)malloc(sizeof(struct SNode));//这里很不理解
    a->Data = (ElementType *)malloc(sizeof(ElementType) * Maxsize);
    a->Top1=-1;
    a->Top2=Maxsize;
    a->MaxSize=Maxsize;
    return a;
    //Stack a={.Top1=-1,.Top2=Maxsize,.MaxSize=Maxsize;
}

bool Push( Stack S, ElementType X, int Tag )
{
    if(S->Top1+1>=S->Top2)
    {
        printf("Stack Full\n");
        return false;
    }
    else{
        if(Tag==1)
        {
            S->Data[++(S->Top1)]=X;
        }
        else if(Tag==2)
        {
            S->Data[--(S->Top2)]=X;
        }
    }
    return true;
}

ElementType Pop( Stack S, int Tag )
{
    if(Tag==1)
    {
        if((S->Top1)==-1)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        else 
        {
            (S->Top1)--;
            return S->Data[S->Top1+1];
        }
    }
    else if(Tag==2)
    {
        if((S->Top2)==S->MaxSize)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        else 
        {
            (S->Top2)++;
            return S->Data[S->Top2-1];
        }
    }
}
