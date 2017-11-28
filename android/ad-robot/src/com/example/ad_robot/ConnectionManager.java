package com.example.ad_robot;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;

import android.app.Activity;
import android.bluetooth.BluetoothSocket;
import android.widget.TextView;

public final class ConnectionManager extends Thread implements IConnectionManager {
	
	private static ConnectionManager SINGLETON = null;
	
	private BluetoothSocket socket;
	private BufferedReader fromServer;
	private OutputStream toServer;
	private Activity main;
	
	private ConnectionManager() { }
	
	public static ConnectionManager getInstance() {
		if(SINGLETON == null) {
			SINGLETON = new ConnectionManager();
		}
		return SINGLETON;
	}
	
	@Override
	public void linkToMainThread(final Activity main) {
		this.main = main;
	}
	
	@Override
	public void setChannel(final BluetoothSocket socket) {
		this.socket = socket;
		
		try {
			this.fromServer = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
			this.toServer = this.socket.getOutputStream();
		} 
		catch(IOException e) { }
	}
	
	@Override
	public void run() {
		while(this.socket.isConnected()) {
			try {
				final String s = this.fromServer.readLine();
				this.main.runOnUiThread(new Runnable() {
					
					@Override
					public void run() {
						if(Integer.parseInt(s) == 0) {
							((TextView) main.findViewById(R.id.distanceLog)).setText("FAILED!");
						}
						else {
							((TextView) main.findViewById(R.id.distanceLog)).setText(s + " cm");
						}
					}
					
				});
			}
			catch(IOException e) { }
		}
	}
	
	@Override
	public void writeToServer(byte b) throws IOException {
		if(this.toServer == null) throw new IOException();
		this.toServer.write((int) b);
	}
	
	@Override
	public void cancel() {
		try {
			this.socket.close();
		}
		catch(IOException e) { }
	}
	
}