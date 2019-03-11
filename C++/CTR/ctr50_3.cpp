/*
In this noncompliant code example, the f_imp() function is given the (correct) ending iterator e for a container, and b is an iterator from the same container. However, it is possible that b is not within the valid range of its container. For instance, if the container were empty, b would equal e and be improperly dereferenced.
*/

#include <iterator>
  
template <typename ForwardIterator>
void f_imp(ForwardIterator b, ForwardIterator e, int val, std::forward_iterator_tag) {
  do {
    *b++ = val;
  } while (b != e);
}
 
template <typename ForwardIterator>
void f(ForwardIterator b, ForwardIterator e, int val) {
  typename std::iterator_traits<ForwardIterator>::iterator_category cat;
  f_imp(b, e, val, cat);
}