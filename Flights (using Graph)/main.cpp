#include <iostream>
#include "Graph.h"
using namespace std;

int main() {

    Graph graph;

    Vertex* vertexA = graph.AddVertex("Tokyo");
    Vertex* vertexB = graph.AddVertex("New York");
    Vertex* vertexC = graph.AddVertex("London");
    Vertex* vertexD = graph.AddVertex("Sydney");

    graph.AddUndirectedEdge(vertexA, vertexB, 6743);
    graph.AddUndirectedEdge(vertexA, vertexC, 5941);
    graph.AddUndirectedEdge(vertexA, vertexD, 4863);
    graph.AddUndirectedEdge(vertexB, vertexC, 3425);
    graph.AddUndirectedEdge(vertexB, vertexD, 9868);
    graph.AddUndirectedEdge(vertexB, vertexA, 6743);
    graph.AddUndirectedEdge(vertexC, vertexD, 18562);


    for (Vertex* vertex : graph.GetVertices()) {
        cout << "Location: " << vertex->label << endl;

        cout << "  Flights from " << vertex->label << ':' << endl;
        for (Edge* outgoingEdge : *graph.GetEdgesFrom(vertex)) {
            cout << "		" << vertex->label << " to ";
            cout << outgoingEdge->toVertex->label << ", ";
            cout << (int)outgoingEdge->weight << " miles" << endl;
        }

        cout << "  Flights to " << vertex->label << ":" << endl;
        for (Edge* outgoingEdge : *graph.GetEdgesTo(vertex)) {
            cout << "		" << outgoingEdge->fromVertex->label << " to ";
            cout << outgoingEdge->toVertex->label << ", ";
            cout << (int)outgoingEdge->weight << " miles" << endl;
        }
    }

    return 0;
}
