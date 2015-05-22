#include <iostream>
#include <string>

using namespace std;

const int maxn = 10010;

typedef long long ll;

ll T, L, X;
string s;

//i=2, j=3, k=4
int mat[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1} 
};

int chartoijk(char x)
{
	return x-'i'+2;
}

int a[maxn];
int head[maxn];
int tail[maxn];

//虚数相乘
int multiply(int x, int y)
{
	int signx = x < 0 ? -1 : 1;
	int signy = y < 0 ? -1 : 1;
	if (abs(x)==1)
		return x*y;
	else
		return signy*signx*mat[abs(x)][abs(y)];
}

int main()
{

	freopen("a.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	cin>>T;
	for (int kase = 1; kase <= T; kase++)
	{
		cin>>L>>X;
		cin>>s;
		printf("Case #%d: ", kase);
		
		//长度不够
		if (L*X < 3)
		{
			puts("NO");
			continue;
		}

		for (int i = 0; i < L; ++i)
			a[i] = chartoijk(s[i]);

		int p = head[0] = a[0], q, tmp;
		for (int i = 1; i < L; ++i)
		{
			q = a[i];
			head[i] = p = multiply(p, q);
		}

		p = tail[0] = a[L-1];
		for (int i = 1; i < L; ++i)
		{
			q = a[L-1-i];
			tail[i] = p = multiply(q, p);
		}

		int S = 1;
		for (int i = 0; i < X%4; ++i)
			S = multiply(S, p);

		// i*j*k 等于 -1
		if (S != -1)
		{
			puts("NO");
			continue;
		}

		ll l, r;

		//找到 head = i 的位置，
		bool find = false;
		S = 1;
		for (ll k = 0; k < min(X, (ll)4); ++k)
		{
			for (ll i = 0; i < L; ++i)
			{
				if (multiply(S, head[i]) == 2)
				{
					find = true;
					l = i+k*L;
					break;
				}
			}
			S = multiply(S, p);
			if (find)	break;
		}
		if (!find)
		{
			puts("NO");
			continue;
		}
		//cout<<l<<" ";

		find = false;
		S = 1;
		for (ll k = 0; k < min(X, (ll)4); ++k)
		{
			for (ll i = 0; i < L; ++i)
			{
				if (multiply(S, tail[i]) == 4)
				{
					find = true;
					r = (L*X-1) - (i+k*L);
					break;
				}
			}
			S = multiply(S, p);
			if (find)	break;
		}
		if (!find)
		{
			puts("NO");
			continue;
		}
		///cout<<r<<" ";

		bool ans = false;
		if (l < r)
			ans = true;

		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}

/**
 * head[i]*tail[L-1-i] = 
 */