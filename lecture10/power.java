public class power
{
    public static void main(String[] args)
    {
        System.out.println(pow(5,3));
        System.out.println(betterpow(2,7));
    }

    public static int pow(int a,int b)
    {
        if(b==1) return a;
        else return a*pow(a,b-1);
    }

    public static int betterpow(int a,int b)
    {
        if(b==0) return 1;
        else if(b==1) return a;
        else if((b&1)==0) return betterpow(a,b/2)*betterpow(a, b/2);
        else return a*betterpow(a,b/2)*betterpow(a, b/2);
    }
}