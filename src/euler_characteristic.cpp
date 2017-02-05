#include "euler_characteristic.h"
#include "edges.h"
#include <iostream>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  int maxVertex = 0;

  //calculate the number of Vertexes based on the max Vertex Index
  for(int b = 0; b < F.rows(); b++){
    if(F(b, 0) > maxVertex){
      maxVertex = F(b, 0);
    }
    if(F(b, 1) > maxVertex){
      maxVertex = F(b, 2);
    }
    if(F(b, 2) > maxVertex){
      maxVertex = F(b, 2);
    }
  }


  Eigen::MatrixXi E = edges(F);

  Chi = maxVertex - E.rows() + F.rows();

  std::cout << "Vertices: " << maxVertex << " ::Edges: " << E.rows() << " ::Faces: "
              << F.rows() << std::endl;

  std::cout << "Euler Characteristic: "
              << Chi << std::endl;
  return Chi;
}
