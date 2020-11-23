#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int PrimeCount(int lo,int hi)
{
	if(lo < 0)
	{
		lo *= -1;
	}

	if(hi < 0)
	{
		hi *= -1;
	}

	int mx = (hi > lo)?(hi):(lo);
	int mn = hi + lo - mx;
	int cnt = 0;
	bool prime;

	for(int i = mn;i <= mx;i += 1)
	{
		prime = true;

		for(int j = 2;j * j <= i;j += 1)
		{
			if(i % j == 0)
			{
				prime = false;
				break;
			}
		}

		if(prime)
		{
			cout << i << " ";
			cnt += 1;
		}
	}
	cout << "\n";

	return cnt;
}

void Permutation(const string& values,const int p)
{
	int n = values.size();

	if(p > 0 && p < n)
	{
		int idx[p], s = 0, t = (n - 1) * p;

		for(int i = 0;i < p;i += 1)
		{
			idx[i] = 0;
		}

		while(true)
		{
			for(int i = 0;i < p;i += 1)
			{
				cout << values[idx[i]];
			}
			cout << "\n";
			
			if(s == t)
			{
				break;
			}

			for(int i = p - 1;i >= 0;i -= 1)
			{
				s -= idx[i];
				idx[i] = (idx[i] + 1) % n;
				s += idx[i];

				if(idx[i] != 0)
				{
					break;
				}
			}

		}
	}
}

int main()
{
	srand(time(NULL));
	int lo, hi, p, c;
	string wrd;
	
	lo = rand() % 100 + 1;
	hi = lo + (rand() % 50 + 1);

	c = PrimeCount(lo,hi);
	cout << "\nPrime Count Between " << lo << " and " << hi << " is " << c << "\n";

	cout << "\nEnter a word: ";
	cin >> wrd;

	cout << "Enter a number: ";
	cin >> p;
	cout << "\n";
	Permutation(wrd,p);

	return 0;
}
