public class MarkSheetGenerator {
    public class Student {
        public String name { get; set; }
        public Integer mathMarks { get; set; }
        public Integer scienceMarks { get; set; }
        public Integer englishMarks { get; set; }
        public Integer totalMarks { get; set; }
        
        public Student(String name, Integer mathMarks, Integer scienceMarks, Integer englishMarks, Integer totalMarks) {
            this.name = name;
            this.mathMarks = mathMarks;
            this.scienceMarks = scienceMarks;
            this.englishMarks = englishMarks;
            this.totalMarks = totalMarks;
        }
    }
    
    public String studentName { get; set; }
    public Integer mathMarks { get; set; }
    public Integer scienceMarks { get; set; }
    public Integer englishMarks { get; set; }
    public Integer totalMarks { get; private set; }
    public String message { get; private set; }
    public List<Student> previousStudents { get; private set; }

    // Constructor
    public MarkSheetGenerator() {
        studentName = '';
        mathMarks = 0;
        scienceMarks = 0;
        englishMarks = 0;
        totalMarks = 0;
        message = '';
        previousStudents = new List<Student>();
    }

    // Method to calculate total marks
    public void calculateTotalMarks() {
        totalMarks = mathMarks + scienceMarks + englishMarks;
    }

    // Method to generate mark sheet
    public void generateMarkSheet() {
        calculateTotalMarks();

        // Check if all fields are filled
        if (studentName == null || studentName.trim().length() == 0 || mathMarks == null || scienceMarks == null || englishMarks == null) {
            message = 'Please fill in all fields.';
            return;
        }

        // Add current student to the list of previous students
        previousStudents.add(new Student(studentName, mathMarks, scienceMarks, englishMarks, totalMarks));

        // Display the mark sheet
        message = 'Student Name: ' + studentName + '<br/>' +
                  'Math Marks: ' + mathMarks + '<br/>' +
                  'Science Marks: ' + scienceMarks + '<br/>' +
                  'English Marks: ' + englishMarks + '<br/>' +
                  'Total Marks: ' + totalMarks;
    }
}
