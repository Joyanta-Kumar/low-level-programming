#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define NODE_COUNT 4
bool graph[NODE_COUNT][NODE_COUNT] = { 0 };

void addEdge(__uint8_t node1, __uint8_t node2);
void randomizeGraph();
void printGraph();


int main() {
    srand(time(NULL));
    printf("\n");

    randomizeGraph();

    printGraph();
    return 0;
}


void addEdge(__uint8_t node1, __uint8_t node2) {
    if (node1 == node2) {
        return;
    }
    graph[node1][node2] = true;
}


void printGraph() {
    printf("\e[31;1mFrom\e[0m\n");
    printf("\e[34;1mTo\e[0m\n");
    printf("\t");
    for (__uint8_t endNode = 0; endNode < NODE_COUNT; endNode++) {
        printf("\e[1;34m%d\e[0m  ", endNode);
    }
    printf("\n");
    for (__uint8_t startNode = 0; startNode < NODE_COUNT; startNode++) {
        printf("\n\e[1;31m%d\e[0m\t", startNode);
        for (__uint8_t endNode = 0; endNode < NODE_COUNT; endNode++) {
            printf("%b  ", graph[startNode][endNode]);
        }
    }
    printf("\n\n");
}


void randomizeGraph() {
    for (__uint8_t startNode = 0; startNode < NODE_COUNT; startNode++) {
        for (__uint8_t endNode = 0; endNode < NODE_COUNT; endNode++) {
            if (rand() % 2 == 1) {
                addEdge(startNode, endNode);
            }
        }
    }
}
