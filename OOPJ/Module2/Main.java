package project0;
import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;


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


class HotelBooking{
	
	File users;// File which stores the password of different users for login
	User currUser;
	int idAssigned = 0;   // each user will be assigned a different id
	private int loggedin = -1; // to check if current user is logged in or not.
	HotelBooking(){
		try {
			this.users = new File("C:\\Users\\sresh\\Desktop\\HotelBooking\\users.txt");
			users.createNewFile();
		}
		catch(IOException e) {
			System.out.println("Error occured !");
		}
	}
	
	
	//method to signUp
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
	
	// method for login
	public void login() {
		try {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter your name (username)");
		String name = sc.next();
		System.out.println("Enter your password");
		String pass = sc.next();
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(this.users)));
		
		String currLine;
		String fname,fpass;
		while((currLine = br.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(currLine,",");
			if((fname = st.nextToken()).equals(name)) {
				if((fpass = st.nextToken()).equals(pass)) {
					//successfully logged in
					this.loggedin = 1;
					System.out.println("Logged in !");
					return;
				}
				else {
					System.out.println("Password does not match !");
					return;
				}
			}
			else {
				st.nextToken();
				st.nextToken();
				continue;
			}
		}
		}
		catch(IOException e) {
			System.out.println("Cannot login ! Try again later.");
			return;
		}
	}
	
	
	// method to logout the current user.
	public void logOut() {
		this.loggedin = -1;
		System.out.println("Logged out");
		return;
	}
	
	
	//method to check if any user is logged in or not
	public int checkStatus() {
		return this.loggedin;
	}
}

class Main{
	public static void main(String args[]){
		HotelBooking myBookingService = new HotelBooking();
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
				myBookingService.login();
				System.out.println("************");
				if(myBookingService.checkStatus() == 1) {
					//HotelBooking booking 
						
				}
				break;
			}
			
			case 2:{
				//sign  up
				System.out.println("Enter your name (username)");
				String name = sc.next();
				System.out.println("Enter your age");
				int age = sc.nextInt();
				User user = new User(name, age, myBookingService.idAssigned);
				myBookingService.signUp(user);
				System.out.println("************");
				break;
			}
			
			case 3: {
				//exit
				myBookingService.logOut();
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



