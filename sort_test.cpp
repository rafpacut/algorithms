rafal@rafalPC ~/inf $ ls
algorithms  bash  fizyka  pdf  sort_test.cpp  sort_test.cpp~  watching
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
The program 'g++' can be found in the following packages:
 * g++
 * pentium-builder
Try: sudo apt-get install <selected package>
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:9:36: error: in C++98 ‘n’ must be initialized by constructor, not by ‘{...}’
sort_test.cpp:9:36: error: could not convert ‘{1, 6, 3, 18, 1342, 12}’ from ‘<brace-enclosed initializer list>’ to ‘std::vector<int>’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1
3
6
18
1342
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1
3
6
12
18
1342
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
binary search : 4 not found
12 found
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
binary search : 
4 not found
12 found
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:23:28: error: expected primary-expression before ‘int’
sort_test.cpp:23:28: error: expected ‘;’ before ‘int’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 3
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 12 18 1342 
binary search : 
4 not found
12 found
1 3 6 12 18 1342 bounds: 
lower bound at 2
upper bound at 3
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 6 12 18 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 4
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:30:21: error: no match for ‘operator[]’ in ‘first[i]’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 6 12 18 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 4
first set is not empty
and its size is: 6
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:35:68: error: no match for ‘operator-’ in ‘first.std::set<_Key, _Compare, _Alloc>::find [with _Key = int, _Compare = std::less<int>, _Alloc = std::allocator<int>, std::set<_Key, _Compare, _Alloc>::iterator = std::_Rb_tree_const_iterator<int>, std::set<_Key, _Compare, _Alloc>::key_type = int]((* &6)) - first.std::set<_Key, _Compare, _Alloc>::begin [with _Key = int, _Compare = std::less<int>, _Alloc = std::allocator<int>, std::set<_Key, _Compare, _Alloc>::iterator = std::_Rb_tree_const_iterator<int>]()’
sort_test.cpp:35:68: note: candidates are:
/usr/include/c++/4.6/bits/stl_iterator.h:321:5: note: template<class _Iterator> typename std::reverse_iterator::difference_type std::operator-(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
/usr/include/c++/4.6/bits/stl_iterator.h:378:5: note: template<class _IteratorL, class _IteratorR> typename std::reverse_iterator<_IteratorL>::difference_type std::operator-(const std::reverse_iterator<_IteratorL>&, const std::reverse_iterator<_IteratorR>&)
/usr/include/c++/4.6/bits/stl_bvector.h:181:3: note: std::ptrdiff_t std::operator-(const std::_Bit_iterator_base&, const std::_Bit_iterator_base&)
/usr/include/c++/4.6/bits/stl_bvector.h:181:3: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘const std::_Bit_iterator_base&’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:35:55: error: invalid cast from type ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to type ‘int’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:35:50: error: no match for ‘operator<<’ in ‘std::operator<< [with _Traits = std::char_traits<char>]((* & std::cout), ((const char*)"number 6 is at pos : ")) << first.std::set<_Key, _Compare, _Alloc>::find [with _Key = int, _Compare = std::less<int>, _Alloc = std::allocator<int>, std::set<_Key, _Compare, _Alloc>::iterator = std::_Rb_tree_const_iterator<int>, std::set<_Key, _Compare, _Alloc>::key_type = int]((* &6))’
sort_test.cpp:35:50: note: candidates are:
/usr/include/c++/4.6/ostream:110:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::basic_ostream<_CharT, _Traits>::__ostream_type& (*)(std::basic_ostream<_CharT, _Traits>::__ostream_type&)) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:110:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘std::basic_ostream<char>::__ostream_type& (*)(std::basic_ostream<char>::__ostream_type&) {aka std::basic_ostream<char>& (*)(std::basic_ostream<char>&)}’
/usr/include/c++/4.6/ostream:119:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::basic_ostream<_CharT, _Traits>::__ios_type& (*)(std::basic_ostream<_CharT, _Traits>::__ios_type&)) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>, std::basic_ostream<_CharT, _Traits>::__ios_type = std::basic_ios<char>]
/usr/include/c++/4.6/ostream:119:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘std::basic_ostream<char>::__ios_type& (*)(std::basic_ostream<char>::__ios_type&) {aka std::basic_ios<char>& (*)(std::basic_ios<char>&)}’
/usr/include/c++/4.6/ostream:129:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(std::ios_base& (*)(std::ios_base&)) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:129:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘std::ios_base& (*)(std::ios_base&)’
/usr/include/c++/4.6/ostream:167:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long int) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:167:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘long int’
/usr/include/c++/4.6/ostream:171:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long unsigned int) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:171:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘long unsigned int’
/usr/include/c++/4.6/ostream:175:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(bool) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:175:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘bool’
/usr/include/c++/4.6/bits/ostream.tcc:93:5: note: std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(short int) [with _CharT = char, _Traits = std::char_traits<char>]
/usr/include/c++/4.6/bits/ostream.tcc:93:5: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘short int’
/usr/include/c++/4.6/ostream:182:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(short unsigned int) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:182:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘short unsigned int’
/usr/include/c++/4.6/bits/ostream.tcc:107:5: note: std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(int) [with _CharT = char, _Traits = std::char_traits<char>]
/usr/include/c++/4.6/bits/ostream.tcc:107:5: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘int’
/usr/include/c++/4.6/ostream:193:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(unsigned int) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:193:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘unsigned int’
/usr/include/c++/4.6/ostream:202:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long long int) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:202:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘long long int’
/usr/include/c++/4.6/ostream:206:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long long unsigned int) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:206:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘long long unsigned int’
/usr/include/c++/4.6/ostream:211:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(double) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:211:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘double’
/usr/include/c++/4.6/ostream:215:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(float) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:215:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘float’
/usr/include/c++/4.6/ostream:223:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(long double) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:223:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘long double’
/usr/include/c++/4.6/ostream:227:7: note: std::basic_ostream<_CharT, _Traits>::__ostream_type& std::basic_ostream<_CharT, _Traits>::operator<<(const void*) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__ostream_type = std::basic_ostream<char>]
/usr/include/c++/4.6/ostream:227:7: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘const void*’
/usr/include/c++/4.6/bits/ostream.tcc:121:5: note: std::basic_ostream<_CharT, _Traits>& std::basic_ostream<_CharT, _Traits>::operator<<(std::basic_ostream<_CharT, _Traits>::__streambuf_type*) [with _CharT = char, _Traits = std::char_traits<char>, std::basic_ostream<_CharT, _Traits>::__streambuf_type = std::basic_streambuf<char>]
/usr/include/c++/4.6/bits/ostream.tcc:121:5: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘std::basic_ostream<char>::__streambuf_type* {aka std::basic_streambuf<char>*}’
/usr/include/c++/4.6/bits/basic_string.h:2693:5: note: template<class _CharT, class _Traits, class _Alloc> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.6/ostream:451:5: note: template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, _CharT)
/usr/include/c++/4.6/ostream:456:5: note: template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, char)
/usr/include/c++/4.6/ostream:462:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, char)
/usr/include/c++/4.6/ostream:468:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, signed char)
/usr/include/c++/4.6/ostream:473:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, unsigned char)
/usr/include/c++/4.6/ostream:493:5: note: template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const _CharT*)
/usr/include/c++/4.6/bits/ostream.tcc:323:5: note: template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const char*)
/usr/include/c++/4.6/ostream:510:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const char*)
/usr/include/c++/4.6/ostream:523:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const signed char*)
/usr/include/c++/4.6/ostream:528:5: note: template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const unsigned char*)
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:35:65: error: no match for ‘operator-’ in ‘first.std::set<_Key, _Compare, _Alloc>::find [with _Key = int, _Compare = std::less<int>, _Alloc = std::allocator<int>, std::set<_Key, _Compare, _Alloc>::iterator = std::_Rb_tree_const_iterator<int>, std::set<_Key, _Compare, _Alloc>::key_type = int]((* &6)) - first.std::set<_Key, _Compare, _Alloc>::begin [with _Key = int, _Compare = std::less<int>, _Alloc = std::allocator<int>, std::set<_Key, _Compare, _Alloc>::iterator = std::_Rb_tree_const_iterator<int>]()’
sort_test.cpp:35:65: note: candidates are:
/usr/include/c++/4.6/bits/stl_iterator.h:321:5: note: template<class _Iterator> typename std::reverse_iterator::difference_type std::operator-(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
/usr/include/c++/4.6/bits/stl_iterator.h:378:5: note: template<class _IteratorL, class _IteratorR> typename std::reverse_iterator<_IteratorL>::difference_type std::operator-(const std::reverse_iterator<_IteratorL>&, const std::reverse_iterator<_IteratorR>&)
/usr/include/c++/4.6/bits/stl_bvector.h:181:3: note: std::ptrdiff_t std::operator-(const std::_Bit_iterator_base&, const std::_Bit_iterator_base&)
/usr/include/c++/4.6/bits/stl_bvector.h:181:3: note:   no known conversion for argument 1 from ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to ‘const std::_Bit_iterator_base&’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:35:55: error: invalid cast from type ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to type ‘int’
sort_test.cpp:35:75: error: invalid cast from type ‘std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}’ to type ‘int’
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 6 12 18 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 4
first set is not empty
and its size is: 6
number 6 is at pos : 6
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
sort_test.cpp: In function ‘int main()’:
sort_test.cpp:39:48: error: no match for ‘operator<’ in ‘it < first.std::set<_Key, _Compare, _Alloc>::end [with _Key = int, _Compare = std::less<int>, _Alloc = std::allocator<int>, std::set<_Key, _Compare, _Alloc>::iterator = std::_Rb_tree_const_iterator<int>]()’
sort_test.cpp:39:48: note: candidates are:
/usr/include/c++/4.6/bits/stl_pair.h:207:5: note: template<class _T1, class _T2> bool std::operator<(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
/usr/include/c++/4.6/bits/stl_iterator.h:291:5: note: template<class _Iterator> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
/usr/include/c++/4.6/bits/stl_iterator.h:341:5: note: template<class _IteratorL, class _IteratorR> bool std::operator<(const std::reverse_iterator<_IteratorL>&, const std::reverse_iterator<_IteratorR>&)
/usr/include/c++/4.6/bits/basic_string.h:2510:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::basic_string<_CharT, _Traits, _Alloc>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.6/bits/basic_string.h:2522:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
/usr/include/c++/4.6/bits/basic_string.h:2534:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const _CharT*, const std::basic_string<_CharT, _Traits, _Alloc>&)
/usr/include/c++/4.6/bits/stl_tree.h:856:5: note: template<class _Key, class _Val, class _KeyOfValue, class _Compare, class _Alloc> bool std::operator<(const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&, const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&)
/usr/include/c++/4.6/bits/stl_set.h:713:5: note: template<class _Key, class _Compare, class _Alloc> bool std::operator<(const std::set<_Key, _Compare, _Alloc>&, const std::set<_Key, _Compare, _Alloc>&)
/usr/include/c++/4.6/bits/stl_multiset.h:696:5: note: template<class _Key, class _Compare, class _Alloc> bool std::operator<(const std::multiset<_Key, _Compare, _Alloc>&, const std::multiset<_Key, _Compare, _Alloc>&)
/usr/include/c++/4.6/bits/stl_vector.h:1290:5: note: template<class _Tp, class _Alloc> bool std::operator<(const std::vector<_Tp, _Alloc>&, const std::vector<_Tp, _Alloc>&)
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 6 12 18 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 4
first set is not empty
and its size is: 6
 1
 3
 12
 18
 1342
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 6 12 18 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 4
first set is not empty
and its size is: 6
 1 3 12 18 1342
rafal@rafalPC ~/inf $ g++ sort_test.cpp -o sort_test.e
rafal@rafalPC ~/inf $ ./sort_test.e 
1 3 6 6 12 18 18 1342 
binary search : 
4 not found
12 found
bounds: 
lower bound at 2
upper bound at 4
first set is not empty
and its size is: 6
and after erasing all 6 it contains: 
 1 3 12 18 1342
 and now it's size is 5
rafal@rafalPC ~/inf $ 