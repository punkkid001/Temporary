import java.net.*;
import java.io.*;

public class socket_in
{
    public static void main(String[] args)
    {
        try
        {
            ServerSocket server = new ServerSocket(6013);

            while (true)
            {
                Socket client = server.accept();
                PrintWriter port = new PrintWriter(client.getOutputStream(), true);

                port.println(new java.util.Date().toString());

                client.close();
            }
        }
        catch (IOException e)
        {
            System.err.println(e);
        }
    }
}
