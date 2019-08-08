// gap_one.cpp: 定义应用程序的入口点。
//

#include <pthread.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <unistd.h>
#include <functional>
#include <iostream>
#include "RWLock.h"

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

namespace unit3
{
int val;
RWLock rwlock;

void* fun1(void* arg)
{
    rwlock.rdLock();
    std::cout << "###读 id = " << *(int*)arg << " | val = " << val << std::endl;
    rwlock.rdUnlock();
}
void* fun2(void* arg)
{
    rwlock.wrLock();
    ++val;
    std::cout << "$$$写 id = " << *(int*)arg << " | val = " << val << std::endl;
    rwlock.wrUnlock();
}

#define UNIT3_RdThread(x) \
    pthread_t rd##x;      \
    int rdarg##x = x;     \
    pthread_create(&rd##x, NULL, fun1, &rdarg##x);

#define UNIT3_WrThread(x) \
    pthread_t wr##x;      \
    int wrarg##x = x;     \
    pthread_create(&wr##x, NULL, fun2, &wrarg##x);

#define UNIT3_RdJoin(x) pthread_join(rd##x, NULL);
#define UNIT3_WrJoin(x) pthread_join(wr##x, NULL);

void unit3()
{
    val = 0;
    {
        UNIT3_RdThread(1);
        UNIT3_WrThread(1);
        UNIT3_RdThread(2);
        UNIT3_RdThread(3);
        UNIT3_RdThread(4);
        UNIT3_WrThread(2);
        UNIT3_RdThread(5);
        UNIT3_RdThread(6);
        UNIT3_WrThread(3);
        UNIT3_RdThread(7);
        UNIT3_RdThread(8);
        UNIT3_WrThread(4);
        UNIT3_RdThread(9);
        UNIT3_RdThread(10);
        UNIT3_WrThread(5);
        UNIT3_RdThread(11);
        UNIT3_RdThread(12);
        UNIT3_RdThread(13);
        UNIT3_RdThread(14);

        UNIT3_RdJoin(1);
        UNIT3_RdJoin(2);
        UNIT3_RdJoin(3);
        UNIT3_RdJoin(4);
        UNIT3_RdJoin(5);
        UNIT3_RdJoin(6);
        UNIT3_RdJoin(7);
        UNIT3_RdJoin(8);
        UNIT3_RdJoin(9);
        UNIT3_RdJoin(10);
        UNIT3_RdJoin(11);
        UNIT3_RdJoin(12);
        UNIT3_RdJoin(13);
        UNIT3_RdJoin(14);

        UNIT3_WrJoin(1);
        UNIT3_WrJoin(2);
        UNIT3_WrJoin(3);
        UNIT3_WrJoin(4);
        UNIT3_WrJoin(5);
    }
}
}  // namespace unit3

int main()
{
    unit3::unit3();
    return 0;
}
