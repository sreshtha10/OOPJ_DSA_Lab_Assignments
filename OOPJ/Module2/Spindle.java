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

class SpindleSpeeds {
	double minSpeed;
	double maxSpeed;
	double ratio;
	int numSpeed;
	double[] speed = new double[100];

	// calculating the speed
	public void getSpeed() {
		this.ratio = Math.pow((this.maxSpeed / this.minSpeed), (1 / Double.valueOf(this.numSpeed - 1))); // calculating
																											// R
		this.speed[this.numSpeed] = this.maxSpeed;
		for (int i = 0; i < this.numSpeed; i++) {
			this.speed[i] = this.minSpeed * (Math.pow(this.ratio, i));
		}
	}

	// Displaying speed
	public void displaySpeed() {
		System.out.println("Speeds :");
		for (int i = 0; i <= this.numSpeed; i++) {
			System.out.println(this.speed[i]);
		}
	}

}

public class Spindle {

	public static void main(String[] args) {
		SpindleSpeeds speed = new SpindleSpeeds();
		try {
			Scanner scanner = new Scanner(System.in);
			System.out.println("Enter the minimum speed");
			speed.minSpeed = scanner.nextDouble();
			if (speed.minSpeed == 0) {
				throw new MyException("Minimum speed cannot be zero !");
			}
			System.out.println("Enter the maximum speed");
			speed.maxSpeed = scanner.nextDouble();
			//throwing custom exception if maxSpeed is 0
			if (speed.maxSpeed == 0) {
				throw new MyException("Maximum speed cannot be zero !");
			}
			System.out.println("Enter number of speeds: ");
			speed.numSpeed = scanner.nextInt();
			//throwing custom exception if n <=1
			if (speed.numSpeed == 1 || speed.numSpeed < 1) {
				throw new MyException("Number of speed cant be one or less than one");
			}
			speed.getSpeed();
			speed.displaySpeed();
			
			scanner.close();
		} catch (MyException e) {
			System.out.println(e);
		}
		System.exit(0);
	}
}
