#include <stdio.h>
#include <syslog.h>
#include <time.h>
#include <math.h>

/*******************
CLOCK_REALTIME                  获取真实的时间
CLOCK_MONOTONIC                 获取单调时间
CLOCK_MONOTONIC_RAW             获取原始的单调时间
CLOCK_MONOTONIC_RAW_APPROX      获取原始的单调时间的近似值
CLOCK_UPTIME_RAW                获取系统启动时间的原始时间
CLOCK_UPTIME_RAW_APPROX         获取系统启动时间的原始时间的近似值
CLOCK_PROCESS_CPUTIME_ID        获取进程的CPU时间ID
CLOCK_THREAD_CPUTIME_ID         获取线程的CPU时间ID
*********************/

int main() {
   
    //获取真实时间
    struct timespec tv = {0};
    int ret = clock_gettime(CLOCK_REALTIME, &tv);
    printf("sec %ld ns %ld\n",tv.tv_sec,tv.tv_nsec);

    //获取本地时间
    printf("Local time: ");
    struct tm *timer = localtime(&tv.tv_sec);; 
    printf("%d %d %d\n",timer->tm_hour,timer->tm_min,timer->tm_sec);

    //获取UTC时间 （协调世界时）
    printf("UTC time: ");
    timer = gmtime(&tv.tv_sec);
    printf("%d %d %d\n",timer->tm_hour,timer->tm_min,timer->tm_sec);
    
    return 0;
}