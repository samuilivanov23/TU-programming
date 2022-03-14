import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;

import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.Executors;
import java.lang.StringBuilder;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.Headers;

class SimpleHttpServer {

  public static void main(String[] args) throws Exception {
    HttpServer server = HttpServer.create(new InetSocketAddress("127.0.0.1", 8987), 5);

    server.createContext("/bedo_izverg", new InfoHandler());
    server.createContext("/get", new GetHandler());
    
    ThreadPoolExecutor threadPoolExecutor = (ThreadPoolExecutor)Executors.newFixedThreadPool(10);
    server.setExecutor(threadPoolExecutor);
    
    server.start();
    System.out.println(" Server started on port 192.168.87.142:8987");
  }

    static class InfoHandler implements HttpHandler {
        public void handle(HttpExchange httpExchange) throws IOException {
            Headers h = httpExchange.getResponseHeaders();
            h.add("Content-Type", "text/html");

            OutputStream outputStream = httpExchange.getResponseBody();
            StringBuilder htmlBuilder = new StringBuilder();

            htmlBuilder.append("<html>")
                    .append("<body>")
                    .append("<h1>")
                    .append("AHAAAAAAAAAHHHHRRRRRR")
                    .append("</h1>")
                    .append("<img src=\"https://i.ytimg.com/vi/dIJg6kMflts/hqdefault.jpg\" alt=\"Bedo Suleymanov\">")
                    .append("<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/DqJ3oWWyxmc\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>")
                    .append("</body>")
                    .append("</html>");
            // encode HTML content 
            String htmlResponse = htmlBuilder.toString();
     
            // this line is a must
            httpExchange.sendResponseHeaders(200, htmlResponse.length());
            outputStream.write(htmlResponse.getBytes());
            outputStream.flush();
            outputStream.close();
        }
    }

  static class GetHandler implements HttpHandler {
    public void handle(HttpExchange t) throws IOException {

      // add the required response header for a PDF file
      Headers h = t.getResponseHeaders();
      h.add("Content-Type", "application/pdf");

      // a PDF (you provide your own!)
      File file = new File ("c:/temp/doc.pdf");
      byte [] bytearray  = new byte [(int)file.length()];
      FileInputStream fis = new FileInputStream(file);
      BufferedInputStream bis = new BufferedInputStream(fis);
      bis.read(bytearray, 0, bytearray.length);

      // ok, we are ready to send the response.
      t.sendResponseHeaders(200, file.length());
      OutputStream os = t.getResponseBody();
      os.write(bytearray,0,bytearray.length);
      os.close();
    }
  }
}