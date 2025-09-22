// Main.cpp
// implement Europeanopt class to calculate the price of put and call opts
//
// author: amandeep singh gujral

#include <iostream>

#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
#include "MatrixPricer.hpp"
#include "Enum.hpp"
#include "iomanip"

using namespace INSTRUMENT::OPTION;
using namespace INSTRUMENT::SIMULATOR;

using namespace std;

// group A: a & b
int main()
{
    // group A
    // A.a & a.b compute option price using direct method and check put-call parity
    //  bath 1
    EuropeanOption option1(0.08, 65.0, 0.25, 0.30, 0.08, 60.0);
    double c1 = 2.13337;
    double p1 = 5.84628;

    cout << "********* Batch 1 **********" << endl;
    cout << "call price: " << option1.Price() << endl;
    cout << "call price from put-call parity: " << option1.Parity(p1) << endl;
    cout << "delta call: " << option1.Delta() << endl;
    option1.toggle();
    cout << "put price: " << option1.Price() << endl;
    cout << "put price from put-call parity: " << option1.Parity(c1) << endl;
    cout << "delta put: " << option1.Delta() << endl;
    option1.Parity(c1, p1, 0.00001) ? cout << "is parity: true" << endl : cout << "is parity: false" << endl;
    cout << endl;

    // bath 2
    EuropeanOption option2(0.0, 100.0, 1.0, 0.20, 0.0, 100.0);
    double c2 = 7.96557;
    double p2 = 7.96557;

    cout << "********* Batch 2 **********" << endl;
    cout << "call price: " << option2.Price() << endl;
    cout << "call price from put-call parity: " << option2.Parity(p2) << endl;
    cout << "delta call: " << option2.Delta() << endl;
    option2.toggle();
    cout << "put price: " << option2.Price() << endl;
    cout << "put price from put-call parity: " << option2.Parity(c2) << endl;
    cout << "delta put: " << option2.Delta() << endl;
    option2.Parity(c2, p2, 0.00001) ? cout << "is parity: true" << endl : cout << "is parity: false" << endl;
    cout << endl;

    // bath 3
    EuropeanOption option3(0.12, 10.0, 1.0, 0.50, 0.12, 5.0);
    double c3 = 0.204058;
    double p3 = 4.07326;

    cout << "********* Batch 3 **********" << endl;
    cout << "call price: " << option3.Price() << endl;
    cout << "call price from put-call parity: " << option3.Parity(p3) << endl;
    cout << "delta call: " << option3.Delta() << endl;
    option3.toggle();
    cout << "put price: " << option3.Price() << endl;
    cout << "put price from put-call parity: " << option3.Parity(c3) << endl;
    cout << "delta put: " << option3.Delta() << endl;
    option3.Parity(c3, p3, 0.00001) ? cout << "is parity: true" << endl : cout << "is parity: false" << endl;
    cout << endl;

    // bath 4
    EuropeanOption option4(0.08, 100.0, 30.0, 0.30, 0.08, 100.0);
    double c4 = 92.17570;
    double p4 = 1.24750;

    cout << "********* Batch 4 **********" << endl;
    cout << "call price: " << option4.Price() << endl;
    cout << "call price from put-call parity: " << option4.Parity(p4) << endl;
    cout << "delta call: " << option4.Delta() << endl;
    option4.toggle();
    cout << "put price: " << option4.Price() << endl;
    cout << "put price from put-call parity: " << option4.Parity(c4) << endl;
    cout << "delta put: " << option4.Delta() << endl;
    option4.Parity(c4, p4, 0.00001) ? cout << "is parity: true" << endl : cout << "is parity: false" << endl;
    cout << endl;

    // A.c simulate option price by changing spot price
    Param name[2];
    name[0] = Param::STRIKE;
    name[1] = Param::SPOT;
    option1.toggle();
    MatrixPricer<EuropeanOption> Simulator(option1, 60, 65, 5);

    for (const double i : Simulator.SimulatePrice(name[1]))
    {
        cout << setw(10) << i << " ";
    }
    cout << endl
         << endl;

    // A.d simulate option price by changing strike and spot price
    for (const vector<double> row : Simulator.SimulatePrice(name))
    {
        for (const double i : row)
            cout << setw(10) << i << " ";
        cout << endl;
    };
    cout << endl;

    // B.a compute gamma of the option
    cout << "********* Option 5 **********" << endl;
    EuropeanOption option5(0.1, 100.0, 0.5, 0.36, 0.0, 105.0);
    double deltaCall5 = 0.5946;
    double deltaPut5 = -0.3566;
    cout << "delta call: " << option5.Delta() << endl;
    option5.toggle();
    cout << "delta put: " << option5.Delta() << endl;
    cout << "gamma: " << option5.Gamma() << endl
         << endl;

    // B.b simulate delta by changing spot price
    option5.toggle();
    Simulator.Option(option5);
    Simulator.Start(100);
    Simulator.End(105);

    for (const double i : Simulator.SimulateDelta(name[1]))
    {
        cout << setw(10) << i << " ";
    }
    cout << endl
         << endl;

    // B.c simulate delta by changing the spot and strike price
    for (const vector<double> row : Simulator.SimulateDelta(name))
    {
        for (const double i : row)
            cout << setw(10) << i << " ";
        cout << endl;
    };
    cout << endl;

    // B.d divide differance to approximate greeks
    double divisor = 1;
    cout << setw(10) << "divisor" << setw(10) << "delta" << endl;
    while (divisor > 1.0e-4)
    {
        cout << setw(10) << divisor << setw(10) << option5.Delta(divisor) << endl;
        divisor /= 10;
    }
    cout << endl;
    divisor = 1;
    cout << setw(10) << "h" << setw(10) << "gamma" << endl;
    while (divisor > 1.0e-4)
    {
        cout << setw(10) << divisor << setw(10) << option5.Gamma(divisor) << endl;
        divisor /= 10;
    }
    cout << endl;

    // group B
    // B.b compute price of american options
    cout << "********* Option 5: American Option **********" << endl;
    AmericanOption option6(0.1, 100.0, 0.1, 0.02, 110);
    double c5 = 18.5035;
    double p5 = 3.03106;
    cout << "call price: " << option6.Price() << endl;
    option6.toggle();
    cout << "put price: " << option6.Price() << endl
         << endl;

    // B.c simulate option price by changing spot price
    option6.toggle();
    MatrixPricer<AmericanOption> Simulator1(option6, 100, 110, 5);

    for (const double i : Simulator1.SimulatePrice(name[1]))
    {
        cout << setw(10) << i << " ";
    }
    cout << endl
         << endl;

    // B.d simulate delta by changing the spot and strike price
    for (const vector<double> row : Simulator1.SimulatePrice(name))
    {
        for (const double i : row)
            cout << setw(10) << i << " ";
        cout << endl;
    };
    cout << endl;

    return 0;
}