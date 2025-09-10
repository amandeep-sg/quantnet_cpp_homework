// main.cpp
// show usage of exponential and poisson distribution
// calculate pdf and cdf of each distribution at some value of x
//
// author: amandeep singh gujral

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    using namespace boost::math;

    //=============exponential distribution=============

    exponential_distribution<> myExpo(1.0); // Default type is 'double'
    cout << "Mean: " << mean(myExpo) << ", standard deviation: " << standard_deviation(myExpo) << endl;

    // Distributional properties
    double x = 2.0;

    cout << "pdf: " << pdf(myExpo, x) << endl;
    cout << "cdf: " << cdf(myExpo, x) << endl;

    exponential_distribution<float> myExpo2(0.5);
    cout << "Mean: " << mean(myExpo2) << ", standard deviation: " << standard_deviation(myExpo2) << endl;

    cout << "pdf: " << pdf(myExpo2, x) << endl;
    cout << "cdf: " << cdf(myExpo2, x) << endl;

    // Choose precision
    cout.precision(10); // Number of values behind the comma

    // Other properties
    cout << "\n***exponential distribution: \n";
    cout << "mean: " << mean(myExpo) << endl;
    cout << "variance: " << variance(myExpo) << endl;
    cout << "median: " << median(myExpo) << endl;
    cout << "mode: " << mode(myExpo) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myExpo) << endl;
    cout << "kurtosis: " << kurtosis(myExpo) << endl;
    cout << "characteristic function: " << chf(myExpo, x) << endl;
    cout << "hazard: " << hazard(myExpo, x) << endl;

    //=============poisson distribution=============
    double mean = 3.0;
    poisson_distribution<double> myPoi(mean);

    double val = 4.0;
    cout << endl
         << "pdf: " << pdf(myPoi, val) << endl;
    cout << "cdf: " << cdf(myPoi, val) << endl;

    vector<double> pdfList;
    vector<double> cdfList;

    double start = 0.0;
    double end = 10.0;
    long N = 30; // Number of subdivisions

    val = 0.0;
    double h = (end - start) / double(N);

    for (long j = 1; j <= N; ++j)
    {
        pdfList.push_back(pdf(myPoi, val));
        cdfList.push_back(cdf(myPoi, val));

        val += h;
    }

    for (long j = 0; j < pdfList.size(); ++j)
    {
        cout << pdfList[j] << ", ";
    }

    cout << endl
         << "***" << endl;

    for (long j = 0; j < cdfList.size(); ++j)
    {
        cout << cdfList[j] << ", ";
    }

    return 0;
}