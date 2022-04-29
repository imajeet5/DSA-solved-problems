#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 5, m = 6, source = 1;
	vector<pair<int, int>> g[n + 1]; // assuming 1 based indexing of graph

	/*
	We can also take input from user as well
	int a, b, wt;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b, wt));
		g[b].push_back(make_pair(a, wt));
	}
	cin>>source;
	 */

	// Constructing the graph
	g[1].push_back({2, 2});
	g[1].push_back({4, 1});
	g[2].push_back({1, 2});
	g[2].push_back({5, 5});
	g[2].push_back({3, 4});
	g[3].push_back({2, 4});
	g[3].push_back({4, 3});
	g[3].push_back({5, 1});
	g[4].push_back({1, 1});
	g[4].push_back({3, 3});
	g[5].push_back({2, 5});
	g[5].push_back({3, 1});
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> distTo(n + 1, INT_MAX); // 1-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push(make_pair(0, source)); // (dist,source)
	while (!pq.empty())
	{
		int dist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		// from the current element of the . priority queue
		// we will iterate over the children, and check their distances
		
		
		for (auto child : g[curr])
		{
			int next = child.first;
			int nextDist = child.second;
			if (distTo[curr] + nextDist < distTo[next])
			{
				distTo[next] = distTo[curr] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
	cout << "The distances from source " << source << " are : \n";
	for (int i = 1; i <= n; i++)
		cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}