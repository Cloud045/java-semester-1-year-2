package lab2.part7;

public class book {
    private String author;
    private String name;
    private int publish_year;

    public book(String author, String name, int publish_year) {
        this.author = author;
        this.publish_year = publish_year;
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getPublish_year() {
        return publish_year;
    }

    public void setPublish_year(int publish_year) {
        this.publish_year = publish_year;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    @Override
    public String toString() {
        return "book{" +
                "name: " + this.name + ", " +
                "author: " + this.author + ", " +
                "publish_year: " + this.publish_year + "}"
                ;
    }
}
