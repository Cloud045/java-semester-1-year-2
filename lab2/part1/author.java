package lab2.part1;

public class author {
    private String name;
    private String mail;
    private char gender;

    public author(String name, String mail, char gender) {
        this.name = name;
        this.mail = mail;
        this.gender = gender;
    }

    public String getName() {
        return this.name;
    }

    public String getMail() {
        return this.mail;
    }

    public char getGender() {
        return this.gender;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    @Override
    public String toString() {
        return "Author{" +
                "name:" + this.name + ", " +
                "mail:" + this.mail + ", " +
                "gender:" + this.gender + "}"
                ;
    }
}
