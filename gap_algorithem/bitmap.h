#pragma once
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace BitMap
{
class BitMap
{
  private:
    int32_t* bitmap_;
    int32_t capacity_;
    int32_t size_;

  public:
    BitMap(int32_t cap)
    {
        capacity_ = (cap >> 5) + 1;
        bitmap_ = new int32_t[capacity_];
        bzero(bitmap_, capacity_);
    }
    bool insert(int32_t val)
    {
        int32_t idx = val >> 5;
        if (idx >= capacity_)
        {
            return false;
        }
        int32_t mod = val & 31;
        if (bitmap_[idx] & (1 << mod))
        {
            return false;
        }
        bitmap_[idx] |= 1 << mod;
        ++size_;
        return true;
    }
    bool Get(int32_t val)
    {
        int32_t idx = val >> 5;
        if (idx >= capacity_)
        {
            return false;
        }
        int32_t mod = val & 31;
        return bitmap_[idx] & (1 << mod);
    }
    void erase(int32_t val)
    {
        int32_t idx = val >> 5;
        if (idx >= capacity_)
        {
            return;
        }
        int32_t mod = val & 31;
        if (!(bitmap_[idx] & (1 << mod)))
        {
            return;
        }
        bitmap_[idx] &= ~(1 << mod);
        --size_;
    }
    int32_t size() const
    {
        return size_;
    }
    static void Test()
    {
        std::cout << "=============" << std::endl;
        {
            BitMap bm(11);
            std::cout << bm.insert(10) << std::endl;
            std::cout << bm.insert(20) << std::endl;
            std::cout << bm.insert(0) << std::endl;
            std::cout << bm.insert(8) << std::endl;
            std::cout << bm.Get(10) << std::endl;
            std::cout << bm.Get(20) << std::endl;
            std::cout << bm.Get(0) << std::endl;
            std::cout << bm.Get(8) << std::endl;

            bm.erase(0);
            std::cout << bm.Get(0) << std::endl;
            bm.erase(10);
            std::cout << bm.Get(10) << std::endl;
            bm.erase(20);
            std::cout << bm.Get(20) << std::endl;
            bm.erase(8);
            std::cout << bm.Get(8) << std::endl;
        }
        std::cout << "=============" << std::endl;
    }
};
}  // namespace BitMap