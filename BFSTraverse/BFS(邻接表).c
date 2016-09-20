邻接表的广度优先遍历
void BFSTraverse(GraphAdjList GL)
{
	int i;

	EdgeNode *p;

	Queue Q;

	for (i = 0; i < GL->numVertexes; ++i)
	{
		visited[i] = 0;
	}

	InitQueue(&Q);

	for (i = 0; i < GL->numVertexes; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;

			printf("%c", GL->adjList[i].data);

			EnQueue(&Q, i);

			while(!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);

				p = GL->adjList[i].firstEdge;

				while(p)
				{
					if (!visited[p->adjvex])
					{
						printf("%c", GL->adjList[p->adjvex].data);

						EnQueue(&Q, &p->adjvex);
					}

					p = p->next;
				}
			}
		}
	}
}