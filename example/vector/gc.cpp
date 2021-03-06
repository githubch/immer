#include <immer/heap/gc_heap.hpp>
#include <immer/heap/heap_policy.hpp>
#include <immer/refcount/no_refcount_policy.hpp>
#include <immer/memory_policy.hpp>
#include <immer/vector.hpp>

#include <iostream>

// declare a memory policy for using a tracing garbage collector
using gc_policy = immer::memory_policy<
    immer::heap_policy<immer::gc_heap>,
    immer::no_refcount_policy,
    false>;

// alias the vector type so we are not concerned about memory policies
// in the places where we actually use it
template <typename T>
using my_vector = immer::vector<T, gc_policy>;

int main()
{
    auto v = my_vector<const char*>()
        .push_back("hello, ")
        .push_back("world!\n");

    for (auto s : v) std::cout << s;
}
