广度优先遍历BFS（Breadth-First-Search）
注：广度优先遍历是借助队列实现的

/*邻接矩阵的广度优先遍历算法*/
void BFSTraverse(MGraph G)
{
	int i, j;

	Queue Q;
    
    for (i = 0; i < G->numVertexes; ++i)
    {
    	visited[i] = 0;
    }

    /*初始化一辅助用的队列*/
    InitQueue(&Q);

    /*对每个顶点做循环处理*/
    for (i = 0; i < G->numVertexes; ++i)
    {
    	if (!visited[i])
    	{
    		visited[i] = 1;

    		printf("%c", G.vexs[i]);

    		EnQueue(&Q, i);

    		while(!QueueEmpty(Q))
    		{
    			DeQueue(&Q, &i);

    			for (j = 0; j < G->numVertexes; ++j)
    			{
    				if (G.arc[i][j] == 1 && !visited[j])
    				{
    					/*将找到的顶点标记为已访问*/
    					visited[j] = 1;
                        
                        /*打印顶点*/
    					printf("%c", G->vexs[j]);
                        
                        /*将找到的顶点入队列*/
    					EnQueue(&Q, j);
    				}
    			}
    		}
    	}
    }

}