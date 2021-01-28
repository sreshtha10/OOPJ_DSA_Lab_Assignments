package project0;
import java.io.*;
import java.util.Scanner;

class User{
	String name;
	int age;
	int id;
	String password;
	User(String name,int age,int id){
		this.name = name;
		this.age = age;
		this.id = id;
	}

}


class Hotel{
	File users; // File which stores the password of different users for login
	
}

class Main{
	Hotel hotel = new Hotel();
	public static void main(String args[]) {
		System.out.println("Choose from the following");
		System.out.println("1. Login ");
		System.out.println("2. Signup");
		System.out.println("3. Exit");
		System.out.println("************");
		Scanner sc = new Scanner(System.in);
		while(true) {
			int opt = sc.nextInt();
			switch(opt) {
				
			case 1:{
				//login
				
				
				System.out.println("************");
				break;
			}
			
			case 2:{
				//sign  up
				
				System.out.println("************");
				break;
			}
			
			case 3: {
				//exit
				System.exit(0);
				
			}
			
			default:{
				System.out.println("Invalid choice !");
				System.out.println("************");
			}
			
			}
		}
		
	}
}



