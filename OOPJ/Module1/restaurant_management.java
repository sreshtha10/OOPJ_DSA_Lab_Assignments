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
	File users;// File which stores the password of different users for login
	User currUser;
	int idAssigned = 0;   // each user will be assigned a different id
	Hotel(){
		try {
			this.users = new File("C:\\Users\\sresh\\Desktop\\Hotel\\users.txt");
			users.createNewFile();
		}
		catch(IOException e) {
			System.out.println("Error occured !");
		}
	}
	
	public void signUp(User user) {
		try {
			Scanner scanner = new Scanner(System.in);
			String pass,cpass;
			FileOutputStream fo = new FileOutputStream(this.users,true);
			System.out.println("Please enter your password");
			pass = scanner.next();
			System.out.println("Please confirm your password");
			cpass = scanner.next();
			if(cpass.equals(pass)) {
				user.password = pass;
				user.id  = this.idAssigned;
				String s = user.name +","+user.password+","+this.idAssigned+","+user.age+"\n";  // storing in comma seperated format
				byte b[] = s.getBytes();
				fo.write(b);
				this.idAssigned += 1;
				System.out.println("Your id is "+this.idAssigned);  
				System.out.println("Account created ! Please login to continue");
				fo.close();
				return;
			}
			else {
				System.out.println("Password does not match !");
				signUp(user);
				return;
			}
		}
		catch(IOException e) {
			System.out.println("Account cannot be created. Try again later !");
			return;
		}
		
	}
	
	
	public void login(User user) {
		
	}
	
}

class Main{
	public static void main(String args[]){
		Hotel hotel = new Hotel();
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
				System.out.println("Enter your name (username)");
				String name = sc.next();
				System.out.println("Enter your age");
				int age = sc.nextInt();
				System.out.println("Enter your id");
				int id = sc.nextInt();
				User user = new User(name, age, id);
				hotel.login(user);
				System.out.println("************");
				break;
			}
			
			case 2:{
				//sign  up
				System.out.println("Enter your name (username)");
				String name = sc.next();
				System.out.println("Enter your age");
				int age = sc.nextInt();
				User user = new User(name, age, hotel.idAssigned);
				hotel.signUp(user);
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



