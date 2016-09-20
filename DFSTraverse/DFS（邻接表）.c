深度优先遍历方式访问邻接表

int visited[numVertexs];

void DFS(GraphAdjList G, int i)
{
	EdgeNode *p;

	visited[i] = 1;

	printf("%c", G->adjList[i].data);

	p = G->adjList[i].firstedge;

	while(p)
	{
		if (!visited[p->adjvex])
		{
			DFS(G, p->adjvex);
		}

		p = p->next;
	}
}

void DFSTraverse(GraphAdjList G)
{
	int i;
	for (int i = 0; i < G->numVertexes; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < G->numVertexes; ++i)
	{
		if (!visited[i])
		{
			/*对未访问过的顶点调用DFS，若是连通图则只需要递归一次*/
			DFS(G, i);
		}
	}
}

邻接表做存储结构的时候，找邻接点所需要的时间取决于顶点和边的数量，所以是O(n+e).

通过对比得知，对于点多边少的稀疏图来说，邻接表结构是的算法在时间效率上大大提高。