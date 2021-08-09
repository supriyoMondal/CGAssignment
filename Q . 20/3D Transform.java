public class threeD 
{
	static double[][] mul(double[][] a, double[][] b)
	{
		int i,j,k;
		double[][] c=new double[4][2];
	    for(i=0;i<4;i++)
		{
			for(j=0;j<2;j++)
			{
				c[i][j]=0;
			}
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<2;j++)
			{
				for(k=0;k<4;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		return c;
	}
	public static void main(String[] args) 
	{
		double x1=1,y1=5,z1=2,x2=6,y2=8,z2=9;
		double cosa=Math.cos(Math.toRadians(45));
		double sina=Math.sin(Math.toRadians(45));
		double[][] res=new double[4][2];
		double[][] p={{x1,x2},{y1,y2},{z1,z2},{1,1}};
		double[][] t2={{1,0,0,-x1},{0,1,0,-y1},{0,0,1,-z1},{0,0,0,1}};
		double[][] s={{3,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
		double[][] t1={{1,0,0,x1},{0,1,0,y1},{0,0,1,z1},{0,0,0,1}};
		res=mul(t1,mul(s,mul(t2,p)));
		double[][] r= {{cosa,-sina,0,0},{sina,cosa,0,0},{0,0,1,0},{0,0,0,1}};
		res=mul(r,res);
		System.out.println("Transformed coordinates are:");
		for(int i=0;i<2;i++)
		{
			System.out.print("(");
			for(int j=0;j<3;j++)
			{
				if(j==2)
					System.out.print(String.format("%.2f",res[j][i]));
				else
				    System.out.print(String.format("%.2f",res[j][i])+",");
			}
			System.out.println(")");
		}
	}

}
