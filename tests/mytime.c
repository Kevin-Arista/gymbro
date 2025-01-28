#include <stdio.h>
#include <time.h>
int main(void)
{
    time_t t = time(NULL);
    struct tm *ptr = localtime(&t);
    printf("%s", asctime(ptr));
    printf("%d", ptr->tm_wday);
    return 0;
}
