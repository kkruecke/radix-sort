//============================================================================
// Name        : Radix.cpp
// Author      : Kurt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace::std;

// Comments: This radix sort uses division and modulo arithmetic. It uses base 10 as the digit to extract.
// We can speed it up by switching to base 256, a byte, as the digit, and shifting bits to do the multiplication.

typedef vector<unsigned int> input_type;

void radix_sort(input_type & x)
{
    if ( x.empty() ) {
    	return; // at least one element
    }

    typedef deque< deque < input_type::value_type > > buckets_type;

    buckets_type buckets(10); // allocate buckets
    // for sorting decimal numbers

    int pow10 = 1; // pow10 holds powers of 10 (1, 10, 100, ...)

    // find maximum in the array to limit the main loop below
    input_type::value_type max = *max_element(x.begin(), x.end());

    // sort while still digital "columns" to examine. If max is 7897, say, we
    // need only examine four colums. This shortens the loop.
    for(; max != 0 ; max /= 10, pow10 *= 10)     {

        // 1. determine which bucket each element should enter
        // for each element in 'x':
        for(auto elem = x.begin(); elem != x.end(); ++elem) {

                // Use rightmost digit to determine bucket number
                int const bucket_num = ( *elem / pow10 ) % 10;

                // add the element to the list in the bucket:
                buckets[ bucket_num ].push_back( *elem );
        }

        // 2. transfer results of buckets back into main, input array array
        input_type::iterator store_pos = x.begin();

        // for each bucket:
        for(auto bucket = buckets.begin(); bucket != buckets.end(); ++bucket) {

                // for each element in the bucket:
                for(buckets_type::value_type::const_iterator bucket_elem = bucket->begin();
                        bucket_elem != bucket->end(); ++bucket_elem)  {

                        // copy the element into next position in the main array
                        *store_pos++ = *bucket_elem;
                }

                bucket->clear(); // forget the current bucket's list
        }
    }
}

int RandomNumber ()
{
	return (rand() % 1000);
}

int main()
{
	vector<unsigned> input(20);

	generate (input.begin(), input.end(), RandomNumber);

	// using built-in random generator:
	random_shuffle ( input.begin(), input.end() );

    cout << " ** Elements before sorting: " << endl;

    copy(input.begin(), input.end(), ostream_iterator<unsigned int>(cout, " "));

    radix_sort(input);

    cout << endl << " ** Elements after sorting: " << endl;

    copy(input.begin(), input.end(), ostream_iterator<unsigned int>(cout, " "));

    cout << endl;

    return 0;
}
