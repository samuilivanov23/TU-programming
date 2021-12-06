import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.Executors;
import java.net.InetSocketAddress;
import java.io.IOException;

class ServerApp 
{
    public static void main( String args[] )
    {
        HttpServer server = HttpServer.create(new InetSocketAddress("localhost", 8987), 5);

        server.createContext("/test", new  HTTPRequestHandler());
        ThreadPoolExecutor threadPoolExecutor = (ThreadPoolExecutor)Executors.newFixedThreadPool(10);
        server.setExecutor(threadPoolExecutor);

        server.start();
        System.out.println(" Server started on port 8987");
    }
}