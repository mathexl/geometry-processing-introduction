#include "edges.h"
#include <iostream>

Eigen::MatrixXi add_the_edges(Eigen::MatrixXi &F, Eigen::MatrixXi &E, int start, int end)
{
  for(int i = 0; i < F.rows(); i++){
    int vertex1 = F(i, start);
    int vertex2 = F(i, end);
    for(int j = i + 1; j < F.rows(); j++){ // = to i to avoid repeats
      if(vertex1 == F(j, 0) || vertex1 == F(j, 1) || vertex1 == F(j, 2)){
        if(vertex2 == F(j, 0) || vertex2 == F(j, 1) || vertex2 == F(j, 2)){
          E.resize(E.rows() + 1,2);
          E(E.rows() - 1, 0) = i;
          E(E.rows() - 1, 1) = j;
        }
      }
    }
  }
  return E;
}


Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;


  Eigen::MatrixXi X = F;

  E = add_the_edges(X, E, 0, 1);
  E = add_the_edges(X, E, 1, 2);
  E = add_the_edges(X, E, 0, 2);



  std::cout << "The matrix E is of size "
            << E.rows() << "x" << E.cols() << std::endl;
  return E;
}
