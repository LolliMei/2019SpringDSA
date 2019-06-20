//
// Created by ������ on 2019-06-20.
//

#ifndef INC_2019SPRINGDSA_ALGRAPH_H
#define INC_2019SPRINGDSA_ALGRAPH_H

#include <stdlib.h>

#define VertexType int

typedef struct ALLink {
    int vertex;
    int weight;
    struct ALLink *nextadj;
} ALLink;

typedef struct ALVertex {
    VertexType data;
    int outdegree;
    ALLink *nextadj;
} ALVertex;

typedef struct ALGraph {
    ALVertex *vertexs;
    int vertexNum;
    int edge;
} *ALGraph;


//��ʼ��ALGraph
ALGraph init_algraph(int vertexNum);

//��ӱߵ��ڽӱ��У�����ͷ�巨
void add_edge_algraph(ALGraph graph, int start, int end, int weight);

//�׸��ڽӵ�
ALVertex *al_firstadj(ALGraph graph, int vertex);

//��һ���ڽӵ�
ALVertex *al_nextadj(ALGraph graph, int vertex, ALVertex *last);



#endif //INC_2019SPRINGDSA_ALGRAPH_H
