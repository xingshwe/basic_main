#include <stdio.h>
#include <syslog.h>
#include <time.h>

int main() {
   
    char num = 1;
    printf("/**num:%d**/\n",num);
    printf("/**num:%2d**/\n",num);

    struct timespec tv = {0};
    int ret = clock_gettime(CLOCK_REALTIME, &tv);
    printf("sec %ld ns %ld\n",tv.tv_sec,tv.tv_nsec);

    struct tm *timer = localtime(&tv.tv_sec);; 
    printf("%d %d %d\n",timer->tm_hour,timer->tm_min,timer->tm_sec);

    
    time_t timer_sec = timelocal(timer);
    printf("timer_sec %ld\n", timer_sec);


    return 0;
}