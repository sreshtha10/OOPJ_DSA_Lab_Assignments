package project0;

import java.util.Date;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;

class Employee{
	int id;
	//String type = "";
	String name;
	Date dob;
	Department department;
	Employee(int id,String name,Date dob,Department department){
		this.id = id;
		this.name = name;
		this.dob =dob;
		this.department = department;
	}
}

class Department{
	int id;
	//String type = "";
	String location;
	Department(int id,String location){
		this.id = id;
		this.location = location;
	}
}

class Manager extends Employee{
	//final String type= "Manager";
	Manager(int id, String name, Date dob, Department department) {
		super(id, name, dob, department);
		
	}
	
}

class Clerk extends Employee{
	//final String type = "Clerk";
	Clerk(int id, String name, Date dob, Department department) {
		super(id, name, dob, department);
		
	}
	
}


class GDW extends Employee{
	//final String type = "GDW";
	GDW(int id, String name, Date dob, Department department) {
		super(id, name, dob, department);
		
	}
	
}



class Sales extends Department{
	//final String type = "Sales";
	Sales(int id, String location) {
		super(id, location);
		
	}
	
}

class Marketing extends Department{
	//final String type = "Marketing";
	Marketing(int id, String location) {
		super(id, location);
	}
	
}


class Finance extends Department{
//	final String type = "Finance";
	Finance(int id, String location) {
		super(id, location);
		
	}
	
}



//created a class Admin
class Admin{
	Employee e;
	File adminFile;
	Admin(Employee e){
		this.e = e;
	}
	
	
	//format of writing data - id,name,dob,depId,depCity
	public void setEmployeeData() {
		this.adminFile = new File("C:\\Users\\sresh\\Desktop\\OOPJ\\admin.txt");
		try {
			this.adminFile.createNewFile();
			FileOutputStream fo = new FileOutputStream(this.adminFile,true);
			String s = e.id+","+e.name+","+e.dob+","+/*e.type+","*+e.department.type+","*/+e.department.id+","+e.department.location+ "\n";
			byte b[] = s.getBytes();
			fo.write(b);
			
			System.out.println("Data Saved Successfully !");
		}
		catch(IOException e) {
			System.out.println("Error occured");
		}
		
	}
}


// created a class user
class User{
	String nameEntered;
	int idEntered;
	
	User(String nameEntered,int idEntered){
		this.nameEntered= nameEntered;
		this.idEntered = idEntered;
	}
	
	
	public void getEmployeeData() {
		//display
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C:\\Users\\sresh\\Desktop\\OOPJ\\admin.txt")));
			String currLine;
			while((currLine = br.readLine()) != null) {
				StringTokenizer st = new StringTokenizer(currLine,",");
				if(this.idEntered == Integer.parseInt(st.nextToken()) && this.nameEntered.equals(st.nextToken())) {
					// successfully found the user
					System.out.println(currLine);
					return;
				}
			}
			System.out.println("Employee not found");
		}
		catch(IOException exp) {
			System.out.println("Error occurred !");
		}
	}
}


public class Main {
	public static void main(String agrs[]) {
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			System.out.println("Choose from the following");
			System.out.println("1. Admin");
			System.out.println("2. User");
			System.out.println("3. Exit");
			System.out.println("***********");
			int opt = sc.nextInt();
			switch(opt) {
			case 1:{
				
				
				//admin
				Admin admin = null;
				Employee e = null;
				Department d = null;
				String name;
				int id;
				Date dob = new Date();
				int dId;
				String dCity;
				while(true) {
					System.out.println("Choose from the following");
					System.out.println("1. Enter Employee Data");
					System.out.println("2. Exit");
					System.out.println("**************");
					int opt2 = sc.nextInt();
					switch(opt2) {
					case 1:{
						//enter the data
						System.out.println("Choose from the following");
						System.out.println("Enter Employee name");
						name = sc.next();
						
						//throw error
						System.out.println("Enter Employee id");
						id = sc.nextInt();
						//throw error
						System.out.println("Enter Employee DOB");
						String dateString = sc.next();
						//throw error
						SimpleDateFormat format = new SimpleDateFormat("dd-mm-yyyy");
						try {
							dob = format.parse(dateString);
						}
						catch(ParseException exp) {
							System.out.println("Wrong Format");
						}
						
						//throw error
						System.out.println("Enter department id");
					    dId = sc.nextInt();
					    //throw error
						System.out.println("Enter department city");
					    dCity = sc.next();
					    //throw error
						System.out.println("Choose the department ");
						System.out.println("1. Sales");
						System.out.println("2. Marketing");
						System.out.println("3. Finance");
						int depType = sc.nextInt();
						switch(depType) {
						case 1:{
							d = new Sales(dId, dCity);
							break;
						}
						
						case 2:{
							d = new Marketing(dId, dCity);
							break;
						}
						
						case 3:{
							d = new Finance(dId, dCity);
							break;
						}
						
						default:{
							System.out.println("Invalid Option");
						}
						}
						
						System.out.println("1. Manager");
						System.out.println("2. Clerk");
						System.out.println("3. GDW");
						int empType = sc.nextInt();
						switch(empType) {
						case 1:{
							e = new Manager(id, name, dob,d);
							break;
						}
						
						case 2:{
							e = new Clerk(id, name, dob, d);
							break;
						}
						
						case 3:{
							e = new Clerk(id, name, dob, d);
							break;
						}
						
						default:{
							System.out.println("Invalid option");
							
						}
						}
						
						admin = new Admin(e);
						admin.setEmployeeData();
						
						break;
					}
					
					case 2:{
					
						System.exit(0);
					}
					
					default:{
						System.out.println("Invalid Option");
					}
					}
				}
				
				
			}
			
			case 2:{
				
				
				
				//user
				User user = null;
				String name;
				int id;
				while(true) {
					System.out.println("Choose from the following");
					System.out.println("1. Display User Data");
					System.out.println("2. Exit");
					int opt3 = sc.nextInt();
					switch(opt3) {
					case 1:{
						
						// display user data by name and id
						System.out.println("Please enter the name");
						name = sc.next();
						//throw error
						System.out.println("Please enter the id");
						id = sc.nextInt();
						//throw error
						
						user = new User(name, id);
						user.getEmployeeData();
						
						break;
					}
					
					case 2:{
						
						// exit
						
						System.exit(0);
					}
					
					default:{
						System.out.println("Invalid option");
					}
					}
				}
				
				
			}
			
			
			case 3:{
				
				System.exit(0);
			}
			
			default:{
				System.out.println("Invalid option");
			}
			
			
			}
		}
	}
}
