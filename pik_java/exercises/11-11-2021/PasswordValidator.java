import java.util.regex.Pattern;
import java.util.regex.Matcher;

class PasswordValidator
{
    private Pattern pattern;
    private Matcher matcher;

    private static final String PASSWORD_PATTERN = "^[a-zA-z]{11,}$";

    public PasswordValidator()
    {
        this.pattern = Pattern.compile( PASSWORD_PATTERN );
    }

    public boolean isPasswordValid( String password )
    {
        return pattern.matcher( password ).matches();
    }
}