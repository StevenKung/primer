/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#ifndef CACHED_OBJ_H
#define CACHED_OBJ_H
#include <cstddef>

template <class T> class CachedObj {
public:
    void *operator new(std::size_t);
    void operator delete(void *, std::size_t);
    virtual ~CachedObj() { }
    void operator delete[](void *, std::size_t);
    void *operator new[](std::size_t);
protected:
    T *next;
private:
    static void add_to_freelist(T*);
    static std::allocator<T> alloc_mem;
    static T *freeStore;
    static const std::size_t chunk;
};

#include "CachedObj.cc"  // inclusion compilation model

#endif
