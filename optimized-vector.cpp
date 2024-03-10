#include <iostream>

class Vertex {

    private:
        float x, y, z;

    public:
        Vertex( float x, float y, float z)
            : x(x), y(y), z(z)
        {
            //std::cout << "Created" << std::endl;
        }

        Vertex( const Vertex& vertex )
            : x(vertex.x), y(vertex.y), z(vertex.z)
        {
            std::cout << "Copied" << std::endl;
        }

        ~Vertex()
        {
            //std::cout << "Destroyed" << std::endl;
        }
};

int main() {

    // std::vector<Vertex> vertices; // capacity low
    // vertices.push_back( Vertex(1, 2, 3) ); // Vertex(1, 2, 3) is in MAIN
    // vertices.push_back( Vertex(4, 5, 6) );

    
    // Optimization 1
    // std::vector<Vertex> vertices; // capacity low
    // vertices.reserve(3);
    // vertices.push_back( Vertex(1, 2, 3) ); // Problem: Constructor manual creation
    // vertices.push_back( Vertex(4, 5, 6) );
    // vertices.push_back( Vertex(7, 8, 9) );

    // Optimization 2
    std::vector<Vertex> vertices;
    vertices.reserve(3);
    vertices.emplace_back(1, 2, 3); // auto creates object with these parameters
    vertices.emplace_back(4, 5, 6); // NOT A SINGLE COPY !!!
    vertices.emplace_back(7, 8, 9);








    return 0;
}