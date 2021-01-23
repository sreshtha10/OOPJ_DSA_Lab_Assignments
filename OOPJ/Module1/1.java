package project0;
import java.util.*;
import java.io.*;


//item_detail class
class item_detail{
	int price;
	List<String> ingredients = new ArrayList<String>(); // ArrayList to store ingredients
	String name;
	int id;
	int total_order = 0;
	item_detail(int price,String name,int id,String... ingredients){
		this.price = price;
		this.name = name;
		this.id = id;
		for(String ingredient: ingredients) {
			this.ingredients.add(ingredient);
		}
	}
}// end of class



// Person class
class Person{
	String name;
	String mobile_no;
	int order_no;
	File orderHistoryFile;
	List<item_detail> orderHistory = new ArrayList<item_detail>();  // ArrayList to keep track of items 
	Person(String name,String mobile_no){
		this.name = name;
		this.mobile_no = mobile_no;
		this.order_no =0;
		// creating a file by the name_mobileno. of the person if it doesn't exists.
		orderHistoryFile = new File("C:\\Users\\sresh\\Desktop\\Restaurant\\"+this.name+"_"+this.mobile_no+ ".txt");
		try {
			orderHistoryFile.createNewFile();
		}
		catch(IOException e) {
			System.out.println("Error occured. Try again !");
		}
	}
	
	
	// using ArrayList to store the items ordered
	void placeOrder(item_detail item) {
		//using FileOutputStream to write order history in the user file in comma separated format.
		try {
			FileOutputStream fo = new FileOutputStream(this.orderHistoryFile,true);
			String s = item.name+","+item.price+","+item.id+"\n";
			byte b[] = s.getBytes();
			fo.write(b);
			fo.flush();
			fo.close();
			System.out.println("Your order has been placed");
			this.orderHistory.add(item);
			this.order_no += 1;
		}
		catch(IOException e) {
			System.out.println("Your order can't be place at the moment");
		}
		
		return;
	}
	
	
	//displaying history of user by reading the user file.
	void displayHistory() {
		try {
			System.out.println("Order History: ");
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(this.orderHistoryFile)));
			String currLine;
			int price,id;
			String name;
			while((currLine = br.readLine()) != null) {
				StringTokenizer st = new StringTokenizer(currLine,",");
				name = st.nextToken();
				price = Integer.parseInt(st.nextToken());
				id = Integer.parseInt(st.nextToken());
				System.out.println(id+"  "+name+"  "+price);
			}
		}
		catch(IOException e) {
				System.out.println("Can't display history");
		}
		return;
	}
}//end of class



//Restaurant class
class Restaurant{
	List<item_detail> menu= new ArrayList<item_detail>();
	int revenue;
	List<Person> customers = new ArrayList<Person>();  //ArrayList to store details of customers.
	
	
	 Restaurant(item_detail...details ) { // I will add the items in the menu through constructor.
		 	for(item_detail i: details) {
		 		this.menu.add(i);  //each item will be added to the menu of the restaurant.
		 	}
		}
	
	 
	//adding customer 
	void addCustomer(Person p) {
		this.customers.add(p);
		return;
	}
	
	
   //placing order	
   void placeOrder(Person p) {
	   
	   }
	   
	   
	   
    
	void DisplayPersonHistory(Person p) {
		p.displayHistory();

	}
	 
	//printing the menu of the restaurant.
	void displayMenu() {
		System.out.println("Menu:");
		for(item_detail i : this.menu) {
			System.out.println(i.id+" "+i.name+" "+i.price);
		}
	}
	 
	
	//displaying the bill of the customer.
	void displayBill(Person p) {
		// using orderHistory vector of Person class to create bill
		Iterator itr = p.orderHistory.iterator();
		p.displayHistory();
		int sum = 0;
		while(itr.hasNext()) {
			item_detail item =(item_detail) itr.next();
			sum += item.price;
		}
		
		System.out.println("Total bill is Rs."+sum);
		return;
	}
	
	 
}//end of class



//Main class
class Main{
	public static void main(String args[]) throws IOException {
		
		// creating restaurant menu
		item_detail item1 = new item_detail(250,"butter chicken", 1,"chicken","butter","tomato","cream");
		item_detail item2 = new item_detail(230,"butter paneer", 2,"paneer","butter","tomato","cream");
		item_detail item3 = new item_detail(150,"mix veg", 3,"potato","tomato","chilli");
		item_detail item4 = new item_detail(200,"dal makhani", 4,"dal","butter","garlic");
		item_detail item5 = new item_detail(20,"roti", 5,"wheat");
		item_detail item6 = new item_detail(180,"pulao", 6,"rice","cinnamon","cardamom");
		item_detail item7 = new item_detail(220,"custard", 7,"apple","sugar","banana","almond");
		Restaurant restaurant = new Restaurant(item1,item2,item3,item4,item5,item6,item7);
		
		
		restaurant.displayMenu();
		
		
		
	
		
	}
}//end of class



