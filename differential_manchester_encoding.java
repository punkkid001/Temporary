import java.util.Scanner;

class differantial_manchester_encoding
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String value = "";
        String result = "";

        while(true)
        {
            System.out.print("Input : ");
            value = input.next();

            if(value.equals("exit"))
                break;

            result = "";
            if (value.charAt(0)=='0')
                result += "-┐_";
            else
                result += "_┌-";
            for(int i=1;i<value.length();i++)
            {
                int curr = result.length()-1;
                if (value.charAt(i)=='0')
                {
                    if (result.charAt(curr)=='-')
                        result += "_┌-";
                    else
                        result += "-┐_";
                }

                else
                {
                    if (result.charAt(curr)=='-')
                        result += "-┐_";
                    else
                        result += "_┌-";
                }
            }
            
            System.out.println(result);
            
            System.out.print("  ");
            for(int i=0;i<value.length();i++)
                System.out.print(value.charAt(i)+"  ");
            System.out.println();
        }
    }
}       
