public class Course {
    private String courseName;
    private String[] students = new String[100];
    private int numverOfStudents;

    public String getCourseName() {
        return courseName;
    }

    public String[] getStudents() {
        return students;
    }

    public int getNumverOfStudents() {
        return numverOfStudents;
    }

    public Course(String courseName) {
        this.courseName = courseName;
    }

    public void addStudent(String student) {
        students[numverOfStudents++] = student;
    }

    public void dropStudent(String student) {

    }
}
