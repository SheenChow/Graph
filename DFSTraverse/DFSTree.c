/*从第v个顶点出发，深度优先遍历图G，并且建立以T为根的生成树，生成树的结构是孩子兄弟法*/
/*孩子兄弟法存储结构如下：
typedef struct CSNode
{
	TElemType data;

	struct CSNode *firstchild, *nextsibling;

} CSNode, *CSTree;*/

void DFSTree(Graph G, int v, CSTree &T)
{
	visited[v] = 1;

	first = true;

	for (w = firstAdjVex(G, v); w >= 0; w = nextAdjVex(G, v)) //这一点根据图的存储方式来变化，比如，邻接矩阵，或者邻接表
	{
		if (!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode)); //分配孩子结点

			*P = {GetVex(G, w), NULL, NULL};//这句话的意思就是，把w的data值赋给p，并且初始化他的左右指针域

			if (first)  //w是v的第一个被访问的结点，是根的左孩子
			{
				T->firstchild = p;
			}
			else
			{
				q->nextsibling = p;    //不然的话就是上一个邻接点的右兄弟
			}

			q = p;

			DFSTree(G, w, q);//建立子生成树q（p也可以）
		}
	}
}

void DFSForest(Graph G, CSTree&T)
{
	T = NULL;

	for (int i = 0; i < G.numVertexes; ++i)
	{
		visited[i] = 0;
	}

	for(i = 0; i < G.numVertexes; ++i)
	{
		if(!visited[i])
		{
			p = (CSTree)malloc(sizeof(CSNode));

			if(!T)
			{
				T = p;
			}
			else
			{
				q->nextsibling = p;
			}

			q = p;

			DFSTree(G, i, p);
		}
	}
}