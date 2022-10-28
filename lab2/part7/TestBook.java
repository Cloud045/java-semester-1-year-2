package lab2.part7;

import java.lang.System;

public class TestBook {
    public static void main(String[] args) {
        bookshelf Shelf1 = new bookshelf();
        book Book1 = new book("Harry Potter", "J. K. Rowling", 1997);
        book Book2 = new book("Gone with the wind", "Margaret Mitchell", 1936);
        book Book3 = new book("Война и мир", "Lev Nikolayevich Tolstoy", 1965);
        System.out.println(Book1);
        Shelf1.insertBook(Book1);
        Shelf1.insertBook(Book2);
        Shelf1.insertBook(Book3);
        Shelf1.ShowAllBook();
        Shelf1.FindNewestBook();
        Shelf1.SortByDate();
        Shelf1.ShowAllBook();
    }

}
