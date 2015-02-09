import java.util.Scanner;
public class Main {
	public static void main(String[] arg) throws Exception
	{
		Scanner In=new Scanner(System.in);
		int N=In.nextInt();
		In.nextLine();
		for(int i=1;i<=N;++i)
		{
			String temp=In.nextLine();
			System.out.println("String #"+i);
			for(int k=0;k<temp.length();++k)
				if(temp.charAt(k)=='Z')
					System.out.print("A");
				else
				    System.out.print(""+(char)(temp.charAt(k)+1));
			System.out.println("");
			System.out.println("");
			
		}
		In.close();
	}

}
