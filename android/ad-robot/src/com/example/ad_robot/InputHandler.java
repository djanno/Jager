package com.example.ad_robot;

import java.io.IOException;

public class InputHandler implements IInputHandler {

	private static final char SMART_TO_LAZY = 'a';
	private static final char LAZY_TO_SMART = 'b';
	private static final char AUTO_TO_MANUAL = 'c';
	private static final char MANUAL_TO_AUTO = 'd';
	private static final char SERVO_0 = 'e';
	private static final char SERVO_45 = 'f';
	private static final char SERVO_90 = 'g';
	private static final char SERVO_135 = 'h';
	private static final char SERVO_180 = 'i';
	private static final char LIGHTS_ON = 'j';
	private static final char LIGHTS_OFF = 'k';
	private static final char MOTORS_RETRO_2 = 'l';
	private static final char MOTORS_RETRO_1 = 'm';
	private static final char MOTORS_STOP = 'n';
	private static final char MOTORS_GEAR_1 = 'o';
	private static final char MOTORS_GEAR_2 = 'p';
	private static final char LEFT_RETRO_2 = 'q';
	private static final char LEFT_RETRO_1 = 'r';
	private static final char LEFT_STOP = 's';
	private static final char LEFT_GEAR_1 = 't';
	private static final char LEFT_GEAR_2 = 'u';
	private static final char RIGHT_RETRO_2 = 'v';
	private static final char RIGHT_RETRO_1 = 'w';
	private static final char RIGHT_STOP = 'x';
	private static final char RIGHT_GEAR_1 = 'y';
	private static final char RIGHT_GEAR_2 = 'z';
	private static final char GET_DISTANCE = '+';
	
	private final MainActivity main;
	private boolean autopilot;
	
	public InputHandler(final MainActivity main) {
		this.main = main;
		this.autopilot = true;
	}
	
	private void sendMessageToServer(final byte message) {
		try {
			ConnectionManager.getInstance().writeToServer(message);
		}
		catch(IOException e) { }
	}

	@Override
	public void handleChangeOfLogicRequest(final int checkedId) {
		switch(checkedId) {
		case R.id.smartRB:
			if(this.autopilot) {
				this.sendMessageToServer((byte) LAZY_TO_SMART);
			}
			break;
		case R.id.lazyRB:
			this.sendMessageToServer((byte) SMART_TO_LAZY);
			break;
		case R.id.manualRB:
			if(this.autopilot) {
				try {
					ConnectionManager.getInstance().writeToServer((byte) AUTO_TO_MANUAL);
					this.main.enableManualNavigation(true);
					this.autopilot = false;
				}
				catch(IOException e) { }
			}
			break;
		}
	}

	@Override
	public void handleMotorEngagementRequest(final int buttonId) {
		switch(buttonId) {
		case R.id.leftGearTwoButton:
			this.sendMessageToServer((byte) LEFT_GEAR_2);
			break;
		case R.id.leftGearOneButton:
			this.sendMessageToServer((byte) LEFT_GEAR_1);
			break;
		case R.id.leftGearZeroButton:
			this.sendMessageToServer((byte) LEFT_STOP);
			break;
		case R.id.leftGearMinusOneButton:
			this.sendMessageToServer((byte) LEFT_RETRO_1);
			break;
		case R.id.leftGearMinusTwoButton:
			this.sendMessageToServer((byte) LEFT_RETRO_2);
			break;
		case R.id.rightGearTwoButton:
			this.sendMessageToServer((byte) RIGHT_GEAR_2);
			break;
		case R.id.rightGearOneButton:
			this.sendMessageToServer((byte) RIGHT_GEAR_1);
			break;
		case R.id.rightGearZeroButton:
			this.sendMessageToServer((byte) RIGHT_STOP);
			break;
		case R.id.rightGearMinusOneButton:
			this.sendMessageToServer((byte) RIGHT_RETRO_1);
			break;
		case R.id.rightGearMinusTwoButton:
			this.sendMessageToServer((byte) RIGHT_RETRO_2);
			break;
		case R.id.bothGearTwoButton:
			this.sendMessageToServer((byte) MOTORS_GEAR_2);
			break;
		case R.id.bothGearOneButton:
			this.sendMessageToServer((byte) MOTORS_GEAR_1);
			break;
		case R.id.bothGearZeroButton:
			this.sendMessageToServer((byte) MOTORS_STOP);
			break;
		case R.id.bothGearMinusOneButton:
			this.sendMessageToServer((byte) MOTORS_RETRO_1);
			break;
		case R.id.bothGearMinusTwoButton:
			this.sendMessageToServer((byte) MOTORS_RETRO_2);
			break;
		}
	}

	@Override
	public void handleLightSwitchInteraction(final boolean checked) {
		if(checked) {
			this.sendMessageToServer((byte) LIGHTS_ON);
		}
		else {
			this.sendMessageToServer((byte) LIGHTS_OFF);
		}
	}

	@Override
	public void handleGetDistanceRequest() {
		this.sendMessageToServer((byte) GET_DISTANCE);
	}

	@Override
	public void handleRotateServoRequest(final String servoPosition) {
		switch(Integer.parseInt(servoPosition)) {
		case 0:
			this.sendMessageToServer((byte) SERVO_0);
			break;
		case 45:
			this.sendMessageToServer((byte) SERVO_45);
			break;
		case 90:
			this.sendMessageToServer((byte) SERVO_90);
			break;
		case 135:
			this.sendMessageToServer((byte) SERVO_135);
			break;
		case 180:
			this.sendMessageToServer((byte) SERVO_180);
			break;
		}
	}

	@Override
	public void handleBackToAutoRequest() {
		try {
			ConnectionManager.getInstance().writeToServer((byte) MANUAL_TO_AUTO);
			this.main.enableManualNavigation(false);
			this.autopilot = true;
		}
		catch(IOException e) { }
	}
	
}
