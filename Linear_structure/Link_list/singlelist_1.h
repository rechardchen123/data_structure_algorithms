#ifndef __LIST_H__
#define __LIST_H__

#include <exception>
#include <stdio.h>

template <typename T>
class List
{
public:
    List() {}
    virtual bool insert(const T &e) = 0;
    virtual bool insert(int i, const T &e) = 0;
    virtual bool remove(int i) = 0;
    virtual bool set(int i, const T &e) = 0;
    virtual bool get(int i, T &e) const = 0;
    virtual int find(const T &e) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;

protected:
    List(const List &);
    List &operator=(const List &);
};

#endif /*__LIST_H__*/
