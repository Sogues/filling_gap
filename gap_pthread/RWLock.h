#pragma once
#include <pthread.h>
#include "Mutex.h"
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
        m_mutex.lock();
        while (m_wr_stat)
        {
            m_cond.wait(m_mutex.get());
        }
        ++m_rd_stat;
        m_mutex.unlock();
    }
    void rdUnlock()
    {
        m_mutex.lock();
        if (!--m_rd_stat)
        {
            m_cond.signal();
        }
        m_mutex.unlock();
    }
    void wrLock()
    {
        m_mutex.lock();
        while (m_wr_stat)
        {
            m_cond.wait(m_mutex.get());
        }
        ++m_wr_stat;
        while (m_rd_stat)
        {
            m_cond.wait(m_mutex.get());
        }
        m_mutex.unlock();
    }
    void wrUnlock()
    {
        m_mutex.lock();
        // 写锁次数只有 0和1
        if (!--m_wr_stat)
        {
            // m_cond.broadcast();
            m_cond.signal();
        }
        m_mutex.unlock();
    }

  protected:
    RWLock(const RWLock&);
    RWLock& operator=(const RWLock&);

  private:
    Mutex m_mutex;
    Condition m_cond;
    int m_wr_stat;
    int m_rd_stat;
};