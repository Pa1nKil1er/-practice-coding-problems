int GetHeight( BinTree BT )
{
    int heigh=0;
    BinTree a=BT;
    // 记得之前写过但是不记得怎么写了>人<
    // 应该要用到递归吧    
    if(BT==NULL)
    {
        return 0;
    }
    //边界
    //if(!BT->Left && !BT->Right)
    //{
    //    return height;
    //}
    else
    {
        int llen=GetHeight(BT->Left);
        int rlen=GetHeight(BT->Right);
        if(llen<=rlen) llen=rlen;
        heigh=llen+1;
        return heigh;
    }
}
