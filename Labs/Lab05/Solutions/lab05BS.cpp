#include <iostream>
#include <string>
using namespace std;

int Mode(const int data[])
{
	int cnt = 0, mx = -1, mxcnt = 0, vals[4], idcs[4], cnts[4] = {0,0,0,0};

	vals[cnt] = data[0];
	idcs[cnt] = 0;
	cnts[cnt] += 1;
	cnt += 1;

	
	if(vals[0] == data[1])
	{
		cnts[0] += 1;
		mxcnt = 2;
		mx = 0;
	}
	else
	{
		vals[cnt];
		idcs[cnt] = 1;
		cnts[cnt] += 1;
		cnt += 1;
	}

	if(vals[0] == data[2])
	{
		cnts[0] += 1;
		
		if(cnts[0] > mxcnt)
		{
			mx = idcs[0];
		}
	}
	else if(cnt >= 2 && vals[1] == data[2])
	{
		cnts[1] += 1;

		if(cnts[1] > mxcnt)
		{
			mx = idcs[1];
		}
	}
	else
	{
		vals[cnt] = data[2];
		idcs[cnt] = 2;
		cnts[cnt] += 1;
		cnt += 1;
	}

	if(vals[0] == data[3])
	{
		cnts[0] += 1;

		if(cnts[0] > mxcnt)
		{
			mx = idcs[0];
		}
	}
	else if(cnt >= 2 && vals[1] == data[3])
	{
		cnts[1] += 1;

		if(cnts[1] > mxcnt)
		{
			mx = idcs[1];
		}
	}
	else if(cnt >= 3 && vals[2] == data[3])
	{
		cnts[2] += 1;

		if(cnts[2] > mxcnt)
		{
			mx = idcs[2];
		}
	}
	else
	{
		vals[cnt] = data[3];
		idcs[cnt] = 3;
		cnts[cnt] += 1;
		cnt += 1;
	}

	if(vals[0] == data[4])
	{
		cnts[0] += 1;

		if(cnts[0] > mxcnt)
		{
			mx = idcs[0];
		}
	}
	else if(cnt >= 2 && vals[1] == data[4])
	{
		cnts[1] += 1;

		if(cnts[1] > mxcnt)
		{
			mx = idcs[1];
		}
	}
	else if(cnt >= 3 && vals[2] == data[4])
	{
		cnts[2] += 1;

		if(cnts[2] > mxcnt)
		{
			mx = idcs[2];
		}
	}
	else if(cnt >= 4 && vals[3] == data[4])
	{
		cnts[3] += 1;

		if(cnts[3] > mxcnt)
		{
			mx = idcs[3];
		}
	}
	return mx;
}

void Print(const int a[])
{
	cout << "[" << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << "," << a[4] << "]";
}
 
int main() 
{
	int data[5], mm;

	for(int i = 0;i < 5;i += 1)
	{
		data[0] = i + 1;

		for(int j = 0;j < 5;j += 1)
		{
			if(j == i)
			{
				continue;
			}
			data[1] = j + 1;
		
			for(int k = 0;k < 5;k += 1)
			{
				if(k == j || k == i)
				{
					continue;
				}
				data[2] = k + 1;

				for(int l = 0;l < 5;l += 1)
				{
					if(l == k || l == j || l == i)
					{
						continue;
					}
					data[3] = l + 1;

					for(int m = 0;m < 5;m += 1)
					{
						data[4] = m + 1;
						mm = Mode(data);
						Print(data);
						cout << " Mode: " << mm << "\n";
					}	
				}
			}
		}
	}				
	return 0;
}
