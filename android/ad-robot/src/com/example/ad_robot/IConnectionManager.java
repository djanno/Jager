package com.example.ad_robot;

import java.io.IOException;

import android.app.Activity;
import android.bluetooth.BluetoothSocket;

public interface IConnectionManager {
	
	void linkToMainThread(final Activity main);
	
	void setChannel(final BluetoothSocket socket);
	
	void writeToServer(final byte b) throws IOException;
	
	void cancel();
}
