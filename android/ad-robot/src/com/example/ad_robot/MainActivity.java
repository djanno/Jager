package com.example.ad_robot;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;

public class MainActivity extends Activity {

	private static final String TARGET = "JAGER";
	
	private IInputHandler handler;
	private IBluetoothClient client;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		this.handler = new InputHandler(this);
		this.client = new BluetoothClient(this);
		((Spinner)this.findViewById(R.id.servoPositionSpinner)).setEnabled(false);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
	
	@Override
	public void onStart() {
		super.onStart();
		
		if(this.client.isBluetoothEnabled()) {
			try {
				this.client.findServerDevice(TARGET);
				this.client.connectToServer();
			}
			catch(IllegalArgumentException e) { 
				Log.e("JAGER not found", e.getMessage());
				this.finish();
			}
		}
		
		class EngineButtonListener implements OnClickListener {

			@Override
			public void onClick(View v) {
				handler.handleMotorEngagementRequest(v.getId());
			}
			
		}
		
		OnClickListener engineButtonsListener = new EngineButtonListener();
		((Button) this.findViewById(R.id.leftGearTwoButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.leftGearOneButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.leftGearZeroButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.leftGearMinusOneButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.leftGearMinusTwoButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.rightGearTwoButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.rightGearOneButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.rightGearZeroButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.rightGearMinusOneButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.rightGearMinusTwoButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.bothGearTwoButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.bothGearOneButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.bothGearZeroButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.bothGearMinusOneButton)).setOnClickListener(engineButtonsListener);
		((Button) this.findViewById(R.id.bothGearMinusTwoButton)).setOnClickListener(engineButtonsListener);
		((RadioGroup) this.findViewById(R.id.modeMenu)).setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {

			@Override
			public void onCheckedChanged(RadioGroup group, int checkedId) {
				handler.handleChangeOfLogicRequest(checkedId);
			}
			
		});
		((Switch) this.findViewById(R.id.Lights)).setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
			
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				handler.handleLightSwitchInteraction(isChecked);
			}
		});
		((Spinner) this.findViewById(R.id.servoPositionSpinner)).setOnItemSelectedListener(new OnItemSelectedListener() {

			@Override
			public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
				handler.handleRotateServoRequest(((Spinner) findViewById(R.id.servoPositionSpinner)).getSelectedItem().toString());
			}

			@Override
			public void onNothingSelected(AdapterView<?> parent) {
				// TODO Auto-generated method stub
				
			}
			
		});
		((Button) this.findViewById(R.id.getDistanceButton)).setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				handler.handleGetDistanceRequest();
			}
			
		});
		((Button) this.findViewById(R.id.backToAutoButton)).setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				handler.handleBackToAutoRequest();
			}
		});
	}
	
	@Override
	public void onStop() {
		super.onStop();
	}
	
	@Override
	public void onDestroy() {
		super.onDestroy();
		ConnectionManager.getInstance().cancel();
	}
	
	@Override
	public void onActivityResult(int requestID, int result, Intent data) {
		if (requestID == BluetoothClient.ENABLE_BT_REQUEST && result == Activity.RESULT_CANCELED) {
			Log.e("Error", "Could not initiate Bluetooth. Quitting...");
			this.finish();
		}
		else if (requestID == BluetoothClient.ENABLE_BT_REQUEST && result == Activity.RESULT_OK) {
			try {
				this.client.findServerDevice(TARGET);
				this.client.connectToServer();
			}
			catch(IllegalArgumentException e) {
				Log.e("JAGER not found", e.getMessage());
				this.finish();
			}
		}
	}
	
	public void enableManualNavigation(final boolean enabled) {
		
		if(!enabled) {
			((Spinner) this.findViewById(R.id.servoPositionSpinner)).setSelection(0);
			((RadioGroup) this.findViewById(R.id.modeMenu)).check(R.id.smartRB);
			((TextView) this.findViewById(R.id.distanceLog)).setText("N.D.");
		}
		
		((Button) this.findViewById(R.id.leftGearTwoButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.leftGearOneButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.leftGearZeroButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.leftGearMinusOneButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.leftGearMinusTwoButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.rightGearTwoButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.rightGearOneButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.rightGearZeroButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.rightGearMinusOneButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.rightGearMinusTwoButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.bothGearTwoButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.bothGearOneButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.bothGearZeroButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.bothGearMinusOneButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.bothGearMinusTwoButton)).setEnabled(enabled);
		((Switch) this.findViewById(R.id.Lights)).setEnabled(enabled);
		((Spinner) this.findViewById(R.id.servoPositionSpinner)).setEnabled(enabled);
		((Button) this.findViewById(R.id.getDistanceButton)).setEnabled(enabled);
		((Button) this.findViewById(R.id.backToAutoButton)).setEnabled(enabled);
		((TextView) this.findViewById(R.id.distanceLog)).setEnabled(enabled);
		((RadioButton) this.findViewById(R.id.smartRB)).setEnabled(!enabled);
		((RadioButton) this.findViewById(R.id.lazyRB)).setEnabled(!enabled);
		((RadioButton) this.findViewById(R.id.manualRB)).setEnabled(!enabled);

	}
}
