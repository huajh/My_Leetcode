//
// 有n个石子（n<＝100），A、B双方轮流选取，每次取走若干个石子，取走最后一个石子的一方获胜。
// 要求：第一次不能全部取完；各方每次选取的石子数不能为0，也不能超过上次对方选择的石子数。
// 问：如果A先取，那么第一次应该选几个才能保证获胜？如果第一次有多种策略，则输出石子数最多的一种。

#include <stdio.h>
#include <string.h>

int main()
{
    int n = 100;
    int res[100];
    memset(res,0,sizeof(res));
    res[0] = 1;
    res[1] = 0;    
    int cur = 1, maxval = 2;
    for (int i=2; i<100;i++)
    {
        if (cur < maxval)
        {
            res[i] = cur;
            cur++;
        }else 
        {
            res[i] = 0;
            maxval = i+1;
            cur = 1;
        }                 
    }
    scanf("%d", &n);
    printf("%d\n", res[n-1]);

    return 0;
}
