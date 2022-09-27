import java.util.*;
public class practise1{
    public static void main(String args[]){
        child2 c=new child2();
        c.hello1();
    }
}
class child1 extends practise1{
    void hello1(){
        System.out.println("child1");
    }
}
class child2 extends child1{
    void hello(){
        System.out.println("child2");
    }
}
