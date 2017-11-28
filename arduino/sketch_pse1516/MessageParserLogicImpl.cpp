#include "MessageParserLogicImpl.h"
#include "LightControlTask.h"
#include "OrientationTask.h"
#include "NavigationTask.h"
#include "RobotImpl.h"
#include "Smart.h"
#include "Lazy.h"

#define SMART_TO_LAZY 'a'
#define LAZY_TO_SMART 'b'
#define AUTO_TO_MANUAL 'c'
#define MANUAL_TO_AUTO 'd'
#define SERVO_0 'e'
#define SERVO_45 'f'
#define SERVO_90 'g'
#define SERVO_135 'h'
#define SERVO_180 'i'
#define LIGHTS_ON 'j'
#define LIGHTS_OFF 'k'
#define MOTORS_RETRO_2 'l'
#define MOTORS_RETRO_1 'm'
#define MOTORS_STOP 'n'
#define MOTORS_GEAR_1 'o'
#define MOTORS_GEAR_2 'p'
#define LEFT_RETRO_2 'q'
#define LEFT_RETRO_1 'r'
#define LEFT_STOP 's'
#define LEFT_GEAR_1 't'
#define LEFT_GEAR_2 'u'
#define RIGHT_RETRO_2 'v'
#define RIGHT_RETRO_1 'w'
#define RIGHT_STOP 'x'
#define RIGHT_GEAR_1 'y'
#define RIGHT_GEAR_2 'z'
#define GET_DISTANCE '+'

MessageParserLogicImpl::MessageParserLogicImpl() {
	this->robot = RobotImpl::getInstance();
}

MessageParserState MessageParserLogicImpl::stateListening() {
	if (this->robot->getMessageBox()->messageAvailable()) {
		Message* message = this->robot->getMessageBox()->getMessage();
		switch (message->getContent()) {
		case SMART_TO_LAZY:
			this->robot->reset();
			OrientationTask::getInstance()->changeLogic(new Lazy());
			NavigationTask::getInstance()->reset();
			break;
		case LAZY_TO_SMART:
			this->robot->reset();
			OrientationTask::getInstance()->changeLogic(new Smart());
			NavigationTask::getInstance()->reset();
			break;
		case AUTO_TO_MANUAL:
			this->robot->reset();
			OrientationTask::getInstance()->sleep();
			NavigationTask::getInstance()->sleep();
			LightControlTask::getInstance()->sleep();
			break;
		case MANUAL_TO_AUTO:
			this->robot->reset();
			OrientationTask::getInstance()->changeLogic(new Smart());
			NavigationTask::getInstance()->reset();
			LightControlTask::getInstance()->reset();
			break;
		case SERVO_0:
			this->robot->getServo()->changePosition(0);
			break;
		case SERVO_45:
			this->robot->getServo()->changePosition(45);
			break;
		case SERVO_90:
			this->robot->getServo()->changePosition(90);
			break;
		case SERVO_135:
			this->robot->getServo()->changePosition(135);
			break;
		case SERVO_180:
			this->robot->getServo()->changePosition(180);
			break;
		case LIGHTS_ON:
			for (int i = 0; i < LIGHTS; i++) this->robot->getLight(i)->switchOn();
			break;
		case LIGHTS_OFF:
			for (int i = 0; i < LIGHTS; i++) this->robot->getLight(i)->switchOff();
			break;
		case MOTORS_RETRO_2:
			this->robot->getLeftMotor()->setSpeed(-GEAR2);
			this->robot->getRightMotor()->setSpeed(-GEAR2);
			break;
		case MOTORS_RETRO_1:
			this->robot->getLeftMotor()->setSpeed(-GEAR1);
			this->robot->getRightMotor()->setSpeed(-GEAR1);
			break;
		case MOTORS_STOP:
			this->robot->getLeftMotor()->setSpeed(0);
			this->robot->getRightMotor()->setSpeed(0);
			break;
		case MOTORS_GEAR_1:
			this->robot->getLeftMotor()->setSpeed(GEAR1);
			this->robot->getRightMotor()->setSpeed(GEAR1);
			break;
		case MOTORS_GEAR_2:
			this->robot->getLeftMotor()->setSpeed(GEAR2);
			this->robot->getRightMotor()->setSpeed(GEAR2);
			break;
		case LEFT_RETRO_2:
			this->robot->getLeftMotor()->setSpeed(-GEAR2);
			break;
		case LEFT_RETRO_1:
			this->robot->getLeftMotor()->setSpeed(-GEAR1);
			break;
		case LEFT_STOP:
			this->robot->getLeftMotor()->setSpeed(0);
			break;
		case LEFT_GEAR_1:
			this->robot->getLeftMotor()->setSpeed(GEAR1);
			break;
		case LEFT_GEAR_2:
			this->robot->getLeftMotor()->setSpeed(GEAR2);
			break;
		case RIGHT_RETRO_2:
			this->robot->getRightMotor()->setSpeed(-GEAR2);
			break;
		case RIGHT_RETRO_1:
			this->robot->getRightMotor()->setSpeed(-GEAR1);
			break;
		case RIGHT_STOP:
			this->robot->getRightMotor()->setSpeed(0);
			break;
		case RIGHT_GEAR_1:
			this->robot->getRightMotor()->setSpeed(GEAR1);
			break;
		case RIGHT_GEAR_2:
			this->robot->getRightMotor()->setSpeed(GEAR2);
			break;
		case GET_DISTANCE:
			byte distance = (byte) this->robot->getProxSens()->measure();
			Serial.println(distance);
			break; 
		}
		delete(message);
	}
	return LISTENING;
}
