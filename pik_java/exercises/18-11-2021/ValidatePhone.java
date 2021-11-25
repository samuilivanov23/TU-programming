import java.util.regex.Pattern;
import java.util.regex.Matcher;

interface ValidatePhone
{
    public static boolean isPhoneNumberValid( String phoneNumber )
    {
        String PHONE_NUMBER_PATTERN = "^[0-9]{10}$";
        Pattern pattern = Pattern.compile( PHONE_NUMBER_PATTERN );

        return pattern.matcher( phoneNumber ).matches();
    }
}