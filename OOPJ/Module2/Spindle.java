package project0;

import java.util.*;
import java.lang.Math;
import java.lang.Exception;


//custom exception
class MyException extends Exception { 
  public MyException(String errorMessage) {
      super(errorMessage);
  }
} 


class Spinspeeds{
  double minSpeed;
  double maxSpeed;
  double ratio;
  int numSpeed;
  double[] speed = new double[100];
  
  
  public void init() throws MyException{
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter Minspeed: ");
    minSpeed = scanner.nextDouble();
    if(minSpeed==0)
      throw new MyException("Minspeed cant be zero");
    System.out.println("Enter Maxspeed: ");
    maxSpeed = scanner.nextDouble();
    if(maxSpeed==0) {
    	throw new MyException("Maxspeed cant be zero");
    }
    System.out.println("Enter number of speeds: ");
    numSpeed = scanner.nextInt();
    if(numSpeed==1 || numSpeed<1) {
    	throw new MyException("Number of speed cant be one or less than one");
    }  
  }
  
  
  public void calcspeed(){
    ratio = Math.pow((maxSpeed/minSpeed),(1/Double.valueOf(numSpeed-1)));
    speed[numSpeed] = maxSpeed;
    for(int i=0;i<numSpeed;i++){
      speed[i] = minSpeed*(Math.pow(ratio,i));
    }
  }
  
  
  public void showspeed(){
    System.out.println("-------->All Speeds<--------");
    for(int i=0;i<=numSpeed;i++){
      System.out.print(speed[i]+"\t");
    }
  }
}



public class Spindle{
  public static void main(String[] args) {
    Spinspeeds speed = new Spinspeeds();
    try{
      speed.init();
      speed.calcspeed();
      speed.showspeed();
    }
    catch(MyException e){
      e.printStackTrace();
    }
    System.out.println("Program finished....");
  }
}
