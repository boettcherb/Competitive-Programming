/*

pprint is a competitive-programming debugging utility that can print most
common C++ data structures, including nested containers.

Examples:
    int x = 5;
    vector<int> v = {1, 2, 3};
    set<pair<int, long long>> s = {{1, 2}, {5, 3}, {6, 11}};

    pprint(x);
    // >> (x): 5

    pprint(v);
    // >> (v): [1, 2, 3]

    pprint(s);
    // >> (s): [(1, 2), (5, 3), (6, 11)]

Multiple values can also be printed:
    pprint(x, v, s);

The output is written to std::cerr so that debug output does not interfere
with normal program output.

*/

#pragma once

#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>

#define _OUT std::cerr

// Represents a range of iterators [begin, end).
template <class Iterator>
struct DebugRange {
    Iterator begin;
    Iterator end;
};

// Creates a DebugRange from two iterators.
template <class Iterator>
DebugRange<Iterator> makeRange(Iterator begin, Iterator end) {
    return {begin, end};
}

// Selected when T can be printed directly with std::cerr.
template <class T>
auto isPrintable(T* x) -> decltype(_OUT << *x, 0);

// Fallback selected when the expression above is invalid.
template <class T>
char isPrintable(...);

struct debug {
    // Allows debug{a, b, c};
    // Each value is printed in sequence.
    template <typename... Things>
    debug(const Things&... things) {
        printAll(things...);
    }

    template <typename Head, typename... Tail>
    void printAll(const Head& head, const Tail&... tail) {
        *this << head;
        if constexpr (sizeof...(tail) > 0) {
            *this << "  ";
            printAll(tail...);
        }
    }

    void printAll() {}

    // End every debug statement with a newline.
    ~debug() {
        _OUT << std::endl;
    }

    // Directly printable types (int, double, char, string)
    template <class T>
    typename std::enable_if<sizeof(isPrintable<T>(nullptr)) != 1, debug&>::type
    operator<<(const T& value) {
        _OUT << value;
        return *this;
    }

    // Iterable types (vector, set, map, array). If the type cannot be printed
    // directly, attempt to obtain begin/end iterators and print it as a range.
    template <class T>
    typename std::enable_if<sizeof(isPrintable<T>(nullptr)) == 1, debug&>::type
    operator<<(const T& container) {
        return *this << makeRange(std::begin(container), std::end(container));
    }

    // Print std::pair as (first, second)
    template <class T1, class T2>
    debug& operator<<(const std::pair<T1, T2>& pair) {
        return *this << "(" << pair.first << ", " << pair.second << ")";
    }

    // Print a range as: [a, b, c]
    template <class Iterator>
    debug& operator<<(const DebugRange<Iterator>& range) {
        *this << "[";
        bool first = true;
        for (auto it = range.begin; it != range.end; ++it) {
            if (!first) *this << ", ";
            first = false;
            *this << *it;
        }
        return *this << "]";
    }
};

#define pprint(...) _OUT << ">> (" #__VA_ARGS__ "): "; debug{__VA_ARGS__};
#define db(x) _OUT << "<" << (x) << ">" << '\n';
