import java.io.*;
import java.net.*;
import java.util.*;

class ErrorControlServer
{
    public static void main(String[] args)throws IOException
    {
        Scanner input = new Scanner(System.in);
        String ip = "127.0.0.1";
        int selection = 0, port;

        //Making Socket
        ServerSocket server_s;
        Socket socket;

        System.out.print("1) Stop and wait   2) Go Back N : ");
        selection = input.nextInt();

        if (selection==1)
        {
            System.out.println("=====Stop and Wait=====");
            port = 8000;
            server_s=new ServerSocket(port);

            socket=server_s.accept();
            System.out.println("Connect!");

        }
        else if (selection==2)
        {
            System.out.println("=====Go Back N=====");
            port = 8001;
            server_s=new ServerSocket(port);
            
            socket=server_s.accept();
            System.out.println("Connect!");

        }
        else
            System.out.println("Wrong selection!");
    }

    public static void stop_and_wait()
    {

    }

    public static void go_back_n()
    {

    }
}