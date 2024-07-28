#include <stdio.h>

int main(void){
    int po = 0;
    scanf("%d", &po);
    int con = 1;
    int nw_c = 1;
    int dy = 1;
    while(con < po){
        nw_c = 2*con;
        con = con + nw_c;
        dy++;
        printf("%d\n", con);
    }
    printf("%d", dy);
    return 0;
}

/*Input:
3
Output:
2
For a total population of 10 inhabitants, on day 1 a single person is infected. This is followed by 2 new people on the second day for a total of 3 infected people. On the third day,  6 new people are infected for a total of 9 infected people. On the fourth day the last of the 10 people is infected (though the epedemic had the potential to infect 18 people on the fourth day) so your program should output '4'.

Input:
10
Output:
4
For a total population of 100 inhabitants, on day 1 a single person is infected. This is followed by 2 new people on the second day for a total of 3 infected people. On the third day,  6 new people are infected for a total of 9 infected people. On the fourth day, 18 new people are infected, for a total of 27 people. On the fifth day, 27 new people infect 54 people for a total of 81 people infected. On the sixth day, the last of the 100 people will be infected (though the 81 people have the potential to contaminate 162 people) so your program shuld output '6'.

Input:

100
Output:

6*/