// main.cpp
// simulate 6 face dice throwing experiment using uniform int distribution
//
// author: amandeep singh gujral

#include <boost/random.hpp>
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    boost::random::mt19937 my_rng;
    my_rng.seed(static_cast<boost::int32_t>(std::time(0))); // set the sead

    boost::random::uniform_int_distribution<int> six(1, 6); // uniform in range [1,6]

    map<int, long> statistic; // structure to hold outcome + frequencies
    int outcome;

    unsigned int trials; // no of trials
    cout << "Enter number of trials: ";
    cin >> trials;

    // intialise statistics
    for (int i = 0; i < 6; i++)
    {
        statistic[i + 1] = 0;
    }

    // simulate throw dice
    for (int i = 0; i < trials; i++)
    {
        outcome = six(my_rng);
        statistic[outcome]++; // increment the frequency by 1
    }

    cout << fixed << setprecision(4); // set the precision of cout

    // produce the answer
    cout << "how many number of trials? " << trials << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "Trial " << i + 1 << " has " << 100.0 * double(statistic[i + 1]) / double(trials) << "% outcomes" << endl;
    }
    return 0;
}
