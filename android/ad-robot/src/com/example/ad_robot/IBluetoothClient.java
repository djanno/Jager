package com.example.ad_robot;

public interface IBluetoothClient {
	
	boolean isBluetoothEnabled();
	
	void findServerDevice(final String target) throws IllegalArgumentException;
	
	void connectToServer();
	
}
