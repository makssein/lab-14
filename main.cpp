#include <iostream>                                                     // в лучшем случае - n
#include <fstream>                                                      // в среднем случае - n^2
#include "timer.cpp"                                                    // в худшем случае - n^3


int main() {
    int n;
    std::ifstream inMatrix_1("../matrix-1.txt");
    std::ifstream inMatrix_2("../matrix-2.txt");

    inMatrix_1 >> n;
    int matrix_1[n][n], matrix_2[n][n], matrix[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            inMatrix_1 >> matrix_1[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            inMatrix_2 >> matrix_2[i][j];
        }
    }
    Timer timer;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = 0;
            for(int k=0;k<n;k++){
                matrix[i][j]+= matrix_1[i][k]*matrix_2[k][j];
            }
        }
    }
    std::cout << "Time elapsed: " << timer.elapsed() << " seconds" << '\n';

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }



    return 0;
}
