#pragma once
#include <pthread.h>

class Condition
{
  public:
    Condition()
    {
        pthread_condattr_t attr;
        pthread_condattr_init(&attr);
        pthread_cond_init(&m_cond, &attr);
        pthread_condattr_destroy(&attr);
    }
    ~Condition()
    {
        pthread_cond_destroy(&m_cond);
    }

  public:
    void wait(pthread_mutex_t* mutex)
    {
        pthread_cond_wait(&m_cond, mutex);
    }
    void signal()
    {
        pthread_cond_signal(&m_cond);
    }
    void broadcast()
    {
        pthread_cond_broadcast(&m_cond);
    }
    void wait(pthread_mutex_t* mutex, int time_ms)
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        struct timespec ts;
        tv.tv_usec += time_ms * 1000;
        ts.tv_sec = tv.tv_sec + tv.tv_usec / 1000000;
        ts.tv_nsec = tv.tv_usec % 1000000 * 1000;
        pthread_cond_timedwait(&m_cond, mutex, &ts);
    }

  private:
    pthread_cond_t m_cond;
};