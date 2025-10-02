# Table Of Contents
- [Section C.a](#Section-ca)
- [Section C.b](#section-cb)
- [Section C.c](#section-cc)
- [Section D.a](#section-da)
- [Section D.b](#section-db)

# Section C.a
## Compile and run the code
During the initial compile, following errors and warnings were generated at the compile time

### List of error and warnings
#### Errors
```
./UtilitiesDJD/Geometry/Range.hpp:46:2: error: use of undeclared identifier 'std'
        std::vector<Type> mesh(long nSteps) const;      // Create a discrete mesh
```
```
UtilitiesDJD/Geometry/Range.cpp:151:1: error: use of undeclared identifier 'std'
std::vector<Type> Range<Type>::mesh(long nSteps) const
```
```
UtilitiesDJD/Geometry/Range.cpp:156:2: error: use of undeclared identifier 'std'
        std::vector<Type>result(nSteps + 1);
```
```
UtilitiesDJD/Geometry/Range.cpp:156:14: error: 'Type' does not refer to a value
        std::vector<Type>result(nSteps + 1);
                    ^
UtilitiesDJD/Geometry/Range.cpp:150:17: note: declared here
template <class Type>
```
```
UtilitiesDJD/Geometry/Range.cpp:156:19: error: use of undeclared identifier 'result'
        std::vector<Type>result(nSteps + 1);
```
```
UtilitiesDJD/Geometry/Range.cpp:162:3: error: use of undeclared identifier 'result'
                result[i] = val;
```
```
UtilitiesDJD/Geometry/Range.cpp:166:9: error: use of undeclared identifier 'result'
        return result;
```
```
TestMC.cpp:24:2: error: missing 'typename' prior to dependent type name 'std::vector<T>::const_iterator'
        std::vector<T>::const_iterator i;
```
#### Warning
```
TestMC.cpp:142:2: warning: delete called on 'NormalGenerator' that is abstract but has non-virtual destructor [-Wdelete-abstract-non-virtual-dtor]
        delete myNormal;
```
### Solutions

To cater to there, following implementation were done

1. Add `#include <vector>` in Range.hpp and Range.cpp files
2. Add `typename` before the vector declaration
3. Declare and define the destructor in the NormalGenerator class

### Compile comand
```
clang++ -std=c++14 TestMC.cpp UtilitiesDJD/RNG/NormalGenerator.cpp UtilitiesDJD/Geometry/Range.cpp -o myCode
```

## Code explanation of TestMC.cpp
### Construct a simulated path of the underlying stock
To achieve this,
1. User is prompted to give no of subintervals(N)
2. Range class is used to get the vector of size N+1 between 0.0 and T. The vector contains the value of each step from 0.0 to T.

The following code in the **TextMC.cpp** is helps achieves the construction of the simulated path
```
	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	std::vector<double> x = range.mesh(N);
```

### Calculate the stock price
To calculate the option price, we use the original assumption of black scholes i.e. the stock price follows the geometric brownian motion. The equation is as follow:

$$dS(t)=r*S(t)dt+σ*S(t)*dW(t)$$

- S(t) : Stock Price   
- r : risk free rate
- σ : Volatility (diffusion cofficient)
- dW(t) : increment of Wiener process(or brownian motion)

Approximating the solution of the above equation using Euler-Maruyama scheme, we get the following

$$S_{n+1} = S_n +r*S_n*Δt+σ*S_n*ΔW_n$$

- $Δt = T/N$
- $ΔW = \sqrt{Δt}*Z_n$

The following code in the **TestMC.cpp** file is used to compute the price for each step

```
double k = myOption.T / double (N);
double sqrk = sqrt(k);
// Create a random number
dW = myNormal->getNormal();
				
// The FDM (in this case explicit Euler)
VNew = VOld  + (k * drift(x[index-1], VOld)) + (sqrk * diffusion(x[index-1], VOld) * dW);
```
Drift is $r*Δt$ and is computed using the following code using in **TestMC.cpp**

```
double drift(double t, double X)
{ // Drift term
	return (data->r)*X; // r - D
}
```

Diffusion is $σ*S_n$ and is computed using the following code

```
double diffusion(double t, double X)
{ // Diffusion term	
	double betaCEV = 1.0;
	return data->sig * pow(X, betaCEV);		
}
```

### Calculate the option price using payoff function

The following member function of the **OptionData.hpp** is used to calculate the option price

```
double myPayOffFunction(double S)
{ // Payoff function
	if (type == 1)
	{ // Call
		return max(S - K, 0.0);		}
	else
	{ // Put
		return max (K - S, 0.0);
	}
}
```

### Calculate the average call price
The above three executed for Nsim time and then avg it taken using the following line of code

`price += (tmp)/double(NSim);`

### Discount the price computed

using the following code, the expected price computed using the following code

```
// D. Finally, discounting the average price
price *= exp(-myOption.r * myOption.T);
```

# Section C.b
In this section, we will run **TestMC.cpp** code for batch-1 and batch-2 by varying number of sub-intervals(N) and number of simulations (Nsim).

The simulations for both batch 1 and 2 will be executed for following values of N and Nsim.
- N = [100,200,300,400,500]
- Nsim = [10000, 100000, 1000000, 10000000]

**Link to google sheets workbook:** [link](https://docs.google.com/spreadsheets/d/1IAtablFFOv3s3nWLMF0NHzeMZW41vmouTA1qBPEFRHg/edit?usp=sharing)
 
The **key observations** are following
1. The prices converge to exact value as Nsim increases for same values of N. 
2. There is no liner relationship between N and relative error. The relative error increases/decreases for different values of N as Nsim increases
3. For prices to converge upto two places behind decimal, N >= 400 and Nsim >= 1,000,000

### Batch-1
The option parameters of batch-1 are as follow
- T = 0.25
- K = 65
- sig = 0.30
- r = 0.08
- S = 60 
- C price = 2.13337
- P price = 5.84628

Following cross-tabulation shows the computed option prices using Monte Carlo method. The prices which are accurate upto two places behind the decimal are highlighted in bold.

The graph show the convergence of option prices to the exact option price and decreased in relative error, as Nsim increases. 

#### Call price data
![MC call price](./images/batch_1_call_price.png)
![MC call price convergence](./images/batch_1_call_price_convergence.png)
![MC call price relative error](./images/batch_1_call_price_relative_error.png)

#### Put price data
![MC put price](./images/batch_1_put_price.png)
![MC put price convergence](./images/batch_1_put_price_convergence.png)
![MC put price relative error](./images/batch_1_put_price_relative_error.png)


### Batch-2
The option parameters of batch-2 are as follow
- T = 1.0
- K = 100
- sig = 0.2
- r = 0.0
- S = 100
- C price = 7.96557
- P price = 7.96557

Following cross-tabulation shows the computed option prices using Monte Carlo method. The prices which are accurate upto two places behind the decimal are highlighted in bold.

The graph show the convergence of option prices to the exact option price and decreased in relative error, as Nsim increases. 

#### Call price data
![MC call price](./images/batch_2_call_price.png)
![MC call price convergence](./images/batch_2_call_price_convergence.png)
![MC call price relative error](./images/batch_2_call_price_relative_error.png)

#### Put price data
![MC put price](./images/batch_2_put_price.png)
![MC put price convergence](./images/batch_2_put_price_convergence.png)
![MC put price relative error](./images/batch_2_put_price_relative_error.png)

# Section C.c
The option parameters of batch-4 are as follow
- T = 30.0
- K = 100.0
- sig  = 0.30
- r = 0.08
- S = 100.0
- C price = 92.17570
- P price = 1.24750

The simulations for batch 4 will be executed for following values of N and Nsim.
- N = [600,700,800,900,1000]
- Nsim = [100000, 1000000, 10000000]

**Link to google sheets workbook:** [Link](https://docs.google.com/spreadsheets/d/1IAtablFFOv3s3nWLMF0NHzeMZW41vmouTA1qBPEFRHg/edit?gid=33164124#gid=33164124&range=A1:I31)

The **key observations** are following
1. The call price do not converge, even upto 2 place behind decimal. Where as put price converge upto 2 places behind decimal
2. For prices to converge, N >= 800 and Nsim >= 1,000,000
3. The standard error decreases significantly as Nsim increases from 100,000 to 10,000,000
4. Option prices tend to diverge for N > 900 and Nsim > 10,000,000

#### Call option
Following cross-tabulation shows the computed option prices using Monte Carlo method. The prices which are accurate upto two places behind the decimal are highlighted in bold.

The graph show the convergence of option prices to the exact option price and decreased in relative error, as Nsim increases. 

#### Call price data
![MC call price](./images/batch_4_call_price.png)
![MC call price convergence](./images/batch_4_call_price_convergence.png)
![MC call price relative error](./images/batch_4_call_price_relative_error.png)
![MC call price standard error](./images/batch_4_call_price_standard_error.png)

#### Put price data
![MC put price](./images/batch_4_put_price.png)
![MC put price convergence](./images/batch_4_put_price_convergence.png)
![MC put price relative error](./images/batch_4_put_price_relative_error.png)
![MC put price standard error](./images/batch_4_put_price_standard_error.png)

# Section d.a
The following code block is added to **TestMC.cpp** to compute the standard deviation and standard error of the simulation. It takes in a vector of prices, r and T. In echange, it returns a vector of size 2 containing value of standard deviation and standard error.

```
vector<double> SDSE(const vector<double> &price, const double r, const double T)
{
	vector<double> result;
	double p_sq = 0.0, p = 0.0;
	for (int i = 0; i < price.size(); ++i)
	{
		p_sq += pow(price[i], 2);
		p += price[i];
	}
	result.push_back(sqrt((p_sq - pow(p, 2) / price.size()) / (price.size() - 1)) * exp(-r * T));
	result.push_back(result[0] / sqrt(price.size()));
	return result;
}
```

# Section D.b
In this section, we will run **TestMC.cpp** code for batch-1 and batch-2 by varying number of sub-intervals(N) and number of simulations (Nsim).

The simulations for both batch 1 and 2 will be executed for following values of N and Nsim.
- N = [100,200,300,400,500]
- Nsim = [10000, 100000, 1000000, 10000000]

**Link to google sheets workbook:** [link](https://docs.google.com/spreadsheets/d/1IAtablFFOv3s3nWLMF0NHzeMZW41vmouTA1qBPEFRHg/edit?usp=sharing)
 
The **key observations** are following
1. The error bars in the chart clearly show that standard deviation varies a lot for different values of N, relatively, for smaller value of Nsim.
2. As the Nsim increases, the standard error decreases.
3. Standard deviation and standard error, both doesnot convey whether the prices computed will converge or not. This is observed in Section c.c when computing prices of batch-4.

### Batch-1
The option parameters of batch-1 are as follow
- T = 0.25
- K = 65
- sig = 0.30
- r = 0.08
- S = 60 
- C price = 2.13337
- P price = 5.84628

Following cross-tabulation shows the computed standard deviation and standard error of the Monte Carlo simulation. The graph shows the variation of standard error vs N for different values of Nsim.

#### Call option
![MC call price standard deviation](./images/batch_1_call_price_standard_deviation.png)
![MC call price standard error](./images/batch_1_call_price_standard_error.png)

#### Put option
![MC put price standard deviation](./images/batch_1_put_price_standard_deviation.png)
![MC put price standard error](./images/batch_1_put_price_standard_error.png)

### Batch-2
The option parameters of batch-2 are as follow
- T = 1.0
- K = 100
- sig = 0.2
- r = 0.0
- S = 100
- C price = 7.96557
- P price = 7.96557

Following cross-tabulation shows the computed standard deviation and standard error of the Monte Carlo simulation. The graph shows the variation of standard error vs N for different values of Nsim.

#### Call option
![MC call price standard deviation](./images/batch_2_call_price_standard_deviation.png)
![MC call price standard error](./images/batch_2_call_price_standard_error.png)

#### Put option
![MC put price standard deviation](./images/batch_2_put_price_standard_deviation.png)
![MC put price standard error](./images/batch_2_put_price_standard_error.png)