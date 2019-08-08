#pragma once
#include <pthread.h>
#include "condition.h"

class RWLock
{
  public:
    RWLock() : m_wr_stat(0), m_rd_stat(0)
    {
    }

  public:
    void rdLock()
    {
        while (m_wr_stat > 0)
        {
            m_cond.wait(m_mutex.get());
        }
        m_mutex.lock();
        ++m_rd_stat;
        m_mutex.unlock();
    }
    void rdUnlock()
    {
        m_mutex.lock();
        --m_rd_stat;
        m_cond.broadcast();
        m_mutex.unlock();
    }
    void wrLock()
    {
        while (m_wr_stat)
        {
            m_cond.wait(m_mutex.get());
        }
        m_wr_stat++;
        while (m_rd_stat)
        {
            m_cond.wait(m_mutex.get());
        }
    }
    void wrUnlock()
    {
        pthread_mutex_unlock(&m_mutex);
        m_cond.broadcast();
    }

  protected:
    RWLock(const& RWLock);
    RWLock& operator=(const RWLock);

  private:
    Mutex m_mutex;
    Condition m_cond;
    int m_wr_stat;
    int m_rd_stat;
};