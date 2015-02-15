#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

const int maxn = 1000 + 5;

int n;

struct Point{
	
	int x, y;

	Point(){};

	Point(int tx, int ty):
	x(tx),
	y(ty) 
	{}

	bool operator < (const Point& other) const
	{
		return (x == other.x && y < other.y) || x < other.x;
	}

	const Point operator - (const Point& other) const
	{
		return Point(x-other.x, y-other.y);
	}

}points[maxn];

typedef Point Vec;

int main() 
{
//	freopen("a.txt", "r", stdin);

	while(cin>>n&&n)
	{
		for(int i=0; i<n; i++)
			scanf("%d %d", &points[i].x, &points[i].y);

		sort(points, points+n);

		int count = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				Point other1, other2;
				Vec ij = points[j] - points[i];

				other1 = Point(ij.y+points[i].x, -ij.x+points[i].y);
				other2 = Point(ij.y+points[j].x, -ij.x+points[j].y);
				if(binary_search(points, points+n, other1) && binary_search(points, points+n, other2))
					count++;

				other1 = Point(-ij.y+points[i].x, ij.x+points[i].y);
				other2 = Point(-ij.y+points[j].x, ij.x+points[j].y);
				if(binary_search(points, points+n, other1) && binary_search(points, points+n, other2))
					count++;
			}
		}

		cout<<count/4<<endl;
	}
	return 0;
}