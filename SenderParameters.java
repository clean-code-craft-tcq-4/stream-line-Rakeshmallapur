package com.java.stream.line;

public class SenderParameters {

	public int temperature;
	public int stateOfCharge;
	public float chargeRate;

	public SenderParameters(int temperature, int soc, float chargeRate) {
		this.temperature = temperature;
		this.stateOfCharge = soc;
		this.chargeRate = chargeRate;
	}
}