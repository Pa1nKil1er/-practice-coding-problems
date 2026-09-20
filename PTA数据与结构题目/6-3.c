int Length( List L )
{
    int len=0;
    List p=L;
    while(p)
    {
        len++;
        p=p->Next;
    }
    return len;
}
