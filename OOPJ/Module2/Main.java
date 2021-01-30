package project0;
import java.io.*;
import java.util.*;


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



class Traveller extends User{

	Traveller(String name, int age, int id) {
		super(name, age, id);
	}
	
}



class Hotel{
	String name;  // name of the hotel
	List<Traveller> travellers;
	String city;   //city in which the hotel is located.
	int rooms[] = new int[15];   //  1 means room is booked 0 means room is vacant, with 15 rooms
	Hotel(String name, String city) {
		this.name = name;
		this.city = city;
		this.travellers = new ArrayList<Traveller>();
	}
}


class HotelBooking{
	
	List<Hotel> hotels = new ArrayList<Hotel>(); //ArrayList to store all the hotel details  
	File users;// File which stores the password of different users for login
	File userBills;   // This file will store the bill of each user.
	User currUser;
	int idAssigned = 0;   // each user will be assigned a different id
	private int loggedin = -1; // to check if current user is logged in or not.
	HotelBooking(){
		hotels.add(new Hotel("Taj","New Delhi"));
		hotels.add(new Hotel("Paradise","Varanasi"));
		hotels.add(new Hotel("The Imperial Hotel","Jaipur"));
		hotels.add(new Hotel("Elsewhere","Goa"));
		hotels.add(new Hotel("The Leela Palace","Bengaluru"));
		hotels.add(new Hotel("Surya Samudra","Kovalam"));
		hotels.add(new Hotel("Taj Lake Palace","Udaipur"));
		hotels.add(new Hotel("Umaid Bhawan Palace","Jodhpur"));
		hotels.add(new Hotel("Lotus House Boat","Kerela"));
		
		
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
			System.out.println("Account cannot be created. Try again later !"+e);
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
	
	
	//to display the cities
	private void displayCities() {
		System.out.println("Cities in which hotels are available:");
		Iterator itr = hotels.iterator();
		while(itr.hasNext()) {
			System.out.println(((Hotel)(itr.next())).city);
		}
		return;
	}
	
	
	//method for roomBooking
	public void RoomBooking(){
		Scanner scanner = new Scanner(System.in);
		this.displayCities();
		System.out.println("Please choose a city:");
		String c = scanner.next();
		Iterator itr = hotels.iterator();
		while(itr.hasNext()) {
			if(c.equals(((Hotel)itr.next()).city)) {
				System.out.println("Hotels available :"+((Hotel)itr.next()).name);
				
			}
		}
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
					//Hotel booking	
					System.out.println("Choose from the following");
					System.out.println("1. Book a room");
					System.out.println("2. Bill");
					System.out.println("3. Logout & Exit");
					System.out.println("************");
					while(true) {
						int opt2 = sc.nextInt();
						switch(opt2) {
						case 1 :{
							// room booking
							myBookingService.RoomBooking();
							System.out.println("************");
							break;
						}
						
						
						case 2:{
							//bill generation
							
							System.out.println("************");
							break;
						}
						
						case 3:{
							// logout current user.
							
							myBookingService.logOut();
							System.exit(0);
							System.out.println("************");
							break;
						}
					
						default:{
							System.out.println("Invalid Option !");
						}
						}
					}
				}
				System.out.println("************");
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



