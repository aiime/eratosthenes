#include <iostream>
#include <vector>

using namespace std;

/*
Find all prime numbers up to n.
*/
vector<int> eratosthenes(unsigned int n)
{
	if (n < 2)
	{
		return vector<int>();
	}

	/*
	Vector indexes of "corresponding_vec" represent natural numbers; elements of the vector represent
	primality of corresponding natural number ("true" if prime, "false" if not).
	*/
	vector<bool> corresponding_vec(n + 1, true);

	corresponding_vec[0] = false; // Not a prime initially.
	corresponding_vec[1] = false; // Not a prime initially.

	for (unsigned int i = 2; i < corresponding_vec.size(); i++)
	{
		if (corresponding_vec[i] == true)
		{
			for (int j = 2; (j * i) < corresponding_vec.size(); j++)
			{
				corresponding_vec[j * i] = false;
			}
		}
	}

	vector<int> primes;

	for (unsigned int i = 0; i < corresponding_vec.size(); i++)
	{
		if (corresponding_vec[i] == true)
		{
			primes.push_back(i);
		}
	}

	return primes;
}

int main()
{
	vector<int> primes = eratosthenes(101);

	for (unsigned int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << " ";
	}

	return 0;
}
