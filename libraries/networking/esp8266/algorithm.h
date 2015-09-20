#ifndef ALGORITHM_H
#define ALGORITHM_H

// because Arduino doesn't include the stdlib, not even really useful things like this

namespace std {

	/// http://www.cplusplus.com/reference/algorithm/min_element/
	template <class ForwardIterator>
	ForwardIterator min_element( const ForwardIterator first, const ForwardIterator last )
	{
		if (first==last) return last;
		ForwardIterator smallest = first;
		
		while (++first!=last)
			if (*first<*smallest)
				smallest=first;
		return smallest;
	}

}

#endif        //  #ifndef ALGORITHM_H
