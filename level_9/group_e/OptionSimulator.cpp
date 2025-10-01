// Main.cpp
// implement Europeanopt class to calculate the price of put and call opts
//
// author: amandeep singh gujral

#include <iostream>
#include <cmath>
#include <list>
#include <string>
#include <vector>

#include "./Options/EuropeanOption.hpp"
#include "./Options/AmericanOption.hpp"
#include "./Options/MatrixPricer.hpp"
#include "./Options/Enum.hpp"
#include "iomanip"
#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"


using namespace INSTRUMENT::OPTION;
using namespace INSTRUMENT::SIMULATOR;

using namespace std;

int main()
{
    
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

    //create list of lables
    list<string> labels;
    labels.push_back("batch 1 call");
    labels.push_back("batch 2 call");
    labels.push_back("batch 3 call");
    labels.push_back("batch 3 call");

    //x 
    auto x = CreateMesh(5, 60,65);

    //list of Y
    list<vector<double>> curves;
    Param name = Param::SPOT;
    option1.toggle("C");
    MatrixPricer<EuropeanOption> Simulator(option1, 60, 65, 5);

    curves.push_back(Simulator.SimulatePrice(name));

    option2.toggle("C"); // toggle to call option
    Simulator.Option(option2); //set option 2 for simulation
    curves.push_back(Simulator.SimulatePrice(name));

    option3.toggle("C"); // toggle to call option
    Simulator.Option(option3);// set option 3 for simulation
    curves.push_back(Simulator.SimulatePrice(name));

    option4.toggle("C"); //toggle to call option
    Simulator.Option(option4); // set option 4 for simulation
    curves.push_back(Simulator.SimulatePrice(name));

    ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, labels, curves, "Option Price vs Spot Price", "x", "y");
    
    return 0;
}