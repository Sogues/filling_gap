#pragma once
#include <pthread.h>

class Mutex
{
  public:
    Mutex()
    {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutex_init(&m_mutex, &attr);
        pthread_mutexattr_destroy(&attr);
    }
    ~Mutex()
    {
        pthread_mutex_destroy(&m_mutex);
    }

  public:
    void lock()
    {
        pthread_mutex_lock(&m_mutex);
    }
    void unlock()
    {
        pthread_mutex_unlock(&m_mutex);
    }
    pthread_mutex_t* get()
    {
        return &m_mutex;
    }

  private:
    pthread_mutex_t m_mutex;
};