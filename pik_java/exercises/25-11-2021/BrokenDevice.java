class BrokenDevice extends Device
{
    private String symptoms;
    private int recoveryDueDays;

    public BrokenDevice( String brand, String model, double price, String symptoms, int recoveryDueDays )
    {
        super( brand, model, price );
        this.setSymptoms( symptoms );
        this.setRecoveryDueDays( recoveryDueDays );
    }

    public String getSymptoms() { return this.symptoms; }
    public void setSymptoms( String symptoms ) { this.symptoms = symptoms; }

    public int getRecoveryDueDays() { return this.recoveryDueDays; }
    public void setRecoveryDueDays( int recoveryDueDays ) { this.recoveryDueDays = recoveryDueDays; }
}