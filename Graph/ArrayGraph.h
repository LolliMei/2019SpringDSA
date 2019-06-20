//
// Created by ������ on 2019-06-04.
//

#ifndef INC_2019SPRINGDSA_ARRAYGRAPH_H
#define INC_2019SPRINGDSA_ARRAYGRAPH_H

#include <stdlib.h>
#include <memory.h>

#define VertexType int
typedef struct Vertex {
    VertexType data;
} *Vertex;

typedef struct MatGraph {
    Vertex *verts;
    int **mat;
    int vertexNum;
    int edgeNum;
} *MatGraph;

MatGraph init_matgraph(int vertexNum);

//������
int outdegree(MatGraph graph, int vertex);

//������
int indegree(MatGraph graph, int vertex);

//��һ���ڽӵ�
int firstadj(MatGraph graph, int vertex);

//��һ���ڽӵ�
int nextadj(MatGraph graph,int vertex,int last);

//��ӱ�
void add_nodirect_edge(MatGraph graph,int begin,int end,int weight);


#endif //INC_2019SPRINGDSA_ARRAYGRAPH_H
