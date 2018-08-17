#include <stdio.h>
int press[6][8];
int puzzle[6][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 1, 1}
};
bool guess(){
    int c, r;
    for(r=1; r<5; r++)
        for(c=1; c<7; c++)
            press[r+1][c] = (
                puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1]
            ) % 2;/* 根据press第一行和puzzle数组推算press其他行 */
    for(c=1; c<7; ++c)
        if((press[5][c-1] + press[5][c] + press[5][c+1] + press[4][c]) % 2
            != puzzle[5][c]) /* 检查第五行是否完全熄灭 */
            /* 第5行原来是1，就应该输出1；原来是0，就应该输出0 */
            return false;
    return true;
}
void enumerate(){
    int c;
    bool res;
    for(c=1; c<7; c++)
        press[1][c]=0;
    while(!guess()){
        /*----------------*/
        press[1][1]++;/* 加1进行下一个枚举 */
        c=1;
        while(press[1][c]>1){/* 手动进位处理 */
            press[1][c] = 0;
            c++;
            press[1][c]++;
            /*---------------*/
            /* 两段注释之间，对press第一行的元素press[1][1]~press[1][6]的
               各种取值情况进行枚举，依次考虑：
               0 0 0 0 0 0
               1 0 0 0 0 0
               0 1 0 0 0 0
               1 1 0 0 0 0
               0 0 1 0 0 0
               .
               .
               .
               1 1 1 1 1 1
            */
        }
    }
}
int main()
{
    int cases, i, r, c;
    // scanf("%d", &cases);
    for(r=0; r<6; ++r)
        press[r][0] = press[r][7] = 0;/* 第0列第7列置零 */
    for(c=1; c<7; ++c)
        press[0][c] = 0;/* 第一行置零 */

    // for(i=0; i<cases; i++){
    //     for(r=1; r<6; r++)
    //         for(c=1; c<7; c++)
    //             scanf("&d", &puzzle[r][c]);
    printf("/*--------puzzle-------*/\n");
    for(r=1; r<6; r++) {
        for (c = 1; c < 7; c++)
            printf("%d", puzzle[r][c]);
        printf("\n");
    }
        enumerate();
        // printf("PUZZLE #%d\n, i+1");
    printf("/*--------press-------*/\n");
        for(r=1; r<6; ++r){
            for(c=1; c<7; c++)
                printf("%d", press[r][c]);
            printf("\n");
        }
    // }
    return 0;
}