import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.ArrayList;
public class Main 
{
	private class Edge
	{
		public int s;
		public int e;
		public int leng;
		public Edge(int s,int e,int leng)
		{
			this.s=s;
			this.e=e;
			this.leng=leng;
		}
	}
	
	private class Cmp implements Comparator<Edge>
	{

		@Override
		public int compare(Edge arg0, Edge arg1)
		{
			return arg0.leng-arg1.leng;
		}
		
	}
	
	public static void main(String[] arg)
	{
		Scanner in =new Scanner(System.in);
		int N;
		Main Solu=new Main();
		ArrayList<Edge> store=new ArrayList<Edge>();
		while((N=in.nextInt())>0)
		{
			while(N-->1)
			{
				int S=in.next().charAt(0)-'A';
				int N_edge=in.nextInt();
				while(N_edge-->0)
				{
					int E=in.next().charAt(0)-'A';
					int leng=in.nextInt();
					store.add(Solu.new Edge(S,E,leng));			
				}
			}
			System.out.println(""+Solu.findMin(store));
			store.clear();
		}
		in.close();
	}

	
	private int findMin(ArrayList<Edge> store)
	{
		int [] state =new int[28];
		for(int i=0;i<28;++i)
			state[i]=-1;
		Collections.sort(store,new Cmp());
		int Sum=0;
		for(Edge temp : store)
		{
			if(findFather(state,temp.s)!=findFather(state,temp.e))
			{
				Sum+=temp.leng;
				Unity(state,temp.s,temp.e);
			}
		}
		return Sum;
	}
	
	private int findFather(int [] state,int index)
	{
		if(state[index]==-1)
			return index;
		state[index]=findFather(state,state[index]);
		return state[index];
		
	}
	
	private void Unity(int []state,int index1,int index2)
	{
		state[findFather(state,index1)]=findFather(state,index2);
	}
	
}
