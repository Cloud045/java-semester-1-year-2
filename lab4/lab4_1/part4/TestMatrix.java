package lab4.lab4_1.part4;

import java.io.IOException;

public class TestMatrix {
    public static void main(String[] args) throws IOException {
        Matrix A = new Matrix(2, 3);
        Matrix B = new Matrix(2, 3);
        A.SetRandomArr();
        B.SetRandomArr();
        A.printMatrix("[A]");
        B.printMatrix("[B]");

        Matrix C = new Matrix();
        C = C.SumMatrix(A, B);
        C.printMatrix("[C]");
        Matrix D = new Matrix(3, 2);
        Matrix E = new Matrix(2, 4);
        D.SetRandomArr();
        E.SetRandomArr();
        D.printMatrix("[D]");
        E.printMatrix("[E]");
        Matrix C1 = new Matrix();
        C1 = C1.MulMatrix(D, E);
        C1.printMatrix("[C1]");
        Matrix C2 = new Matrix();
        C2 = C2.MulNum(C1, 10);
        C2.printMatrix("[C2]");
    }
}
