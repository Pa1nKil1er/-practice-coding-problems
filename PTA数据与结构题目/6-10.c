Position BinarySearch( List L, ElementType X )
{
    int a,b,npos;
    a=1;b=L->Last;
    npos=(a+b)/2;
    if(X==L->Data[a]) return a;
    if(X==L->Data[b]) return b;
    if(X>L->Data[b] || X<L->Data[1]) return NotFound;
    while(X!=L->Data[npos])
        {
            if(b<=a) return NotFound;
            if(X>L->Data[npos])  a=npos+1;
            else if(X<L->Data[npos])  b=npos-1;
            npos=(a+b)/2;
        }
    return npos;
}
