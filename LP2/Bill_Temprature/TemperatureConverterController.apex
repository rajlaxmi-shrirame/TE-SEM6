public class TemperatureConverterController1 {
	public Decimal celsius { get; set; }
    public Decimal fahrenheit { get; set; }
    
    // Method to convert Celsius to Fahrenheit
    public void convertTemperature() {
        fahrenheit = (celsius * 9/5) + 32;
    }
}