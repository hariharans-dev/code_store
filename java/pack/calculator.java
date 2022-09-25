package pack;
public class calculator {
    public void addition(int a[]){
        int s=0,n=a.length;
        for(int i=0;i<n;i++)
            s+=a[i];
        System.out.println(s);
    }
}
