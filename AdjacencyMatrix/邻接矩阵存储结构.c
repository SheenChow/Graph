typedef char VertexType;

  typedef int EdgeType;

  #define MAXVEX 100;//最大顶点数，其实应该由用户决定

  #define INFINITY 65535 //由6535来代表∞ 

  typedef struct {

  	/*顶点表*/
  	VertexType vexs[MAXVEX];

    /*邻接矩阵，可以看作表*/
  	EdgeType arc[MAXVEX][MAXVEX];

  	int numVertex, numEdges;

  } MGraph;