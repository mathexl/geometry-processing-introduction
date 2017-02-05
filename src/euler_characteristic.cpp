#include "euler_characteristic.h"
#include "edges.h"
#include <iostream>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi;
  int maxVertex = 0;

  //calculate the number of Vertexes based on the max Vertex Index
  for(int i; i < F.rows(); i++){
    if(F(i, 0) > maxVertex){
      maxVertex = F(i, 0);
    }
    if(F(i, 1) > maxVertex){
      maxVertex = F(i, 2);
    }
    if(F(i, 2) > maxVertex){
      maxVertex = F(i, 2);
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
