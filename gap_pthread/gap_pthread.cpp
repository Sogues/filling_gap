// gap_one.cpp: 定义应用程序的入口点。
//

#include <pthread.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <unistd.h>
#include <functional>

#include <iostream>

pthread_rwlock_t rwlock;
int32_t a;

void* func1(void* arg)
{
    pthread_rwlock_rdlock(&rwlock);
    std::cout << __FUNCTION__ << " | start sleep:" << *(int*)arg << std::endl;
    sleep(*(int*)arg);
    std::cout << __FUNCTION__ << " | end sleep:" << *(int*)arg << " a= " << a << std::endl;
    pthread_rwlock_unlock(&rwlock);
}

void* func2(void*)
{
    pthread_rwlock_wrlock(&rwlock);
    std::cout << __FUNCTION__ << " | " << ++a << std::endl;
    sleep(3);
    pthread_rwlock_unlock(&rwlock);
}

//////////////////////////////////////////////////////////////////////////

void unit1()
{
#define Thread(k, x, v) \
    pthread_t t##x;     \
    int32_t a##x = v;   \
    pthread_create(&t##x, NULL, func##k, &a##x);

#define Join(x) pthread_join(t##x, NULL);

    ///// 读，2s
    // Thread(1, 1, 2);
    ///// 读，3s
    // Thread(1, 2, 3);
    ///// 读，4s
    // Thread(1, 3, 4);
    ///// 读，5s
    // Thread(1, 4, 5);
    /// 写，2s
    Thread(2, 5, 2);
    /// 写，1s
    Thread(2, 6, 1);
    /// 写，1s
    Thread(2, 7, 1);
    /// 写，1s
    Thread(2, 8, 1);
    /// 读，1s
    Thread(1, 9, 1);
    /// 读，1s
    Thread(1, 10, 1);
    /// 读，1s
    Thread(1, 11, 1);

    // Join(1);
    // Join(2);
    // Join(3);
    // Join(4);
    Join(5);
    Join(6);
    Join(7);
    Join(8);
    Join(9);
    Join(10);
    Join(11);
}

void unit2()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::cout << tv.tv_sec << " " << tv.tv_usec << std::endl;
}

int main()
{
    unit2();
    return 0;
}
