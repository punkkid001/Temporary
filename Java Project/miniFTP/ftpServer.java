/**
 * Created by Jiyoon on 2015-06-10.
 */
import java.util.*;
import java.net.*;
import java.io.*;

public class ftpServer
{
    public static void main(String[] args)throws IOException
    {
        Scanner input=new Scanner(System.in);
        int port;

        System.out.print("Input Port Number : ");
        port=input.nextInt();

        //Making Socket
        ServerSocket server_s;
        server_s=new ServerSocket(port);
        System.out.println("ServerSocket is ok");

        Socket socket=server_s.accept();
        System.out.println("Connect!");

        InputStream in=socket.getInputStream();
        DataInputStream D_in=new DataInputStream(in);
        OutputStream out=socket.getOutputStream();
        DataOutputStream D_out=new DataOutputStream(out);
        DataOutputStream D_file_out=new DataOutputStream(out);

        //Showing File list
        File file=new File("C:\\java_download\\");
        //File []file_list=file.listFiles();
        String []file_list_st=file.list();

        for(int i=0;i<file_list_st.length;i++)
        {
            D_file_out.writeUTF(file_list_st[i]);
            D_file_out.flush();
        }
        /*
        File file=new File("C:\\Users\\Public\\Music\\Sample Music\\");
        File []file_list=file.listFiles();
        //String []file_list_st=file.list();
        //System.out.println(file_list_st.length);

        for(int i=0;i<file_list.length;i++)
        {
            PrintWriter pw=new PrintWriter(socket.getOutputStream(),true);
            pw.println(file_list[i]);
            pw.flush();
        }
        */

        //Transfer File
        String FileName=D_in.readUTF();
        System.out.println("Client want to download "+FileName);

        FileInputStream F_in=new FileInputStream("C:\\java_download\\"+FileName);
        System.out.println("Transmitting ..");
        while(true)
        {
            int data=F_in.read();
            if(data==-1)
            {
                break;
            }
            D_out.write(data);
        }

        System.out.println("Done!");

        //Closing Socket
        server_s.close();
        socket.close();
        in.close();
        D_in.close();
        out.close();
        D_out.close();
        F_in.close();
    }
}
