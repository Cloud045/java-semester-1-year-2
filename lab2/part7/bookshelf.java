package lab2.part7;

public class bookshelf {
    book[] shelf;
    private int numbers;

    public bookshelf() {
        shelf = new book[10001];
        numbers = 0;
    }

    public void insertBook(book newBook) {
        numbers++;
        shelf[numbers] = newBook;
    }

    public void FindNewestBook() {
        int Min = 3000;
        for (int i = 1; i <= numbers; ++i) {
            if (shelf[i].getPublish_year() < Min) Min = shelf[i].getPublish_year();
        }
        System.out.println("List of Newest Books: ");
        for (int i = 1; i <= numbers; ++i) {
            if (shelf[i].getPublish_year() == Min) System.out.println("\t" + shelf[i]);
        }
    }

    public void ShowAllBook() {
        System.out.println("Show All Books: ");
        for (int i = 1; i <= numbers; ++i) {
            System.out.println("\t" + shelf[i]);
        }
    }

    public void SortByDate() {
        for (int i = 1; i <= numbers; ++i)
            for (int j = i + 1; j <= numbers; ++j)
                if (shelf[i].getPublish_year() > shelf[j].getPublish_year()) {
                    book tmp = shelf[i];
                    shelf[i] = shelf[j];
                    shelf[j] = tmp;
                }
    }

}
