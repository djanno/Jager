package com.example.ad_robot;

public interface IInputHandler {
	
	void handleChangeOfLogicRequest(final int checkedId);
	
	void handleMotorEngagementRequest(final int buttonId);
	
	void handleLightSwitchInteraction(final boolean checked);
	
	void handleGetDistanceRequest();
	
	void handleRotateServoRequest(final String servoPosition);
	
	void handleBackToAutoRequest();
	
}
