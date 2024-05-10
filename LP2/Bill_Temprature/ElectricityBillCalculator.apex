public class ElectricityBillCalculator {
    public Decimal unitsConsumed { get; set; }
    public Decimal totalBill { get; private set; }
    public Decimal perUnitRate { get; set; }
    
    // Constructor
    public ElectricityBillCalculator() {
        unitsConsumed = 0;
        totalBill = 0;
        perUnitRate = 0; // Default per unit rate, you can change it according to your requirement
    }
    
    // Method to calculate the electricity bill
    public void calculateBill() {
        totalBill = unitsConsumed * perUnitRate;
    }
}
