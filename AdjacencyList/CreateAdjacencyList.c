/*无向图的创建邻接表创建代码*/
CreateALGraph(GraphAdjList *G) 
{

	int i, j, k, w;

	EdgeNode *e;

	printf("输入顶点数numVertexes和边数numEdges：\n");

	scanf("%d,%d", &G->numVertexes, &G->numEdges);
    
    /*初始化顶点表*/
	for (int i = 0; i < G->numVertexes; ++i)
	{
		/*输入顶点信息*/
		scanf(&G->adjList[i].data);
        
        /*将边表置空*/
		G->adjList[i].firstEdge = NULL;
	}

    /*建立边表*/
	for (int k = 0; k < G->numEdges; ++k)
	{
		printf("输入边（vi,vj）上的顶点序号和权值w：\n");

		scanf("%d,%d,%d", &i, &j, &w);
        
        /*采用头插法来增加结点*/
		e = (EdgeNode *)malloc(sizeof(EdgeNode));

		e->data = j;

		e->weight = w;

		e->next = G->adjList[i].firstEdge;

		G->adjList[i].firstEdge = e;

		/*因为是无向图,所以一次处理两个结点*/

		e = (EdgeNode *)malloc(sizeof(EdgeNode));

		e->data = i;

		e->weight = w;

		e->next = G->adjList[j].firstEdge;

		G->adjList[j].firstEdge = e;
	}
}

对于n个顶点和e条边的图来说,时间复杂度是O(n+e)
