
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include "radix256.h"

using namespace std;

int RandomNumber ()
{
	return (rand() % 1000);
}

int main(int argc, char** argv) 
{
    vector<unsigned> input(20);

    generate (input.begin(), input.end(), RandomNumber);

    // using built-in random generator:
    random_shuffle ( input.begin(), input.end() );

    cout << " ** Elements before sorting: " << endl;

    copy(input.begin(), input.end(), ostream_iterator<unsigned int>(cout, " "));

    radix_sort_base256(input);

    cout << endl << " ** Elements after sorting: " << endl;

    copy(input.begin(), input.end(), ostream_iterator<unsigned int>(cout, " "));

    cout << endl;

    return 0;

}

