public class GreatestNumberFinder {
    public Integer number1 { get; set; }
    public Integer number2 { get; set; }
    public Integer number3 { get; set; }
    public Integer greatestNumber { get; private set; }
    
    // Constructor
    public GreatestNumberFinder() {
        number1 = 0;
        number2 = 0;
        number3 = 0;
        greatestNumber = 0;
    }
    
    // Method to find the greatest number
    public void findGreatestNumber() {
        greatestNumber = Math.max(number1, Math.max(number2, number3));
    }
}
