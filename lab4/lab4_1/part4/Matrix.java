package lab4.lab4_1.part4;

import java.io.IOException;
import java.util.Random;

public class Matrix {
    private double[][] arr;
    private int M, N;

    public Matrix() {
    }

    public Matrix(int M, int N) {
        this.M = M;
        this.N = N;
        this.arr = new double[M][N];
    }

    public void SetRandomArr() {
        Random r = new Random();
        double rangeMin = 10;
        double rangeMax = 20;

        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j) {
                arr[i][j] = rangeMin + (rangeMax - rangeMin) * r.nextDouble();
            }
    }

    public Matrix SumMatrix(Matrix A, Matrix B) throws IOException {
        Matrix C = new Matrix(A.M, A.N);
        if (A.M != B.M || A.N != B.N) {
            System.out.println("Cannot add 2 matrices!");
            throw new IOException("MathError!");
        }

        for (int i = 0; i < A.M; ++i)
            for (int j = 0; j < A.N; ++j) {
                C.arr[i][j] = A.arr[i][j] + B.arr[i][j];
            }
        return C;
    }

    public Matrix MulMatrix(Matrix A, Matrix B) throws IOException {
        this.M = A.M;
        this.N = B.N;
        arr = new double[M][N];
        if (A.N != B.M) {
            System.out.println("Cannot multiply 2 matrices!");
            throw new IOException("MathError!");
        }

        for (int i = 0; i < A.M; ++i)
            for (int j = 0; j < B.N; ++j)
                for (int k = 0; k < A.N; ++k) {
                    arr[i][j] += A.arr[i][k] + B.arr[k][j];
                }
        return this;
    }

    public Matrix MulNum(Matrix A, int B) {
        Matrix C = new Matrix(A.M, A.N);
        for (int i = 0; i < A.M; ++i)
            for (int j = 0; j < A.N; ++j) {
                C.arr[i][j] = A.arr[i][j] * B;
            }
        return C;
    }

    public void printMatrix(String aaa) {
        System.out.println(aaa);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                System.out.print((double) Math.round(arr[i][j] * 10) / 10 + "\t");
            }
            System.out.println();
        }
    }
}
