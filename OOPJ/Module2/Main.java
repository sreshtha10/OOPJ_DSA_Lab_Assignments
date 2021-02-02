package project0;
import java.io.*;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;


//interface DateValidator
interface DateValidator{
	boolean isValid(String dateString);
}

//abstract class to check date
abstract class CheckDate implements DateValidator{
	String dateFormat = "dd/mm/yyyy";
	
	public void DateValidatorUsingDateFormat(String dateFormat) {
		this.dateFormat = dateFormat;
	}
	
	public abstract boolean isValid(String dateString);
}



//custom exception for invalid date format
class InvalidDateFormat extends Exception{
	public InvalidDateFormat(String s) {
		super(s);
	}
}


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
	int rooms[];  
	final int price;  // charge for one night stay
	Hotel(String name, String city,int price) {
		this.name = name;
		this.city = city;
		this.travellers = new ArrayList<Traveller>();
		this.rooms = new int[15];
		for(int i =0;i<15;i++) {
			this.rooms[i] = 0;    // initially all rooms will be vacant.
		}
		this.price = price;
	}
}


class HotelBooking extends CheckDate{
	
	List<Hotel> hotels = new ArrayList<Hotel>(); //ArrayList to store all the hotel details  
	File users;// File which stores the password of different users for login
	File userBills;   // This file will store the bill of each user.
	File userBookings; // this will contain the booking dates
	User currUser;
	int idAssigned = 0;   // each user will be assigned a different id
	private int loggedin = -1; // to check if current user is logged in or not.
	HotelBooking(){
		hotels.add(new Hotel("Taj","New Delhi",1000));
		hotels.add(new Hotel("Paradise","Varanasi",2000));
		hotels.add(new Hotel("The Imperial Hotel","Jaipur",3000));
		hotels.add(new Hotel("Elsewhere","Goa",600));
		hotels.add(new Hotel("The Leela Palace","Bengaluru",800));
		hotels.add(new Hotel("Surya Samudra","Kovalam",900));
		hotels.add(new Hotel("Taj Lake Palace","Udaipur",1200));
		hotels.add(new Hotel("Umaid Bhawan Palace","Jodhpur",2200));
		hotels.add(new Hotel("Lotus House Boat","Kerela",3400));
		
		
		try {
			this.users = new File("C:\\Users\\sresh\\Desktop\\HotelBooking\\users.txt");
			this.userBills = new File("C:\\\\Users\\\\sresh\\\\Desktop\\\\HotelBooking\\\\userBills.txt");
			this.userBookings = new File("C:\\\\Users\\\\sresh\\\\Desktop\\\\HotelBooking\\\\userBookings.txt");
			this.users.createNewFile();
			this.userBills.createNewFile();
			this.userBookings.createNewFile();
			
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
	
	
	
	//method for selecting the hotel in which user is staying
	public void hotelBooking(){
		Scanner scanner = new Scanner(System.in);
		this.displayCities();
		System.out.println("Please choose a city:");
		String c = scanner.next();
		Iterator itr = hotels.iterator();
		Object i;
		while(itr.hasNext()) {
			i = itr.next();
			if(c.equals(((Hotel)i).city)) {
				System.out.println("Hotels available :"+((Hotel)i).name);
				System.out.println("Do you want to continue? 1/0");
				int x = scanner.nextInt();
				if(x == 1) {
					this.roomBooking((Hotel)i);
				}
				else {
					return;
				}
				
			}
		}
	}
	
	
	
	//method to book a room once a hotel is selected
	public void roomBooking(Hotel hotel) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Each room has a capacity for two adults. How many rooms do you wanna book?");
		int numRooms = sc.nextInt();
		for(int i=0;i<15;i++) {
			if(hotel.rooms[i] == 0) {  // 0 means room is vacant
				System.out.println("Enter the numbers of days you want to stay in "+hotel.name);
				int numDays = sc.nextInt();
				
				//check in
				System.out.println("Please enter the check in date in dd/mm/yyyy format");
				String checkinDate = sc.next();
				
				//checking if the entered date is in right format or not.
				try {
					if(!isValid(checkinDate)) {
						//not valid format
						throw new InvalidDateFormat("Please enter the date in dd/mm/yyyy format");
					}
				}
				catch(InvalidDateFormat e) {
					System.out.println(e);
				}

				StringTokenizer st1 = new StringTokenizer(checkinDate,"/");
				String checkinDay = st1.nextToken();
				String checkinMonth = st1.nextToken();
				String checkinYear = st1.nextToken();
				
				//check out 
				System.out.println("Please enter the check out date");
				String checkoutDate = sc.next();
				
				//checking if the entered date is in right format or not.
				try {
					if(!isValid(checkoutDate)) {
						//not valid format
						throw new InvalidDateFormat("Please enter the date in dd/mm/yyyy format");
					}
				}
				catch(InvalidDateFormat e) {
					System.out.println(e);
				}
				
				StringTokenizer st2 = new StringTokenizer(checkoutDate,"/");
				String checkoutDay = st2.nextToken();
				String checkoutMonth = st2.nextToken();
				String checkoutYear = st2.nextToken();
				
				
				
				//writing check in and check out date in file userBookings
				try {
					FileOutputStream fo =new FileOutputStream(this.userBookings,true);
					String write = currUser.id+","+hotel.price + "," +numDays+","+","+","+","+checkinDate+","+checkoutDate;
					byte b[] = write.getBytes();
					fo.write(b);
					hotel.rooms[i] = 1;
					System.out.println("Your room is booked.");
					System.out.println("Are you a traveller? 1/0");
					int opt = sc.nextInt();
					if(opt == 1) {
						hotel.travellers.add((Traveller) currUser);
					}
					else {
						continue;
					}
					return;
				}
				catch(IOException e) {
					System.out.println("Room cannot be booked !");
					return;
				}
			}
		}	
	}

	
	
	//this will print the bill of the current user.
	public void getBill() {
		try {
			
			//calculating bill from userBookings file and writing bill in userBills file
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(this.userBookings)));
			FileOutputStream fo = new FileOutputStream(this.userBills,true);
			String currLine;
			int bill = 0;
			int price = 0,numDays = 0;
			while((currLine = br.readLine()) != null) {
				StringTokenizer st = new StringTokenizer(currLine,",");
				
				//Finding user by Id
				if(currUser.id == Integer.parseInt(st.nextToken())) {
					numDays = Integer.parseInt(st.nextToken());
					price = Integer.parseInt(st.nextToken());
					bill = numDays*price;
					break;
				}
				else {
					continue;
				}
				
			}
			
			//if bill is greater than 10000, discount of 1000 Rs is granted
			if(bill>=10000) {
				bill = bill-1000;
			}
			
			System.out.println("Your bill is Rs "+bill);
			
			//writing data in userBills file
			String s = currUser.id+","+(bill);
			byte b[] = s.getBytes();
			fo.write(b);
			fo.close();
		}
		catch(IOException e) {
			System.out.println("Cannot calculate bill. Try again later !");
		}
	}
	
	
	
	// this method will validate the format of the entered date.
	@Override
	public boolean isValid(String dateString) {
		DateFormat sdf = new SimpleDateFormat(this.dateFormat);
        sdf.setLenient(false);
        try {
            sdf.parse(dateString);
        } catch (ParseException e) {
            return false;
        }
        return true;
	}
}




//Main
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
							myBookingService.hotelBooking();
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



