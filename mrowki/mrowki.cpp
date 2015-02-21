#include <iostream>
#include <vector>
#include <deque>

struct V
{
	int t, s;
	V() :
		t(-1),
		s(-1)
	{}
};

template <typename Vertex, typename Edge>
struct Graph
{
	struct BasicEdge 
	{
		int v;
	};
	struct E : Edge, BasicEdge {};
	struct V : Vertex, std::vector<E> {};
	std::vector<V> g;

	Graph(int n) : g(n) {}

	void Bfs(int s)
	{
		for (std::vector<V>::iterator it = g.begin(); it != g.end(); ++it)
		{
			it->t = -1;
			it->s = -1;
		}

		std::deque<int> queue;
		queue.push_back(s);

		g[s].t = 0;
		while (queue.empty() == false)
		{
			int n = queue.front();
			queue.pop_front();

			int nt = g[n].t + 1;

			for (std::vector<E>::iterator it = g[n].begin(); it != g[n].end(); ++it)
			{
				queue.push_back(it->v);
				g[it->v].t = nt;
				g[it->v].s = n;
			}
		}
	}

	void EdgeD(int a, int b)
	{
		Edge e;
		e.v = b;
		g[a].push_back(e);
	}
};

struct Empty
{};

int main()
{
	int n, m, s, a, b;
	std::cin >> n >> m >> s;
	Graph<V, Empty> g(n);
	for (int i = 0; i < m; ++i)
	{
		std::cin >> a >> b;
		g.EdgeD(a,b);
	}

	g.Bfs();

	for (int i = 0; i < n; ++i)
	{
		std::cout << "Wierzcholek " << i << ", czas: " << g[i].t << ", ojciec: " << g[i].s << "\n";
	}
	return 0;
}
