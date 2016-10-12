/*
    MST性质：假设N=(V,{E})是一个连通网，U是顶点V的一个子集。若（u,v）是一条具有最小权值的边，且u属于U，v属于V-U
  ，那么必存在一棵最小生成树，其包含边（u,v）
*/

  /*Prim算法和Kruskal算法均是基于MST性质的算法*/

  /*
    Prim算法：假设N=(V,{E})是一个连通网，TE是N上最小生成树的边的集合。算法从U={v0},TE={}开始，重复执行以下操作：
    在所有的u属于U，v属于V-U的边（u,v）中挑选出一条代价最小的边（u0,v0）并入TE，同时把u0并入U，直至U=V为止。
    此时，TE中必有n-1条边，则T=（V,{TE})是N的最小生成树

  */
    /*图的存储结构是邻接矩阵，且两个顶点间不存在的边的权值为机内允许的最大值（INT_MAX）*/

    /*Prim算法实现*/
    void MiniSpanTree_Prim(Graph G, VertexType u) //最初的U中的唯一顶点
    {
    	//用Prim算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边
    	//记录从定点U到V-U代价最小边的辅助数组
    	/*struct
    	{
    		VertexType adjvex;  该边依附的在U中的顶点

    		VRType lowcost;

    	} closedge[MAX_VERTEX_NUM];*/

    	k = LocateVex(G, u);

    	for (int i = 0; i < G.numVertexes; ++i) /*辅助数组初始化*/
    	{
    		if(k != i)
    		{
    			closedge[i] = {u, G.arcs[k][i].adj}; /*此时定义的邻接矩阵的每个元素都是一个结构体类型的，
    		                                       除了元素adj，还有附属信息info*/
    		}
    	}

    	closedge[k].lowcost = 0;

    	for (int j = 0; j < G.numVertexes; ++j)
    	{
    		k = minimum(closedge);
    		/*此时应该保证closedge[k].lowcost = MIN{closedge[vj].lowcost | closedge[vj].lowcost > 0,vj ∈ V-U}
    		  lowcost值必须大于0，这是顶点在V-U的必要条件*/

    		printf(closedge[k].adjvex, G.vexs[k]);

    		closedge[k].lowcost = 0; //结点k进入U中
    	}

    	for (int i = 0; i < G.numVertexes; ++i) //新顶点并入U后重新选择最小边
    	{
    		if (G.arcs[k][i].adj < closedge[i].lowcost)
    		{
    			closedge[i] = {G.vexs[k], G.arcs[k][i].adj};
    		}
    	}
    }

    对算法分析可知，算法中有两个内循环，其一是在closedge[v].lowcost中求最小值，其频度为n-1;其二是重新选择
    具有最小代价的边，其频度为n。由此克制，Prim算法的时间复杂度是O（n^2），与网中的边数无关，因此适用于求
    边稠密的网的最小生成树。