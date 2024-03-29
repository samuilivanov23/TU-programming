import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import java.io.OutputStream;
import java.io.IOException;
import java.lang.StringBuilder;
import org.apache.commons.*;

class HTTPRequestHandler implements HttpHandler 
{
    @Override    
    public void handle(HttpExchange httpExchange) throws IOException 
    {
        String requestParamValue=null; 
        if("GET".equals(httpExchange.getRequestMethod()))
        { 
            requestParamValue = handleGetRequest(httpExchange);
        }
        else if("POST".equals(httpExchange)) 
        { 
            //TODO
            //requestParamValue = handlePostRequest(httpExchange);        
        } 
        handleResponse(httpExchange,requestParamValue); 
    }
    private String handleGetRequest(HttpExchange httpExchange) 
    {
            return httpExchange.
                    getRequestURI()
                    .toString()
                    .split("\\?")[1]
                    .split("=")[1];
    }

    private void handleResponse(HttpExchange httpExchange, String requestParamValue)  throws  IOException
    {
            OutputStream outputStream = httpExchange.getResponseBody();
            StringBuilder htmlBuilder = new StringBuilder();

            htmlBuilder.append("<html>")
                    .append("<body>")
                    .append("<h1>")
                    .append("Hello ")
                    .append(requestParamValue)
                    .append("</h1>")
                    .append("</body>")
                    .append("</html>");
            // encode HTML content 
            String htmlResponse = StringEscapeUtils.escapeHtml4(htmlBuilder.toString());
     
            // this line is a must
            httpExchange.sendResponseHeaders(200, htmlResponse.length());
            outputStream.write(htmlResponse.getBytes());
            outputStream.flush();
            outputStream.close();
    }
}