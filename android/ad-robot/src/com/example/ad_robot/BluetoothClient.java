package com.example.ad_robot;

import java.io.IOException;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.graphics.Color;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.RadioGroup;
import android.widget.TextView;

public class BluetoothClient implements IBluetoothClient {
	
	private static final String CONNECTION_UUID = "00001101-0000-1000-8000-00805F9B34FB";
	protected static final int ENABLE_BT_REQUEST = 255;
	
	private final BluetoothAdapter adapter;
	private final Activity main;
	private BluetoothDevice server;
	
	public BluetoothClient(final Activity main) {
		this.adapter = BluetoothAdapter.getDefaultAdapter();
		this.main = main;
		this.server = null;
		
		if(this.adapter == null) {
			Log.e("Error", "Bluetooth not available on this device.");
			this.main.finish();
		}
		if(!this.adapter.isEnabled()) {
			this.main.startActivityForResult(new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE), ENABLE_BT_REQUEST);
		}
	}
	
	@Override
	public boolean isBluetoothEnabled() {
		return this.adapter.isEnabled();
	}
	
	@Override
	public void findServerDevice(final String target) throws IllegalArgumentException {
		for(BluetoothDevice device : this.adapter.getBondedDevices()) {
			if(device.getName().equals(target)) {
				this.server = device;
				return;
			}
		}

		throw new IllegalArgumentException("Server device not found in the paired devices list");
		
	}
	
	@Override
	public void connectToServer() {
		new ConnectionTask(this.server, UUID.fromString(CONNECTION_UUID), this.main).execute();
	}

	private static class ConnectionTask extends AsyncTask<Void, Void, Void> {

		private final Activity main;
		private BluetoothSocket socket;

		public ConnectionTask(final BluetoothDevice server, final UUID uuid, final Activity main) {
			this.main = main;
			try {
				this.socket = server.createRfcommSocketToServiceRecord(uuid);
			} catch (IOException e) { }
		}

		@Override
		protected Void doInBackground(final Void... params) {
			while(!this.socket.isConnected()) {
				try {
					this.socket.connect();
				} catch (IOException e) { }
			}
			ConnectionManager.getInstance().linkToMainThread(this.main);
			ConnectionManager.getInstance().setChannel(this.socket);
			ConnectionManager.getInstance().start();
			return null;
		}

		@Override
		protected void onPostExecute(final Void result) {
			if(this.socket.isConnected()) {
				TextView tv = (TextView) this.main.findViewById(R.id.connectionLog);
				tv.setText("Connected to the JAGER");
				tv.setTextColor(Color.GREEN);
				tv.setHintTextColor(Color.GREEN);
				RadioGroup menu = (RadioGroup) this.main.findViewById(R.id.modeMenu);
				for(int i = 0; i < menu.getChildCount(); i++) {
					menu.getChildAt(i).setEnabled(true);
				}
			}
			else {
				Log.e("Failed to connect", "Couldn't connect to the JAGER");
				this.main.finish();
			}
		}

	}
}
