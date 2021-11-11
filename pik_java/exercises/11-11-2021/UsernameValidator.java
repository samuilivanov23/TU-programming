import java.util.regex.Matcher;
import java.util.regex.Pattern;

class UsernameValidator
{
    private Pattern pattern;
    private Matcher matcher;

    private static final String USERNAME_PATTERN = "^[a-z0-9-_]{3,15}$";

    public UsernameValidator()
    {
        this.pattern = Pattern.compile( USERNAME_PATTERN );
    }

    public boolean isUsernameValid( String username )
    {
        return pattern.matcher( username ).matches();
    }
}