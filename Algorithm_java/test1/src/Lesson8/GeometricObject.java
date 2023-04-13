package Lesson8;

public class GeometricObject {
    private String color = "white";
    private boolean filled;

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    private java.util.Date dateCreated;

    public java.util.Date getDateCreated() {
        return dateCreated;
    }

    public GeometricObject(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
        dateCreated = new java.util.Date();
    }

    public GeometricObject() {
        dateCreated = new java.util.Date();
    }

    public String toStrinng() {
        return "created on " + dateCreated + "\ncolor: " + color + " and filled: " + filled;
    }
}
