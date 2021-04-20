#include <iostream>

using namespace std;

#define infinity 2147483647

struct edge
{
	int source;
	int destination;
	int length;
};





int main()
{
	int M, N, S;

	cin >> N >> M >> S;

	int a, b, c;
	
	edge* edges = new edge[M];

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		edges[i].source = a;
		edges[i].destination = b;
		edges[i].length = c;
	}

	int* dist =  new int[N];

	for (int i = 0; i < N; i++)
	{
		dist[i] = infinity;
	}

	dist[S - 1] = 0;

	int source;
	int destination;
	int length;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			source = edges[j].source;
			destination = edges[j].destination;
			length = edges[j].length;

			if (dist[destination - 1] > dist[source - 1] + length)
			{
				if (dist[source - 1] != infinity)
				{
					dist[destination - 1] = dist[source - 1] + length;
				}
			}
		}
	}

	bool test = false;

	int* lastRow = dist;

	for (int j = 0; j < M; j++)
	{
		source = edges[j].source;
		destination = edges[j].destination;
		length = edges[j].length;

		if (lastRow[destination - 1] > dist[source - 1] + length)
		{
			test = true;
		}
	}



	if (test == true)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}


	return 0;
}