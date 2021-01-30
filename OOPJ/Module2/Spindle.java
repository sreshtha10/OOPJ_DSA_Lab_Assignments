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

class Spinspeeds {
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
			System.out.print(this.speed[i] + "\t");
		}
	}

}

public class Spindle {

	public static void main(String[] args) {
		Spinspeeds speed = new Spinspeeds();
		try {
			Scanner scanner = new Scanner(System.in);
			System.out.println("Enter Minspeed: ");
			speed.minSpeed = scanner.nextDouble();
			if (speed.minSpeed == 0) {
				throw new MyException("Minspeed cant be zero");
			}
			System.out.println("Enter Maxspeed: ");
			speed.maxSpeed = scanner.nextDouble();
			if (speed.maxSpeed == 0) {
				throw new MyException("Maxspeed cant be zero");
			}
			System.out.println("Enter number of speeds: ");
			speed.numSpeed = scanner.nextInt();
			if (speed.numSpeed == 1 || speed.numSpeed < 1) {
				throw new MyException("Number of speed cant be one or less than one");
			}
			System.out.println("******************");
			speed.getSpeed();
			System.out.println("******************");
			speed.displaySpeed();
			System.out.println("******************");
		} catch (MyException e) {
			System.out.println(e);
		}
		System.exit(0);
	}
}
