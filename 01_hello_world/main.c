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


    //歌曲时间已播放100秒
    //当前时间为0秒
    //计算歌曲开始播放的时间
    unsigned int song_time = 100;
    unsigned int curr_time = 10;
    unsigned int song_start_time = 0;

    /*方案1*/
    // song_start_time = 0 - song_time;
    // song_start_time = 30 - song_start_time;
    // printf("song_start_time %u\n", song_start_time);

    /*方案2*/
    song_start_time = curr_time - song_time;
    printf("song_start_time %u\n",30 - song_start_time);


    return 0;
}