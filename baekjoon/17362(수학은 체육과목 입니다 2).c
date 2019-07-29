#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rev[8] = {2,1,2,3,4,5,4,3};
int main(){
    long long finger;
    scanf("%lld",&finger);

    printf("%d\n",rev[finger % 8]);
    return 0;
}

/*
1   2   3   4   5 (5*0 ~ 5*1) 1
9   8   7   6   5 (5*1 ~ 5*2) 2
9   10. 11. 12. 13            3
17. 16  15. 14. 13            4
17. 18. 19. 20. 21            5
25. 24. 23. 22. 21            6

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
----------------------------------------
1 2 3 4 5 4 3 2 1  2  3. 4  5. 4 3.  2 
*/

