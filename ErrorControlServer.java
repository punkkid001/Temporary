import java.io.*;
import java.net.*;
import java.util.*;

class ErrorControlServer
{
    public static void main(String[] args)throws IOException
    {
        Scanner input = new Scanner(System.in);
        BufferedReader file;
        ServerSocket server_s;
        Socket socket;

        String name, ip = "127.0.0.1";
        int selection = 0, port = 0;

        System.out.print("1) Stop and wait   2) Go Back N : ");
        selection = input.nextInt();

        System.out.print("File name : ");
        name = input.next();

        file = new BufferedReader(new FileReader(name));

        if (selection==1)
        {
            System.out.println("=====Stop and Wait=====");
            port = 8000;
        }
        else if (selection==2)
        {
            System.out.println("=====Go Back N=====");
            port = 8001;
        }
        else
        {
            System.out.println("Wrong selection!");
            System.exit(-1);
        }
        
        server_s=new ServerSocket(port);

        socket=server_s.accept();
        System.out.println("Connect!");

        server_s.close();
        socket.close();
    }

    public static void stop_and_wait(Socket send, String file_name)
    {
        InputStream in = send.getInputStream();
        DataInputStream d_in = new DataInputStream(in);
        OutputStream out = send.getOutputStream();
        DataOutputStream d_out = new DataOutputStream(out);
        DataOutputStream d_file_out = new DataOutputStream(out);

        FileInputStream f_in = new FileInputStream(file_name);
        System.out.println("Transmitting ..");
        
        while(true)
        {
            int data=f_in.read();
            if(data==-1)
            {
                break;
            }
            d_out.write(data);
            System.out.print(data);
        }

        System.out.println("Done!");

        //Closing Socket
        in.close();
        d_in.close();
        out.close();
        d_out.close();
        f_in.close();
    }

    public static void go_back_n(Socket send, String file_name)
    {
        InputStream in = send.getInputStream();
        DataInputStream d_in = new DataInputStream(in);
        OutputStream out = send.getOutputStream();
        DataOutputStream d_out = new DataOutputStream(out);
        DataOutputStream d_file_out = new DataOutputStream(out);

        FileInputStream f_in = new FileInputStream(file_name);
        System.out.println("Transmitting ..");
        
        while(true)
        {
            int data=f_in.read();
            if(data==-1)
            {
                break;
            }
            d_out.write(data);
            System.out.print(data);
        }

        System.out.println("Done!");

        //Closing Socket
        in.close();
        d_in.close();
        out.close();
        d_out.close();
        f_in.close();
    }
}