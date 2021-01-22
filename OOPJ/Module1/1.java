package project0;
import java.util.*;
import java.io.*;


class item_detail{
	int price;
	String ingredients[]; // array to store ingredients
	String name;
	int id;
	static int total_order = 0;
	item_detail(int price,String name,int id){
		Scanner sc = new Scanner(System.in);
		this.price = price;
		this.name = name;
		this.id = id;
		System.out.println("Enter the number of ingredients used");
		int size = sc.nextInt();
		this.ingredients = new String[size];
		System.out.println("Enter the ingredients");
		for(int i=0;i<size;i++) {
			this.ingredients[i] = sc.next();
		}
		sc.close();
	}
	
	// end of class
}

class person{
	String name;
	int mobile_no;
	int order_no;
	List<item_detail> orderHistory = new Vector<item_detail>();  // array to keep track of items 
	person(String name,int mobile_no){
		this.name = name;
		this.mobile_no = mobile_no;
		this.order_no =0;
	}
	
	
	// using Vector to store the items ordered
	void placeOrder(item_detail item) {
		System.out.println("Your order has been accepted");
		this.orderHistory.add(item);
		return;
	}
	
	void displayHistory() {
		System.out.println("Order History: ");
		Iterator i = this.orderHistory.iterator();
		while(i.hasNext()) {
			item_detail x = (item_detail)i.next();
			System.out.println(x.name);
		}
		return;
	}
	
	
	
}

class Restaurant{
	item_detail menu[];
	
	List<person> customers = new Vector<person>();
	

	 Restaurant() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of dishes available");
		int size = sc.nextInt();
		this.menu = new item_detail[size];
		System.out.println("Enter the dishes");
		for(int i=0;i<size;i++) {
			System.out.println("Enter the name of the dish");
			String name = sc.next();
			System.out.println("Enter the price of the dish");
			int price = sc.nextInt();
			System.out.println("Enter the id of the dish");
			int id = sc.nextInt();
			this.menu[i] = new item_detail(price,name,id);
		}
		
		sc.close();
		
	}
	 
	 
	void addcustomer(person p) {
		this.customers.add(p);
		return;
	}
	 
   void placeOrder(person p) {
	   System.out.println("Enter the item to be ordered");
	   
	   
   }
	 
	// void DisplayPersonHistory(person p)
	 
	 //void display menu()
	 
	 
	 
}

class Main{
	public static void main(String args[]) {
			// Implementation
		

		
		
	
	}
}



