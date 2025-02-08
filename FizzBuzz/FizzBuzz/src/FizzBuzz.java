//Copyright 2025 Abby Holdcraft
public class FizzBuzz {
    public static int SIZE = 100;
    public static void main(String[] args) {
        System.out.println("Playing FizzBuzz...");

        for(int i=1;i<=SIZE;i++) {
            boolean has_printed = false;
            if(i%3==0) {
                System.out.print("FIZZ");
                has_printed = true;
            }
            if(i%5==0){
                System.out.print("BUZZ");
                has_printed = true;
            }
            if(!has_printed)
                System.out.print(i);
            System.out.println();
        }
        
    }
}
